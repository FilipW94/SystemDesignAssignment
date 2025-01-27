// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_Persistence.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInterface_Persistence : public UInterface
{
	GENERATED_BODY()
};

class SDASSIGNMENT_API IInterface_Persistence
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RequestSave(bool Async);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RequestLoad(UObject* Requester);

};
