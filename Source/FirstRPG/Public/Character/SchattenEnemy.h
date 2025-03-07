// Coprright SchattenHerz

#pragma once

#include "CoreMinimal.h"
#include "Character/SchattenCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "SchattenEnemy.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTRPG_API ASchattenEnemy : public ASchattenCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()
public:
	ASchattenEnemy();

	/** enemy 接口*/
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
	/** enemy 接口*/

protected:
	virtual void BeginPlay() override;

};
