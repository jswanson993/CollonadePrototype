// Fill out your copyright notice in the Description page of Project Settings.


#include "CollonadeCharacter.h"
#include "AbilitySystemComponent.h"
// Sets default values
ACollonadeCharacter::ACollonadeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));

}

UAbilitySystemComponent* ACollonadeCharacter::GetAbilitySystemComponent() const {
	return AbilitySystem;
}

// Called when the game starts or when spawned
void ACollonadeCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (AbilitySystem) {
		FGameplayAbilityActorInfo* actorInfo = new FGameplayAbilityActorInfo();
		actorInfo->InitFromActor(this, this, AbilitySystem);
		AbilitySystem->AbilityActorInfo = TSharedPtr<FGameplayAbilityActorInfo>(actorInfo);
		if (HasAuthority()) {
			for (int i = 0; i < Abilites.Num(); i++) {
				AbilitySystem->GiveAbility(FGameplayAbilitySpec(Abilites[i].GetDefaultObject(), 1, i));
			}
		}
		AbilitySystem->InitAbilityActorInfo(this, this);
	}
	
}

// Called every frame
void ACollonadeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollonadeCharacter::PossessedBy(AController* NewController) {
	Super::PossessedBy(NewController);
	AbilitySystem->RefreshAbilityActorInfo();
}

// Called to bind functionality to input
void ACollonadeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	AbilitySystem->BindAbilityActivationToInputComponent(PlayerInputComponent, FGameplayAbilityInputBinds("ConfiromInput", "CancelInput", "AbilityInput"));

}

