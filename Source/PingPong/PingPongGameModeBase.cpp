// Copyright Epic Games, Inc. All Rights Reserved.


#include "PingPongGameModeBase.h"
#include "Player/PlayerPing.h"
#include "Player/PlayerControllerPing.h"

APingPongGameModeBase::APingPongGameModeBase()
{
	DefaultPawnClass = APlayerPing::StaticClass();
	PlayerControllerClass = APlayerControllerPing::StaticClass();
}