// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

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
}

