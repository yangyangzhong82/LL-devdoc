#pragma once

#include "mc/_HeaderOutputPredefine.h"

enum class CurrentCmdVersion : int {
    Invalid                                      = -1,
    Initial                                      = 1,
    TpRotationClamping                           = 2,
    NewBedrockCmdSystem                          = 3,
    ExecuteUsesVec3                              = 4,
    CloneFixes                                   = 5,
    UpdateAquatic                                = 6,
    EntitySelectorUsesVec3                       = 7,
    ContainersDontDropItemsAnymore               = 8,
    FiltersObeyDimensions                        = 9,
    ExecuteAndBlockCommandAndSelfSelectorFixes   = 10,
    InstantEffectsUseTicks                       = 11,
    DontRegisterBrokenFunctionCommands           = 12,
    ClearSpawnPointCommand                       = 13,
    CloneAndTeleportRotationFixes                = 14,
    TeleportDimensionFixes                       = 15,
    CloneUpdateBlockAndTimeFixes                 = 16,
    CloneIntersectFix                            = 17,
    FunctionExecuteOrderAndChestSlotFix          = 18,
    NonTickingAreasNoLongerConsideredLoaded      = 19,
    SpreadplayersHazardAndResolvePlayerByNameFix = 20,
    NewExecuteCommandSyntaxExperimentAndChestLootTableFixAndTeleportFacingVerticalUnclampedAndLocateBiomeAndFeatureMerged =
        21,
    WaterloggingAddedToStructureCommand            = 22,
    SelectorDistanceFilteredAndRelativeRotationFix = 23,
    NewSummonCommandAddedRotationOptionsAndBubbleColumnCloneFixAndExecuteInDimensionTeleportFixAndNewExecuteRotationFix =
        24,
    NewExecuteCommandReleaseEnchantCommandLevelFixAndHasItemDataFixAndCommandDeferral = 25,
    ExecuteIfScoreFixes                                                               = 26,
    ReplaceItemAndLootReplaceBlockCommandsDoNotPlaceItemsIntoCauldronsFix             = 27,
    ChangesToCommandOriginRotation                                                    = 28,
    RemoveAuxValueParameterFromBlockCommands                                          = 29,
    VolumeSelectorFixes                                                               = 30,
    EnableSummonRotation                                                              = 31,
    SummonCommandDefaultRotation                                                      = 32,
    PositionalDimensionFiltering                                                      = 33,
    CommandSelectorHasItemFilterNoLongerCallsSameItemFunction                         = 34,
    AgentSweepingBlockTest                                                            = 34,
    BlockStateEquals                                                                  = 35,
    CommandPositionFix                                                                = 35,
    CommandSelectorHasItemFilterUsesDataAsDamageForSelectingDamageableItems           = 36,
    ExecuteDetectConditionSubcommandNotAllowNonLoadedBlocks                           = 37,
    RemoveSuicideKeyword                                                              = 38,
    CloneContainerBlockEntityRemovalFix                                               = 39,
    StopSoundMusicFix                                                                 = 40,
    SpreadPlayersStuckInGroundFixAndMaxHeightParameter                                = 41,
    LocateStructureOutput                                                             = 42,
    PostBlockFlattening                                                               = 43,
    TestForBlockCommandDoesNotIgnoreBlockState                                        = 44,
    Count                                                                             = 45,
    Latest                                                                            = 44,
};
