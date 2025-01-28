// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCrouchComponent.h"
#include "Engine/World.h"
#include "CollisionQueryParams.h"
#include "DrawDebugHelpers.h"
#include "Curves/CurveFloat.h"
#include "Components/TimelineComponent.h"

// Sets default values for this component's properties
UBasicCrouchComponent::UBasicCrouchComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	CrouchTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("CrouchTimeline"));

}

void UBasicCrouchComponent::HandleTimelineProgress(float Value) const
{
	float PlayerHeightTransition = FMath::Lerp(PlayerStandingHeight, PlayerCrouchingHeight, Value);

	if (PlayerCapsuleComponent)
	{
		if(bShowDebug)
		{
			UE_LOG(LogTemp, Warning, TEXT("Value: %f"), Value);
		}
		PlayerCapsuleComponent->SetCapsuleHalfHeight(PlayerHeightTransition);
	}
}

void UBasicCrouchComponent::OnTimelineFinished()
{
	PrintMessage("Timeline finished");
	bTimelineInProgress = false;
	//BIsCrouching = !BIsCrouching;
}


void UBasicCrouchComponent::StartCrouch()
{
	if (!bTimelineInProgress)
	{
		PrintMessage("StartCrouch");
		bTimelineInProgress = true;
		bIsCrouching = true;
		CrouchStatusChanged.Broadcast(true);
		ShortenPlayerCapsule();
	}
}

void UBasicCrouchComponent::StopCrouch()
{
	if (!bTimelineInProgress && !CheckOverheadObstacles())
	{
		PrintMessage("StopCrouch");
		bTimelineInProgress = true;
		bIsCrouching = false;
		CrouchStatusChanged.Broadcast(false);
		LengthenPlayerCapsule();
	}
}

void UBasicCrouchComponent::ShortenPlayerCapsule() const
{
	CrouchTimeline->Play();
}

void UBasicCrouchComponent::LengthenPlayerCapsule() const
{
	CrouchTimeline->Reverse();
}

void UBasicCrouchComponent::AssignPlayerCapsuleComponent(UCapsuleComponent* AssignedPlayerCapsuleComponent)
{
	if (!PlayerCapsuleComponent)
	{
		if (AssignedPlayerCapsuleComponent)
		{
			PlayerCapsuleComponent = AssignedPlayerCapsuleComponent;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No valid PlayerCapsuleComponent was supplied"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerCapsuleComponent was already set"));
	}
}


void UBasicCrouchComponent::SetPlayerHeightValues()
{
	if (PlayerCapsuleComponent)
	{
		PlayerStandingHeight = PlayerCapsuleComponent->GetScaledCapsuleHalfHeight();
		if (PlayerStandingHeight > 0)
		{
			PlayerCrouchingHeight = PlayerStandingHeight / 2;
		}
		else
		{
			PrintMessage("Did not set crouch height because PlayerStandingHeight was less than 1");
		}
	}
	else
	{
		PrintMessage("Could not set height values because PlayerCapsuleComponent was null");
	}
	if(bShowDebug)
	{
		PrintMessage(FString::Printf(TEXT("Standingheight: %f"), PlayerStandingHeight));
		PrintMessage(FString::Printf(TEXT("Crouchingheight: %f"), PlayerCrouchingHeight));
	}

}

void UBasicCrouchComponent::PrintMessage(const FString& MessageToPrint)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *MessageToPrint);
}

bool UBasicCrouchComponent::CheckOverheadObstacles() const
{
	FVector TraceStartPoint = PlayerCapsuleComponent->GetRelativeLocation();
	FVector TraceEndPoint = TraceStartPoint + FVector(0, 0, PlayerStandingHeight + TraceEndPointAdjustment);
	FCollisionShape TraceCollisionShape = FCollisionShape::MakeSphere(
		PlayerCapsuleComponent->GetUnscaledCapsuleRadius());
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());

	FHitResult OutHit;
	bool bHit = GetWorld()->SweepSingleByChannel(
		OutHit,
		TraceStartPoint,
		TraceEndPoint,
		FQuat::Identity,
		ECC_Visibility,
		TraceCollisionShape,
		Params
	);

	if (bShowDebug)
	{
		DrawDebugSphere(GetWorld(), TraceStartPoint, TraceCollisionShape.GetSphereRadius(), 16, FColor::Blue, false,
		                5.0f);
		DrawDebugSphere(GetWorld(), TraceEndPoint, TraceCollisionShape.GetSphereRadius(), 16, FColor::Blue, false,
		                5.0f);
	}

	if (bHit)
	{
		PrintMessage("Actor hit");
		if (bShowDebug)
		{
			DrawDebugSphere(GetWorld(), OutHit.Location, TraceCollisionShape.GetSphereRadius(), 16, FColor::Red, false,
			                5.0f);
		}
	}
	return bHit;
}

// Called when the game starts
void UBasicCrouchComponent::BeginPlay()
{
	Super::BeginPlay();

	CurveFloat = NewObject<UCurveFloat>(this, TEXT("Timeline CurveFloat"));
	CurveFloat->FloatCurve.AddKey(0.0f, 0.0f);

	CurveFloat->FloatCurve.AddKey(CrouchTransitionPeriod, 1.0f);

	if (CurveFloat)
	{
		if (CrouchTimeline && CurveFloat)
		{
			FOnTimelineFloat TimelineProgress;
			TimelineProgress.BindUFunction(this, FName("HandleTimelineProgress"));
			CrouchTimeline->AddInterpFloat(CurveFloat, TimelineProgress);
			CrouchTimeline->SetLooping(false);

			FOnTimelineEvent TimelineFinishedFunction;
			TimelineFinishedFunction.BindUFunction(this, FName("OnTimelineFinished"));
			CrouchTimeline->SetTimelineFinishedFunc(TimelineFinishedFunction);
			CrouchTimeline->SetTimelineLength(CrouchTransitionPeriod);
			CrouchTimeline->SetPlayRate(1.0f);
		}
		for (auto It = CurveFloat->FloatCurve.GetKeyIterator(); It; ++It)
		{
			UE_LOG(LogTemp, Warning, TEXT("Curve Key: Time = %f, Value = %f"), It->Time, It->Value);
		}
	}
	else
	{
		PrintMessage("CurveFloat not valid");
	}
	if(bShowDebug)
	{
		UE_LOG(LogTemp, Warning, TEXT("CrouchTransitionPeriod: %f"), CrouchTransitionPeriod);
		UE_LOG(LogTemp, Warning, TEXT("TimelineLength: %f"), CrouchTimeline->GetTimelineLength());
	}
	
}

void UBasicCrouchComponent::HandleCrouchInput()
{
	if(PlayerCapsuleComponent)
	{
		PrintMessage("PlayerCapsuleComponent has not been assigned");
	}
	if (bIsCrouching)
	{
		StopCrouch();
	}
	else
	{
		StartCrouch();
	}
}

void UBasicCrouchComponent::SetCrouchComponents(UCapsuleComponent* PlayerCapsuleComponentRef)
{
	AssignPlayerCapsuleComponent(PlayerCapsuleComponentRef);
	SetPlayerHeightValues();
}

bool UBasicCrouchComponent::GetCrouchingStatus()
{
	return bIsCrouching;
}
