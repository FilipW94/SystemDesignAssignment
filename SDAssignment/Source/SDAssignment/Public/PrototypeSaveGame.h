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

	UPrototypeSaveGame();

public:
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void LoadDataForRequester(UObject* Requester);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SaveAllData(const TArray<AActor*>&  SavableObject);

	UPROPERTY(BlueprintReadWrite)
	int32 Saved_TotalResources = 100.f;

	UPROPERTY(BlueprintReadWrite)
	int32 Saved_SessionResources = 0.f;

	UPROPERTY(BlueprintReadWrite)
	TMap<E_Levels, bool> Saved_UnlockedMaps;

	UPROPERTY(BlueprintReadWrite)
	float Saved_DirectDamage = 25.f;

	UPROPERTY(BlueprintReadWrite)
	int32 Saved_StartingBolts = 10.f;

	UPROPERTY(BlueprintReadWrite)
	float Saved_ReloadSpeed = 2.0f;

	UPROPERTY(BlueprintReadWrite)
	float Saved_MoveSpeed = 600.f;

	UPROPERTY(BlueprintReadWrite)
	float Saved_MapHighScore = 0.f;

	UPROPERTY(BlueprintReadWrite)
	float Saved_MaxHealth = 100.f;

	UFUNCTION()
	void SetInitialMapStatus();
	
};
