// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CurrencySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSessionResourcesChanged, float, NewSessionResourceAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTotalResourcesChanged, float, NewTotalResourceAmount);

UCLASS()
class UCurrencySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	int32 TotalResources;

	UPROPERTY()
	int32 SessionResources;

public:

	UPROPERTY(BlueprintAssignable)
	FSessionResourcesChanged SessionResourcesChanged;

	UPROPERTY(BlueprintAssignable)
	FTotalResourcesChanged TotalResourcesChanged;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void IncreaseTotalResources(float ResourcesGained);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DecreaseTotalResources(float ResourcesSpent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void IncreaseSessionResources(float ResourcesGained);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DecreaseSessionResources(float ResourcesLost);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetTotalScore() const{return TotalResources;}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetSessionScore() const{return SessionResources;}
	
};
