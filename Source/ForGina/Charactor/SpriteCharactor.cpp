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

	SpriteCamera->SetRelativeLocation(FVector(-200, 450, 0));
	SpriteCamera->SetRelativeRotation(FRotator(0, 15, -90));

	// init Sprite Component
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite component"));
	SpriteComponent->SetupAttachment(RootComponent);

	// init Sprite Flipbook Component
	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite flipbook component"));
	FlipbookComponent->SetupAttachment(RootComponent);
	FlipbookComponent->SetRelativeLocation(FVector(0, 0, 50));
}

// Called when the game starts or when spawned
void ASpriteCharactor::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ASpriteCharactor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpriteCharactor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

