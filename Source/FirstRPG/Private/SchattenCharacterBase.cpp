// Coprright SchattenHerz


#include "SchattenCharacterBase.h"

// Sets default values
ASchattenCharacterBase::ASchattenCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASchattenCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASchattenCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASchattenCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

