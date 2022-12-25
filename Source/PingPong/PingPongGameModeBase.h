// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PingPongGameModeBase.generated.h"

UCLASS()
class PINGPONG_API APingPongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	//APingPongGameModeBase();

public:
	void StartGame() const;
	void EndGame();

protected:
	virtual void PostLogin(APlayerController* NewPlayer) override;

	int ConnectedPlayers{};
};
