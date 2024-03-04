// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Canvas.h" 
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class GAMEDEVSCIFI30_API APlayerHUD : public AHUD
{
	GENERATED_BODY()


public:

	virtual void DrawHUD() override;


protected:




	
};
