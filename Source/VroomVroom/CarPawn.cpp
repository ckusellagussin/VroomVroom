// Fill out your copyright notice in the Description page of Project Settings.


#include "CarPawn.h"
DEFINE_LOG_CATEGORY(LogMyCar);


// Sets default values
ACarPawn::ACarPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Chassis = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarBody"));
	RootComponent = Chassis;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BodyMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (BodyMesh.Succeeded())
	{
		UE_LOG(LogMyCar, Log, TEXT("Mesh has been loaded"));		
		Chassis->SetStaticMesh((BodyMesh.Object));
		Chassis->SetWorldScale3D(FVector(2.0f));
		Chassis->SetRelativeScale3D(FVector(2.0f,5.0f,2.0f));

		Chassis->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Chassis->SetVisibility(true);

		static ConstructorHelpers::FObjectFinder<UStaticMesh> WheelMesh(TEXT("StaticMesh'/Engine/Content/BasicShapes/Cylinder.Cylinder'"));
	}
else
	{	

	UE_LOG(LogMyCar, Error, TEXT("Failed to Load Cube Mesh"));
	
	}

}

// Called when the game starts or when spawned
void ACarPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

