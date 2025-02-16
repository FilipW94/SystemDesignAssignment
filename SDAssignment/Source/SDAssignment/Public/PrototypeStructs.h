// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "PrototypeStructs.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct FUpgrades
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName UpgradeName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Rank;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Value;
};

USTRUCT(BlueprintType)
struct FShopUpgrades : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FUpgrades UpgradeDetails;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Cost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* UpgradeIcon;
};

class SDASSIGNMENT_API PrototypeStructs
{
public:
	PrototypeStructs();
	~PrototypeStructs();
};
