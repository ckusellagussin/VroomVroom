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
		Chassis->SetSimulatePhysics(true);
		Chassis->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Chassis->SetVisibility(true);

		static ConstructorHelpers::FObjectFinder<UStaticMesh> WheelMesh(TEXT("StaticMesh'/Engine/Content/BasicShapes/Cylinder.Cylinder'"));
	}
	else
	{
		UE_LOG(LogMyCar, Error, TEXT("Failed to Load Cube Mesh"));
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> WheelMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	
	//Initialize Front Left Wheel
	FL_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontLeftWheel"));
	if (WheelMesh.Succeeded()) {FL_Wheel->SetStaticMesh((WheelMesh.Object));}

	FL_Wheel->SetupAttachment(Chassis);
	FL_Wheel->SetRelativeLocation(FVector(-55.5f,-40.0f, -40.0f));
	FL_Wheel->SetRelativeScale3D(FVector(0.6725f, 0.27f, 0.117f));
	FL_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));
	
	FL_Wheel->SetSimulatePhysics((true));
	FL_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	FL_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("FrontLeftConstraint"));
	FL_Constraint ->SetConstrainedComponents(Chassis, NAME_None, FL_Wheel, NAME_None);

	//Initialize Front Right Wheel
	FR_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontRightWheel"));
	if (WheelMesh.Succeeded()) {FR_Wheel->SetStaticMesh((WheelMesh.Object));}

	FR_Wheel->SetupAttachment(Chassis);
	FR_Wheel->SetRelativeLocation(FVector(55.0f,-40.0f, -40.0f));
	FR_Wheel->SetRelativeScale3D(FVector(0.6725f, 0.27f, 0.117f));
	FR_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));

	FR_Wheel->SetSimulatePhysics((true));
	FR_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	FR_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("FrontRightConstraint"));
	FR_Constraint ->SetConstrainedComponents(Chassis, NAME_None, FR_Wheel, NAME_None);

	//Initialize Back Right Wheel
	BR_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackRightWheel"));
	if (WheelMesh.Succeeded()) {BR_Wheel->SetStaticMesh((WheelMesh.Object));}

	BR_Wheel->SetupAttachment(Chassis);
	BR_Wheel->SetRelativeLocation(FVector(55.0f,40.0f, -40.0f));
	BR_Wheel->SetRelativeScale3D(FVector(0.6725f, 0.27f, 0.117f));
	BR_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));
	
	BR_Wheel->SetSimulatePhysics((true));
	BR_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	BR_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("BackRightConstraint"));
	BR_Constraint ->SetConstrainedComponents(Chassis, NAME_None, BR_Wheel, NAME_None);
	
	//Initialize Back Left Wheel
	BL_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackLeftWheel"));
	if (WheelMesh.Succeeded()) {BL_Wheel->SetStaticMesh((WheelMesh.Object));}

	BL_Wheel->SetupAttachment(Chassis);
	BL_Wheel->SetRelativeLocation(FVector(-55.0f,40.0f, -40.0f));
	BL_Wheel->SetRelativeScale3D(FVector(0.6725f, 0.27f, 0.117f));
	BL_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));

	BL_Wheel->SetSimulatePhysics((true));
	BL_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	BL_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("BackLeftConstraint"));
	BL_Constraint ->SetConstrainedComponents(Chassis, NAME_None, BL_Wheel, NAME_None);

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

