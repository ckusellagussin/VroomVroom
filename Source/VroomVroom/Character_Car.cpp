// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Car.h"

// Sets default values
ACharacter_Car::ACharacter_Car()
{
/*
	PrimaryActorTick.bCanEverTick = true;
	
	//Create the Chassis
	Chassis = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarBody"));
	RootComponent = Chassis;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BodyMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (BodyMesh.Succeeded()) {Chassis->SetStaticMesh((BodyMesh.Object));}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> WheelMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	
	//Initialize Front Left Wheel
	FL_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontLeftWheel"));
	if (WheelMesh.Succeeded()) {FL_Wheel->SetStaticMesh((WheelMesh.Object));}

	FL_Wheel->SetupAttachment(Chassis);
	FL_Wheel->SetRelativeLocation(FVector(50.0f,-50.0f, -30.0f));
	FR_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));

	//FL_Wheel->SetSimulatePhysics((true));
	//FL_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	//FL_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("FrontLeftConstraint"));
	//FL_Constraint ->SetConstrainedComponents(Chassis, NAME_None, FL_Wheel, NAME_None);

	
	//Initialize Front Right Wheel
	FR_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontRightWheel"));
	if (WheelMesh.Succeeded()) {FR_Wheel->SetStaticMesh((WheelMesh.Object));}

	FR_Wheel->SetupAttachment(Chassis);
	FR_Wheel->SetRelativeLocation(FVector(50.0f,50.0f, -30.0f));
	FR_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));

	//FR_Wheel->SetSimulatePhysics((true));
	//FR_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	//FR_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("FrontRightConstraint"));
	//FR_Constraint ->SetConstrainedComponents(Chassis, NAME_None, FR_Wheel, NAME_None);

	//Initialize Back Right Wheel
	BR_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackRightWheel"));
	if (WheelMesh.Succeeded()) {BR_Wheel->SetStaticMesh((WheelMesh.Object));}

	BR_Wheel->SetupAttachment(Chassis);
	BR_Wheel->SetRelativeLocation(FVector(-50.0f,-50.0f, -30.0f));
	BR_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));

	//BR_Wheel->SetSimulatePhysics((true));
	//BR_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	//BR_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("BackRightConstraint"));
	//BR_Constraint ->SetConstrainedComponents(Chassis, NAME_None, BR_Wheel, NAME_None);

	//Initialize Back Left Wheel
	BL_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackLeftWheel"));
	if (WheelMesh.Succeeded()) {BL_Wheel->SetStaticMesh((WheelMesh.Object));}

	BL_Wheel->SetupAttachment(Chassis);
	BL_Wheel->SetRelativeLocation(FVector(-50.0f,50.0f, -30.0f));
	BL_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));

	//BL_Wheel->SetSimulatePhysics((true));
	//BL_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	//BL_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("BackLeftConstraint"));
	//BL_Constraint ->SetConstrainedComponents(Chassis, NAME_None, BL_Wheel, NAME_None);
	
	*/

}

// Called when the game starts or when spawned
void ACharacter_Car::BeginPlay()
{
	Super::BeginPlay();
	
	/*
	//Front Left Wheel Constraint
	FL_Constraint->SetLinearPositionDrive(true,true,true);
	FL_Constraint->SetLinearDriveParams(500.0f,50.0f,0.0f);
	FL_Constraint->SetAngularSwing1Limit(ACM_Locked,0.0f);
	FL_Constraint->SetAngularSwing2Limit(ACM_Free,0.0f);
	FL_Constraint->SetAngularTwistLimit(ACM_Locked,0.0f);

	//Front Right Wheel Constraint
	FR_Constraint->SetLinearPositionDrive(true,true,true);
	FR_Constraint->SetLinearDriveParams(500.0f,50.0f,0.0f);
	FR_Constraint->SetAngularSwing1Limit(ACM_Locked,0.0f);
	FR_Constraint->SetAngularSwing2Limit(ACM_Free,0.0f);
	FR_Constraint->SetAngularTwistLimit(ACM_Locked,0.0f);

	//Back Left Wheel Constraint
	BL_Constraint->SetLinearPositionDrive(true,true,true);
	BL_Constraint->SetLinearDriveParams(500.0f,50.0f,0.0f);
	BL_Constraint->SetAngularSwing1Limit(ACM_Locked,0.0f);
	BL_Constraint->SetAngularSwing2Limit(ACM_Free,0.0f);
	BL_Constraint->SetAngularTwistLimit(ACM_Locked,0.0f);

	//Back Right Wheel Constraint
	BR_Constraint->SetLinearPositionDrive(true,true,true);
	BR_Constraint->SetLinearDriveParams(500.0f,50.0f,0.0f);
	BR_Constraint->SetAngularSwing1Limit(ACM_Locked,0.0f);
	BR_Constraint->SetAngularSwing2Limit(ACM_Free,0.0f);
	BR_Constraint->SetAngularTwistLimit(ACM_Locked,0.0f);

	Chassis->SetCenterOfMass(FVector(0.0f,0.0f,-50.0f));
	*/
}

// Called every frame
void ACharacter_Car::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float RotationSpeed = GetInputAxisValue("MoveForward") * 100.0f;
	

}

// Called to bind functionality to input
void ACharacter_Car::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{


}




