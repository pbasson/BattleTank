// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"





void UTankTurret::Rotation(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1,+1);
    auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RotationNew = RelativeRotation.Yaw + RotationChange;

    SetRelativeRotation(FRotator(0.0f, RotationNew, 0.0f));
}
