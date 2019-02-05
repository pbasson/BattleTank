//PURPOSE: 
//AUTHOR:PREETPAL_BASSON
//GAME:BATTLETANK

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:

	UPROPERTY(EditAnywhere, Category = "Setup")
    float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
