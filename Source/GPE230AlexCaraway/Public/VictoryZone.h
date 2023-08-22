// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "VictoryZone.generated.h"

/**
 * 
 */
UCLASS()
class GPE230ALEXCARAWAY_API AVictoryZone : public ATriggerBox
{
	GENERATED_BODY()

		AVictoryZone();

	UFUNCTION()
		void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void WinTheGame(AMazeCharacter* PlayerChar);
};
