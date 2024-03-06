// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDummy.h"
#include "Projectile.cpp"
#include "Projectile.h"


// Sets default values
AMyDummy::AMyDummy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	  
}

// Called when the game starts or when spawned
void AMyDummy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyDummy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//while (boxCollider)
}

// Called to bind functionality to input
void AMyDummy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

