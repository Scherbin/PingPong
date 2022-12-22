// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UStaticMeshComponent;

UCLASS()
class PINGPONG_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABall();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

private:
	void MovementBall(float const DeltaTime);
};
