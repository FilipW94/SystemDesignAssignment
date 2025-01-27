// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/CapsuleComponent.h"
#include "InteractComponent.generated.h"

UENUM(BlueprintType)
enum class EInteractType : uint8
{
		None UMETA(DisplayName = "None"),
		CapsuleInteract UMETA(DisplayName = "CapsuleInteract"),
		LineTrace UMETA(DisplayName = "LineTrace")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SDASSIGNMENT_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()
	
	UPROPERTY()
	UCapsuleComponent* InteractCapsule;

	UPROPERTY()
	AActor* InteractTraceSender;

	UFUNCTION()
	void PrintMessage(const FString& MessageToPrint);

	UFUNCTION()
	void PerformCapsuleInteract();

	UFUNCTION()
	void PerformTraceInteract();

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Interact Settings")
	bool bUseDebugMessage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Interact Settings")
	bool bUseThrottle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Interact Settings")
	bool bUseInteractPrompt;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Interact Settings")
	float InteractTraceRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Interact Settings")
	EInteractType ChosenInteractType;
	
	// Sets default values for this component's properties
	UInteractComponent();

	
	UFUNCTION(BlueprintCallable)
	void SetInteractCapsule(UCapsuleComponent* DesiredInteractCapsule);

	UFUNCTION(BlueprintCallable)
	void SetInteractTraceSender(AActor* NewInteractTraceSender);

	UFUNCTION(BlueprintCallable)
	void InteractAttempt();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
