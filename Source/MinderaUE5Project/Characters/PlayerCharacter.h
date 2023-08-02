// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MINDERAUE5PROJECT_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float mouseSensitivity;

protected:
	UFUNCTION(BlueprintCallable)
		void ReceiveMoveInput(const FVector2D& input);
	UFUNCTION(BlueprintCallable)
		void ReceiveLookInput(const FVector2D& input);
	
};
