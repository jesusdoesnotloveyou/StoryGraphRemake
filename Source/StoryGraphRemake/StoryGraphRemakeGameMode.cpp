// Copyright Epic Games, Inc. All Rights Reserved.

#include "StoryGraphRemakeGameMode.h"
#include "StoryGraphRemakeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStoryGraphRemakeGameMode::AStoryGraphRemakeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
