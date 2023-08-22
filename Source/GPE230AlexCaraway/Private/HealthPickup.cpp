// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickup.h"

AHealthPickup::AHealthPickup()
{

}

void AHealthPickup::Apply(AMazeCharacter* PlayerChar)
{
	UE_LOG(LogTemp, Log, TEXT("Applying health pickup! Healed %f!"), _healAmount);
	PlayerChar->Heal(_healAmount);
}
