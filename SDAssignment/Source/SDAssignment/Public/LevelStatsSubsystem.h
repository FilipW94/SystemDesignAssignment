// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "LevelStatsSubsystem.generated.h"

/**
 * 
 */

UENUM(Blueprintable)
enum ELevelStatCategories
{
	EnemiesKilled,
	BoltsFired,
	BoltCacheFound,
	CurrencyCacheFound,
	PlayerDeaths
	
};

USTRUCT(Blueprintable, BlueprintType)
struct FLevelStats
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 EnemiesKilled;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 BoltsFired;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 TimeElapsed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 BoltCachesFound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CurrencyCachesFound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 PlayerDeaths;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bPacifistRun = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bStealthRun = true;
};

UCLASS()
class SDASSIGNMENT_API ULevelStatsSubsystem : public UWorldSubsystem
{
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

private:
	GENERATED_BODY()

	FLevelStats LevelStats;

public:
	UFUNCTION(BlueprintCallable)
	void IncrementLevelStat(ELevelStatCategories StatToIncrement);
	
	UFUNCTION(BlueprintCallable)
	const FLevelStats& GetLevelStats();

	FORCEINLINE void StealthRunFailed() { LevelStats.bStealthRun = false; }

};
