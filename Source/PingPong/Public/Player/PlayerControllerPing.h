// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerPing.generated.h"


UCLASS()
class PINGPONG_API APlayerControllerPing : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;
};
