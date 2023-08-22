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
	int latestLevelCompleted;
	float masterVolumeSliderSetting;
	float musicVolumeSliderSetting;
	float sfxVolumeSliderSetting;
};
