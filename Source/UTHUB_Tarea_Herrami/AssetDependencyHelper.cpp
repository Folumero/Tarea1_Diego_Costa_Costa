// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetDependencyHelper.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "AssetRegistry/AssetRegistryModule.h"

void UAssetDependencyHelper::ListAssetDependencies()
{
    UE_LOG(LogTemp, Warning, TEXT("Esto furula"));
   
    // Obtener el módulo de registro de assets
    FAssetRegistryModule& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

    // Lista para almacenar los assets no referenciados
    TArray<FAssetData> AllAssets;
    AssetRegistry.Get().GetAssetsByPath(TEXT("/Game"), AllAssets, true, false);

    // Map para almacenar dependencias
    TMap<FString, TArray<FString>> AssetDependencies;

    for (const FAssetData& Asset : AllAssets)
    {
        TArray<FName> Dependencies;
        AssetRegistry.Get().GetDependencies(Asset.PackageName, Dependencies);

        if (Dependencies.Num() > 0)
        {
            // Almacenar dependencias en el mapa
            TArray<FString> DependencyNames;
            for (const FName& Dependency : Dependencies)
            {
                DependencyNames.Add(Dependency.ToString());
            }

            AssetDependencies.Add(Asset.AssetName.ToString(), DependencyNames);
        }
    }
    FString OutputString;
    for (const auto& Pair : AssetDependencies)
    {
        OutputString += Pair.Key + TEXT(" [ROOT]\n");
        for (const FString& Dependency : Pair.Value)
        {
            OutputString += TEXT("  |- ") + Dependency + TEXT("\n");
        }
    }

    // Generar la ruta del archivo
    FString FilePath = FPaths::ProjectSavedDir() + TEXT("Logs/RefLogOutput_") +
        FDateTime::Now().ToString(TEXT("%Y%m%d")) + TEXT(".log");

    // Guardar el archivo
    FFileHelper::SaveStringToFile(OutputString, *FilePath);

    // Mensaje de confirmación
    FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Dependencias exportadas correctamente.")));
}
