// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPing.generated.h"

//class USceneComponent;
class USpringArmComponent;
class UStaticMeshComponent;
class UCameraComponent;

UCLASS()
class PINGPONG_API APlayerPing : public APawn
{
	GENERATED_BODY()

public:

	APlayerPing();

protected:
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	//USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveRight(float Amount);
	void TurnAround(float Amount);
};
