// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interface_Savable.h"
#include "CurrencySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSessionResourcesChanged, float, NewSessionResourceAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTotalResourcesChanged, float, NewTotalResourceAmount);

UCLASS()
class UCurrencySubsystem : public UGameInstanceSubsystem, public IInterface_Savable
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite)
	int32 TotalResources;

	UPROPERTY(BlueprintReadWrite)
	int32 SessionResources;


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
	FORCEINLINE float GetTotalResources() const{return TotalResources;}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetSessionResources() const{return SessionResources;}
	
	virtual void LoadData_Implementation(UPrototypeSaveGame* SaveGameRef) override;
	
	virtual void SaveData_Implementation(UPrototypeSaveGame* SaveGameRef) override;

	
};
