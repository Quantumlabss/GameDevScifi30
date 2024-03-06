// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMEDEVSCIFI30_API AFPSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;

public:
	UFUNCTION(BlueprintPure, Category = "Health")
//GamePlayState GetCurrentState() const;

	/** Sets a new playing state */
//oid SetCurrentState(EGamePlayState NewState);

	UPROPERTY(EditAnywhere, Category = "Health")
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Health")
	class UUserWidget* CurrentWidget;
};
