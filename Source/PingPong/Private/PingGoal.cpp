// Fill out your copyright notice in the Description page of Project Settings.


#include "PingGoal.h"
#include "Ball.h"
#include "Components/BoxComponent.h"
#include "PingPong/PingPongGameModeBase.h"
//include "Core/PongGameState.h"
#include "Kismet/GameplayStatics.h"

class UBoxComponent;

APingGoal::APingGoal()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxComponent->SetupAttachment(StaticMeshComponent);
	BoxComponent->SetBoxExtent(FVector(100.f, 2500.f, 100.f));
	BoxComponent->SetCollisionProfileName("Trigger");
}

void APingGoal::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &APingGoal::Score);
}

void APingGoal::Score(AActor* OverlappedActor, AActor* OtherActor)
{
	ABall* Ball = Cast<ABall>(OtherActor);
	if (Ball)
	{
		AGameStateBase* GameState = UGameplayStatics::GetGameState(this);
		if (GameState)
		{
			//APingGameState* PingGameState = Cast<APingGameState>(GameState);
			//if (PingGameState)
			//{
				//PingGameState->IncrementScore(PlayerNumber);
			//}
		}
	}
}
