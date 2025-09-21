using UnrealBuildTool;

public class Svetun : ModuleRules
{
	public Svetun(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput", "GameplayTags", "GameplayAbilities", "GameplayTasks" });
    }
}
