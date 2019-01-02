
#include "TankAimingComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

    // ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel *BarrelToSet)
{
    if(!BarrelToSet) {return;}
    Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret *TurretToSet)
{
    if(!TurretToSet) {return;}
    Turret = TurretToSet;
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
        DrawDebugLine(GetWorld(), StartLocation, StartLocation + AimDirection * 100000, FColor::Red, false, -1.f, 0, 20.f);
        MoveBarrel(AimDirection);
    }
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
    auto BarrelRotator = Barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - BarrelRotator;

    Barrel->Elevate(DeltaRotator.Pitch);
    Turret->Rotation(DeltaRotator.Yaw);
}

