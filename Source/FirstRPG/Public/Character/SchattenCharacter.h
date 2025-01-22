// Coprright SchattenHerz

#pragma once

#include "CoreMinimal.h"
#include "Character/SchattenCharacterBase.h"
#include "SchattenCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTRPG_API ASchattenCharacter : public ASchattenCharacterBase
{
	GENERATED_BODY()

public:
	ASchattenCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
