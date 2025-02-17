// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class E_Levels : uint8
{
	None,
	MainMenu,
	LVL_01 = 0,
	LVL_02 = 1,
	LVL_03 = 2,
	LVL_04 = 3,
	LVL_05 = 4,
	LVL_06 = 5,
	LVL_07 = 6,
	LVL_08 = 7,
	LVL_09 = 8

};
UENUM(BlueprintType)
enum class E_BoltType : uint8
{
	None,
	LifeSteal,
	Poison,
	Frost,
	Explosive
};

UENUM(BlueprintType)
enum class E_Upgrades : uint8
{
	None,
	DirectDamage,
	MoreStartingBolts,
	FasterReload,
	IncreasedMoveSpeed
};

class SDASSIGNMENT_API PrototypeEnums
{
public:
	PrototypeEnums();
	~PrototypeEnums();
};
