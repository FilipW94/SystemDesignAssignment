// Fill out your copyright notice in the Description page of Project Settings.


#include "PrototypeSaveGame.h"
#include "Interface_Savable.h"

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
