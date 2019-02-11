// Fill out your copyright notice in the Description page of Project Settings.


#include "SpringWheel.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"


// Sets default values
ASpringWheel::ASpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
    SetRootComponent(Mass);

    Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
    Wheel->SetupAttachment(Mass);

    PhysicWheel = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("PhysicWheel"));
    PhysicWheel->SetupAttachment(Mass);

}

// Called when the game starts or when spawned
void ASpringWheel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

