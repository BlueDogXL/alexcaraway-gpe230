// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Sound/SoundWave.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Blueprint/UserWidget.h"
#include "MazeCharacter.generated.h"

UCLASS()
class GPE230ALEXCARAWAY_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()

public: 
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float maxHealth;
	UCharacterMovementComponent* CharacterMovement = GetCharacterMovement();

protected:
	UPROPERTY(EditAnywhere)
		float _currentHealth;
	UPROPERTY(EditAnywhere)
		bool _isSpedUp;
	float _normalSpeed = 600.0f;
	float _speedPowerupTimer;

private:
	UPROPERTY(EditAnywhere)
		float moveSpeed;
	UPROPERTY(EditAnywhere)
		float rotateSpeed;
	UPROPERTY(EditAnywhere)
		UAnimSequence* _deathAnim;
	UPROPERTY(EditAnywhere)
		bool _isDead = false;
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* _stunSystem;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _gameOverScreenTemplate;
	UUserWidget* _gameOverScreenInstance;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _victoryScreenTemplate;
	UUserWidget* _victoryScreenInstance;
	APlayerController* _controller;
	UPROPERTY(EditAnywhere)
		USoundWave* _victorySound;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _hudScreenTemplate;
	UUserWidget* _hudScreenInstance;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _pauseScreenTemplate;
	UUserWidget* _pauseScreenInstance;
	UPROPERTY(EditAnywhere)
		bool _gameIsPaused;
public:
	// Sets default values for this character's properties
	AMazeCharacter();
	UFUNCTION(BlueprintCallable)
	float GetCurrentHealth();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
	virtual void DecreaseSpeed(float normalSpeed);
	virtual void DoSpeedTimer(float deltaTime);
	virtual void Die();

	virtual void OpenGameOverScreen();
	virtual void PauseGameplay(bool isPaused);
	virtual void ShowMouseCursor();
	UFUNCTION(BlueprintCallable)
	virtual void OpenPauseScreen();
	UFUNCTION(BlueprintCallable)
	virtual void ClosePauseScreen();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void IncreaseSpeed(float boostedSpeed, float speedTime);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Heal(float healingAmount);
	virtual void OpenVictoryScreen();
	virtual void OpenHUDScreen();

private:
	void MoveFB(float value);
	void MoveLR(float value);
	void Rotate(float value);
	UFUNCTION(BlueprintCallable)
	void ActivateStunParticleSystem();
};
