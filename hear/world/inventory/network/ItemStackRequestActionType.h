#pragma once

#include "mc/_HeaderOutputPredefine.h"

enum class ItemStackRequestActionType : uchar {
  Take = 0,  // 从一个槽位中拿取物品堆栈。
  Place = 1, // 放置一个物品堆栈到一个槽位中。
  Swap = 2,  // 交换两个槽位中的物品。
  Drop = 3,  // 从物品栏丢弃一个物品到世界中。
  Destroy = 4, // 销毁一个物品（例如，在创造模式下拖出物品栏）。
  Consume = 5, // 消耗一个物品（例如，吃食物）。
  Create = 6,  // 在创造模式物品栏中创建一个物品。
  PlaceInItemContainerDeprecated = 7, // [已废弃] 放置物品到物品容器中。
  TakeFromItemContainerDeprecated = 8, // [已废弃] 从物品容器中拿取物品。
  ScreenLabTableCombine = 9, // 在实验台上进行物品组合（教育版特色）。
  ScreenBeaconPayment =
      10, // 在信标界面中放入物品作为“支付”（激活或改变效果）。
  ScreenHUDMineBlock = 11, // 在HUD中挖掘方块（可能是指获取方块的动作）。
  CraftRecipe = 12,     // 使用特定配方进行合成。
  CraftRecipeAuto = 13, // 自动合成（例如，通过配方书shift点击）。
  CraftCreative = 14, // 在创造模式下进行“合成”（即从结果槽拿出物品）。
  CraftRecipeOptional =
      15, // 使用一个可选的配方进行合成（可能与配方解锁系统有关）。
  CraftRepairAndDisenchant = 16, // 在砂轮上进行修复或祛魔。
  CraftLoom = 17,                // 在织布机上应用图案。
  CraftNonImplementedDeprecatedasktylaing =
      18, // [已废弃] 一个未实现的合成操作。
  CraftResultsDeprecatedasktylaing = 19, // [已废弃] 与合成结果相关的操作。
};
