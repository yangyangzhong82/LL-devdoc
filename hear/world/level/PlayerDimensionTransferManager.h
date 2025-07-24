#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/utility/NonOwnerPointer.h"
#include "mc/deps/core/utility/pub_sub/Subscription.h"
#include "mc/deps/game_refs/StackRefResult.h"
#include "mc/deps/game_refs/WeakRef.h"

// auto generated forward declare list
// clang-format off
class Actor;
class ChangeDimensionRequest;
class Dimension;
class DimensionManager;
class EntityContext;
class EntityRegistry;
class GameplayUserManager;
class ILevelCrashDumpManager;
class IPlayerDimensionTransferer;
class PacketSender;
class Player;
class PlayerLimboActorManager;
struct ActorUniqueID;
namespace Bedrock::PubSub { class Subscription; }
// clang-format on

class PlayerDimensionTransferManager {
public:
  // member variables
  // 成员变量
  // NOLINTBEGIN
  // 玩家临时滞留实体管理器，用于处理玩家在维度切换时携带的实体（如Agent）。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::PlayerLimboActorManager> const>
      mPlayerLimboActorManager;
  // 玩家维度传送器，负责执行维度切换的具体步骤。
  ::ll::TypedStorage<
      8, 8,
      ::gsl::not_null<::std::unique_ptr<::IPlayerDimensionTransferer>> const>
      mPlayerDimensionTransferer;
  // 游戏性用户（玩家）管理器。
  ::ll::TypedStorage<8, 24,
                     ::Bedrock::NotNullNonOwnerPtr<::GameplayUserManager> const>
      mGameplayUserManager;
  // 维度管理器。
  ::ll::TypedStorage<8, 24,
                     ::Bedrock::NotNullNonOwnerPtr<::DimensionManager> const>
      mDimensionManager;
  // 实体注册表的弱引用。
  ::ll::TypedStorage<8, 16, ::WeakRef<::EntityRegistry> const> mEntityRegistry;
  // 关卡崩溃转储管理器。
  ::ll::TypedStorage<
      8, 8, ::gsl::not_null<::std::unique_ptr<::ILevelCrashDumpManager>> const>
      mLevelCrashDumpManager;
  // 标记关卡是否已完成初始化。
  ::ll::TypedStorage<1, 1, bool> mLevelFinishedInitializing;
  // 当游戏性用户被移除时的事件订阅，用于清理相关的传送请求。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnGameplayUserRemoved;
  // NOLINTEND

public:
  // prevent constructor by default
  PlayerDimensionTransferManager();

public:
  // member functions
  // 成员函数
  // NOLINTBEGIN
  /**
   * @brief PlayerDimensionTransferManager 的构造函数。
   * @param playerLimboActorManager 玩家临时滞留实体管理器。
   * @param playerDimensionTransferer 玩家维度传送器。
   * @param dimensionManager 维度管理器。
   * @param gameplayUserManager 游戏性用户（玩家）管理器。
   * @param entityRegistry 实体注册表。
   * @param levelCrashDumpManager 关卡崩溃转储管理器。
   */
  MCAPI PlayerDimensionTransferManager(
      ::std::unique_ptr<::PlayerLimboActorManager> playerLimboActorManager,
      ::std::unique_ptr<::IPlayerDimensionTransferer> playerDimensionTransferer,
      ::Bedrock::NotNullNonOwnerPtr<::DimensionManager> dimensionManager,
      ::Bedrock::NotNullNonOwnerPtr<::GameplayUserManager> gameplayUserManager,
      ::gsl::not_null<::StackRefResult<::EntityRegistry>> const &entityRegistry,
      ::std::unique_ptr<::ILevelCrashDumpManager> levelCrashDumpManager);

  // (内部) 获取一个有效的实体注册表引用。
  MCAPI ::StackRefResult<::EntityRegistry> _getValidEntityRegistry();

  // (内部) 检查一个玩家是否被暂停（通常在维度切换过程中）。
  MCAPI bool _isPlayerSuspended(::Player const &player) const;

  // (内部) 当一个游戏性用户被移除时调用的处理函数。
  MCAPI void _onGameplayUserRemoved(::EntityContext &entity);

  // (内部) 处理玩家维度切换的核心逻辑，这是一个状态机。
  MCAPI bool _playerChangeDimension(::Player &player,
                                    ::ChangeDimensionRequest &changeRequest);

  // (内部) 处理玩家维度切换中的“准备区域”阶段。
  MCAPI void
  _playerChangeDimensionPrepareRegion(::Player &player,
                                      ::ChangeDimensionRequest &changeRequest,
                                      ::Dimension &toDimension);

  // (内部) 处理玩家维度切换中的“等待区块加载”阶段。
  MCAPI bool _playerChangeDimensionWaitingForChunks(
      ::Player &player, ::ChangeDimensionRequest &changeRequest,
      ::Dimension &toDimension);

  // 在每一tick中处理所有待处理的维度切换请求。
  MCAPI void handleChangeDimensionRequests();

  // 请求为一个玩家进行维度切换。
  MCAPI void
  requestPlayerChangeDimension(::Player const &player,
                               ::ChangeDimensionRequest &&changeRequest);

  // 设置网络数据包发送器。
  MCAPI void setPacketSender(::PacketSender &packetSender);

  // 将一个由玩家拥有的实体（如Agent）转移到临时滞留状态。
  MCAPI void transferActorToOwnedEntityLimbo(::ActorUniqueID playerId,
                                             ::Actor &actor);

  // 析构函数。
  MCAPI ~PlayerDimensionTransferManager();
  // NOLINTEND
};

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::std::unique_ptr<::PlayerLimboActorManager>               playerLimboActorManager,
        ::std::unique_ptr<::IPlayerDimensionTransferer>            playerDimensionTransferer,
        ::Bedrock::NotNullNonOwnerPtr<::DimensionManager>          dimensionManager,
        ::Bedrock::NotNullNonOwnerPtr<::GameplayUserManager>       gameplayUserManager,
        ::gsl::not_null<::StackRefResult<::EntityRegistry>> const& entityRegistry,
        ::std::unique_ptr<::ILevelCrashDumpManager>                levelCrashDumpManager
    );
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN
    MCAPI void $dtor();
    // NOLINTEND
};
