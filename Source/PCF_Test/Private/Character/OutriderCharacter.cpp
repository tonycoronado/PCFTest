// PCF Test


#include "Character/OutriderCharacter.h"

#include "AbilitySystemComponent.h"
#include "Player/OutriderPlayerState.h"

AOutriderCharacter::AOutriderCharacter()
{
	//Constructor
}

void AOutriderCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Only for the server 
	InitAbilityActorInfo();
}

void AOutriderCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Only for the Client 
	InitAbilityActorInfo();
}

void AOutriderCharacter::InitAbilityActorInfo()
{
	// This function is for the server only, not needed for the test
	AOutriderPlayerState* OutriderPlayerState = GetPlayerState<AOutriderPlayerState>();
	check(OutriderPlayerState);
	OutriderPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(OutriderPlayerState, this);
	AbilitySystemComponent = OutriderPlayerState->GetAbilitySystemComponent();
	AttributeSet = OutriderPlayerState->GetAttributeSet();
}
