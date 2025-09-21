#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)           \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)               \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)               \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class SVETUN_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

	public:

	ATTRIBUTE_ACCESSORS(UAttributeSetBase, CurrentHealth);
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MaxHealth);
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, CurrentMana);
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MaxMana);

protected:

	UPROPERTY(EditAnywhere)
	FGameplayAttributeData CurrentHealth = 5.f;

	UPROPERTY(EditAnywhere)
	FGameplayAttributeData MaxHealth = 5.f;

	UPROPERTY(EditAnywhere)
	FGameplayAttributeData CurrentMana = 5.f;

	UPROPERTY(EditAnywhere)
	FGameplayAttributeData MaxMana = 5.f;
};
