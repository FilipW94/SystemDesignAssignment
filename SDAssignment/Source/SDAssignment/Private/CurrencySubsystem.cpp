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

void UCurrencySubsystem::IncreaseSessionCurrency(FName AcquisitionMethod,float CurrencyGained)
{
	SessionCurrency += CurrencyGained;
	SessionCurrencyChanged.Broadcast(SessionCurrency);
	AddAcquisitionLogEntry(AcquisitionMethod, CurrencyGained);
}

void UCurrencySubsystem::DecreaseSessionCurrency(FName AcquisitionMethod, float CurrencyLost)
{
	SessionCurrency -= CurrencyLost;
	SessionCurrencyChanged.Broadcast(SessionCurrency);
	AddAcquisitionLogEntry(AcquisitionMethod, -CurrencyLost);
}

TMap<FName, int32> UCurrencySubsystem::GetAcquisitionLog()
{
	return CurrencyAcquisitionLog;
}

void UCurrencySubsystem::AddAcquisitionLogEntry(FName AcquisitionMethod, int32 CurrencyGained)
{
	CurrencyAcquisitionLog.Add(AcquisitionMethod, CurrencyGained);
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
