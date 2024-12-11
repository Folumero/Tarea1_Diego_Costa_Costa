// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UTHUB_Tarea_Herrami : ModuleRules
{
	public UTHUB_Tarea_Herrami(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
          "Core",
          "CoreUObject",
          "Engine",
          "InputCore",
          "EnhancedInput",
          "AssetRegistry"  
        });
	}
}
