// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/TimelineComponent.h"
#include "BasicCrouchComponent.generated.h"

class UCurveFloat;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCrouchStatusChanged, bool, IsCrouching);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), DisplayName= "Crouch Component")

class SDASSIGNMENT_API UBasicCrouchComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBasicCrouchComponent();

	UFUNCTION()
	void HandleTimelineProgress(float Value) const;

	UFUNCTION()
	void OnTimelineFinished();
	
	UPROPERTY(BlueprintAssignable)
	FCrouchStatusChanged CrouchStatusChanged;
	
private:
	UPROPERTY(EditAnywhere)
	bool bShowDebug;

	UPROPERTY(EditAnywhere)
	float TraceEndPointAdjustment;
	
	UPROPERTY(EditAnywhere)
	float CrouchTransitionPeriod;

	UPROPERTY()
	UCurveFloat* CurveFloat;

	void ShortenPlayerCapsule() const;

	UFUNCTION()
	void LengthenPlayerCapsule() const;
	
	UPROPERTY()
	bool bIsCrouching;

	UPROPERTY()
	bool bCanUncrouch;

	UPROPERTY()
	bool bTimelineInProgress;
	
	UPROPERTY()
	UTimelineComponent* CrouchTimeline;
	
	UPROPERTY()
	UCapsuleComponent* PlayerCapsuleComponent;

	UPROPERTY()
	float PlayerStandingHeight;

	UPROPERTY()
	float PlayerCrouchingHeight;
	
	UFUNCTION()
	void AssignPlayerCapsuleComponent(UCapsuleComponent* AssignedPlayerCapsuleComponent);
	
	UFUNCTION()
	void SetPlayerHeightValues();

	UFUNCTION()
	static void PrintMessage(const FString& MessageToPrint);

	UFUNCTION()
	bool CheckOverheadObstacles() const;
	
	UFUNCTION()
	void StartCrouch();

	UFUNCTION()
	void StopCrouch();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable)
	void HandleCrouchInput();

	UFUNCTION(BlueprintCallable)
	void SetCrouchComponents(UCapsuleComponent* PlayerCapsuleComponentRef);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetCrouchingStatus();
};
