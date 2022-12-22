// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPing.generated.h"

class UStaticMeshComponent;

UCLASS()
class PINGPONG_API APlayerPing : public APawn
{
	GENERATED_BODY()

public:
	APlayerPing();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	FVector MovementDirection;

	UPROPERTY(EditAnywhere,Category="Movement")
	float MovementSpeed = 500.0f;

	void MoveUp(float Value);
};
