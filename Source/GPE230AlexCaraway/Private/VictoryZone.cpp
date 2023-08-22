// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryZone.h"
#include "MazeCharacter.h"

AVictoryZone::AVictoryZone() 
{
	OnActorBeginOverlap.AddDynamic(this, &AVictoryZone::CheckActorType); // when something overlaps we get ourselves and the thing overlapping us
}

void AVictoryZone::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) // is it a player? if so
		{
			WinTheGame(Cast<AMazeCharacter>(OtherActor)); // they're winner
		}
}

void AVictoryZone::WinTheGame(AMazeCharacter* PlayerChar)
{
	PlayerChar->OpenVictoryScreen();
}
