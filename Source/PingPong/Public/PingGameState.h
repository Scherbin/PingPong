// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PingGameState.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API APingGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void RestartGame();

	UFUNCTION(BlueprintCallable)
	void IncrementScore(int PlayerNumber);

	int GetPlayerOneScore() const { return PlayerOneScore; }
	int GetPlayerTwoScore() const { return PlayerTwoScore; }

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "PongGameState|Config")
	int PlayerOneScore{};

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "PongGameState|Config")
	int PlayerTwoScore{};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PongGameState|Config")
	int ScoreToWin{ 3 };

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "PongGameState|Config")
	bool bGameover{ false };
};
