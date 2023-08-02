// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.033f;//Using a higher interval for small performance impact
	CapsuleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CapsuleMesh"));
	CapsuleMesh->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::ReceiveMoveInput(const FVector2D& input)
{
	if (Controller == nullptr)
		return;
	AddMovementInput(FVector(GetActorForwardVector().X * input.X, GetActorRightVector().Y * input.Y, 0.f));
}

