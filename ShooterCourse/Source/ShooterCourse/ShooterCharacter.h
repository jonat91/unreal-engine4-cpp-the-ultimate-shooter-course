// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SHOOTERCOURSE_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void LogData() const;

	/** Called for forwards/backwards input */
	void MoveForward(float AxisValue);

	/** Called for side to side input */
	void MoveRight(float AxisValue);

	/**
	 * Called via input to turn at a given rate
	 * @param Rate This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to look up/down at a given rate
	 * @param Rate This is a normalized rate, i.e. 1.0 means 100% of desired look up/down rate
	 */
	void LookUpRate(float Rate);

	/**
	 * Rotate controller based on mouse X movement
	 * @param Value the input value from mouse movement
	 */
	void Turn(float Value);

	/**
	 * Rotate controller based on mouse Y movement
	 * @param Value the input value from mouse movement
	 */
	void LookUp(float Value);

	/** Called when the fire button is pressed */
	void FireWeapon();

	bool GetBeamEndLocation(const FVector MuzzleSocketLocation, FVector& OutResult, bool& bBlockingHit) const;

	/** set bAiming to true or false with button press */
	void AimingButtonPressed();
	void AimingButtonReleased();

	void CameraInterpZoom(float DeltaTime);

	/** set base turn rate and base look rate bases on aiming*/
	void SetLookRates();

	void CalculateCrosshairSpread(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* CameraBoom;

	/** Camera that follows the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* FollowCamera;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	float BaseTurnRate;

	/** turn rate while not aiming */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	float HipTurnRate;

	/** look up/down rate while not aiming */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	float HipLookUpRate;

	/** turn rate while aiming */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	float AimingTurnRate;

	/** look up/down rate while aiming */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	float AimingLookUpRate;

	/** scale factor for mouse look sensitivity, turn rate when not aiming */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Camera, meta=(AllowPrivateAccess="true"), meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float MouseHipTurnRate;

	/** scale factor for mouse look sensitivity, look up when not aiming */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Camera, meta=(AllowPrivateAccess="true"), meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float MouseHipLookUpRate;

	/** scale factor for mouse look sensitivity, turn rate when aiming */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Camera, meta=(AllowPrivateAccess="true"), meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float MouseAimingTurnRate;

	/** scale factor for mouse look sensitivity, look up when aiming */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Camera, meta=(AllowPrivateAccess="true"), meta=(ClampMin="0.0", ClampMax="1.0", UIMin="0.0", UIMax="1.0"))
	float MouseAimingLookUpRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	float BaseLookUpRate;

	/** Randomized gunshot sound cue */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Combat, meta=(AllowPrivateAccess="true"))
	class USoundCue* FireSound;

	/** Flash spawned at barrel socket */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Combat, meta=(AllowPrivateAccess="true"))
	class UParticleSystem* MuzzleFlash;

	/** montage for firing the weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Combat, meta=(AllowPrivateAccess="true"))
	class UAnimMontage* HipFireMontage;

	/** particles spawned upon bullet impact */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Combat, meta=(AllowPrivateAccess="true"))
	UParticleSystem* ImpactParticles;

	/** smoke trail for bullets */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Combat, meta=(AllowPrivateAccess="true"))
	UParticleSystem* BeamParticles;

	/** true when aiming */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Combat, meta=(AllowPrivateAccess="true"))
	bool bAiming;

	/** default camera field of view value */
	float CameraDefaultFOV;

	/** field of view value for when zoomed in */
	float CameraZoomedFOV;

	/** Current field of view this frame*/
	float CameraCurrentFOV;

	/** Interp speed for zooming when aiming */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Combat, meta=(AllowPrivateAccess="true"))
	float ZoomInterpSpeed;

	/** VDetermines the spread of the crosshairs */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Crosshairs, meta=(AllowPrivateAccess="true"))
	float CrosshairSpreadMultiplier;

	/** Velocity component for crosshairs spread */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Crosshairs, meta=(AllowPrivateAccess="true"))
	float CrosshairVelocityFactor;

	/** In air component for crosshairs spread */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Crosshairs, meta=(AllowPrivateAccess="true"))
	float CrosshairInAirFactor;

	/** Aim component for crosshairs spread */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Crosshairs, meta=(AllowPrivateAccess="true"))
	float CrosshairAimFactor;

	/** Shooting component for crosshairs spread */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Crosshairs, meta=(AllowPrivateAccess="true"))
	float CrosshairShootingFactor;

public:
	/** Returns CameraBoom Subobject */
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera Subobject */
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	FORCEINLINE bool GetAiming() const { return bAiming; }

	UFUNCTION(BlueprintCallable)
	float GetCrosshairSpreadMultiplier() const;
};
