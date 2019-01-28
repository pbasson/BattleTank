
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{

    PrimaryComponentTick.bCanEverTick = true;

    // ...
}

void UTankAimingComponent::BeginPlay()
{
	LastFireTime = FPlatformTime::Seconds();
}

void UTankAimingComponent::Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet)
{
	Turret = TurretToSet;
	Barrel = BarrelToSet;
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
	{ FiringStatus = EFiringStatus::Reloading; }
	else if (IsBarrelMoving()) { FiringStatus = EFiringStatus::Aiming; }
	else { FiringStatus = EFiringStatus::Locked; }
}


void UTankAimingComponent::AimAt(FVector OutHitLocation)
{
    if(!ensure(Barrel)){return;}

    FVector OutLaunchVelocity;
    FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
    bool bAimIsOn = UGameplayStatics::SuggestProjectileVelocity(
                this,
                OutLaunchVelocity,
                StartLocation,
                OutHitLocation,
                LaunchSpeed,
                false,
                0.0f,
                0.0f,
                ESuggestProjVelocityTraceOption::DoNotTrace);
    if(bAimIsOn){
        AimDirection = OutLaunchVelocity.GetSafeNormal();
        DrawDebugLine(GetWorld(), StartLocation, StartLocation + AimDirection * 100000, FColor::Red, false, -1.f, 0, 20.f);
        MoveBarrel(AimDirection);
    }
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	if (!ensure(Barrel) || !ensure(Turret)) { return; }
    auto BarrelRotator = Barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - BarrelRotator;

    Barrel->Elevate(DeltaRotator.Pitch);
	if (DeltaRotator.Yaw < 180)
	{ Turret->Rotation(FMath::Abs(DeltaRotator.Yaw)); }
	else { Turret->Rotation(-FMath::Abs(DeltaRotator.Yaw)); };
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }
	auto BarrelLoc = Barrel->GetForwardVector();
	return !BarrelLoc.Equals(AimDirection, 0.01);
}

void UTankAimingComponent::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (isReloaded)
	{
	if (!ensure(Barrel)) { return; }
	if (!ensure(ProjectileBlueprint)) { return; }
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile")));
	Projectile->LaunchProjectile(LaunchSpeed);
	LastFireTime = FPlatformTime::Seconds();
	}
}

