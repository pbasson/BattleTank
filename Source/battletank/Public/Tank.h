// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	void AimAt(FVector HitLocation);

    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel* BarrelToSet);

    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetTurretReference(UTankTurret* TurretToSet);

    UFUNCTION(BlueprintCallable, Category = Fire)
    void Fire();

protected:
    UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr; 

    UPROPERTY(BlueprintReadOnly, Category = "Input")
    UTankMovementComponent* TankMovementComponent = nullptr;

private:
    virtual void BeginPlay() override;
    ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float ReloadTimeInSeconds = 3.0f;

    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float LaunchSpeed = 10000;
	
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint;

    UTankBarrel* Barrel = nullptr;

    double LastFireTime = 0;
};
