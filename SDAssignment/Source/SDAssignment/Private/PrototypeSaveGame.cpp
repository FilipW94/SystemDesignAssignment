// Fill out your copyright notice in the Description page of Project Settings.


#include "PrototypeSaveGame.h"
#include "Interface_Savable.h"
#include "PrototypeEnums.h"

void UPrototypeSaveGame::LoadDataForRequester_Implementation(UObject* Requester)
{
	IInterface_Savable::Execute_LoadData(Requester, this);
}

void UPrototypeSaveGame::SaveAllData_Implementation(const TArray<AActor*>& SavableObject)
{
	for (auto Element : SavableObject)
	{
		IInterface_Savable::Execute_SaveData(Element, this);
	}
}

UPrototypeSaveGame::UPrototypeSaveGame()
{
	SetStartingValues();
}

void UPrototypeSaveGame::SetStartingValues()
{
	if(Saved_UnlockedMaps.Num() == 0 )
	{
		Saved_UnlockedMaps.Add(E_Levels::LVL_01, true);
		Saved_UnlockedMaps.Add(E_Levels::LVL_02, false);
		Saved_UnlockedMaps.Add(E_Levels::LVL_03, false);
		Saved_UnlockedMaps.Add(E_Levels::LVL_04, false);
		Saved_UnlockedMaps.Add(E_Levels::LVL_05, false);
		Saved_UnlockedMaps.Add(E_Levels::LVL_06, false);
		Saved_UnlockedMaps.Add(E_Levels::LVL_07, false);
		Saved_UnlockedMaps.Add(E_Levels::LVL_08, false);
	}
	if(Saved_PlayerUpgrades.Num() == 0)
	{
		Saved_PlayerUpgrades.Add(FUpgrades{ FName(TEXT("MoveSpeed")), 0, 600.f });
		Saved_PlayerUpgrades.Add(FUpgrades{ FName(TEXT("DirectDamage")), 0, 25.0f });
		Saved_PlayerUpgrades.Add(FUpgrades{ FName(TEXT("StartingBolts")), 0, 12.0f });
		Saved_PlayerUpgrades.Add(FUpgrades{ FName(TEXT("ReloadSpeed")), 0, 2.0f });
		Saved_PlayerUpgrades.Add(FUpgrades{ FName(TEXT("MaxHealth")), 0, 100.0f });
	}
	if(Saved_UnlockedBolts.Num() == 0)
	{
		Saved_UnlockedBolts.Add(E_BoltType::None, true);
		Saved_UnlockedBolts.Add(E_BoltType::Frost, false);
		Saved_UnlockedBolts.Add(E_BoltType::Poison, false);
		Saved_UnlockedBolts.Add(E_BoltType::LifeSteal, false);
		Saved_UnlockedBolts.Add(E_BoltType::Explosive, false);
	}
}
