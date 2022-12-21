// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerPing.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/PrimitiveComponent.h"

APlayerPing::APlayerPing()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMeshComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(StaticMeshComponent);

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

}

void APlayerPing::MoveUp()
{

}



