#include "GAS/AC_AbilitySystem.h"

void UAC_AbilitySystem::BeginPlay()
{
	Super::BeginPlay();

	for (auto AttributeSetClass : AttributeSets)
	{
		if (IsValid(AttributeSetClass))
		{
			if (UAttributeSet* AttributeSet = NewObject<UAttributeSet>(this, AttributeSetClass); IsValid(AttributeSet))
			{
				AddAttributeSetSubobject(AttributeSet);
			}
		}
	}
}
