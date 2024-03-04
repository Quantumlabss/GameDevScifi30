// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <GameDevScifi30/FPSCharacter.h>
#include "PHUD.generated.h"


/**
 * 
 */
UCLASS()
class GAMEDEVSCIFI30_API UPHUD : public UUserWidget
{
	GENERATED_BODY()


protected:
	// Begin Play alternative
	virtual void NativeConstruct() override;

	/** Function to calculate Player HP Percentage */
	UFUNCTION(BlueprintPure)
	float CalculateHealthPercentage();

	/** The player */
	UPROPERTY(VisibleAnywhere)
	AFPSCharacter* Player;
	
};
