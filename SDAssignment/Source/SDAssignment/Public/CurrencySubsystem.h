// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interface_Savable.h"
#include "CurrencySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSessionCurrencyChanged, float, NewSessionCurrencyAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTotalCurrencyChanged, float, NewTotalCurrencyAmount);

USTRUCT(BlueprintType)
struct FAcquisition
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText AcquisitionMethod;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Currency;
};

UCLASS()
class UCurrencySubsystem : public UGameInstanceSubsystem, public IInterface_Savable
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FAcquisition> CurrencyAcquisitionLog;

public:
	UPROPERTY(BlueprintReadWrite)
	int32 TotalCurrency;

	UPROPERTY(BlueprintReadWrite)
	int32 SessionCurrency;

	UPROPERTY(BlueprintAssignable)
	FSessionCurrencyChanged SessionCurrencyChanged;

	UPROPERTY(BlueprintAssignable)
	FTotalCurrencyChanged TotalCurrencyChanged;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FAcquisition> GetAcquisitionLog();

	UFUNCTION(BlueprintCallable)
	void AddAcquisitionLogEntry(FAcquisition Entry);
	
	UFUNCTION(BlueprintCallable)
	void IncreaseTotalCurrency(float CurrencyGained);

	UFUNCTION(BlueprintCallable)
	void DecreaseTotalCurrency(float CurrencySpent);

	UFUNCTION(BlueprintCallable)
	void IncreaseSessionCurrency(FAcquisition Entry);

	UFUNCTION(BlueprintCallable)
	void DecreaseSessionCurrency(FAcquisition Entry);

	UFUNCTION(BlueprintCallable)
	void ClearSessionCurrency();

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetTotalCurrency() const{return TotalCurrency;}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetSessionCurrency() const{return SessionCurrency;}
	
	virtual void LoadData_Implementation(UPrototypeSaveGame* SaveGameRef) override;
	
	virtual void SaveData_Implementation(UPrototypeSaveGame* SaveGameRef) override;

	
};
