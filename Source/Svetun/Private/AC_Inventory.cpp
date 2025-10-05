#include "AC_Inventory.h"

UAC_Inventory::UAC_Inventory()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_Inventory::BeginPlay()
{
	Super::BeginPlay();

	Inventory.SetNum(AmountOfSlots);
}

void UAC_Inventory::TakeItem(UPDA_InventoryItem* Item)
{
	PutItemToSlot(Item, FindSlotToItem(Item));
}

void UAC_Inventory::PutItemToSlot(UPDA_InventoryItem* Item, const int32 ID)
{
	Inventory[ID].Item = Item;
	Inventory[ID].Count += 1;
	OnSlotChanged.Broadcast(ID);
}

int32 UAC_Inventory::FindSlotToItem(UPDA_InventoryItem* Item)
{
	int32 FreeIndex = -1;
	
	for (int i = 0; i < Inventory.Num(); ++i)
	{
		if (Inventory[i].Item == Item)
		{
			return i;
		}
		
		if (FreeIndex == -1 && IsSlotFree(i))
		{
			FreeIndex = i;
		}
	}

	return FreeIndex;

	
}

bool UAC_Inventory::IsSlotFree(const int32 ID) const
{
	if (Inventory.IsValidIndex(ID)) return !Inventory[ID].Item;

	return false;
}
