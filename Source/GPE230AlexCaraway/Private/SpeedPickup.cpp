// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedPickup.h"
#include "TimerManager.h"
#include "Engine/EngineTypes.h"
#include "Misc/DateTime.h"

ASpeedPickup::ASpeedPickup()
{

}

void ASpeedPickup::Apply(AMazeCharacter* PlayerChar)
{
	UE_LOG(LogTemp, Log, TEXT("Applying speed pickup! Speed increased to %f!"), _speedAmount);
	// just calls the function in the maze character
	PlayerChar->IncreaseSpeed(_speedAmount, speedTime);
	
}
