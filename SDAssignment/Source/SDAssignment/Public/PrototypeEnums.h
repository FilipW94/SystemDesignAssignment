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
	LVL_01,
	LVL_02,
	LVL_03,
	LVL_04,
	LVL_05,
	LVL_06,
	LVL_07,
	LVL_08,
	LVL_09

};
class SDASSIGNMENT_API PrototypeEnums
{
public:
	PrototypeEnums();
	~PrototypeEnums();
};
