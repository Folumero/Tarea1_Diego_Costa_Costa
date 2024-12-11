// Copyright Epic Games, Inc. All Rights Reserved.

#include "UTHUB_Tarea_HerramiGameMode.h"
#include "UTHUB_Tarea_HerramiCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUTHUB_Tarea_HerramiGameMode::AUTHUB_Tarea_HerramiGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
