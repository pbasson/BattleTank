// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

class UTankBarrel;

class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	void AimAt(FVector HitLocation);



protected:
    UPROPERTY(BlueprintReadOnly, Category = "Input")
    UTankMovementComponent* TankMovementComponent = nullptr;

private:
    ATank();
	virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float ReloadTimeInSeconds = 3.0f;

    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float LaunchSpeed = 10000;

    double LastFireTime = 0;
};
