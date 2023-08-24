// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SlashAnimInstance.h"
#include "Characters/RPGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void USlashAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	RPGCharacter = Cast<ARPGCharacter>(TryGetPawnOwner());
	if (RPGCharacter)
	{
		CharacterMovementComponent = RPGCharacter->GetCharacterMovement();
	}
}

void USlashAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (CharacterMovementComponent)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(CharacterMovementComponent->Velocity);
		bIsFalling = CharacterMovementComponent->IsFalling();
		CharacterState = RPGCharacter->GetCharacterState();
		ActionState = RPGCharacter->GetActionState();
		DeathPose = RPGCharacter->GetDeathPose();
	}
}
