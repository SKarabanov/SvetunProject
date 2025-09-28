#include "InteractableActor.h"

#include "AC_Interaction.h"
#include "SvetunCharacter.h"
#include "Components/SphereComponent.h"

AInteractableActor::AInteractableActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	RootComponent = SphereComponent;

	SphereComponent->InitSphereRadius(300.f);
	SphereComponent->SetGenerateOverlapEvents(true);
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));


}

void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AInteractableActor::OnOverlapBegin);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AInteractableActor::OnOverlapEnd);
	
}

void AInteractableActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ASvetunCharacter* OverlappedCharacter = Cast<ASvetunCharacter>(OtherActor))
	{
		OverlappedCharacter->GetInteractionComponent()->AddActorToInteractionArray(this);
	}
}

void AInteractableActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ASvetunCharacter* OverlappedCharacter = Cast<ASvetunCharacter>(OtherActor))
	{
		OverlappedCharacter->GetInteractionComponent()->RemoveActorFromInteractionArray(this);
		IInteractionInterface::Execute_ShowInteractionWidget(this, false);
	}
}

void AInteractableActor::TryToInteract_Implementation(ASvetunCharacter* PlayerCharacter)
{
	
}

void AInteractableActor::ShowInteractionWidget_Implementation(bool bShouldShow)
{

}

void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

