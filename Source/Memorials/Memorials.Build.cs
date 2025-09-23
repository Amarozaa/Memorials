// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Memorials : ModuleRules
{
	public Memorials(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Memorials",
			"Memorials/Variant_Platforming",
			"Memorials/Variant_Platforming/Animation",
			"Memorials/Variant_Combat",
			"Memorials/Variant_Combat/AI",
			"Memorials/Variant_Combat/Animation",
			"Memorials/Variant_Combat/Gameplay",
			"Memorials/Variant_Combat/Interfaces",
			"Memorials/Variant_Combat/UI",
			"Memorials/Variant_SideScrolling",
			"Memorials/Variant_SideScrolling/AI",
			"Memorials/Variant_SideScrolling/Gameplay",
			"Memorials/Variant_SideScrolling/Interfaces",
			"Memorials/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
