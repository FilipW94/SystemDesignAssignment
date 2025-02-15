// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelStatsSubsystem.h"
#include "Kismet/GameplayStatics.h"

void ULevelStatsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void ULevelStatsSubsystem::IncrementLevelStat(ELevelStatCategories StatToIncrement)
{
	switch (StatToIncrement)
	{
	case ELevelStatCategories::EnemiesKilled:
		LevelStats.EnemiesKilled++;
		LevelStats.bPacifistRun = false;
		break;
	case ELevelStatCategories::BoltsFired:
		LevelStats.BoltsFired++;
		break;

	case ELevelStatCategories::BoltCacheFound:
		LevelStats.BoltCachesFound++;
		break;

	case ELevelStatCategories::CurrencyCacheFound:
		LevelStats.CurrencyCachesFound++;
		break;
	case ELevelStatCategories::PlayerDeaths:
		LevelStats.PlayerDeaths++;
		break;
	}
}

const FLevelStats& ULevelStatsSubsystem::GetLevelStats()
{
	LevelStats.TimeElapsed = UGameplayStatics::GetTimeSeconds(this);
	return LevelStats;
}
