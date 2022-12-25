// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerControllerPing.h"

#include "Camera/CameraActor.h"
#include "Player/PlayerPing.h"
#include "Kismet/GameplayStatics.h"

void APlayerControllerPing::SetupInputComponent()
{
	Super::SetupInputComponent();

	
}

void APlayerControllerPing::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// setup camera
	TArray<AActor*> CameraArray;
	UGameplayStatics::GetAllActorsOfClass(this, ACameraActor::StaticClass(), CameraArray);
	if (CameraArray.Num() > 0)
	{
		SetViewTargetWithBlend(CameraArray[0]);
	}
}