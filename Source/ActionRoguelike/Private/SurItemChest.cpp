// Fill out your copyright notice in the Description page of Project Settings.


#include "SurItemChest.h"

// Sets default values
ASurItemChest::ASurItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
    RootComponent = BaseMesh;

    LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
    LidMesh->SetupAttachment(BaseMesh);

    TargetPitch = 110;
}

// Called when the game starts or when spawned
void ASurItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASurItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASurItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
    LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}

