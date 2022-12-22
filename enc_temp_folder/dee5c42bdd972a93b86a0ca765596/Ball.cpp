// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Kismet/KismetMathLibrary.h"

ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMeshComponent);
}

void ABall::BeginPlay()
{
	Super::BeginPlay();
	
	//StaticMeshComponent->SetPhysicsLinearVelocity()
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovementBall( DeltaTime);
}

void ABall::MovementBall(float const DeltaTime)
{
	//FTransform LocationBall = GetActorTransform();
	//FTransform LocationPoint = FTransform(FRotator::ZeroRotator, TargetLocation);

	FVector BallLocation = GetActorLocation();

	float Velocity = 1000.0f;
	FVector TargetBAll = UKismetMathLibrary::Normal(GetActorForwardVector() - GetActorLocation());
	FVector Current = DeltaTime * Velocity * TargetBAll + GetActorLocation();
	
	SetActorLocation(Current);
}