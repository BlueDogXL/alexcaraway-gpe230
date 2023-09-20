// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "BoomPickup.generated.h"

/**
 * 
 */
UCLASS()
class GPE230ALEXCARAWAY_API ABoomPickup : public APickup
{
	GENERATED_BODY()
public:
	ABoomPickup();
protected:
	UPROPERTY(EditAnywhere)
		float _damageAmount;
	virtual void Apply(AMazeCharacter* PlayerChar) override;
private:
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* _boomSystem;
	void ActivateBoomParticleSystem();
};
