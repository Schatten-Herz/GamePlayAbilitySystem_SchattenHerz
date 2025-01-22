// Copyright SchattenHerz


#include "Actor/SchattenEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/SchattenAttributeSet.h"


ASchattenEffectActor::ASchattenEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere"); //碰撞检测
	Sphere->SetupAttachment(GetRootComponent());
}

void ASchattenEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormSweep, const FHitResult& SweepResult)
{
	//TODO: 暂时使用const_cast,需要改变
	if(IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const USchattenAttributeSet* SchattenAttributeSet = Cast<USchattenAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(USchattenAttributeSet::StaticClass()));
		
		USchattenAttributeSet* MutableSchattenAttributeSet = const_cast<USchattenAttributeSet*>(SchattenAttributeSet);
		MutableSchattenAttributeSet->SetHealth(SchattenAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void ASchattenEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void ASchattenEffectActor::BeginPlay()
{
	Super::BeginPlay();

	//绑定到动态委托
	Sphere->OnComponentBeginOverlap.AddDynamic(this,&ASchattenEffectActor::OnOverlap); //进入 Sphere 的范围时触发
	Sphere->OnComponentEndOverlap.AddDynamic(this,&ASchattenEffectActor::EndOverlap);//离开Sphere 的范围时触发
}


