// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Projectile.h"

#include "FPSCharacter.generated.h"

UCLASS()
class GAMEDEVSCIFI30_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AProjectile> ProjectileClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	/** The speed at which the character will be walking */




	

protected:



	UFUNCTION()
	void MoveForward(float Value);


	UFUNCTION()
	void StrafeRight(float Value);

	UFUNCTION()
	void StrafeLeft(float Value);

	UFUNCTION()
	void MoveBackward(float Value);


	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();


	UFUNCTION()
	void StartSprint();

	UFUNCTION()
	void StopSprint();

	UFUNCTION()
	void StartCrouch();

	UFUNCTION()
	void StopCrouch();

	UFUNCTION()
	void Shoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;



};
