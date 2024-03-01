// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"


// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(RootComponent);

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);

    InteractionComp = CreateDefaultSubobject<USurInteractionComponent>("InteractionComp");
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASCharacter::MoveForward(float value)
{
    FRotator ControlRot = GetControlRotation();
    // 转向只关注水平Yaw方向，因此置0防止影响
    ControlRot.Pitch = 0;
    ControlRot.Roll = 0;
    // 获取相机（鼠标控制器）的朝向，并朝这个方向移动
    AddMovementInput(ControlRot.Vector(), value);
}

void ASCharacter::MoveRight(float value)
{
    FRotator ControlRot = GetControlRotation();
    ControlRot.Pitch = 0;
    ControlRot.Roll = 0;
    // 获取相机（鼠标控制器）的朝向，转向右侧，并朝这个方向移动；传入的Y表示右侧
    FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
    AddMovementInput(RightVector, value);
}


void ASCharacter::PrimaryAttack() {

    // 获取模型右手位置
    FVector RightHandLoc = GetMesh()->GetSocketLocation("ik_hand_r");


    // Spawn Transform Matrix， spawn的变换矩阵
    // 朝向角色方向
    FTransform SpawnTM = FTransform(GetActorRotation(), RightHandLoc);//GetActorLocation());

    // 参数设置。
    // 此处设置碰撞检测规则为：即使碰撞也总是生成，因为粒子在角色中间生成必然碰撞
    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    // 所有能放置或生成的对象都是Actor
    GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);

    //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("The vector value is: %s"), *SpawnTM.GetLocation().ToString());
}

void ASCharacter::PrimaryInteract()
{
    InteractionComp->PrimaryInteract();
}


// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);

    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);


    PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ASCharacter::PrimaryAttack);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

    // 交互
    PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &ASCharacter::PrimaryInteract);
}

