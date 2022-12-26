// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPing.h"


APlayerPing::APlayerPing()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Static Camera"));
	Camera->SetupAttachment(RootComponent);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Move Component"));

	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}


void APlayerPing::BeginPlay()
{
	Super::BeginPlay();

	CameraLocation = Camera->GetComponentLocation();
}


void APlayerPing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Attach cameta to initial location (can be unpinned or rewrite just to not do using tick function)
	if (Camera->GetComponentLocation() != CameraLocation)
	{
		Camera->SetWorldLocation(CameraLocation);
	}
}


void APlayerPing::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}



