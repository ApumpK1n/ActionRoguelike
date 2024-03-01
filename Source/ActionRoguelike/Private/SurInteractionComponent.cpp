// Fill out your copyright notice in the Description page of Project Settings.


#include "SurInteractionComponent.h"
#include "SurGameplayInterface.h"

// Sets default values for this component's properties
USurInteractionComponent::USurInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USurInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USurInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USurInteractionComponent::PrimaryInteract()
{

    FHitResult Hit; // 检测结果


    FVector EyeLocation; // 角色眼睛位置
    FRotator EyeRotation; // 角色视线方向
    AActor* owner = GetOwner(); // 获取控制角色
    // 将玩家视线的位置和方向输出到EyeLocation和EyeRotation
    owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
    // 沿着视线方向，模型的眼睛位置开始1000距离的点为终点
    FVector End = EyeLocation + (EyeRotation.Vector() * 1000);

    FCollisionObjectQueryParams ObjectQueryParams; // 查询参数
    ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic); // 选择查询场景动态对象

    GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, ObjectQueryParams);

    AActor* HitActor = Hit.GetActor();
    if (HitActor) {
        if (HitActor->Implements<USurGameplayInterface>()) {
            APawn* pawn = Cast<APawn>(owner);
            ISurGameplayInterface::Execute_Interact(HitActor, pawn);
            // 用于debug，绘制这条碰撞检测的线，绿色
            DrawDebugLine(GetWorld(), EyeLocation, End, FColor::Green, false, 3);
        }
    }
    else { DrawDebugLine(GetWorld(), EyeLocation, End, FColor::Red, false, 3); }

}

