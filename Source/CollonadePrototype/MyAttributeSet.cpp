// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAttributeSet.h"

UMyAttributeSet::UMyAttributeSet() {
	Health = 8;
}

FGameplayAttribute UMyAttributeSet::HealthAttribute() {
    static UProperty* Property = FindFieldChecked<UProperty>(UMyAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UMyAttributeSet, Health));
    return FGameplayAttribute(Property);
}