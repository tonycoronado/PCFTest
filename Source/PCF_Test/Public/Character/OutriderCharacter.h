// PCF Test

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "OutriderCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PCF_TEST_API AOutriderCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	AOutriderCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	//Function to avoid repeating code in the cpp file
	void InitAbilityActorInfo();
};
