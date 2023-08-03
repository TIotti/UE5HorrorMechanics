// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/PawnSensingComponent.h"
#include "PlayerPawnSensing.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = AI, HideCategories = (Activation, "Components|Activation", Collision), meta = (BlueprintSpawnableComponent))
class MINDERAUE5PROJECT_API UPlayerPawnSensing : public UPawnSensingComponent
{
	GENERATED_BODY()

public:
	virtual FRotator GetSensorRotation() const override;
	
};
