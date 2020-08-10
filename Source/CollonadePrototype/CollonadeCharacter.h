// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CollonadeCharacter.generated.h"

UCLASS(config = game)
class COLLONADEPROTOTYPE_API ACollonadeCharacter : public ACharacter, public IAbilitySystemInterface
{


	GENERATED_BODY()

	
public:
	// Sets default values for this character's properties
	ACollonadeCharacter();
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Abilities)
	TArray<TSubclassOf<class UGameplayAbility>> Abilites;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PossessedBy(AController* NewController);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

UENUM(BlueprintType)
enum class AbilityInput : uint8 {
	WeaponAbility1 UMETA(DisplayName = "Use Weapon Ability 1"),
	WeaponAbility2 UMETA(DisplayName = "Use Weapon Ability 2"),
	SpecialAbility UMETA(DisplayName = "Use Special Ability"),
	ItemAbility UMETA(DisplayName = "Use Item Ability"),
};