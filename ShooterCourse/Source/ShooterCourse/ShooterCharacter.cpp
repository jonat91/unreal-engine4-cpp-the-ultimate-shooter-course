// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"

#include "Camera/CameraComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "DrawDebugHelpers.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AShooterCharacter::AShooterCharacter() :
	// base rates for turning/looking up
	BaseTurnRate(45.f),
	BaseLookUpRate(45.f),
	// camera field of view values
	CameraDefaultFOV(0.f), // set in begin play
	CameraZoomedFOV(35.f/*60.f*/),
	CameraCurrentFOV(0.f),
	ZoomInterpSpeed(20.f),
	// true when aiming the weapon
	bAiming(false),
	// turn rate for aiming/not aiming
	HipTurnRate(90.f),
	HipLookUpRate(90.f),
	AimingTurnRate(20.f),
	AimingLookUpRate(20.f),
	// mouse look sensitivity scale factors
	MouseHipTurnRate(1.f),
	MouseHipLookUpRate(1.f),
	MouseAimingTurnRate(0.2f),
	MouseAimingLookUpRate(0.2f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 180.f; /*300.0f;*/ // the camera follows at this distance behind the character
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	CameraBoom->SocketOffset = FVector(0.f, 50.f, 70.f /*50.f*/);
	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom); // Attach the camera to the end of the boom
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// don't rotate when the controller rotates. Let the controller only affect the camera
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

    // configure character movement
    GetCharacterMovement()->bOrientRotationToMovement = false; // Character moves in the direction of input
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;
}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	// LogData();

	if (FollowCamera != nullptr)
	{
		CameraDefaultFOV = GetFollowCamera()->FieldOfView;
		CameraCurrentFOV = CameraDefaultFOV;
	}
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// handle interpolation for zoom when aiming
	CameraInterpZoom(DeltaTime);
	// Change look rates based on aiming
	SetLookRates();
	// calculate crosshair spread
	CalculateCrosshairSpread(DeltaTime);
}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent); // Check if the pointer is valid

	PlayerInputComponent->BindAxis("MoveForward", this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AShooterCharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnRate", this, &AShooterCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AShooterCharacter::LookUpRate);

	PlayerInputComponent->BindAxis("Turn", this, &AShooterCharacter::Turn /*&APawn::AddControllerYawInput*/);
	PlayerInputComponent->BindAxis("LookUp", this, &AShooterCharacter::LookUp /*&APawn::AddControllerPitchInput*/);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("FireButton", IE_Pressed, this, &AShooterCharacter::FireWeapon);

	PlayerInputComponent->BindAction("AimingButton", IE_Pressed, this, &AShooterCharacter::AimingButtonPressed);
	PlayerInputComponent->BindAction("AimingButton", IE_Released, this, &AShooterCharacter::AimingButtonReleased);
}

float AShooterCharacter::GetCrosshairSpreadMultiplier() const
{
	return CrosshairSpreadMultiplier;
}

// Log data types
void AShooterCharacter::LogData() const
{
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay() called!"));

	int myInt{ 45 };
	UE_LOG(LogTemp, Warning, TEXT("int myInt: %d"), myInt);

	float myFloat{ 3.1416f };
	UE_LOG(LogTemp, Warning, TEXT("float myFloat: %f"), myFloat);

	double myDouble{ 0.000756 };
	UE_LOG(LogTemp, Warning, TEXT("double myDouble: %lf"), myDouble);

	char myChar{ 'J' };
	UE_LOG(LogTemp, Warning, TEXT("char myChar: %c"), myChar);

	wchar_t myWChar{ L'J' };
	UE_LOG(LogTemp, Warning, TEXT("wchar_t myWChar: %lc"), myWChar);

	bool myBool{ true };
	UE_LOG(LogTemp, Warning, TEXT("bool myBool: %d"), myBool);

	UE_LOG(LogTemp, Warning, TEXT("int: %d,  float: %f, bool: %d"), myInt, myFloat, myBool);

	FString myString{ TEXT("Hello, World!") };
	UE_LOG(LogTemp, Warning, TEXT("FString myString: %s"), *myString);

	// int x = 2;
	// int* p_x = &x;  // Put the address of the x variable into the pointer p_x
	// *p_x = 4;       // Change the memory at the address in p_x to be 4
	// assert(x == 4); // Check x is now 4

	UE_LOG(LogTemp, Warning, TEXT("Name of instance: %s"), *GetName());
}

void AShooterCharacter::MoveForward(float AxisValue)
{
	if ((Controller != nullptr) && (AxisValue != 0.f))
	{
		// Find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
	}
}

void AShooterCharacter::MoveRight(float AxisValue)
{
	if ((Controller != nullptr) && (AxisValue != 0.f))
	{
		// Find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get right vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, AxisValue);
	}
}

void AShooterCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds()); //deg/sec * sec/frame
}

void AShooterCharacter::LookUpRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds()); //deg/sec * sec/frame
}

void AShooterCharacter::Turn(float Value)
{
	float turnScaleFactor{ 1.f };
	if (bAiming)
	{
		turnScaleFactor = MouseAimingTurnRate;
		
	}
	else
	{
		turnScaleFactor = MouseHipTurnRate;
	}

	AddControllerYawInput(Value * turnScaleFactor);
}

void AShooterCharacter::LookUp(float Value)
{
	float turnScaleFactor{ 1.f };
	if (bAiming)
	{
		turnScaleFactor = MouseAimingLookUpRate;
		
	}
	else
	{
		turnScaleFactor = MouseHipLookUpRate;
	}

	AddControllerPitchInput(Value * turnScaleFactor);
}

void AShooterCharacter::FireWeapon()
{
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySound2D(this, FireSound);
	}

	const USkeletalMeshSocket* BarrelSocket = GetMesh()->GetSocketByName("BarrelSocket");
	if (BarrelSocket != nullptr)
	{
		const FTransform SocketTransform = BarrelSocket->GetSocketTransform(GetMesh());
		if (MuzzleFlash != nullptr)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleFlash, SocketTransform);
		}

		bool bBlockingHit{ false };
		FVector BeamEnd{ FVector::ZeroVector };
		const bool bBeamEnd = GetBeamEndLocation(SocketTransform.GetLocation(), BeamEnd, bBlockingHit);

		if (bBeamEnd)
		{
			if (ImpactParticles != nullptr && bBlockingHit) // spawn impact particles if there was a blocking hit
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, BeamEnd);
			}

			if (BeamParticles != nullptr)
			{
				UParticleSystemComponent* Beam = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BeamParticles, SocketTransform);
				if (Beam != nullptr)
				{
					Beam->SetVectorParameter(FName("Target"), BeamEnd);
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("BarrelSocket not found!"));
	}

	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance != nullptr && HipFireMontage != nullptr)
	{
		AnimInstance->Montage_Play(HipFireMontage);
		AnimInstance->Montage_JumpToSection(FName("StartFire"));
	}

	UE_LOG(LogTemp, Warning, TEXT("Fire weapon"));
}

bool AShooterCharacter::GetBeamEndLocation(const FVector MuzzleSocketLocation, FVector& OutResult, bool& bBlockingHit) const
{
	// get current viewport size
	FVector2D ViewportSize{ FVector2D::ZeroVector };
	if (GEngine != nullptr && GEngine->GameViewport != nullptr)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}

	// get screen location of crosshair
	FVector2D CrosshairLocation{ ViewportSize.X / 2.f, ViewportSize.Y / 2.f };
	CrosshairLocation.Y -= 50.f;

	FVector CrosshairWorldPosition{ FVector::ZeroVector };
	FVector CrosshairWorldDirection{ FVector::ZeroVector };

	// get world position and direction of crosshair
	const bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(this, 0), CrosshairLocation, CrosshairWorldPosition, CrosshairWorldDirection);

	if (bScreenToWorld) // was deprojection successful?
	{
		FHitResult FireHitResult;
		const FVector Start{ CrosshairWorldPosition };
		const FVector End{ Start + CrosshairWorldDirection * 50'000.f };
		// FVector BeamEnd{ End }; //set beam end to end of line trace by default
		OutResult = End;

		GetWorld()->LineTraceSingleByChannel(FireHitResult, Start, End, ECollisionChannel::ECC_Visibility);
		if (FireHitResult.bBlockingHit) // was there a trace hit?
		{
			OutResult = FireHitResult.Location; // beam end is now the location of the hit
			bBlockingHit = true;
		}

		FHitResult WeaponTraceHitResult;
		const FVector WeaponTraceStart{ MuzzleSocketLocation };
		const FVector WeaponTraceEnd{ OutResult };

		GetWorld()->LineTraceSingleByChannel(WeaponTraceHitResult, WeaponTraceStart, WeaponTraceEnd, ECollisionChannel::ECC_Visibility);

		if (WeaponTraceHitResult.bBlockingHit) // object between barrel and beam end point
		{
			OutResult = WeaponTraceHitResult.Location;
			bBlockingHit = true;
		}

		return true;
	}

	return false;
}

void AShooterCharacter::AimingButtonPressed()
{
	bAiming = true;
	/*GetFollowCamera()->SetFieldOfView(CameraZoomedFOV);*/
}

void AShooterCharacter::AimingButtonReleased()
{
	bAiming = false;
	//GetFollowCamera()->SetFieldOfView(CameraDefaultFOV);
}

void AShooterCharacter::CameraInterpZoom(float DeltaTime)
{
	// set current camera field of view
	if (bAiming)
	{
		// interpolate to zoomed fov
		CameraCurrentFOV = FMath::FInterpTo(CameraCurrentFOV, CameraZoomedFOV, DeltaTime, ZoomInterpSpeed);
	}
	else
	{
		// interpolate to default fov
		CameraCurrentFOV = FMath::FInterpTo(CameraCurrentFOV, CameraDefaultFOV, DeltaTime, ZoomInterpSpeed);
	}

	GetFollowCamera()->SetFieldOfView(CameraCurrentFOV);
}

void AShooterCharacter::SetLookRates()
{
	if (bAiming)
	{
		BaseTurnRate = AimingTurnRate;
		BaseLookUpRate = AimingLookUpRate;
	}
	else
	{
		BaseTurnRate = HipTurnRate;
		BaseLookUpRate = HipLookUpRate;
	}
}

void AShooterCharacter::CalculateCrosshairSpread(float DeltaTime)
{
	FVector2D WalkSpeedRange{ 0.f, 600.f };
	FVector2D VelocityMultiplierRange{ 0.f, 1.f };
	// FVector2D Velocity{ GetVelocity() };
	FVector Velocity{ GetVelocity() };
	Velocity.Z = 0.f; // ignore vertical movement

	/** GetMappedRangeValueClamped example:
	 * WalkSpeedRange == 300.f
	 * VelocityMultiplierRange = 0.5f
	 */
	CrosshairVelocityFactor = FMath::GetMappedRangeValueClamped(
		WalkSpeedRange,
		VelocityMultiplierRange,
		Velocity.Size());

	CrosshairSpreadMultiplier = 0.5f + CrosshairVelocityFactor;
	
}
