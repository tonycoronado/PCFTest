// PCF Test


#include "Character/EnemyCharacter.h"

#include "AbilitySystem/OutriderAbilitySystemComponent.h"
#include "AbilitySystem/OutriderAttributeSet.h"

//Constructor
AEnemyCharacter::AEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UOutriderAbilitySystemComponent>("AbilitySystemComponent");
	// only if replication is needed
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UOutriderAttributeSet>("AttributeSet");
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
