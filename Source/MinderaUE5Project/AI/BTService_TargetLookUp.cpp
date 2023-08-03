// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_TargetLookUp.h"
#include "../Characters/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"

UBTService_TargetLookUp::UBTService_TargetLookUp(const FObjectInitializer& ObjectInitializer) : UBTService(ObjectInitializer)
{
	NodeName = "Target lookup";
	bNotifyBecomeRelevant = true;
}


void UBTService_TargetLookUp::OnSearchStart(FBehaviorTreeSearchData& SearchData)
{	
	if (!SearchData.OwnerComp.IsActive())
		return;

	UBlackboardComponent* BlackboardComp = SearchData.OwnerComp.GetBlackboardComponent();
	if (!IsValid(BlackboardComp))
		return;
	if (BlackboardComp->GetValueAsBool(this->DetectedKey.SelectedKeyName))
	{		
		return;
	}
	TArray<AActor*> FoundPlayers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerCharacter::StaticClass(), FoundPlayers);
	
	if (FoundPlayers.Num() > 0)
	{		
		BlackboardComp->SetValueAsObject(this->TargetPlayerKey.SelectedKeyName, FoundPlayers[0]);
	}
	
}

void UBTService_TargetLookUp::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!IsValid(BlackboardComp))
		return;
	if (BlackboardComp->GetValueAsBool(this->DetectedKey.SelectedKeyName))
	{
		AAIController* aiOwner = OwnerComp.GetAIOwner();
		if (!IsValid(aiOwner))
			return;
		aiOwner->StopMovement();
		return;
	}
}
