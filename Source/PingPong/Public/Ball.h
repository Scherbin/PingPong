// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Ball.generated.h"

UCLASS()
class PINGPONG_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABall();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void ResetBallState();

	void Play();

	void MoveBall(float DeltaTime);

	void ShowScore();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* BallMesh;

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* CollisionSphere;

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 2000.0f;

	// Launch ball variables
	bool IsPlay;
	bool DoOnce;

	// Score variables
	int Score1;
	int Score2;

	// Direction variables
	float DirX;
	float DirY;
	float DirZ;

	FVector Direction;

	// Overlap checker to be sure there are no any 'double' overlaps with Pawn paddle
	bool IsPawnOverlapped;
};
