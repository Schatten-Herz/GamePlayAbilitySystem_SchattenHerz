// Coprright SchattenHerz


#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Player/SchattenPlayerController.h"

#include "Interaction/EnemyInterface.h"

ASchattenPlayerController::ASchattenPlayerController()
{
	bReplicates = true;
}

void ASchattenPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}


void ASchattenPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility,false,CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	//判断高亮
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			//前为空后有效，高亮后
			ThisActor->HighLightActor();
		}
		else
		{
			//前后空，无
		}
	}
	else
	{
		if (ThisActor == nullptr)
		{
			//前有效后空，取消高亮
			LastActor->UnHighLightActor();
		}else{
			//都有效
			if (LastActor != ThisActor)
			{
				//前后不一样
				LastActor->UnHighLightActor();
				ThisActor->HighLightActor();
			}
			else
			{
				//前后一致，不变
			}
		}
	}
}


void ASchattenPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(SchattenContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(SchattenContext,0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ASchattenPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ASchattenPlayerController::Move);
}

void ASchattenPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f,Rotation.Yaw,0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection,InputAxisVector.X);
	}
}
