// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "DrawDebugHelpers.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/GameEngine.h"

ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	BallMesh->SetupAttachment(RootComponent);

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Ball Collision"));
	CollisionSphere->SetupAttachment(RootComponent);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ABall::OnOverlapBegin);

	IsPlay = false;
	DoOnce = false;

	Score1 = 0;
	Score2 = 0;

	ResetBallState();
}


void ABall::BeginPlay()
{
	Super::BeginPlay();
}


void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsPlay == true)
	{
		// DrawDebugSphere(GetWorld(), CollisionSphere->GetComponentLocation(), 200, 20, FColor::Purple, false, -1, 0, 1);
		// UE_LOG(LogTemp, Warning, TEXT("DirX = %f, DirY = %f"), DirX, DirY);

		MoveBall(DeltaTime);

		if (DoOnce == false)
		{
			ShowScore();
			DoOnce = true;
		}
	}
}


void ABall::ResetBallState()
{
	FVector ResetLocation = { 0, 0 ,0 };
	SetActorLocation(ResetLocation);

	float random = FMath::RandRange(0, 1);

	if (random == 0) { random = -1; }

	DirX = random;
	DirY = 0;
	Direction = { DirX, DirY, 0 };
	IsPawnOverlapped = false;
}


void ABall::Play()
{
	IsPlay = true;
}


void ABall::MoveBall(float DeltaTime)
{
	FVector Location = GetActorLocation();
	FVector TargetLocation = Location + Direction * MoveSpeed * DeltaTime;

	SetActorLocation(TargetLocation);
}

void ABall::ShowScore()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, FString::Printf(TEXT("Score: %d , %d"), Score1, Score2));

	}
}


void ABall::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this && OtherActor != nullptr && OtherComp != nullptr)
	{
		// UE_LOG(LogTemp, Warning, TEXT("ACTOR COLLIDE!"));

		if (OtherActor->ActorHasTag(TEXT("PlayerPawn")) && IsPawnOverlapped == false)
		{
			DirX = -DirX;
			if (DirY == 0) { DirY = 1; }
			IsPawnOverlapped = true;
		}

		else if (OtherActor->ActorHasTag(TEXT("SideWall")))
		{
			DirY = -DirY;
			IsPawnOverlapped = false;
		}

		else if (OtherActor->ActorHasTag(TEXT("PlayerWall")))
		{
			DirX = -DirX;
			IsPawnOverlapped = false;
		}

		else if (OtherActor->ActorHasTag(TEXT("LeftObliqueWall")))
		{
			DirX = -DirX;

			if (DirY != 0) { DirY = 0; }
			else { DirY = -1; }

			IsPawnOverlapped = false;
		}

		else if (OtherActor->ActorHasTag(TEXT("RightObliqueWall")))
		{
			DirX = -DirX;

			if (DirY != 0) { DirY = 0; }
			else { DirY = 1; }

			IsPawnOverlapped = false;
		}

		else if (OtherActor->ActorHasTag(TEXT("GateWall1")))
		{
			ResetBallState();
			Score1++;
			ShowScore();
		}

		else if (OtherActor->ActorHasTag(TEXT("GateWall2")))
		{
			ResetBallState();
			Score2++;
			ShowScore();
		}

		Direction = { DirX, DirY, 0 };
	}
}