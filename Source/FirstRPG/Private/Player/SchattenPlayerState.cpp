// Copyright SchattenHerz


#include "Player/SchattenPlayerState.h"

#include "AbilitySystem/SchattenAbilitySystemComponent.h"
#include "AbilitySystem/SchattenAttributeSet.h"

ASchattenPlayerState::ASchattenPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USchattenAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);  //可复制的属性
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed); //玩家的复制为mixed，实时

	AttributeSet = CreateDefaultSubobject<USchattenAttributeSet>("AttributeSet");
	
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* ASchattenPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
