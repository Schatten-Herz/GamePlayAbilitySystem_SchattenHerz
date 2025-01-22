// Copyright SchattenHerz

#pragma once

#include "CoreMinimal.h"
//#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerController.h"
#include "SchattenPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class FIRSTRPG_API ASchattenPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ASchattenPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> SchattenContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
	
};


