// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class PINGPONG_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABall();

	void Start();

	void Restart();

	void GameOver();


protected:
	UFUNCTION()
	void OnPaddleHit(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UBoxComponent* BoxComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UStaticMesh* BallMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	uint8 bGameover : 1;

	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

private:
	//UPROPERTY(EditAnywhere, Category = "Movement")
	//float Speed = 500.0f;
};
