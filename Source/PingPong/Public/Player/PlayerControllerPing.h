// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerPing.generated.h"


UCLASS()
class PINGPONG_API APlayerControllerPing : public APlayerController
{
	GENERATED_BODY()

public:
	APlayerControllerPing();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupInputComponent() override;

private:

	void MoveLR(float Value);

	bool LeaveGateBorders(FVector Dir, float Val);

	UFUNCTION(Server, Unreliable)
	void UpdatePawnLocationOnServer(FVector Location);

private:
	UPROPERTY(EditAnywhere)
	float MoveSpeed;

	FVector PlayerLocation;
};
