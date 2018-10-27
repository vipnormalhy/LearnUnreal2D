// Fill out your copyright notice in the Description page of Project Settings.

#include "SpriteCharactor.h"
#include "Components/SceneComponent.h"


 // Sets default values
ASpriteCharactor::ASpriteCharactor() {
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("scene component"));
	SpriteCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("character camera component"));
	SpriteCamera->SetupAttachment(RootComponent);

	SpriteCamera->SetRelativeLocation(FVector(0, 900, 350));
	SpriteCamera->SetRelativeRotation(FRotator(0, 0, -90));

	// init Sprite Flipbook Component
	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite flipbook component"));
	FlipbookComponent->SetupAttachment(RootComponent);
	FlipbookComponent->SetRelativeLocation(FVector(0, 0, 50));

	// JumpMaxCount = 1;

	// AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ASpriteCharactor::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ASpriteCharactor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	UpdateMoveAction(DeltaTime);
}

// Called to bind functionality to input
void ASpriteCharactor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveX", this, &ASpriteCharactor::MoveX);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASpriteCharactor::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ASpriteCharactor::StopJump);
}

void ASpriteCharactor::MoveX(float AxisValue) {
	if (AxisValue == 0.0f && CurrentVelocity.IsZero()) {
		return;
	}

	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 300.0f;
}

void ASpriteCharactor::StartJump() {
	bPressedJump = true;
	JumpKeyHoldTime = 1.0;
}

void ASpriteCharactor::StopJump() {
	ResetJumpState();
}

void ASpriteCharactor::UpdateMoveAction(float DeltaTime) {
	if (!CurrentVelocity.IsZero()) {
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// bool ASpriteCharactor::CanJumpInternal_Implementation() const {
// 	return true;
// }
