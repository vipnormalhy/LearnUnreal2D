// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Learn2DGameMode.h"
#include "Learn2DCharacter.h"

ALearn2DGameMode::ALearn2DGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ALearn2DCharacter::StaticClass();	
}
