#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

class USphereComponent;

UCLASS()
class SVETUN_API AInteractableActor : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

public:
	AInteractableActor();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure)
	FORCEINLINE class USphereComponent* GetSphereComponent() const { return SphereComponent; }

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	                    bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void TryToInteract_Implementation(ASvetunCharacter* PlayerCharacter) override;
	virtual void ShowInteractionWidget_Implementation(bool bShouldShow) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ability, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USphereComponent> SphereComponent;
};
