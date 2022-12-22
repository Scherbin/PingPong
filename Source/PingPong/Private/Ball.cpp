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
	
	
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	Location += GetActorForwardVector() * Speed * DeltaTime;
	SetActorLocation(Location);
}

