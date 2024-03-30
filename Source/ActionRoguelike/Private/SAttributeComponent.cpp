// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/ProgressBar.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{
    Health = 100;
}

// Called when the game starts
void USAttributeComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
}


bool USAttributeComponent::ApplyHealthChange(float delta, UWidgetComponent* HealthWidget)
{
    Health += delta;
    UUserWidget* UUserWidget = HealthWidget->GetUserWidgetObject();
    
    UProgressBar* ProgressBar = Cast<UProgressBar>(UUserWidget->GetWidgetFromName("Health"));
    float health = Health / 100.0;
    ProgressBar->SetPercent(health);
    return true;
}

