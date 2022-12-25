// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PingGoal.generated.h"

class UBoxComponent;

UCLASS()
class PINGPONG_API APingGoal : public AActor
{
	GENERATED_BODY()
	
public:	
	APingGoal();


	UFUNCTION()
	void Score(AActor* OverlappedActor, AActor* OtherActor);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PongGoal|Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PongGoal|Components")
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PongGoal|Config")
	int PlayerNumber{};

};
