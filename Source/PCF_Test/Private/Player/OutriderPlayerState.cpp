// PCF Test


#include "Player/OutriderPlayerState.h"

#include "AbilitySystem/OutriderAbilitySystemComponent.h"
#include "AbilitySystem/OutriderAttributeSet.h"

AOutriderPlayerState::AOutriderPlayerState()
{

	AbilitySystemComponent = CreateDefaultSubobject<UOutriderAbilitySystemComponent>("AbilitySystemComponent");
	//Only if replication is needed
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UOutriderAttributeSet>("AttributeSet");
	
	// a higher update frequency is needed since GAS component and attributes will be set on here -only replication
	NetUpdateFrequency = 100.0f;

	
}

UAbilitySystemComponent* AOutriderPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
