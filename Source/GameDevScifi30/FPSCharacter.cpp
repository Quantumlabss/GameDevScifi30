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
// skibbidi toilet
// ohio rizz

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	check(GEngine != nullptr);

	FullHealth = 1000.0f;
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




void AFPSCharacter::Shoot()
{
	// Attempt to fire a projectile.
	FHitResult OutHit;
	FVector Start = GetActorLocation();
	//FVector Start = UCameraComponent.
	//Start.Z += 50.f;
	//Start.X += 200.f;
	FRotator Rotation = GetActorRotation();
	FVector ForwardVector = GetActorForwardVector();
	FVector End = ((ForwardVector * 500.f) + Start);
	FCollisionQueryParams CollisionParams;

	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 5);
	//if (ActorLineTraceSingle(OutHit, Start, End, ECC_WorldStatic, CollisionParams))
	//{
	// GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green,
	//FString::Printf(TEXT("The Component Being Hit is: %s"), *OutHit.GetActor()->GetName()));

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,


	//}
	if (ActorLineTraceSingle(OutHit, Start, End, ECC_WorldStatic, CollisionParams)) {
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green,

			FString::Printf(TEXT("The Component Being Hit is: %s"), *OutHit.GetActor()->GetName()));

		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green,

			FString::Printf(TEXT("The Component Being Hit is: %s"),
				*OutHit.GetComponent()->GetName()));
		//MyHit = SweepResult;
		//UGameplayStatics::ApplyPointDamage(OutHit.GetActor(), 200.0f, GetActorLocation());
		Health = Health - 10;
	}








}





