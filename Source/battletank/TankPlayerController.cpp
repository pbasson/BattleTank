// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
	GetControlledTank();
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

/*	CODE_PLAN: 
	AimTowardsCrossHair()
		GetSightRayHitLocation(OutHitLocation)
			GetLookDirection(ScreenLocation, LookDirection) 
*/

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControllerTank()) { return;  }

	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation)){}
}



bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection; 
	if (GetLookDirection(ScreenLocation, LookDirection))
	{ UE_LOG(LogTemp, Warning, TEXT("Location: %s"), *LookDirection.ToString()); }
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection); 
}

void ATankPlayerController::GetControlledTank() const
{
	auto ControlledTank = GetControllerTank();

	if (!ControlledTank) { UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Found")); }
	else { UE_LOG(LogTemp, Warning, TEXT("PlayerController: %s"), *(ControlledTank->GetName())); }
}



ATank* ATankPlayerController::GetControllerTank() const
{ 
	return Cast<ATank>(GetPawn()); 
}



