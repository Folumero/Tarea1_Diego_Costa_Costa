// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssetDependencyHelper.generated.h"

/**
 * 
 */
UCLASS()
class UTHUB_TAREA_HERRAMI_API UAssetDependencyHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
    // Declaración de la función que listará las dependencias de assets
    UFUNCTION(BlueprintCallable, Category = "Assets")
    static void ListAssetDependencies();
};
