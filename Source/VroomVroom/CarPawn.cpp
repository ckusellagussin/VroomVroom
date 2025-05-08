// Fill out your copyright notice in the Description page of Project Settings.


#include "CarPawn.h"

#include "Kismet/GameplayStatics.h"
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
		Chassis->SetCollisionProfileName(TEXT("Vehicle"));
		Chassis->SetSimulatePhysics(true);
		Chassis->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Chassis->SetVisibility(true);
		Chassis->SetCenterOfMass(FVector(0,0, -50));

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
	FL_Wheel->SetRelativeLocation(FVector(-60.0f,-40.0f, -40.0f));
	FL_Wheel->SetRelativeScale3D(FVector(0.6725f, 0.27f, 0.117f));
	FL_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));
	
	FL_Wheel->SetSimulatePhysics((true));
	FL_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	FL_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("FrontLeftConstraint"));
	FL_Constraint->SetupAttachment(Chassis);
	FL_Constraint->SetRelativeLocation(FVector(-45.0f,-40.0f,-40.0f));
	FL_Constraint->SetConstrainedComponents(Chassis, NAME_None, FL_Wheel, NAME_None);
	

	FL_Constraint->SetLinearPositionDrive(true, true, true);
	FL_Constraint->SetLinearDriveParams(500.0f, 50.0f,0.0f);
	FL_Constraint->SetAngularSwing1Limit(ACM_Locked,0.0f);
	FL_Constraint->SetAngularSwing2Limit(ACM_Free,0.0f);
	FL_Constraint->SetAngularTwistLimit(ACM_Locked,0.0f);

	//Initialize Front Right Wheel
	FR_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrontRightWheel"));
	if (WheelMesh.Succeeded()) {FR_Wheel->SetStaticMesh((WheelMesh.Object));}

	FR_Wheel->SetupAttachment(Chassis);
	FR_Wheel->SetRelativeLocation(FVector(60.0f,-40.0f, -40.0f));
	FR_Wheel->SetRelativeScale3D(FVector(0.6725f, 0.27f, 0.117f));
	FR_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));

	FR_Wheel->SetSimulatePhysics((true));
	FR_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	FR_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("FrontRightConstraint"));
	FR_Constraint->SetupAttachment(Chassis);
	FR_Constraint->SetRelativeLocation(FVector(50.0f,-40.0f, -40.0f));
	FR_Constraint->SetConstrainedComponents(Chassis, NAME_None, FR_Wheel, NAME_None);

	FR_Constraint->SetLinearPositionDrive(true, true, true);
	FR_Constraint->SetLinearDriveParams(500.0f, 50.0f,0.0f);
	FR_Constraint->SetAngularSwing1Limit(ACM_Locked,0.0f);
	FR_Constraint->SetAngularSwing2Limit(ACM_Free,0.0f);
	FR_Constraint->SetAngularTwistLimit(ACM_Locked,0.0f);

	//Initialize Back Right Wheel
	BR_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackRightWheel"));
	if (WheelMesh.Succeeded()) {BR_Wheel->SetStaticMesh((WheelMesh.Object));}

	BR_Wheel->SetupAttachment(Chassis);
	BR_Wheel->SetRelativeLocation(FVector(60.0f,40.0f, -40.0f));
	BR_Wheel->SetRelativeScale3D(FVector(0.6725f, 0.27f, 0.117f));
	BR_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));
	
	BR_Wheel->SetSimulatePhysics((true));
	BR_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	BR_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("BackRightConstraint"));
	BR_Constraint->SetupAttachment(Chassis);
	BR_Constraint->SetRelativeLocation(FVector(50.0f,40.0f,-40.0f));
	BR_Constraint ->SetConstrainedComponents(Chassis, NAME_None, BR_Wheel, NAME_None);

	BR_Constraint->SetLinearPositionDrive(true, true, true);
	BR_Constraint->SetLinearDriveParams(500.0f, 50.0f,0.0f);
	BR_Constraint->SetAngularSwing1Limit(ACM_Locked,0.0f);
	BR_Constraint->SetAngularSwing2Limit(ACM_Free,0.0f);
	BR_Constraint->SetAngularTwistLimit(ACM_Locked,0.0f);
	
	//Initialize Back Left Wheel
	BL_Wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BackLeftWheel"));
	if (WheelMesh.Succeeded()) {BL_Wheel->SetStaticMesh((WheelMesh.Object));}

	BL_Wheel->SetupAttachment(Chassis);
	BL_Wheel->SetRelativeLocation(FVector(-60.0f,40.0f, -40.0f));
	BL_Wheel->SetRelativeScale3D(FVector(0.6725f, 0.27f, 0.117f));
	BL_Wheel->SetRelativeRotation(FRotator(90.0f,0.0f,0.0f));

	BL_Wheel->SetSimulatePhysics((true));
	BL_Wheel->SetCollisionEnabled((ECollisionEnabled::QueryAndPhysics));

	BL_Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("BackLeftConstraint"));
	BL_Constraint->SetupAttachment(Chassis);
	BL_Constraint->SetRelativeLocation(FVector(-50.0f,40.0f,-40.0f));
	BL_Constraint ->SetConstrainedComponents(Chassis, NAME_None, BL_Wheel, NAME_None);


	BL_Constraint->SetLinearPositionDrive(true, true, true);
	BL_Constraint->SetLinearDriveParams(500.0f, 50.0f,0.0f);
	BL_Constraint->SetAngularSwing1Limit(ACM_Locked,0.0f);
	BL_Constraint->SetAngularSwing2Limit(ACM_Free,0.0f);
	BL_Constraint->SetAngularTwistLimit(ACM_Locked,0.0f);

}

// Called when the game starts or when spawned
void ACarPawn::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{

		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
	
			Subsystem->AddMappingContext(VehicleMappingContext, 0 );
			
		}
		
	}
	
}

// Called every frame
void ACarPawn::Tick(float DeltaTime)
{

	float RotationSpeed = GetInputAxisValue("MoveForward") * 100.0f;
	FL_Wheel->AddLocalRotation(FRotator(RotationSpeed* DeltaTime, 0.0f, 0.0f));
	FR_Wheel->AddLocalRotation(FRotator(RotationSpeed* DeltaTime, 0.0f, 0.0f));
	BL_Wheel->AddLocalRotation(FRotator(RotationSpeed* DeltaTime, 0.0f, 0.0f));
	BR_Wheel->AddLocalRotation(FRotator(RotationSpeed* DeltaTime, 0.0f, 0.0f));
}

// Called to bind functionality to input
void ACarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(!MoveForwardAction)
	{

		UE_LOG(LogTemp, Error, TEXT("MoveForwardAction not assigned"));
		
	}
	
	
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	EnhancedInputComponent->BindAction(MoveForwardAction,ETriggerEvent::Triggered,this,&ACarPawn::MoveForward);
		

}

void ACarPawn::MoveForward(const FInputActionValue& Value)
{

	float InputValue = Value.Get<float>();
	FVector Force = Chassis->GetForwardVector() * InputValue * 100000.0f;
	BL_Wheel->AddForce(Force);
	BR_Wheel->AddForce(Force);
	FR_Wheel->AddForce(Force);
	BR_Wheel->AddForce(Force);
	
}

