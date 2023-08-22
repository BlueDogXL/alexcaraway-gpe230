// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "MazeCharacter.h"


APickup::APickup() 
{
	OnActorBeginOverlap.AddDynamic(this, &APickup::CheckActorType);
}
void APickup::CheckActorType(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("Overlap detected!"));
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) // is it a player? if so
	{
		Apply(Cast<AMazeCharacter>(OtherActor)); // hit them with the Effect
		DestroySelf(); // peace out
	}
}

void APickup::Apply(AMazeCharacter* PlayerChar)
{

}

void APickup::DestroySelf()
{
	this->Destroy();
}
