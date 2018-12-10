// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetControllerTank();
    if (!ControlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Found"));
    }
    else {UE_LOG(LogTemp, Warning, TEXT("PlayerController: %s"), *(ControlledTank->GetName()));}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControllerTank()) { return;  }
}

ATank* ATankPlayerController::GetControllerTank() const
{
    return Cast<ATank>(GetPawn());
}



