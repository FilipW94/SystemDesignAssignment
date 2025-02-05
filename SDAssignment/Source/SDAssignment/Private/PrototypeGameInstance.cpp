// Fill out your copyright notice in the Description page of Project Settings.


#include "PrototypeGameInstance.h"

#include "Interface_Savable.h"
#include "Kismet/GameplayStatics.h"

void UPrototypeGameInstance::Init()
{
	Super::Init();

	DoesMySaveGameExist(SaveGameSlotName, 0) ? LoadGame(false) : CreateSaveGame();
}

void UPrototypeGameInstance::LoadGame(const bool Async)
{
	UE_LOG(LogTemp, Log, TEXT("LoadGame function was called"));
	if(Async)
	{
		FAsyncLoadGameFromSlotDelegate LoadGameDelegate;
		LoadGameDelegate.BindUObject(this, &UPrototypeGameInstance::SetSaveGameRef);
		UGameplayStatics::AsyncLoadGameFromSlot(SaveGameSlotName, 0, LoadGameDelegate);
		GameLoaded.Broadcast(SaveGameRef);
		UE_LOG(LogTemp, Log, TEXT("Game was loaded asynchronously"));

	}
	else
	{
		USaveGame* LoadedGame = UGameplayStatics::LoadGameFromSlot(SaveGameSlotName, 0);
		SetSaveGameRef(SaveGameSlotName, 0, LoadedGame);
		UE_LOG(LogTemp, Log, TEXT("Game was loaded synchronously"));
	}
}

bool UPrototypeGameInstance::DoesMySaveGameExist(const FString& SlotName, const int32 UserIndex) const
{
	return UGameplayStatics::DoesSaveGameExist(SaveGameSlotName, UserIndex);
}

void UPrototypeGameInstance::SetSaveGameRef(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGame)
{
	UE_LOG(LogTemp, Log, TEXT("SetSaveGameRef function was called"));
	if(LoadedGame)
	{
		SaveGameRef = Cast<UPrototypeSaveGame>(LoadedGame);
		if(SaveGameRef)
		{
			GameLoaded.Broadcast(SaveGameRef);
			UE_LOG(LogTemp, Log, TEXT("Game loaded asynchronously from slot: %s"), *SlotName);
		}
		UE_LOG(LogTemp, Log, TEXT("SaveGameRef failed cast to Filip_SaveGame"));
	}
}

void UPrototypeGameInstance::CreateSaveGame()
{
	SaveGameRef = Cast<UPrototypeSaveGame>(UGameplayStatics::CreateSaveGameObject(UPrototypeSaveGame::StaticClass()));
	if(SaveGameRef)
	{
		UE_LOG(LogTemp, Log, TEXT("Save game created successfully"));
	} else
	{
		UE_LOG(LogTemp, Log, TEXT("Save game was not created successfully"));
	}
	
}

void UPrototypeGameInstance::SaveGame(bool Async)
{
	UE_LOG(LogTemp, Log, TEXT("'SaveGame function called'"));
	if(Async)
	{
		FAsyncSaveGameToSlotDelegate SaveGameDelegate;
		SaveGameDelegate.BindUObject(this, &UPrototypeGameInstance::OnGameSaved);
		UGameplayStatics::AsyncSaveGameToSlot(SaveGameRef, SaveGameSlotName, 0, SaveGameDelegate);
		UE_LOG(LogTemp, Log, TEXT("Game was saved asynchronously"));
	} else
	{
		UGameplayStatics::SaveGameToSlot(SaveGameRef,SaveGameSlotName,0);
		bool bSaveSuccessful = UGameplayStatics::SaveGameToSlot(SaveGameRef,SaveGameSlotName,0);
		
		if(bSaveSuccessful)
		{
			GameSaved.Broadcast(SaveGameRef);
			UE_LOG(LogTemp, Log, TEXT("Game was saved synchronously"));
			return;
		}
		UE_LOG(LogTemp, Log, TEXT("Game failed to save synchronously"));
	}
}

void UPrototypeGameInstance::OnGameSaved(const FString& SlotName, const int32 UserIndex, bool bSaveSuccessful)
{
	if(bSaveSuccessful)
	{
		GameSaved.Broadcast(SaveGameRef);
		UE_LOG(LogTemp, Log, TEXT("Game was saved successfully"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Game did not save sucessfully"));
	}
}

void UPrototypeGameInstance::RequestLoad_Implementation(UObject* Requester)
{
	UE_LOG(LogTemp, Log, TEXT("RequestLoad function was called"));
	if(SaveGameRef)
	{
		SaveGameRef->LoadDataForRequester(Requester);
		UE_LOG(LogTemp, Log, TEXT("SaveGameRef is valid"));
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("SaveGameRef is null so a new one was created"));
	}
}

void UPrototypeGameInstance::RequestSave_Implementation(bool Async)
{
	UE_LOG(LogTemp, Log, TEXT("LoadSave function was called"));
	TArray<AActor*> ArrayOfActors;
	UGameplayStatics::GetAllActorsWithInterface(this,UInterface_Savable::StaticClass(),ArrayOfActors);
	//SaveGameRef->SaveAllData(ArrayOfActors);
	if (SaveGameRef)
	{
		UE_LOG(LogTemp, Log, TEXT("SaveGameRef is valid"));
		SaveGameRef->SaveAllData(ArrayOfActors);
		SaveGame(Async);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("SaveGameRef is null"));
	}
	SaveGame(Async);
	// IInterface_Persistence::RequestSave_Implementation(Async);
}
