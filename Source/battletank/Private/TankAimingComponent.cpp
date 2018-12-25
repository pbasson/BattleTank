// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    // ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet)
{
    Barrel = BarrelToSet;
}


void UTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed)
{
    if(!Barrel){return;}

    FVector OutLaunchVelocity;
    FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
    bool bAimIsOn = UGameplayStatics::SuggestProjectileVelocity(
                this, OutLaunchVelocity,StartLocation, OutHitLocation, LaunchSpeed, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace);

    if(bAimIsOn){
        auto AimDirection = OutLaunchVelocity.GetSafeNormal();
        MoveBarrel(AimDirection);
    }
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
    auto BarrelRotator = Barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - BarrelRotator;
   // UE_LOG(LogTemp, Warning, TEXT("Aim Rotator: %s "), *DeltaRotator.ToString());

}

