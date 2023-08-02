// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTService_TargetLookUp.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MINDERAUE5PROJECT_API UBTService_TargetLookUp : public UBTService
{
	GENERATED_BODY()
public:
	UBTService_TargetLookUp(const FObjectInitializer& ObjectInitializer);

	virtual void OnSearchStart(FBehaviorTreeSearchData& SearchData);

	UPROPERTY(EditAnywhere, Category = Blackboard)
		FBlackboardKeySelector TargetPlayerKey;
	UPROPERTY(EditAnywhere, Category = Blackboard)
		FBlackboardKeySelector DetectedKey;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
