//PURPOSE: 
//AUTHOR:PREETPAL_BASSON
//GAME:BATTLETANK

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"


UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* LaunchBlast = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    void LaunchProjectile(float Speed);

private:
    UProjectileMovementComponent* ProjectileMovement = nullptr;
	
};
