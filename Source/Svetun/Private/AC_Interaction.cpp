#include "AC_Interaction.h"

#include "InteractionInterface.h"

UAC_Interaction::UAC_Interaction()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.5f;
}

void UAC_Interaction::BeginPlay()
{
	Super::BeginPlay();
}

void UAC_Interaction::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateInteraction();
}

void UAC_Interaction::AddActorToInteractionArray(AActor* Actor)
{
	InteractionActors.RemoveSwap(nullptr);
	InteractionActors.AddUnique(Actor);
}

void UAC_Interaction::RemoveActorFromInteractionArray(AActor* Actor)
{
	InteractionActors.Remove(Actor);
	
	if (Actor == CurrentInteractionActor)
	{
		CurrentInteractionActor = nullptr;
	}
}

void UAC_Interaction::UpdateInteraction()
{
	if (IsValid(GetOwner()) && InteractionActors.Num() > 0)
	{
		//Set Base "Winner"
		float WinnerDistance = 100000.f;
		AActor* WinnerActor = nullptr;
		
		for (AActor* Actor : InteractionActors)
		{
			
			if (IsValid(Actor))
			{
				//Calculate closest actor
				const float CurrentDistance = GetOwner()->GetDistanceTo(Actor);
				if (CurrentDistance < WinnerDistance)
				{
					WinnerDistance = CurrentDistance;
					WinnerActor = Actor;
				}
			}
		}
		
		if (WinnerActor && WinnerActor != CurrentInteractionActor)
		{
			if (CurrentInteractionActor && CurrentInteractionActor->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()))
			{
				IInteractionInterface::Execute_ShowInteractionWidget(CurrentInteractionActor, false);
			}
			
			if (WinnerActor->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()))
            {
            	IInteractionInterface::Execute_ShowInteractionWidget(WinnerActor, true);
            }
			
			CurrentInteractionActor = WinnerActor;
		}
	}
}

