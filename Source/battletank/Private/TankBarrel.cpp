// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"





void UTankBarrel::Elevate(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	UE_LOG(LogTemp, Warning, TEXT("Raw Text: %f"), ElevationChange);
	SetRelativeRotation(FRotator(Elevation, 0.0f, 0.0f));
	
}
