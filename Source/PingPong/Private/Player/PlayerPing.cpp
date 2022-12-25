// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPing.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/BoxComponent.h"

APlayerPing::APlayerPing()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMeshComponent);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxComponent->SetupAttachment(RootComponent);
	BoxComponent->SetCollisionProfileName("PhysicsActor");
	BoxComponent->SetBoxExtent(FVector(175.f, 50.f, 50.f));
}


void APlayerPing::BeginPlay()
{
	Super::BeginPlay();
	

}

void APlayerPing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MovementDirection.IsZero())
	{
		const FVector NewLocation = GetActorLocation() + (MovementDirection * DeltaTime * MovementSpeed);
		SetActorLocation(NewLocation);
	}

}

void APlayerPing::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveUp", this, &APlayerPing::MoveUp);
}

void APlayerPing::MoveUp(float Value)
{
	//if (Value != 0.f)
	//{
		//AddMovementInput(FVector(1, 0, 0), Value, true);
	//}

	MovementDirection.Y = FMath::Clamp(Value, -1.0f, 1.0f);
}



