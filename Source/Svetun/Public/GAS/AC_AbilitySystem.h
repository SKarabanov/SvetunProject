#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AC_AbilitySystem.generated.h"

UCLASS()
class SVETUN_API UAC_AbilitySystem : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Abilities")
	TArray<TSubclassOf<UAttributeSet>> AttributeSets;
	
};
