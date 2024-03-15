// Fill out your copyright notice in the Description page of Project Settings.


#include "SurMagicProjectile.h"
#include "SCharacter.h"
#include "SAttributeComponent.h"

// Sets default values
ASurMagicProjectile::ASurMagicProjectile()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
    SphereComp->OnComponentHit.AddDynamic(this, &ASurMagicProjectile::OnActorHit);
    RootComponent = SphereComp;

    MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
    MovementComp->InitialSpeed = 1000.0f;
    MovementComp->bRotationFollowsVelocity = true;
    MovementComp->bInitialVelocityInLocalSpace = true;

    EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
    EffectComp->SetupAttachment(SphereComp);
}

// Called when the game starts or when spawned
void ASurMagicProjectile::BeginPlay()
{
    Super::BeginPlay();

}

void ASurMagicProjectile::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if(OtherActor && !OtherActor->IsA<ASCharacter>())
    {
        USAttributeComponent* AttributeComponent = Cast<USAttributeComponent>(OtherActor->GetComponentByClass(USAttributeComponent::StaticClass()));
        if (AttributeComponent)
        {
            AttributeComponent->ApplyHealthChange(-10);
           // Destroy();
        }
    }
}


// Called every frame
void ASurMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

