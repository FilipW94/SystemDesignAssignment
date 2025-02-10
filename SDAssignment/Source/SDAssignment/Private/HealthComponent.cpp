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
		OwnerHasDied();
		OwnerDied.Broadcast();
		return;
		
	}
	HealthChanged.Broadcast(CurrentHealth);
}

void UHealthComponent::SetMaxHealth(float NewMaxHealth)
{
	MaxHealth = NewMaxHealth;
	CurrentHealth = MaxHealth;
}

void UHealthComponent::OwnerHasDied_Implementation()
{
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

