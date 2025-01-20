// Coprright SchattenHerz


#include "Character/SchattenCharacterBase.h"

ASchattenCharacterBase::ASchattenCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


void ASchattenCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



