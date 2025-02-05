// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PrototypeEnums.h"
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
	int32 TotalResources;

	UPROPERTY(BlueprintReadWrite)
	int32 SessionResources;

	UPROPERTY(BlueprintReadWrite)
	TMap<E_Levels, bool> UnlockedMaps;

	UPROPERTY(BlueprintReadWrite)
	float DirectDamage;

	UPROPERTY(BlueprintReadWrite)
	int32 StartingBolts;

	UPROPERTY(BlueprintReadWrite)
	float ReloadSpeed;

	UPROPERTY(BlueprintReadWrite)
	float MoveSpeed;

	UPROPERTY(BlueprintReadWrite)
	float MapHighScore;

	UPROPERTY(BlueprintReadWrite)
	float MaxHealth;
	
};
