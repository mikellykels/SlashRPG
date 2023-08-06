// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlashRPGGameMode.h"
#include "SlashRPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASlashRPGGameMode::ASlashRPGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
