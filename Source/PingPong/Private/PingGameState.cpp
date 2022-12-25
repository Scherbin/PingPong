// Fill out your copyright notice in the Description page of Project Settings.


#include "PingGameState.h"
#include "PingPong/PingPongGameModeBase.h"
#include "PingPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

void APingGameState::IncrementScore(int PlayerNumber)
{
	if (PlayerNumber == 1)
	{
		PlayerOneScore++;
	}
	else if (PlayerNumber == 2)
	{
		PlayerTwoScore++;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerNumber not set on PongGoal"))
	}

	if (PlayerOneScore == ScoreToWin || PlayerTwoScore == ScoreToWin)
	{
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);
		if (GameMode)
		{
			APingPongGameModeBase* PingPongGameModeBase = Cast<APingPongGameModeBase>(GameMode);
			if (PingPongGameModeBase)
			{
				bGameover = true;
				PingPongGameModeBase->EndGame();
			}
		}
	}
}

void APingGameState::RestartGame()
{
	int PlayersReady{};

	for (APlayerState* PlayerState : PlayerArray)
	{
		if (Cast<APingPlayerState>(PlayerState)->GetPlayAgain())
		{
			PlayersReady++;
		}
	}

	if (PlayersReady == 2)
	{
		bGameover = false;
		PlayerOneScore = 0;
		PlayerTwoScore = 0;

		for (APlayerState* PlayerState : PlayerArray)
		{
			Cast<APingPlayerState>(PlayerState)->SetPlayAgain(false);
		}

		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);
		if (GameMode)
		{
			APingPongGameModeBase* PingPongGameModeBase = Cast<APingPongGameModeBase>(GameMode);
			if (PingPongGameModeBase)
			{
				PingPongGameModeBase->StartGame();
			}
		}
	}
}

void APingGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APingGameState, PlayerOneScore)
	DOREPLIFETIME(APingGameState, PlayerTwoScore)
	DOREPLIFETIME(APingGameState, bGameover)
}