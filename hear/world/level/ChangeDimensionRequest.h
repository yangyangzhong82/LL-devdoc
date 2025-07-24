#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/math/Vec3.h"
#include "mc/deps/core/utility/AutomaticID.h"

// auto generated forward declare list
// clang-format off
class CompoundTag;
class Dimension;
// clang-format on

public:
// ChangeDimensionRequest 内部类型定义
enum class State : int {
  PrepareRegion = 0,     // 准备区域阶段
  WaitingForChunks = 1,  // 等待区块加载阶段
  WaitingForRespawn = 2, // 等待重生阶段
};

public:
// member variables
// 成员变量
// NOLINTBEGIN
// 维度切换请求的当前状态。
::ll::TypedStorage<4, 4, ::ChangeDimensionRequest::State> mState;
// 玩家来源维度的ID。
::ll::TypedStorage<4, 4, ::DimensionType> mFromDimensionId;
// 玩家目标维度的ID。
::ll::TypedStorage<4, 4, ::DimensionType> mToDimensionId;
// 玩家在来源维度的位置。
::ll::TypedStorage<4, 12, ::Vec3> mFromLocation;
// 玩家在目标维度的位置。
::ll::TypedStorage<4, 12, ::Vec3> mToLocation;
// 是否通过传送门进行传送。
::ll::TypedStorage<1, 1, bool> mUsePortal;
// 本次传送是否为一次重生。
::ll::TypedStorage<1, 1, bool> mRespawn;
// 用于存储玩家Agent（智能体）数据的NBT标签，以便在维度间转移。
::ll::TypedStorage<8, 8, ::std::unique_ptr<::CompoundTag>> mAgentTag;
// NOLINTEND

public:
// member functions
// NOLINTBEGIN
MCNAPI ~ChangeDimensionRequest();
// NOLINTEND

public:
// destructor thunk
// NOLINTBEGIN
MCNAPI void $dtor();
// NOLINTEND
}
;
