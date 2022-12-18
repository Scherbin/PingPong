// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PingPong : ModuleRules
{
	public PingPong(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] { "PingPong/Public/Player" });
	}
}
