// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerControllerPing.h"
#include "Net/UnrealNetwork.h"


APlayerControllerPing::APlayerControllerPing()
{
	bShowMouseCursor = false;
	bEnableClickEvents = false;

	MoveSpeed = 30;
}


void APlayerControllerPing::BeginPlay()
{
	Super::BeginPlay();
}


void APlayerControllerPing::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("MoveLR"), this, &APlayerControllerPing::MoveLR);
}


void APlayerControllerPing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayerControllerPing::MoveLR(float Value)
{
	if (GetPawn())
	{
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		Value = FMath::Clamp(Value, -1.0f, 1.0f) * MoveSpeed;

		if (LeaveGateBorders(Direction, Value) == false)
		{
			GetPawn()->AddMovementInput(Direction, Value);
		}
	}

	if (GetNetMode() == NM_DedicatedServer)
	{
		return;
	}

	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		if (GetPawn())
		{
			UpdatePawnLocationOnServer(GetPawn()->GetActorLocation());
		}
	}
}


void APlayerControllerPing::UpdatePawnLocationOnServer_Implementation(FVector Location)
{
	GetPawn()->SetActorLocation(Location);
}


bool APlayerControllerPing::LeaveGateBorders(FVector Dir, float Val)
{
	PlayerLocation = GetPawn()->GetActorLocation();

	if (Dir.Y == -1)
	{
		if ((PlayerLocation.Y > 2100 && Val < 0) || (PlayerLocation.Y < -2100 && Val > 0))
		{
			return true;
		}
	}
	else if (Dir.Y == 1)
	{
		if ((PlayerLocation.Y > 2100 && Val > 0) || (PlayerLocation.Y < -2100 && Val < 0))
		{
			return true;
		}
	}

	return false;
}