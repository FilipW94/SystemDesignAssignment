// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_Interact.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterface_Interact : public UInterface
{
	GENERATED_BODY()
};

class SDASSIGNMENT_API IInterface_Interact
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Interact(AActor* Initiator);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InteractPrompt(bool bCanInteract);
};
