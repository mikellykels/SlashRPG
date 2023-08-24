// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterTypes.h"
#include "SlashAnimInstance.generated.h"

class ARPGCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class SLASHRPG_API USlashAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	ARPGCharacter* RPGCharacter;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	UCharacterMovementComponent* CharacterMovementComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsFalling;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	ECharacterState CharacterState;
		
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	EActionState ActionState;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	TEnumAsByte<EDeathPose> DeathPose;
};
