//PURPOSE: 
//AUTHOR:PREETPAL_BASSON
//GAME:BATTLETANK

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    void Elevate(float RelativeSpeed);
	
private:
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxDegreesPerSecond = 5;

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxElevationDegrees = 40;

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MinElevationDegrees = 0;

};
