//PURPOSE: 
//AUTHOR:PREETPAL_BASSON
//GAME:BATTLETANK

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
        auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);

	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    auto ControlledTank = GetPawn();
 
	if (!ensure(PlayerTank && ControlledTank)) { return; }
    MoveToActor(PlayerTank, AcceptanceRadius);
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
    //if ((AimingComponent->GetFiringStatus() == EFiringStatus::Locked) || (AimingComponent->GetFiringStatus() == EFiringStatus::Aiming))
    if (AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
	{AimingComponent->Fire();}

}

void ATankAIController::OnPossedTankDeath()
{
    if(!ensure(GetPawn())){return;}
    GetPawn()->DetachFromControllerPendingDestroy();
}
