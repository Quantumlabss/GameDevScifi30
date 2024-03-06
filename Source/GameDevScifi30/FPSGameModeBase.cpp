// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameModeBase.h"
#include "FPHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include <Subsystems/PanelExtensionSubsystem.h>





	//:Super()


void AFPSGameModeBase::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);
	//#
	//static ConstructorHelpers::FClassFinder<UUserWidget> HealthBar(TEXT("C:/Users/alex.evans/source/repos/GameDevScifi30/Content/Scripts/HUD"));
//	HUDWidgetClass = HealthBar.Class;

	// use our custom HUD class
//	HUDClass = UFPHUD::StaticClass();

	// add Health Bar UI to viewport
//	if (HUDWidgetClass != nullptr)
//	{
//		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);

//		if (CurrentWidget)
//		{
//			CurrentWidget->AddToViewport();
//		}
//	}
#//
	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));


}