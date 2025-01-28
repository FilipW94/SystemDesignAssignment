// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;

}

void UHealthComponent::HealthGained(float HealthAmountGained)
{
	CurrentHealth += HealthAmountGained;
	if(CurrentHealth > MaxHealth)
	{
		CurrentHealth = MaxHealth;
		HealthChanged.Broadcast(CurrentHealth);
	}
}
void UHealthComponent::HealthLost(float HealthAmountLost)
{
	CurrentHealth -= HealthAmountLost;
	if(CurrentHealth <= 0.f)
	{
		CurrentHealth = 0.f;
		PlayerDied.Broadcast();
		return;
		
	}
	HealthChanged.Broadcast(CurrentHealth);
}

void UHealthComponent::PlayerHasDied_Implementation()
{
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

