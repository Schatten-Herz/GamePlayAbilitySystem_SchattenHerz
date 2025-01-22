// Copyright SchattenHerz


#include "Character/SchattenEnemy.h"

#include "AbilitySystem/SchattenAbilitySystemComponent.h"
#include "AbilitySystem/SchattenAttributeSet.h"
#include "FirstRPG/FirstRPG.h"

ASchattenEnemy::ASchattenEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<USchattenAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);  //可复制的属性
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal); //敌人的复制为minimal，对玩家只展示必要信息，不需要同步所有数据

	AttributeSet = CreateDefaultSubobject<USchattenAttributeSet>("AttributeSet");
}

void ASchattenEnemy::HighLightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void ASchattenEnemy::UnHighLightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void ASchattenEnemy::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
}
