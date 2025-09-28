#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "InteractionInterface.generated.h"

class PlayerCharacter;

UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class SVETUN_API IInteractionInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ShowInteractionWidget(bool bShouldShow);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TryToInteract(ASvetunCharacter* PlayerCharacter);
	
};
