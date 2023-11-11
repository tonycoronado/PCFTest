// PCF Test


#include "Player/OutriderPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AOutriderPlayerController::AOutriderPlayerController()
{
	bReplicates = true; //This is just in case we wanted to replicate the prototype
}

void AOutriderPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(OutriderContext); //Will crash if we dont set up the input mapping into the OutriderContext

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(OutriderContext, 0);
}

void AOutriderPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AOutriderPlayerController::Move);
}

void AOutriderPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
