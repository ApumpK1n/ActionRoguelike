// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "SCharacter.generated.h"


UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
    // 投射体子类
    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> ProjectileClass;

    UPROPERTY(VisibleAnywhere)
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    void MoveForward(float value);

    void MoveRight(float value);

    void PrimaryAttack();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // 测试直接push
};
