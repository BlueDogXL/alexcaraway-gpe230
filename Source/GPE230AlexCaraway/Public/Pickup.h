// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MazeCharacter.h"
#include "GameFramework/CharacterMovementComponent.h" 
#include "TimerManager.h"
#include "Engine/EngineTypes.h" 
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class GPE230ALEXCARAWAY_API APickup : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	APickup();

	UFUNCTION()
		void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);
protected:
	UFUNCTION()
		virtual void Apply(AMazeCharacter* PlayerChar);
	UFUNCTION()
		virtual void DestroySelf();
};
