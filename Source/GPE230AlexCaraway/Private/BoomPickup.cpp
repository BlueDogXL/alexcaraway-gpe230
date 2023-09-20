// Fill out your copyright notice in the Description page of Project Settings.


#include "BoomPickup.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

ABoomPickup::ABoomPickup()
{

}

void ABoomPickup::Apply(AMazeCharacter* PlayerChar) 
{
	PlayerChar->TakeDamage(_damageAmount, this);
	// play sound at 2d (that one explosion noise)
	// ActivateBoomParticleSystem();
}

/*void ABoomPickup::ActivateBoomParticleSystem()
{
	if (_boomSystem)
	{
		USceneComponent* AttachComp = GetDefaultAttachComponent();

		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(_boomSystem, AttachComp, NAME_None, FVector(0), FRotator(0), EAttachLocation::Type::KeepRelativeOffset, true);

		NiagaraComp->Activate();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("BoomPickup tried to use the boom ability, but no template particle system was found!"));
	}
}*/