// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"



void APlayerCharacter::ReceiveMoveInput(const FVector2D& input)
{
	if (Controller == nullptr)
		return;
	AddMovementInput(FVector(input.X, input.Y, 0.f).RotateAngleAxis(GetControlRotation().Yaw, FVector(0, 0, 1)));
}

void APlayerCharacter::ReceiveLookInput(const FVector2D& input)
{
	if (Controller == nullptr)
		return;
	AddControllerYawInput(input.X * mouseSensitivity);
	AddControllerPitchInput(-input.Y * mouseSensitivity);
}