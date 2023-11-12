// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract) // Abstract doesnt allow to drag and drop character into the level

class PCF_TEST_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	//Using new TObjectPtr, no need for *
	TObjectPtr<USkeletalMeshComponent> Weapon;

		UPROPERTY()
		TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

		UPROPERTY()
		TObjectPtr<UAttributeSet> AttributeSet;
};
