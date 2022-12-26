// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"
#include "PlayerPing.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class PINGPONG_API APlayerPing : public APawn
{
	GENERATED_BODY()

public:
	APlayerPing();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly)
	UFloatingPawnMovement* FloatingPawnMovement;

	FVector CameraLocation;
};
