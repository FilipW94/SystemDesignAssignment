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
	SetInitialMapStatus();
}

void UPrototypeSaveGame::SetInitialMapStatus()
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
}
