// Fill out your copyright notice in the Description page of Project Settings.


#include "CurrencySubsystem.h"

void UCurrencySubsystem::IncreaseTotalCurrency_Implementation(float CurrencyGained)
{
	TotalCurrency += CurrencyGained;
	TotalCurrencyChanged.Broadcast(TotalCurrency);
}

void UCurrencySubsystem::DecreaseTotalCurrency_Implementation(float CurrencySpent)
{
	TotalCurrency -= CurrencySpent;
	TotalCurrencyChanged.Broadcast(TotalCurrency);
}

void UCurrencySubsystem::IncreaseSessionCurrency_Implementation(float CurrencyGained)
{
	SessionCurrency += CurrencyGained;
	SessionCurrencyChanged.Broadcast(SessionCurrency);
}

void UCurrencySubsystem::DecreaseSessionCurrency_Implementation(float CurrencyLost)
{
	SessionCurrency -= CurrencyLost;
	SessionCurrencyChanged.Broadcast(SessionCurrency);
}

void UCurrencySubsystem::ClearSessionCurrency()
{
	SessionCurrency = 0;
	SessionCurrencyChanged.Broadcast(SessionCurrency);
}

void UCurrencySubsystem::LoadData_Implementation(UPrototypeSaveGame* SaveGameRef)
{
	TotalCurrency = SaveGameRef->Saved_TotalResources;
}

void UCurrencySubsystem::SaveData_Implementation(UPrototypeSaveGame* SaveGameRef)
{
	SaveGameRef->Saved_TotalResources = TotalCurrency;
}
