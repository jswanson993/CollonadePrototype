// Fill out your copyright notice in the Description page of Project Settings.

#include "CollonadePrototype.h"
#include "Modules/ModuleManager.h"

void FCollonadePrototypeModule::StartupModule()
{
#if (ENGINE_MINOR_VERSION >= 21)    
    
    FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders"));
    FString pop = "/Project";
    AddShaderSourceDirectoryMapping(pop, ShaderDirectory);
#endif

}

void FCollonadePrototypeModule::ShutdownModule()
{
}

IMPLEMENT_PRIMARY_GAME_MODULE(FCollonadePrototypeModule, CollonadePrototype, "CollonadePrototype");