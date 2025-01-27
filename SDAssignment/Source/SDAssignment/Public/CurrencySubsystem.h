// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CurrencySubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UCurrencySubsystem : public UGameInstanceSubsystem
{

	GENERATED_BODY()

	UPROPERTY()
	uint32 TotalScore;

	UPROPERTY()
	uint32 SessionScore;
	
};
