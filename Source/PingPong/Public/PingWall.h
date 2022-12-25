// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PingWall.generated.h"

class UBoxComponent;

UCLASS()
class PINGPONG_API APingWall : public AActor
{
	GENERATED_BODY()
	
public:	
	APingWall();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PongWall|Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PongWall|Components")
	UBoxComponent* BoxComponent;

};
