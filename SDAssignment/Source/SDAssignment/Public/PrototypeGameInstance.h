// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface_Persistence.h"
#include "PrototypeSaveGame.h"
#include "Engine/GameInstance.h"
#include "PrototypeGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameLoaded, UPrototypeSaveGame*, SaveGameRef);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameSaved, UPrototypeSaveGame*, SaveGameRef);

UCLASS()
class SDASSIGNMENT_API UPrototypeGameInstance : public UGameInstance, public IInterface_Persistence
{
	GENERATED_BODY()

	UPROPERTY()
	UPrototypeSaveGame* SaveGameRef;
	
public:
	UPROPERTY(BlueprintReadWrite)
	FString SaveGameSlotName = "Slot1";

	UPROPERTY(BlueprintReadWrite)
	FString SaveSlotOne = "Slot1";
	
	UPROPERTY(BlueprintReadWrite)
	FString SaveSlotTwo = "Slot2";
	
	UPROPERTY(BlueprintReadOnly)
	FString SaveSlotThree = "Slot3";
	
	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	void LoadGame(const bool Async);

	UFUNCTION(BlueprintCallable)
	bool DoesMySaveGameExist(const FString& SlotName, const int32 UserIndex) const;
	
	UFUNCTION(BlueprintCallable)
	void SetSaveGameRef(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGame);

	UFUNCTION(BlueprintCallable)
	void CreateSaveGame();

	UFUNCTION(BlueprintCallable)
	void SaveGame(bool Async);

	UFUNCTION()
	void OnGameSaved(const FString& SlotName, const int32 UserIndex, bool bSaveSuccessful);

	virtual void RequestLoad_Implementation(UObject* Requester) override;

	virtual void RequestSave_Implementation(bool Async) override;
	
	UPROPERTY(BlueprintAssignable)
	FGameLoaded GameLoaded;
	UPROPERTY(BlueprintAssignable)
	FGameSaved GameSaved;
	

};
