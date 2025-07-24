#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/utility/AutomaticID.h"
#include "mc/entity/components/PlayerPositionModeComponent.h"
#include "mc/world/level/IPlayerDimensionTransferProxy.h"

// auto generated forward declare list
// clang-format off
class Actor;
class BlockPos;
class Dimension;
class MovePlayerPacket;
class Player;
class SubChunkPos;
class Vec3;
// clang-format on

class PlayerDimensionTransferProxy : public ::IPlayerDimensionTransferProxy {
public:
  // virtual functions
  // 虚函数
  // NOLINTBEGIN
  // vIndex: 0
  virtual ~PlayerDimensionTransferProxy() /*override*/ =
      default; // 默认析构函数

  // vIndex: 1
  virtual void playerDimensionChangedEvent(
      ::Player &player, ::DimensionType fromDimensionId,
      ::DimensionType
          toDimensionId) /*override*/; // 当玩家维度变更后，触发此事件。

  // vIndex: 2
  virtual ::Actor *
  getAgent(::Player &player) /*override*/; // 获取玩家的 Agent (智能体)。

  // vIndex: 3
  virtual void resetAgent(::Player &player) /*override*/; // 重置玩家的 Agent。

  // vIndex: 4
  virtual void stopUsingItem(
      ::Player
          &player) /*override*/; // 让玩家停止正在使用的物品（如吃东西、拉弓）。

  // vIndex: 5
  virtual bool hasRespawnPosition(::Player const &player) const
      /*override*/; // 检查玩家是否有设置重生点（如床）。

  // vIndex: 6
  virtual ::BlockPos const &getSpawnPosition(::Player const &player) const
      /*override*/; // 获取玩家的重生点位置。

  // vIndex: 7
  virtual bool isRespawningFromTheEnd(::Player const &player) const
      /*override*/; // 检查玩家是否正在从末地重生。

  // vIndex: 8
  virtual void fireWillChangeDimension(
      ::Player &player) /*override*/; // 触发一个“即将改变维度”的事件。

  // vIndex: 9
  virtual void
  moveTo(::Player &player,
         ::Vec3 const &position) /*override*/; // 将玩家移动到指定位置。

  // vIndex: 10
  virtual void setPreviousPosition(::Player &player) /*override*/
      ; // 设置玩家的“上一tick位置”为当前位置，以防止插值问题。

  // vIndex: 11
  virtual void
  resetInterpolation(::Player &player) /*override*/; // 重置玩家的位置插值。

  // vIndex: 12
  virtual void prepareRegion(
      ::Player &player,
      ::Dimension const
          &dimension) /*override*/; // 为玩家在目标维度准备区域（加载区块）。

  // vIndex: 13
  virtual ::MovePlayerPacket createMovePlayerPacket(
      ::Player const &player,
      ::PlayerPositionModeComponent::PositionMode resetPosition) const
      /*override*/; // 创建一个移动玩家的数据包，用于通知客户端位置重置。

  // vIndex: 14
  virtual void setAgent(::Player &player,
                        ::Actor &agent) /*override*/; // 为玩家设置一个 Agent。

  // vIndex: 15
  virtual ::Vec3 calculateAgentSpawnPosition(::Player const &player) const
      /*override*/; // 计算 Agent 在新维度中的出生位置。

  // vIndex: 16
  virtual bool isRespawnReady(::Player const &player) const
      /*override*/; // 检查玩家是否已准备好重生。

  // vIndex: 17
  virtual ::std::pair<bool, ::std::optional<::SubChunkPos>>
  hasSubChunksAt(::Player const &player, ::BlockPos const &min,
                 ::BlockPos const &max) const
      /*override*/; // 检查在指定区域内是否存在子区块。

  // vIndex: 18
  virtual void transferTickingArea(
      ::Actor &actor,
      ::Dimension &dimension) /*override*/; // 将实体拥有的常加载区域（Ticking
                                            // Area）转移到新的维度。
  // NOLINTEND
};

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCAPI void
    $playerDimensionChangedEvent(::Player& player, ::DimensionType fromDimensionId, ::DimensionType toDimensionId);

    MCAPI ::Actor* $getAgent(::Player& player);

    MCAPI void $resetAgent(::Player& player);

    MCAPI void $stopUsingItem(::Player& player);

    MCAPI bool $hasRespawnPosition(::Player const& player) const;

    MCAPI ::BlockPos const& $getSpawnPosition(::Player const& player) const;

    MCAPI bool $isRespawningFromTheEnd(::Player const& player) const;

    MCAPI void $fireWillChangeDimension(::Player& player);

    MCAPI void $moveTo(::Player& player, ::Vec3 const& position);

    MCAPI void $setPreviousPosition(::Player& player);

    MCAPI void $resetInterpolation(::Player& player);

    MCAPI void $prepareRegion(::Player& player, ::Dimension const& dimension);

    MCAPI ::MovePlayerPacket
    $createMovePlayerPacket(::Player const& player, ::PlayerPositionModeComponent::PositionMode resetPosition) const;

    MCAPI void $setAgent(::Player& player, ::Actor& agent);

    MCAPI ::Vec3 $calculateAgentSpawnPosition(::Player const& player) const;

    MCAPI bool $isRespawnReady(::Player const& player) const;

    MCAPI ::std::pair<bool, ::std::optional<::SubChunkPos>>
    $hasSubChunksAt(::Player const& player, ::BlockPos const& min, ::BlockPos const& max) const;

    MCFOLD void $transferTickingArea(::Actor& actor, ::Dimension& dimension);
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCAPI static void** $vftable();
    // NOLINTEND
};
