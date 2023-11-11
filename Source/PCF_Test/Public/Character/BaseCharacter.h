// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Abstract) // Abstract doesnt allow to drag and drop character into the level
class PCF_TEST_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	//Using new TObjectPtr, no need for *
	TObjectPtr<USkeletalMeshComponent> Weapon; 
};
