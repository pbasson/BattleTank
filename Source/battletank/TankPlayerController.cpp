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
	if (!GetControllerTank()) { return;  } // Checks if the Controller is assigned 

	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{
		GetControllerTank()->AimAt(OutHitLocation);
	}
}



bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY; // Values are populated from below function
	// Gets the size of the HUD canvas for player Controller : Return 0 If no HUD
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection; 
	if (GetLookDirection(ScreenLocation, LookDirection))
	{ GetLookVectorHitLocation(LookDirection, OutHitLocation); }
	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;
	// Finds the Screen Size based on position & direction in World Space 
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection); 
}

void ATankPlayerController::GetControlledTank() const
{
	auto ControlledTank = GetControllerTank();

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult; 
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange); 


	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false; 
}



ATank* ATankPlayerController::GetControllerTank() const
{ 
	return Cast<ATank>(GetPawn()); 
}



