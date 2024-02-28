// Fill out your copyright notice in the Description page of Project Settings.


#include "SurExplosiveBarrel.h"
#include "SurMagicProjectile.h"

// Sets default values
ASurExplosiveBarrel::ASurExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
    // UE中的“模拟物理”选项
    MeshComp->SetSimulatePhysics(true);
    // 等同于在UE中将“碰撞预设”设置为“PhysicsActor”
    MeshComp->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
    RootComponent = MeshComp;

    ForceComp = CreateDefaultSubobject<URadialForceComponent>("ForceComp");
    ForceComp->SetupAttachment(MeshComp);

    ForceComp->Radius = 750.0f;			 // 爆炸范围
    ForceComp->ImpulseStrength = 700.0f; // 冲击力
    ForceComp->bImpulseVelChange = true; // 忽略质量大小；见UE中ForceComp的“冲量速度变更”

    BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    BoxComp->SetupAttachment(MeshComp);
}

// Called when the game starts or when spawned
void ASurExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();

    BoxComp->OnComponentHit.AddDynamic(this, &ASurExplosiveBarrel::HitFunction);
}

// Called every frame
void ASurExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASurExplosiveBarrel::OnActorHit()
{
    
}

void ASurExplosiveBarrel::HitFunction(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor && OtherActor->IsA(ASurMagicProjectile::StaticClass()))
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("HitFunction ！！")));
        ForceComp->FireImpulse();

        ASurMagicProjectile* projectile = Cast<ASurMagicProjectile>(OtherActor);
        projectile->Destroy();
    }
}

