// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PrototypeSaveGame.h"
#include "Interface_Savable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterface_Savable : public UInterface
{
	GENERATED_BODY()
};

class SDASSIGNMENT_API IInterface_Savable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SaveData(UPrototypeSaveGame* SaveGameRef);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void LoadData(UPrototypeSaveGame* SaveGameRef);
	
};
