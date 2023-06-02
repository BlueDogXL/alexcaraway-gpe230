// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeCharacter.h"
#include "LockAndKey.h"

ALockAndKey::ALockAndKey()
{
	OnActorBeginOverlap.AddDynamic(this, &ALockAndKey::CheckActorType); // when something overlaps we get ourselves and the thing overlapping us
}

void ALockAndKey::CheckActorType(AActor* OverlappedActor, AActor* OtherActor) // and check
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) // is it a player? if so
	{
		OpenTheDoor(); // open 'er up
	}
	// we don't need to define an else, if something else overlaps us we just don't do anything about it
}

void ALockAndKey::OpenTheDoor()
{
	this->Destroy(); // gets rid of all child objects too
}
