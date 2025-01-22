// Coprright SchattenHerz


#include "Character/SchattenCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Player/SchattenPlayerState.h"


ASchattenCharacter::ASchattenCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false; 
}

void ASchattenCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// 服务器玩家初始能力
	InitAbilityActorInfo();
}

void ASchattenCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//客户端玩家初始能力
	InitAbilityActorInfo();
}

void ASchattenCharacter::InitAbilityActorInfo()
{
	ASchattenPlayerState* SchattenPlayerState = GetPlayerState<ASchattenPlayerState>();
	if (!SchattenPlayerState)
	{
		UE_LOG(LogTemp, Error, TEXT("ASchattenCharacter::InitAbilityActorInfo - PlayerState is null!"));
		return;
	}

	// 初始化 Ability System Component 和 Attribute Set
	SchattenPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SchattenPlayerState, this);
	AbilitySystemComponent = SchattenPlayerState->GetAbilitySystemComponent();
	AttributeSet = SchattenPlayerState->GetAttributeSet();

	UE_LOG(LogTemp, Log, TEXT("ASchattenCharacter::InitAbilityActorInfo - Ability System and Attribute Set initialized."));
}
