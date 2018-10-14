// Fill out your copyright notice in the Description page of Project Settings.

#include "SpriteCharactor.h"
#include "Components/SceneComponent.h"


// Sets default values
ASpriteCharactor::ASpriteCharactor() : SpriteCamera(NULL) {
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("scene component"));
	SpriteCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("character camera component"));
	SpriteCamera->SetupAttachment(RootComponent);

	SpriteCamera->SetRelativeLocation(FVector(-200, 0, 110));
	SpriteCamera->SetRelativeRotation(FRotator(-40, 0, 0));
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

