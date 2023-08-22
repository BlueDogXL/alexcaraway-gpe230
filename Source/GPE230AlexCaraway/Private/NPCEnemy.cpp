// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCEnemy.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"

// Sets default values
ANPCEnemy::ANPCEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPCEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANPCEnemy::DetectHit()
{
	bool canDamage = true;
	// find our fist location
	const FVector PunchLocation = GetMesh()->GetSocketLocation(_PunchingHandSocketName);
	// don't punch ourselves
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	ActorsToIgnore.Add(GetOwner());
	// array for the nerds who got punched
	TArray<FHitResult> HitArray;
	// sphere trace and find the nerds we punched (if any)
	const bool Hit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), PunchLocation, PunchLocation, _TraceRadius, UEngineTypes::ConvertToTraceType(ECC_Camera), false, ActorsToIgnore, EDrawDebugTrace::None, HitArray, true, FLinearColor::Red, FLinearColor::Green, 2.0f);
	// get our name engraved in the Hall Of Punching Nerds Good
	FString ownerName = this->GetName();
	// if we did actually punch any nerds
	if (Hit) 
	{
		for (const FHitResult HitResult: HitArray) 
		{
			if (canDamage) 
			{
				// get this nerd's name engraved in the Hall Of Getting Punched As A Nerd 
				FString hitActorName = HitResult.GetActor()->GetName();
				// broadcast to the log that a nerd got punched
				UE_LOG(LogTemp, Log, TEXT("NPCEnemy actor \"%s\" punched nerd \"%s\", dealing %f damage!"), *ownerName, *hitActorName, _HitDamage);
				// apply damage to this nerd
				UGameplayStatics::ApplyDamage(HitResult.GetActor(), _HitDamage, GetController(), this, UDamageType::StaticClass());
				canDamage = false;
			}
		}
	}
	else 
	{
		UE_LOG(LogTemp, Log, TEXT("NPCEnemy actor \"%s\" didn't punch any valid nerds!"), *ownerName);
	}
}

// Called every frame
void ANPCEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPCEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

