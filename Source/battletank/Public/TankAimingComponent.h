// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UTankAimingComponent();
    void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
    void AimAt(FVector OutHitLocation, float LaunchSpeed);

private:

    UStaticMeshComponent* Barrel = nullptr;
    void MoveBarrel(FVector AimDirection);
};
