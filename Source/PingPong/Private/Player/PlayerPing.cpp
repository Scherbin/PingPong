// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPing.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

APlayerPing::APlayerPing()
{
	PrimaryActorTick.bCanEverTick = true;

	//SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	//SceneComponent->SetupAttachment(GetRootComponent());

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMeshComponent->SetupAttachment(GetRootComponent());

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void APlayerPing::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerPing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerPing::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPing::MoveRight);
	PlayerInputComponent->BindAxis("TurnAround", this, &APlayerPing::TurnAround);
}

void APlayerPing::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}

void APlayerPing::TurnAround(float Amount)
{
	AddControllerYawInput(Amount);
}