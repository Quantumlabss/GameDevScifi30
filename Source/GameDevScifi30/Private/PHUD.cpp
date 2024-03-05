// Fill out your copyright notice in the Description page of Project Settings.


#include "PHUD.h"
#include <Kismet/GameplayStatics.h>


void UPHUD::NativeConstruct()
{
	Super::NativeConstruct();

	Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	float UPHUD::CalculateHealthPercentage()
	{
		if (Player)
		{
			return Player->GetHealth() / Player->GetMaxHealth();
		}
		return 0.f;
	}
}



