#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/utility/AutomaticID.h"
#include "mc/deps/core/utility/NonOwnerPointer.h"
#include "mc/deps/core/utility/pub_sub/Connector.h"
#include "mc/deps/core/utility/pub_sub/Publisher.h"
#include "mc/world/level/IPlayerDimensionTransferer.h"

// auto generated forward declare list
// clang-format off
class ChangeDimensionRequest;
class Dimension;
class EntityRegistry;
class GameplayUserManager;
class IPlayerDimensionTransferProxy;
class ISharedSpawnGetter;
class LevelStorage;
class LoadingScreenIdManager;
class PacketSender;
class Player;
class PlayerLimboActorManager;
class PortalForcer;
struct AddLimboActorHelper;
namespace Bedrock::PubSub::ThreadModel { struct MultiThreaded; }
// clang-format on

class PlayerDimensionTransferer : public ::IPlayerDimensionTransferer {
public:
  // member variables
  // 成员变量
  // NOLINTBEGIN
  // 玩家维度传送的代理接口，用于执行实际的传送操作。
  ::ll::TypedStorage<
      8, 8,
      ::gsl::not_null<::std::unique_ptr<::IPlayerDimensionTransferProxy>> const>
      mPlayerDimensionTransferProxy;
  // 标记此实例是否在客户端侧。
  ::ll::TypedStorage<1, 1, bool const> mIsClientSide;
  // 传送门强制生成器，用于在维度传送时寻找或创建传送门。
  ::ll::TypedStorage<8, 24, ::Bedrock::NotNullNonOwnerPtr<::PortalForcer> const>
      mPortalForcer;
  // 共享出生点获取器，用于确定重生位置。
  ::ll::TypedStorage<
      8, 8, ::gsl::not_null<::std::unique_ptr<::ISharedSpawnGetter>> const>
      mSharedSpawnGetter;
  // 关卡存储，用于读写玩家数据。
  ::ll::TypedStorage<8, 24, ::Bedrock::NonOwnerPointer<::LevelStorage> const>
      mLevelStorage;
  // 加载屏幕ID管理器，用于在维度切换时显示加载屏幕。
  ::ll::TypedStorage<8, 24,
                     ::Bedrock::NonOwnerPointer<::LoadingScreenIdManager> const>
      mLoadingScreenIdManager;
  // 网络数据包发送器。
  ::ll::TypedStorage<8, 24, ::Bedrock::NonOwnerPointer<::PacketSender>>
      mPacketSender;
  // 当任何玩家在维度切换前暂停区域时发布的事件。
  ::ll::TypedStorage<8, 128,
                     ::Bedrock::PubSub::Publisher<
                         void(::DimensionType),
                         ::Bedrock::PubSub::ThreadModel::MultiThreaded, 0>>
      mOnAnyPlayerChangeDimensionPreSuspendRegion;
  // 当任何玩家维度切换准备区域完成时发布的事件。
  ::ll::TypedStorage<
      8, 128,
      ::Bedrock::PubSub::Publisher<
          void(), ::Bedrock::PubSub::ThreadModel::MultiThreaded, 0>>
      mOnAnyPlayerChangeDimensionPrepareRegionComplete;
  // NOLINTEND

public:
  // prevent constructor by default
  PlayerDimensionTransferer();

public:
  // virtual functions
  // 虚函数
  // NOLINTBEGIN
  // vIndex: 2
  virtual ~PlayerDimensionTransferer() /*override*/; // 析构函数

  // vIndex: 3
  virtual void playerSaveLimboActors(
      ::Player &player, ::ChangeDimensionRequest &changeRequest,
      ::Dimension &toDimension,
      ::PlayerLimboActorManager *playerLimboActorManager) /*override*/
      ; // 保存玩家的临时滞留实体（如Agent）。

  // vIndex: 4
  virtual void playerDestroyRemotePlayers(
      ::GameplayUserManager
          &gameplayUserManager) /*override*/; // 销毁远程玩家的副本。

  // vIndex: 5
  virtual void playerStartChangeDimensionSuspendRegion(
      ::Player &player,
      ::DimensionType
          fromDimension) /*override*/; // 玩家开始维度切换，暂停当前区域。

  // vIndex: 6
  virtual void setTransitionLocation(
      ::Player &player, ::ChangeDimensionRequest &changeRequest,
      ::Dimension &toDimension) /*override*/; // 设置玩家在目标维度的过渡位置。

  // vIndex: 7
  virtual void syncTransitionComponentTargetPosition(
      ::Player &player,
      ::ChangeDimensionRequest const
          &changeRequest) /*override*/; // 同步过渡组件的目标位置。

  // vIndex: 8
  virtual void playerDestroyRegion(
      ::Player &player,
      ::ChangeDimensionRequest const
          &changeRequest) /*override*/; // 销毁玩家在旧维度的区域。

  // vIndex: 9
  virtual void playerPrepareRegion(
      ::Player &player, ::ChangeDimensionRequest const &changeRequest,
      ::Dimension const &toDimension) /*override*/; // 为玩家准备新维度的区域。

  // vIndex: 0
  virtual ::Bedrock::PubSub::Connector<void(::DimensionType)> &
  getOnAnyPlayerChangeDimensionPreSuspendRegionConnector() /*override*/
      ; // 获取“维度切换前暂停区域”事件的连接器。

  // vIndex: 1
  virtual ::Bedrock::PubSub::Connector<void()> &
  getOnAnyPlayerChangeDimensionPrepareRegionCompleteConnector() /*override*/
      ; // 获取“准备区域完成”事件的连接器。

  // vIndex: 10
  virtual bool
  playerWaitForServer(::Player &player,
                      ::std::chrono::steady_clock::time_point
                          currentTime) /*override*/; // 玩家等待服务器响应。

  // vIndex: 11
  virtual bool playerWaitForDimensionTransitionSystem(
      ::Player const &player,
      ::EntityRegistry
          &entityRegistry) /*override*/; // 玩家等待维度过渡系统完成。

  // vIndex: 12
  virtual void sendClientRespawnMovePacketFromServer(
      ::Player const &player,
      ::ChangeDimensionRequest
          &changeRequest) /*override*/; // 服务器向客户端发送重生/移动数据包。

  // vIndex: 13
  virtual bool waitForSubChunks(
      ::Player &player,
      ::Dimension const
          &toDimension) /*override*/; // 等待目标维度的子区块加载完成。

  // vIndex: 14
  virtual void
  startWaitForRespawn(::Player const &player) /*override*/; // 开始等待重生。

  // vIndex: 15
  virtual void
  playerSwitchDimension(::Player &player,
                        ::ChangeDimensionRequest &changeRequest,
                        ::AddLimboActorHelper *addLimboActorHelper) /*override*/
      ; // 切换玩家的维度属性，并重新加载临时滞留的实体。

  // vIndex: 16
  virtual bool doRespawnIfReady(
      ::Player &player, ::ChangeDimensionRequest &changeRequest,
      ::AddLimboActorHelper
          *addLimboActorHelper) /*override*/; // 如果准备就绪，则执行重生操作。

  // vIndex: 17
  virtual void setPacketSender(
      ::PacketSender &packetSender) /*override*/; // 设置网络数据包发送器。
                                                  // NOLINTEND

public:
  // member functions
  // 成员函数
  // NOLINTBEGIN
  MCAPI PlayerDimensionTransferer(
      ::std::unique_ptr<::IPlayerDimensionTransferProxy>
          playerDimensionTransferProxy,
      bool isClientSide,
      ::Bedrock::NotNullNonOwnerPtr<::PortalForcer> portalForcer,
      ::std::unique_ptr<::ISharedSpawnGetter> sharedSpawnGetter,
      ::Bedrock::NonOwnerPointer<::LevelStorage> levelStorage,
      ::Bedrock::NonOwnerPointer<::LoadingScreenIdManager>
          loadingScreenIdManager);

  // (内部) 完成维度切换的最终步骤。
  MCAPI void
  _finalizeDimensionChange(::Player &player,
                           ::ChangeDimensionRequest const &changeRequest);

  // (内部) 从NBT标签加载玩家的Agent。
  MCAPI void _loadAgentFromTag(::Player &player,
                               ::ChangeDimensionRequest &changeRequest,
                               ::AddLimboActorHelper &addLimboActorHelper);
  // NOLINTEND
};

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::std::unique_ptr<::IPlayerDimensionTransferProxy>   playerDimensionTransferProxy,
        bool                                                 isClientSide,
        ::Bedrock::NotNullNonOwnerPtr<::PortalForcer>        portalForcer,
        ::std::unique_ptr<::ISharedSpawnGetter>              sharedSpawnGetter,
        ::Bedrock::NonOwnerPointer<::LevelStorage>           levelStorage,
        ::Bedrock::NonOwnerPointer<::LoadingScreenIdManager> loadingScreenIdManager
    );
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN
    MCAPI void $dtor();
    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCAPI void $playerSaveLimboActors(
        ::Player&                  player,
        ::ChangeDimensionRequest&  changeRequest,
        ::Dimension&               toDimension,
        ::PlayerLimboActorManager* playerLimboActorManager
    );

    MCAPI void $playerDestroyRemotePlayers(::GameplayUserManager& gameplayUserManager);

    MCAPI void $playerStartChangeDimensionSuspendRegion(::Player& player, ::DimensionType fromDimension);

    MCAPI void
    $setTransitionLocation(::Player& player, ::ChangeDimensionRequest& changeRequest, ::Dimension& toDimension);

    MCAPI void $syncTransitionComponentTargetPosition(::Player& player, ::ChangeDimensionRequest const& changeRequest);

    MCAPI void $playerDestroyRegion(::Player& player, ::ChangeDimensionRequest const& changeRequest);

    MCAPI void $playerPrepareRegion(
        ::Player&                       player,
        ::ChangeDimensionRequest const& changeRequest,
        ::Dimension const&              toDimension
    );

    MCFOLD ::Bedrock::PubSub::Connector<void(::DimensionType)>&
    $getOnAnyPlayerChangeDimensionPreSuspendRegionConnector();

    MCFOLD ::Bedrock::PubSub::Connector<void()>& $getOnAnyPlayerChangeDimensionPrepareRegionCompleteConnector();

    MCAPI bool $playerWaitForServer(::Player& player, ::std::chrono::steady_clock::time_point currentTime);

    MCAPI bool $playerWaitForDimensionTransitionSystem(::Player const& player, ::EntityRegistry& entityRegistry);

    MCAPI void $sendClientRespawnMovePacketFromServer(::Player const& player, ::ChangeDimensionRequest& changeRequest);

    MCAPI bool $waitForSubChunks(::Player& player, ::Dimension const& toDimension);

    MCAPI void $startWaitForRespawn(::Player const& player);

    MCAPI void $playerSwitchDimension(
        ::Player&                 player,
        ::ChangeDimensionRequest& changeRequest,
        ::AddLimboActorHelper*    addLimboActorHelper
    );

    MCAPI bool $doRespawnIfReady(
        ::Player&                 player,
        ::ChangeDimensionRequest& changeRequest,
        ::AddLimboActorHelper*    addLimboActorHelper
    );

    MCAPI void $setPacketSender(::PacketSender& packetSender);
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
