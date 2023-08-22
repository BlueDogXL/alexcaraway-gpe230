// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "SpeedPickup.generated.h"

/**
 * 
 */
UCLASS()
class GPE230ALEXCARAWAY_API ASpeedPickup : public APickup
{
	GENERATED_BODY()
public:
	ASpeedPickup();
	UPROPERTY(EditAnywhere, Category = "Speed")
		float speedTime;
protected:
	UPROPERTY(EditAnywhere, Category = "Speed")
		float _speedAmount;;
	virtual void Apply(AMazeCharacter* PlayerChar) override;
};
