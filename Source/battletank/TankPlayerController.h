//PURPOSE: 
//AUTHOR:PREETPAL_BASSON
//GAME:BATTLETANK

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent; 
class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected: 
   // UFUNCTION(BlueprintCallable, Category = "Setup")

	
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimComp);

    UFUNCTION()
    void OnPossedTankDeath();
    
private:
    virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const; 
	
    UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0f;

    UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5; 

    UPROPERTY(EditDefaultsOnly)
    float CrossHairYLocation = 0.33333;

    void SetPawn(APawn *InPawn);
    };
