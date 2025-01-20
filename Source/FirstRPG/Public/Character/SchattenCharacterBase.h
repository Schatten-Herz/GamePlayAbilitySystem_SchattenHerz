// Coprright SchattenHerz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SchattenCharacterBase.generated.h"

UCLASS(Abstract)
class FIRSTRPG_API ASchattenCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ASchattenCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
