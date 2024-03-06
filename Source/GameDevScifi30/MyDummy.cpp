// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDummy.h"


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

// Function that is called when the projectile hits something.
void AMyDummy::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT(AActor()->GetName()));
		//OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
	}
	//Destroy();
}

