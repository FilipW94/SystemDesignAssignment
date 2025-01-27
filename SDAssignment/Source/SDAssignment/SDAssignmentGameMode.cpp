// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDAssignmentGameMode.h"
#include "SDAssignmentCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASDAssignmentGameMode::ASDAssignmentGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
