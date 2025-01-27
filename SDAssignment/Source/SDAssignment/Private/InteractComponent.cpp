// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"
#include "Interface_Interact.h"

void UInteractComponent::PrintMessage(const FString& MessageToPrint)
{
	if(bUseDebugMessage)
	{
		UE_LOG(LogTemp,Warning,TEXT("%s"),*MessageToPrint);
	}
}

void UInteractComponent::PerformCapsuleInteract()
{
	if(InteractCapsule)
	{
		PrintMessage("Capsule Interact");
		TArray<AActor*> OverlappingActors;
		TArray<AActor*> PossibleInteractTargets;
		InteractCapsule->GetOverlappingActors(OverlappingActors);
		for(AActor* OverlappingActor: OverlappingActors)
		{
			if(OverlappingActor && OverlappingActor->Implements<UInterface_Interact>())
			{
				PossibleInteractTargets.Add(OverlappingActor);
				PrintMessage("Capsule Interact target found");
			}
		}
		FString TextInt = FString::FromInt(PossibleInteractTargets.Num());
		PrintMessage(TextInt);
	}
}

void UInteractComponent::PerformTraceInteract()
{
	if(InteractTraceSender)
	{
		if(InteractTraceRange <= 0)
		{
			
		} else
		{
			PrintMessage("InteractTraceRange <= 0");
		}
	} else
	{
		PrintMessage("InteractTraceSender is not valid");
	}
}

UInteractComponent::UInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}

void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UInteractComponent::SetInteractCapsule(UCapsuleComponent* DesiredInteractCapsule)
{
	if(bUseInteractPrompt == true || ChosenInteractType == EInteractType::CapsuleInteract)
	{
		InteractCapsule = DesiredInteractCapsule;
		PrintMessage("Interact Capsule set");
		return;
	}
	PrintMessage("Interact capsule was not set because bUseInteractPrompt != true AND ChosenInteractType != CapsuleInteract");
}

void UInteractComponent::SetInteractTraceSender(AActor* NewInteractTraceSender)
{
	if(ChosenInteractType == EInteractType::LineTrace)
	{
		InteractTraceSender = NewInteractTraceSender;
		PrintMessage("InteractTraceSender was set");
		return;
	}
	PrintMessage("InteractTraceSender was not set because ChosenInteractType != LineTrace");
}

void UInteractComponent::InteractAttempt()
{
	switch (ChosenInteractType)
	{
	case EInteractType::None:
		PrintMessage("EInteractType::None chosen");
		break;
	case EInteractType::CapsuleInteract:
		PrintMessage("CapsuleInteract chosen");
		PerformCapsuleInteract();
		break;
	case EInteractType::LineTrace:
		PrintMessage("LineTrace chosen");
		PerformTraceInteract();
		break;
		default:
			break;
	}
}
