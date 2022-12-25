// Copyright Epic Games, Inc. All Rights Reserved.


#include "PingPongGameModeBase.h"
#include "Player/PlayerPing.h"
#include "Player/PlayerControllerPing.h"
#include "Ball.h"
#include "PingGameState.h"
#include "Kismet/GameplayStatics.h"

void APingPongGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	// possess a pawn
	TArray<AActor*> PawnArray;
	UGameplayStatics::GetAllActorsOfClass(this, APlayerPing::StaticClass(), PawnArray);
	if (PawnArray.Num() > 0)
	{
		for (AActor* Actor : PawnArray)
		{
			APlayerPing* PlayerPing = Cast<APlayerPing>(Actor);
			if (PlayerPing && !PlayerPing->IsPawnControlled())
			{
				NewPlayer->Possess(PlayerPing);
				PlayerPing->SetOwner(NewPlayer);
			}
		}
	}

	if (GetNumPlayers() == 2)
	{
		StartGame();
	}
}

void APingPongGameModeBase::StartGame() const
{
	TArray<AActor*> BallArray;
	UGameplayStatics::GetAllActorsOfClass(this, ABall::StaticClass(), BallArray);

	if (BallArray.Num() > 0 && IsValid(BallArray[0]))
	{
		Cast<ABall>(BallArray[0])->Start();
	}
}

void APingPongGameModeBase::EndGame()
{
	TArray<AActor*> BallArray;
	UGameplayStatics::GetAllActorsOfClass(this, ABall::StaticClass(), BallArray);

	if (BallArray.Num() > 0 && IsValid(BallArray[0]))
	{
		Cast<ABall>(BallArray[0])->GameOver();
	}
}