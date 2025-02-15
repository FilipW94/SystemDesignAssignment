// Fill out your copyright notice in the Description page of Project Settings.


#include "CurrencySubsystem.h"

void UCurrencySubsystem::IncreaseTotalCurrency(float CurrencyGained)
{
	TotalCurrency += CurrencyGained;
	TotalCurrencyChanged.Broadcast(TotalCurrency);
}

void UCurrencySubsystem::DecreaseTotalCurrency(float CurrencySpent)
{
	TotalCurrency -= CurrencySpent;
	TotalCurrencyChanged.Broadcast(TotalCurrency);
}

void UCurrencySubsystem::IncreaseSessionCurrency(FAcquisition Entry)
{
	SessionCurrency += Entry.CurrencyGained;
	SessionCurrencyChanged.Broadcast(SessionCurrency);
	AddAcquisitionLogEntry(Entry);
}

void UCurrencySubsystem::DecreaseSessionCurrency(float CurrencyLost)
{
	SessionCurrency -= CurrencyLost;
	SessionCurrencyChanged.Broadcast(SessionCurrency);
}

TArray<FAcquisition> UCurrencySubsystem::GetAcquisitionLog()
{
	return CurrencyAcquisitionLog;
}

void UCurrencySubsystem::AddAcquisitionLogEntry(FAcquisition Entry)
{
	CurrencyAcquisitionLog.Add(Entry);
}

void UCurrencySubsystem::ClearSessionCurrency()
{
	SessionCurrency = 0;
	CurrencyAcquisitionLog.Empty();
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
