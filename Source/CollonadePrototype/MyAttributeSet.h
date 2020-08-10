// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "MyAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class COLLONADEPROTOTYPE_API UMyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UMyAttributeSet();


	UPROPERTY(Category = "Character Attributes | Health", EditAnywhere, BlueprintReadWrite)
		FGameplayAttributeData Health;
	FGameplayAttribute HealthAttribute();
};
