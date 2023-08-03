// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/PlayerPawnSensing.h"


FRotator UPlayerPawnSensing::GetSensorRotation() const
{
	AActor* SensorActor = GetOwner();
	AController* Controller = Cast<AController>(SensorActor);
	if (IsValid(Controller))
	{
		return Controller->GetControlRotation();
	}

	return FRotator::ZeroRotator;
}