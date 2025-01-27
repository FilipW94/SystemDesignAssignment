// Fill out your copyright notice in the Description page of Project Settings.


#include "CurrencySubsystem.h"

void UCurrencySubsystem::IncreaseTotalResources_Implementation(float ResourcesGained)
{
	TotalResources += ResourcesGained;
	TotalResourcesChanged.Broadcast(TotalResources);
}

void UCurrencySubsystem::DecreaseTotalResources_Implementation(float ResourcesSpent)
{
	TotalResources -= ResourcesSpent;
	TotalResourcesChanged.Broadcast(TotalResources);
}

void UCurrencySubsystem::IncreaseSessionResources_Implementation(float ResourcesGained)
{
	SessionResources += ResourcesGained;
	SessionResourcesChanged.Broadcast(SessionResources);
}

void UCurrencySubsystem::DecreaseSessionResources_Implementation(float ResourcesLost)
{
	SessionResources -= ResourcesLost;
	SessionResourcesChanged.Broadcast(SessionResources);
}
