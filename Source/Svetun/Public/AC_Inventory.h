#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "AC_Inventory.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotChanged, int32, Slot);

class UPDA_InventoryItem;

USTRUCT(Blueprintable)
struct FInventorySlot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPDA_InventoryItem> Item = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count = 0;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SVETUN_API UAC_Inventory : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AmountOfSlots = 10;
	
	UAC_Inventory();

	virtual void BeginPlay() override;

protected:

	TArray<FInventorySlot> Inventory;

	UFUNCTION(BlueprintPure)
	TArray<FInventorySlot> GetInventory() { return Inventory; }

	UFUNCTION(BlueprintCallable)
	void TakeItem(UPDA_InventoryItem* Item);

	UFUNCTION()
	void PutItemToSlot(UPDA_InventoryItem* Item, const int32 ID);

	UFUNCTION()
	int32 FindSlotToItem(UPDA_InventoryItem* Item);

	UFUNCTION()
	bool IsSlotFree(int32 ID) const;

	UPROPERTY(BlueprintAssignable)
	FOnSlotChanged OnSlotChanged;
};
