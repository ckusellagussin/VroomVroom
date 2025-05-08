// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "CarPawn.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMyCar, Log, All);

UCLASS()
class VROOMVROOM_API ACarPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACarPawn();

	//Chassis Setup
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Car Components")
	UStaticMeshComponent* Chassis;

	//Front Left Wheel Setup
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Car Components")
	UStaticMeshComponent* FL_Wheel;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPhysicsConstraintComponent* FL_Constraint;

	//Front Right Wheel Setup
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Car Components")
	UStaticMeshComponent* FR_Wheel;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPhysicsConstraintComponent* FR_Constraint;

	//Back Left Wheel Setup
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Car Components")
	UStaticMeshComponent* BL_Wheel;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPhysicsConstraintComponent* BL_Constraint;
	
	//Back Right Wheel Setup
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "Car Components")
	UStaticMeshComponent* BR_Wheel;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UPhysicsConstraintComponent* BR_Constraint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputMappingContext* VehicleMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* MoveForwardAction;

	UFUNCTION()
	void MoveForward(const FInputActionValue& Value);
  
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
