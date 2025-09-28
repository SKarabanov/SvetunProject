#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "AC_Interaction.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SVETUN_API UAC_Interaction : public UActorComponent
{
	GENERATED_BODY()

public:
	UAC_Interaction();
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void AddActorToInteractionArray(AActor* Actor);
	
	UFUNCTION(BlueprintCallable)
	void RemoveActorFromInteractionArray(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void UpdateInteraction();

protected:
	void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	TArray<AActor*> InteractionActors;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AActor> CurrentInteractionActor;
};
