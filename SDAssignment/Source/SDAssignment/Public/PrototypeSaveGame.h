// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PrototypeSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class SDASSIGNMENT_API UPrototypeSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void LoadDataForRequester(UObject* Requester);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SaveAllData(const TArray<AActor*>&  SavableObject);

	UPROPERTY(BlueprintReadWrite)
	int32 PlayerCurrency;
	
};
