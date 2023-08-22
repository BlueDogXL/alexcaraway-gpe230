// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "MazeCharacter.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class GPE230ALEXCARAWAY_API AHealthPickup : public APickup
{
	GENERATED_BODY()
public:
	AHealthPickup();

protected:
	UPROPERTY(EditAnywhere)
		float _healAmount;
	virtual void Apply(AMazeCharacter* PlayerChar) override;
};
