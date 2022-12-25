// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Player/PlayerPing.h"
#include "PingWall.h"
#include "PingGoal.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	SetRootComponent(StaticMeshComponent);

	StaticMeshComponent->SetSimulatePhysics(true);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StaticMeshComponent->SetEnableGravity(false);
	StaticMeshComponent->SetConstraintMode(EDOFMode::XYPlane);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	BoxComponent->SetupAttachment(StaticMeshComponent);
	BoxComponent->SetCollisionProfileName("Trigger");
	BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));

	bGameover = false;

}

void ABall::BeginPlay()
{
	Super::BeginPlay();
	
	SetReplicateMovement(true);

	if (BallMesh)
	{
		StaticMeshComponent->SetStaticMesh(BallMesh);
	}

	OnActorBeginOverlap.AddDynamic(this, &ABall::OnPaddleHit);
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector Location = GetActorLocation();
	//Location += GetActorForwardVector() * Speed * DeltaTime;
	//SetActorLocation(Location);
}

void  ABall::Start()
{
	bGameover = false;
	SetActorLocation(FVector::ZeroVector);
	StaticMeshComponent->
		SetPhysicsLinearVelocity(FVector(FMath::RandRange(-500.f, 500.f), (FMath::RandBool() ? 1.f : -1.f) * 9000.f,
			0.f));
}

void  ABall::Restart()
{
	SetActorLocation(FVector::ZeroVector);
	StaticMeshComponent->
		SetPhysicsLinearVelocity(FVector(FMath::RandRange(-500.f, 500.f), (FMath::RandBool() ? 1.f : -1.f) * 9000.f,
			0.f));
}

void ABall::GameOver()
{
	bGameover = true;
	StaticMeshComponent->SetPhysicsLinearVelocity(FVector::ZeroVector);
}

void ABall::OnPaddleHit(AActor* OverlappedActor, AActor* OtherActor)
{
	APlayerPing* PlayerPing = Cast<APlayerPing>(OtherActor);
	if (PlayerPing)
	{
		const FVector BallLinearVelocity = StaticMeshComponent->GetPhysicsLinearVelocity();
		const FVector NewBallLinearVelocity = FVector(BallLinearVelocity.X * -1.f, BallLinearVelocity.Y,
			BallLinearVelocity.Z);

		StaticMeshComponent->SetPhysicsLinearVelocity(NewBallLinearVelocity);
	}

	APingWall* PingWall = Cast<APingWall>(OtherActor);
	if (PingWall)
	{
		const FVector BallLinearVelocity =StaticMeshComponent->GetPhysicsLinearVelocity();
		const FVector NewBallLinearVelocity = FVector(BallLinearVelocity.X * -3.f, BallLinearVelocity.Y,
			BallLinearVelocity.Z);

		StaticMeshComponent->SetPhysicsLinearVelocity(NewBallLinearVelocity);
	}

	APingGoal* PingGoal = Cast<APingGoal>(OtherActor);
	if (PingGoal)
	{
		Restart();
	}
}