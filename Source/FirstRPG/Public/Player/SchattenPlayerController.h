// Coprright SchattenHerz

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SchattenPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class FIRSTRPG_API ASchattenPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ASchattenPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> SchattenContext;

	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& FInputActionValue);
	
};
