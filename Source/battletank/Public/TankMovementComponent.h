//PURPOSE: 
//AUTHOR:PREETPAL_BASSON
//GAME:BATTLETANK

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

    UFUNCTION(BlueprintCallable, Category = "Setup")
    void IntendMoveForward(float Throw);

    UFUNCTION(BlueprintCallable, Category = "Setup")
    void IntendTurnRight(float Throw);

    virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
    UTankTrack* LeftTrack = nullptr;
    UTankTrack* RightTrack = nullptr;

};
