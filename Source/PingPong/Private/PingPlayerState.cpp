// Fill out your copyright notice in the Description page of Project Settings.


#include "PingPlayerState.h"
#include "PingGameState.h"
#include "Kismet/GameplayStatics.h"
#include "PingGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

void APingPlayerState::SetPlayAgain(bool bInPlayAgain)
{
	bPlayAgain = bInPlayAgain;

	AGameStateBase* GameState = UGameplayStatics::GetGameState(this);
	if (GameState)
	{
		APingGameState* PingGameState = Cast<APingGameState>(GameState);
		if (PingGameState)
		{
			PingGameState->RestartGame();
		}
	}
}

void APingPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APingPlayerState, bPlayAgain)
}
