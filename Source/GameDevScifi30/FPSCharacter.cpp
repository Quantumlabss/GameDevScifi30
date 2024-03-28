// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"


// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	/// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	
}
//I am currently hitting the griddy for ukraine
//alex has 0 rizz
// skibbidi toilet
// ohio rizz

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	check(GEngine != nullptr);

	FullHealth = 100.0f;
	Health = FullHealth;
	HealthPercentage = 1.0f;
	
	//bCanBeDamaged = true;


	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));
	//DefaultMaxWalkingSpeed = GetCharacterMovement()->MaxWalkSpeed;



	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Health <= 0.0f) {
		Destroy();
	}

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("StrafeRight", this, &AFPSCharacter::StrafeRight);
	PlayerInputComponent->BindAxis("StrafeLeft", this, &AFPSCharacter::StrafeLeft);
	PlayerInputComponent->BindAxis("MoveBackward", this, &AFPSCharacter::MoveBackward);
	PlayerInputComponent->BindAxis("TurnX", this, &AFPSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnY", this, &AFPSCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFPSCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFPSCharacter::StopSprint);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AFPSCharacter::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AFPSCharacter::StopCrouch);
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AFPSCharacter::Shoot);
	//PlayerInputComponent->BindAction("PeekLeft", IE_Pressed, this, &AFPSCharacter::StartPeekLeft);
	//PlayerInputComponent->BindAction("PeekLeft", IE_Released, this, &AFPSCharacter::StopPeekLeft);
	//PlayerInputComponent->BindAction("PeekRight", IE_Pressed, this, &AFPSCharacter::StartPeekRight);
	//PlayerInputComponent->BindAction("PeekRight", IE_Released, this, &AFPSCharacter::StopPeekRight);
	PlayerInputComponent->BindAction("Gerande", IE_Pressed, this, &AFPSCharacter::Gernade);
}

float AFPSCharacter::GetHealth()
{
	return 0.0f;
}

FText AFPSCharacter::GetHealthIntText()
{
	//turn FText();
	int32 HP = FMath::RoundHalfFromZero(HealthPercentage * 100);
	FString HPS = FString::FromInt(HP);
	FString HealthHUD = HPS + FString(TEXT("%"));
	FText HPText = FText::FromString(HealthHUD);
	return HPText;
}


void AFPSCharacter::UpdateHealth(float HealthChange)
{
	Health = FMath::Clamp(Health += HealthChange, 0.0f, FullHealth);
	HealthPercentage = Health / FullHealth;
}
 
void AFPSCharacter::MoveForward(float Value) 
{
	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AFPSCharacter::StrafeRight(float Value)
{
	
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AFPSCharacter::StrafeLeft(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	
	AddMovementInput(Direction, Value);

}

void AFPSCharacter::MoveBackward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);

}

void AFPSCharacter::StartJump()
{
	bPressedJump = true;
}

void AFPSCharacter::StopJump()
{
	bPressedJump = false;
}

void AFPSCharacter::StartSprint()
{
	//bPressedSprint = true;
	//GetCharacterMovement()->MaxWalkSpeed = DefaultMaxWalkingSpeed * SprintModifier + SpeedModifier;
	
	GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Sprinting"));
}

void AFPSCharacter::StopSprint()
{
	//bPressedSprint = false;
	//GetCharacterMovement()->MaxWalkSpeed = DefaultMaxWalkingSpeed + SpeedModifier;
	
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("stop sprinting"));
}

void AFPSCharacter::StartCrouch()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Crouching"));
	Crouch();
	  
}

void AFPSCharacter::StopCrouch()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Stop Crouching"));
	UnCrouch();
	
}
//void AFPSCharacter::StartPeekLeft()
//{

<<<<<<< HEAD

//}

//void AFPSCharacter::StopPeekLeft()
//{
=======
//I am currently hitting the griddy for palestine
>>>>>>> 959069f41bee68ca14a828a45878abff0f32cdd7


//}
//void AFPSCharacter::StartPeekRight()
//{

//}

//void AFPSCharacter::StopPeekRight()
//{


//}

void AFPSCharacter::Gernade()
{
	// Attempt to fire a projectile.
<<<<<<< HEAD
	if (ProjectileClass)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Shoot"));
		// Get the camera transform.
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		// Set MuzzleOffset to spawn projectiles slightly in front of the camera.
		MuzzleOffset.Set(100.0f, 0.0f, 0.0f);
=======
	//FHitResult OutHit;
//	FVector Start = GetActorLocation();
	//FVector Start = UCameraComponent.
	//Start.Z += 50.f;
	//Start.X += 200.f;
//	FRotator Rotation = GetActorRotation();
	//FVector ForwardVector = GetActorForwardVector();
//	FVector End = ((ForwardVector * 500.f) + Start);
	//FCollisionQueryParams CollisionParams;

//	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 5);
	//if (ActorLineTraceSingle(OutHit, Start, End, ECC_WorldStatic, CollisionParams))
	//{
	// GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green,
	//FString::Printf(TEXT("The Component Being Hit is: %s"), *OutHit.GetActor()->GetName()));

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,


	//}
	//if (ActorLineTraceSingle(OutHit, Start, End, ECC_WorldStatic, CollisionParams)) {
	//	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green,
>>>>>>> 959069f41bee68ca14a828a45878abff0f32cdd7

		// Transform MuzzleOffset from camera space to world space.
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

		// Skew the aim to be slightly upwards.
		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f;

<<<<<<< HEAD
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			// Spawn the projectile at the muzzle.
			AProjectile* Projectile = World->SpawnActor<AProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				// Set the projectile's initial trajectory.
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("granade spawn"));
			}
		}
=======
		//	FString::Printf(TEXT("The Component Being Hit is: %s"),
	//			*OutHit.GetComponent()->GetName()));
		//MyHit = SweepResult;
		//UGameplayStatics::ApplyPointDamage(OutHit.GetActor(), 200.0f, GetActorLocation());
	//	if (OutHit.GetActor()->ActorHasTag("player")) {

		//	Health = Health - 10.0f;
	//		HealthPercentage = HealthPercentage - 0.10f;

		//}

	//	if (OutHit.GetActor()->ActorHasTag("Barrel")) {
			//OutHit.GetActor(d);
	//	}

>>>>>>> 959069f41bee68ca14a828a45878abff0f32cdd7
	}
}




	//void AFPSCharacter::Shoot()
	//{
		// Attempt to fire a projectile.
	//	FHitResult OutHit;
	//	FVector Start = GetActorLocation();
		//FVector Start = UCameraComponent.
		//Start.Z += 50.f;
		//Start.X += 200.f;
	//	FRotator Rotation = GetActorRotation();
	//	FVector ForwardVector = GetActorForwardVector();
	//	FVector End = ((ForwardVector * 500.f) + Start);
		//FCollisionQueryParams CollisionParams;
		//FCollisionQueryParams AddIgnoredActor(OutHit.GetActor()->ActorHasTag("player"));
		//FCollisionQueryParams QueryParams;
	//	QueryParams.AddIgnoredActor(this);
	//	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 5);

	//	if (ActorLineTraceSingle(OutHit, Start, End, ECC_WorldDynamic, QueryParams)) {
	//		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green,

		//		FString::Printf(TEXT("The Component Being Hit is: %s"), *OutHit.GetActor()->GetName()));

		//	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green,

		//		FString::Printf(TEXT("The Component Being Hit is: %s"),
			//		*OutHit.GetComponent()->GetName()));
			//MyHit = SweepResult;
			//UGameplayStatics::ApplyPointDamage(OutHit.GetActor(), 200.0f, GetActorLocation());
		//	if (OutHit.GetActor()->ActorHasTag("player")) {

				//Health = Health - 10.0f;
				//HealthPercentage = HealthPercentage - 0.10f;

		//	}
		//	if (OutHit.GetActor()->ActorHasTag("enemy")) {

				//Health = Health - 10.0f;
				//HealthPercentage = HealthPercentage - 0.10f;
			//	OutHit.GetActor()->Destroy();

			//}

		//}














