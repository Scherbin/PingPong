// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PingPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API APingPlayerState : public APlayerState
{
	GENERATED_BODY()
	

public:
	bool GetPlayAgain() const { return bPlayAgain; }

	UFUNCTION()
	void SetPlayAgain(bool bInPlayAgain);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated)
		bool bPlayAgain{ false };
};
