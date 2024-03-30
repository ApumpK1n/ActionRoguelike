// Fill out your copyright notice in the Description page of Project Settings.


#include "SEnemy.h"

// Sets default values
ASEnemy::ASEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    AttributeComponent = CreateDefaultSubobject<USAttributeComponent>("AttributeComponent");

    HealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthWidgetComponent"));
    HealthWidgetComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ASEnemy::BeginPlay()
{
	Super::BeginPlay();

    auto HealthBlueprintClass = LoadClass<UUserWidget>(NULL, TEXT("WidgetBlueprint'/Game/ActionRoguelike/UI/Health_Widget.Health_Widget_C'"));

    HealthWidgetComponent->SetWidgetClass(HealthBlueprintClass);
    HealthWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
    HealthWidgetComponent->SetPivot(FVector2D(1, 0.5));
    HealthWidgetComponent->SetDrawSize(FVector2D(120.0f, 10.0f));
    HealthWidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 95.0f));
}

// Called every frame
void ASEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

