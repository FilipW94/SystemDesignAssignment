// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthChangedDelegate, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOwnerDiedDelegate);

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SDASSIGNMENT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UHealthComponent();
	
	UPROPERTY(BlueprintReadOnly)
	float CurrentHealth;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxHealth;
	
	UPROPERTY(BlueprintAssignable)
	FHealthChangedDelegate HealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOwnerDiedDelegate OwnerDied;

	UFUNCTION(BlueprintCallable)
	void HealthGained(float HealthAmountGained);

	UFUNCTION(BlueprintCallable)
	void HealthLost(float HealthAmountLost);

	UFUNCTION(BlueprintNativeEvent, Blueprintable)
	void OwnerHasDied();
	

	
};
