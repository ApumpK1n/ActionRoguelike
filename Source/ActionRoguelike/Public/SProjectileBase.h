// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "SProjectileBase.generated.h"

UCLASS(ABSTRACT)
class ACTIONROGUELIKE_API ASProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASProjectileBase();

protected:
    // 球体,用于计算碰撞
    UPROPERTY(VisibleAnywhere)
    USphereComponent* SphereComp;
    // 投射体，控制球体的运动
    UPROPERTY(VisibleAnywhere)
    UProjectileMovementComponent* MovementComp;
    // 粒子系统，控制特效
    UPROPERTY(VisibleAnywhere)
    UParticleSystemComponent* EffectComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
