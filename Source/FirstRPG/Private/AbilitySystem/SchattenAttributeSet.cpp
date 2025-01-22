// Copyright SchattenHerz


#include "AbilitySystem/SchattenAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"


USchattenAttributeSet::USchattenAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(50.f);
}

void USchattenAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Health
	DOREPLIFETIME_CONDITION_NOTIFY(USchattenAttributeSet,Health,COND_None,REPNOTIFY_Always); //客服端无条件注册复制服务端的health
	DOREPLIFETIME_CONDITION_NOTIFY(USchattenAttributeSet,MaxHealth,COND_None,REPNOTIFY_Always);

	//Mana
	DOREPLIFETIME_CONDITION_NOTIFY(USchattenAttributeSet,Mana,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USchattenAttributeSet,MaxMana,COND_None,REPNOTIFY_Always);
}

void USchattenAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USchattenAttributeSet , Health , OldHealth); //通知 Health 属性的值发生变化。触发GAS health 事件，追踪old health以便回滚
}

void USchattenAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USchattenAttributeSet , MaxHealth , OldMaxHealth);
}

void USchattenAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USchattenAttributeSet , Mana , OldMana);
}

void USchattenAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USchattenAttributeSet , MaxMana , OldMaxMana);
}
