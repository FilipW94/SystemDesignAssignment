// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interface_Savable.h"
#include "CurrencySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSessionCurrencyChanged, float, NewSessionCurrencyAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTotalCurrencyChanged, float, NewTotalCurrencyAmount);

UCLASS()
class UCurrencySubsystem : public UGameInstanceSubsystem, public IInterface_Savable
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite)
	int32 TotalCurrency;

	UPROPERTY(BlueprintReadWrite)
	int32 SessionCurrency;


	UPROPERTY(BlueprintAssignable)
	FSessionCurrencyChanged SessionCurrencyChanged;

	UPROPERTY(BlueprintAssignable)
	FTotalCurrencyChanged TotalCurrencyChanged;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void IncreaseTotalCurrency(float CurrencyGained);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DecreaseTotalCurrency(float CurrencySpent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void IncreaseSessionCurrency(float CurrencyGained);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DecreaseSessionCurrency(float CurrencyLost);

	UFUNCTION(BlueprintCallable)
	void ClearSessionCurrency();

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetTotalCurrency() const{return TotalCurrency;}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetSessionCurrency() const{return SessionCurrency;}
	
	virtual void LoadData_Implementation(UPrototypeSaveGame* SaveGameRef) override;
	
	virtual void SaveData_Implementation(UPrototypeSaveGame* SaveGameRef) override;

	
};
