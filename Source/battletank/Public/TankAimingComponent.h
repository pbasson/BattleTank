// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel; // Forward Declarations

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UTankAimingComponent();
    void SetBarrelReference(UTankBarrel* BarrelToSet);
    void SetTurretReference(UTankTurret* TurretToSet);
    void AimAt(FVector OutHitLocation, float LaunchSpeed);

private:

    UTankBarrel* Barrel = nullptr;
    UTankTurret* Turret = nullptr;
    void MoveBarrel(FVector AimDirection);
};
