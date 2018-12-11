// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Found"));
	}
	else { /*UE_LOG(LogTemp, Warning, TEXT("PlayerController: %s"), *(PlayerTank->GetName()));*/ }
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControllerTank()->AimAt(GetPlayerTank()->GetActorLocation());
		
	}

}

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn){ return nullptr; }
	
	
	return Cast<ATank>(PlayerPawn);
}
