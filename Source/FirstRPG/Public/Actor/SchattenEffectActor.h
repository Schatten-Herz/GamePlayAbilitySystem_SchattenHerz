// Copyright SchattenHerz

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "SchattenEffectActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class FIRSTRPG_API ASchattenEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASchattenEffectActor();

	/**
	 *重叠开始事件。其他对象进入组件（USphereComponent）范围时调用
	 *OverlappedComponent：触发重叠的组件（当前组件
	 *OtherActor：进入触发范围的 Actor
	 *OtherComp：进入触发范围的 Actor 中参与重叠检测的具体组件
	 *OtherBodyIndex：与重叠相关的物理体索引
	 *bFromSweep：是否是通过扫掠检测触发的重叠
	 *SweepResult：如果是扫掠检测触发的，包含详细的命中信息
	 */
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent , AActor* OtherActor ,
		UPrimitiveComponent* OtherComp , int32 OtherBodyIndex , bool bFormSweep , const FHitResult& SweepResult);

	/**
	 *离开
	 */
	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

};
