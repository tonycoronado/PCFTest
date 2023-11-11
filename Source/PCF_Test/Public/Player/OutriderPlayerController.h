// PCF Test

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OutriderPlayerController.generated.h"

//Had to include EnhancedInput Module into PCF_Test.cs
class UInputMappingContext; //has to be declared otherwise brings errors
class UInputAction;
struct FInputActionValue;

UCLASS()
class PCF_TEST_API AOutriderPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AOutriderPlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> OutriderContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
};
