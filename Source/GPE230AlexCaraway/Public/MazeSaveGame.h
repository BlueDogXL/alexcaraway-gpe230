// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MazeSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class GPE230ALEXCARAWAY_API UMazeSaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int latestLevelCompleted;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float masterVolumeSliderSetting;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float musicVolumeSliderSetting;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float sfxVolumeSliderSetting;
};
