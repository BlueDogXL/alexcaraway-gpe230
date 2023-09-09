// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float AMazeCharacter::GetCurrentHealth()
{
	return _currentHealth;
}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();
	_currentHealth = maxHealth;
	_controller = Cast<APlayerController>(GetController());
	_gameOverScreenInstance = CreateWidget(GetWorld(), _gameOverScreenTemplate);
	_victoryScreenInstance = CreateWidget(GetWorld(), _victoryScreenTemplate);
	_hudScreenInstance = CreateWidget(GetWorld(), _hudScreenTemplate);
	_pauseScreenInstance = CreateWidget(GetWorld(), _pauseScreenTemplate);
	OpenHUDScreen();
}

float AMazeCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{ 
	if (!_isDead) {
		_currentHealth -= DamageAmount;

		UE_LOG(LogTemp, Log, TEXT("Player took %f damage! %f health remaining!"), DamageAmount, _currentHealth);

		if (_currentHealth <= 0)
		{
			Die();
		}

		return DamageAmount;
	}
	else 
	{
		return 0;
	}
}

void AMazeCharacter::IncreaseSpeed(float boostedSpeed, float speedTime)
{
	_speedPowerupTimer = speedTime;
	_isSpedUp = true;
	CharacterMovement->MaxWalkSpeed = boostedSpeed;
}

void AMazeCharacter::DecreaseSpeed(float normalSpeed)
{
	CharacterMovement->MaxWalkSpeed = normalSpeed;
}

void AMazeCharacter::DoSpeedTimer(float deltaTime)
{
	_speedPowerupTimer = _speedPowerupTimer - deltaTime;
	UE_LOG(LogTemp, Log, TEXT("Time left: %f"), _speedPowerupTimer);
	if (_speedPowerupTimer <= 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Time's up!"));
		_isSpedUp = false;
	}
	if (_isSpedUp == false)
	{
		UE_LOG(LogTemp, Log, TEXT("Removing powerup!"));
		DecreaseSpeed(_normalSpeed);
	}
}

void AMazeCharacter::Heal(float healingAmount)
{
	_currentHealth += healingAmount;
	UE_LOG(LogTemp, Log, TEXT("Player healed %f damage! %f health remaining!"), healingAmount, _currentHealth);
}

void AMazeCharacter::OpenVictoryScreen()
{
	_victoryScreenInstance->AddToViewport();
	// UGameplayStatics::PlaySound2D(GetWorld(), _victorySound);
	PauseGameplay(true);
	ShowMouseCursor();
}

void AMazeCharacter::Die()
{
	_isDead = true;
	_currentHealth = 0;
	// you got got
	moveSpeed = 0;
	rotateSpeed = 0;
	GetMesh()->PlayAnimation(_deathAnim, false);
	OpenGameOverScreen();
}

void AMazeCharacter::OpenGameOverScreen()
{
	_gameOverScreenInstance->AddToViewport();
	ShowMouseCursor();
}

void AMazeCharacter::PauseGameplay(bool isPaused)
{
	_controller->SetPause(isPaused);
}

void AMazeCharacter::ShowMouseCursor()
{
	_controller->bShowMouseCursor = true;
}

void AMazeCharacter::OpenPauseScreen()
{
	_pauseScreenInstance->AddToViewport();
	PauseGameplay(true);
	_gameIsPaused = true;
}

void AMazeCharacter::ClosePauseScreen()
{
	_pauseScreenInstance->RemoveFromViewport();
	PauseGameplay(false);
	_gameIsPaused = false;
}

void AMazeCharacter::OpenHUDScreen()
{
	_hudScreenInstance->AddToViewport();
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (_isSpedUp == true) {
		DoSpeedTimer(DeltaTime);
	}
}

// Called to bind functionality to input
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, & AMazeCharacter::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AMazeCharacter::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AMazeCharacter::Rotate);
}

void AMazeCharacter::MoveFB(float value)
{
	AddMovementInput(GetActorForwardVector(), value * moveSpeed);
}

void AMazeCharacter::MoveLR(float value)
{
	AddMovementInput(-GetActorRightVector(), value * moveSpeed);
}

void AMazeCharacter::Rotate(float value)
{
	AddControllerYawInput(value * rotateSpeed);
}

void AMazeCharacter::ActivateStunParticleSystem()
{
	if (_stunSystem) 
	{
		USceneComponent* AttachComp = GetDefaultAttachComponent();

		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(_stunSystem, AttachComp, NAME_None, FVector(0), FRotator(0), EAttachLocation::Type::KeepRelativeOffset, true);

		NiagaraComp->Activate();
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("Player tried to use the stun ability, but no template particle system was found!"));
	}
}

