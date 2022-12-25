// Fill out your copyright notice in the Description page of Project Settings.


#include "PingWall.h"
#include "Components/BoxComponent.h"

APingWall::APingWall()
{
	PrimaryActorTick.bCanEverTick = false;


	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxComponent->SetupAttachment(StaticMeshComponent);
	BoxComponent->SetBoxExtent(FVector(100.f, 2500.f, 100.f));
	BoxComponent->SetCollisionProfileName("PhysicsActor");
}

void APingWall::BeginPlay()
{
	Super::BeginPlay();
	
}


