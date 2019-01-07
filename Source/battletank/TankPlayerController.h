// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected: 
    UFUNCTION(BlueprintCallable, Category = "Setup")
    ATank* GetControllerTank() const;
	
    
    
private:
    virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	void GetControlledTank() const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const; 
	
    UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0f;

    UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5; 

    UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333;
};
