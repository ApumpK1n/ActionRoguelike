// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeComponent.h"
#include "Components/WidgetComponent.h"

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


bool USAttributeComponent::ApplyHealthChange(float delta)
{
    Health += delta;
    return true;
}

