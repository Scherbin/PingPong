// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPing.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class PINGPONG_API APlayerPing : public APawn
{
	GENERATED_BODY()

public:
	APlayerPing();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PingPlayer|Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PingPlayer|Components")
	UBoxComponent* BoxComponent;

	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UStaticMeshComponent* GetStaticMeshComponent() const { return StaticMeshComponent; }

private:
	FVector MovementDirection;

	UPROPERTY(EditAnywhere,Category="Movement")
	float MovementSpeed = 500.0f;

	void MoveUp(float Value);
};
