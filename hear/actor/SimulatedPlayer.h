#pragma once

#include "mc/_HeaderOutputPredefine.h"
#include "mc/deps/core/math/Vec2.h"
#include "mc/deps/core/math/Vec3.h"
#include "mc/world/actor/provider/SynchedActorDataAccess.h"

// auto generated inclusion list
#include "mc/common/SubClientId.h"
#include "mc/deps/core/utility/AutomaticID.h"
#include "mc/deps/core/utility/NonOwnerPointer.h"
#include "mc/scripting/modules/minecraft/ScriptFacing.h"
#include "mc/server/ServerPlayer.h"
#include "mc/server/sim/BuildIntent.h"
#include "mc/server/sim/LookAtIntent.h"
#include "mc/server/sim/MovementIntent.h"
#include "mc/world/actor/ActorInitializationMethod.h"
#include "mc/world/actor/player/PlayerMovementSettings.h"
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/GameType.h"
#include "mc/world/level/storage/PlayerSuspendLevelStorageSaveToken.h"

// auto generated forward declare list
// clang-format off
class Actor;
class BlockSource;
class ChunkSource;
class ChunkViewSource;
class Dimension;
class EntityContext;
class GameServerToken;
class ItemStack;
class Level;
class NavigationComponent;
class NetworkIdentifier;
class PacketSender;
class ServerNetworkHandler;
class ServerNetworkSystem;
class Vec2;
class Vec3;
struct ActorUniqueID;
struct VariantParameterList;
namespace ClientBlobCache::Server { class ActiveTransfersManager; }
namespace ScriptModuleGameTest { struct ScriptNavigationResult; }
namespace gametest { class BaseGameTestHelper; }
namespace mce { class UUID; }
// clang-format on

class SimulatedPlayer : public ::ServerPlayer { // SimulatedPlayer类，继承自ServerPlayer
public:
    /**
     * @brief 创建一个模拟玩家
     * @param name 玩家名称
     * @param pos 生成位置
     * @param dimId 生成维度ID，默认为主世界(0)
     * @param rotation 生成朝向，默认为(0, 0)
     * @return 创建的模拟玩家的可选引用
     */
    LLAPI static optional_ref<SimulatedPlayer>
    create(std::string const& name, Vec3 const& pos, DimensionType dimId = 0, Vec2 const& rotation = {0, 0});

    /**
     * @brief 模拟潜行
     * @return 是否成功潜行
     */
    [[nodiscard]] inline bool simulateSneaking() {
        setSneaking(true);
        return SynchedActorDataAccess::getActorFlag(getEntityContext(), ActorFlags::Sneaking);
    }
    /**
     * @brief 模拟停止潜行
     * @return 是否成功停止潜行
     */
    [[nodiscard]] inline bool simulateStopSneaking() {
        setSneaking(false);
        return !SynchedActorDataAccess::getActorFlag(getEntityContext(), ActorFlags::Sneaking);
    }
    /**
     * @brief 模拟使用当前手持物品
     * @return 操作是否成功
     */
    inline bool simulateUseItem() { return simulateUseItemInSlot(getSelectedItemSlot()); }

    /**
     * @brief 模拟破坏一个方块
     * @param pos 方块位置
     * @param face 破坏的面
     * @return 操作是否成功
     */
    LLAPI bool simulateDestroyBlock(BlockPos const&, ScriptModuleMinecraft::ScriptFacing);

    /**
     * @brief 模拟破坏视线所指的方块或实体
     * @param handLength 作用距离，默认为5.5格
     * @return 操作是否成功
     */
    LLAPI bool simulateDestroyLookAt(float handLength = 5.5f);

    /**
     * @brief 尝试从实体上下文获取SimulatedPlayer指针
     * @param entity 实体上下文
     * @param includeRemoved 是否包括已移除的实体
     * @return 指向SimulatedPlayer的指针，如果不是或获取失败则为nullptr
     */
    LLAPI static ::SimulatedPlayer* tryGetFromEntity(::EntityContext& entity, bool includeRemoved);

public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 模拟的移动意图
    ::ll::TypedStorage<8, 48, ::sim::MovementIntent> mSimulatedMovement;
    // 建筑意图
    ::ll::TypedStorage<1, 2, ::sim::BuildIntent> mBuildIntention;
    // 看向目标的意图
    ::ll::TypedStorage<8, 40, ::sim::LookAtIntent> mLookAtIntent;
    // 正在破坏的方块位置
    ::ll::TypedStorage<4, 16, ::std::optional<::BlockPos>> mDestroyingBlockPos;
    // 正在破坏的方块的面
    ::ll::TypedStorage<1, 2, ::std::optional<uchar>> mDestroyingBlockFace;
    // 关联的GameTest助手
    ::ll::TypedStorage<8, 24, ::Bedrock::NonOwnerPointer<::gametest::BaseGameTestHelper>> mGameTestHelper;
    // 冷却计时器
    ::ll::TypedStorage<8, 8, uint64> mCooldownTick;
    // 移动设置
    ::ll::TypedStorage<8, 88, ::PlayerMovementSettings> mMovementSettings;
    // 基础输入速度
    ::ll::TypedStorage<4, 4, float> mBaseInputSpeed;
    // XUID
    ::ll::TypedStorage<8, 32, ::std::string> mXuid;
    // 玩家挂起时关卡存储的保存令牌
    ::ll::TypedStorage<8, 40, ::PlayerSuspendLevelStorageSaveToken const> mPlayerSuspendLevelStorageSaveToken;
    // NOLINTEND

public:
    // prevent constructor by default
    // 默认禁止构造
    SimulatedPlayer();

public:
    // virtual functions
    // 虚函数
    // NOLINTBEGIN

    // vIndex: 4
    /**
     * @brief 初始化组件 (重写 ServerPlayer)
     */
    virtual void
    initializeComponents(::ActorInitializationMethod method, ::VariantParameterList const& params) /*override*/;

    // vIndex: 145
    /**
     * @brief AI逻辑步进 (重写 ServerPlayer)
     */
    virtual void aiStep() /*override*/;

    // vIndex: 232
    /**
     * @brief 判断是否是模拟玩家 (重写 Player)
     */
    virtual bool isSimulated() const /*override*/;

    // vIndex: 233
    /**
     * @brief 获取XUID (重写 Player)
     */
    virtual ::std::string getXuid() const /*override*/;

    // vIndex: 234
    /**
     * @brief 获取移动设置 (重写 Player)
     */
    virtual ::PlayerMovementSettings const& getMovementSettings() const /*override*/;

    // vIndex: 21
    /**
     * @brief 传送到指定位置 (重写 Player)
     */
    virtual void teleportTo(
        ::Vec3 const& pos,
        bool          shouldStopRiding,
        int           cause,
        int           sourceEntityType,
        bool          keepVelocity
    ) /*override*/;

    // vIndex: 242
    /**
     * @brief 获取生成区块的限制 (重写 ServerPlayer)
     */
    virtual int _getSpawnChunkLimit() const /*override*/;

    // vIndex: 238
    /**
     * @brief 创建区块源 (重写 Player)
     */
    virtual ::std::shared_ptr<::ChunkViewSource> _createChunkSource(::ChunkSource& mainChunkSource) /*override*/;

    // vIndex: 243
    /**
     * @brief 更新区块发布者视图 (重写 ServerPlayer)
     */
    virtual void _updateChunkPublisherView(::Vec3 const& position, float minDistance) /*override*/;

    // vIndex: 0
    /**
     * @brief 析构函数 (重写 ServerPlayer)
     */
    virtual ~SimulatedPlayer() /*override*/;
    // NOLINTEND

public:
    // member functions
    // 成员函数
    // NOLINTBEGIN

    /**
     * @brief SimulatedPlayer 构造函数
     */
    MCAPI SimulatedPlayer(
        ::Level&                                           level,
        ::PacketSender&                                    packetSender,
        ::ServerNetworkSystem&                             network,
        ::ClientBlobCache::Server::ActiveTransfersManager& clientCacheMirror,
        ::GameType                                         playerGameType,
        ::NetworkIdentifier const&                         owner,
        ::SubClientId                                      subid,
        ::std::function<void(::ServerPlayer&)>             playerLoadedCallback,
        ::mce::UUID                                        uuid,
        ::std::string const&                               deviceId,
        ::GameServerToken const&                           token,
        int                                                maxChunkRadius,
        bool                                               enableItemStackNetManager,
        ::EntityContext&                                   entityContext
    );

    /**
     * @brief 内部方法：添加移动组件
     */
    MCAPI void _addMoveComponent();

    /**
     * @brief 内部方法：创建导航结果
     */
    MCAPI ::ScriptModuleGameTest::ScriptNavigationResult _createNavigationResult(::NavigationComponent* navigation
    ) const;

    /**
     * @brief 内部方法：获取所在区域
     */
    MCFOLD ::BlockSource& _getRegion();

    /**
     * @brief 内部方法：尝试挥手
     */
    MCAPI bool _trySwing();

    /**
     * @brief 内部方法：更新骑乘组件
     */
    MCAPI void _updateRidingComponents();

    /**
     * @brief AI步进前的准备工作
     */
    MCAPI void preAiStep();

    /**
     * @brief 设置GameTest助手
     */
    MCAPI void setGameTestHelper(::Bedrock::NonOwnerPointer<::gametest::BaseGameTestHelper> gameTestHelper);

    /**
     * @brief 模拟攻击
     * @return 操作是否成功
     */
    MCAPI bool simulateAttack();

    /**
     * @brief 模拟聊天
     * @param message 聊天消息
     */
    MCAPI void simulateChat(::std::string const& message);

    /**
     * @brief 模拟交互 (实体或方块)
     * @return 操作是否成功
     */
    MCAPI bool simulateInteract();

    /**
     * @brief 模拟与指定位置的方块交互
     * @param pos 方块位置
     * @param face 交互的面
     * @return 操作是否成功
     */
    MCAPI bool simulateInteract(::BlockPos const& pos, ::ScriptModuleMinecraft::ScriptFacing face);

    /**
     * @brief 模拟跳跃
     * @return 操作是否成功
     */
    MCAPI bool simulateJump();

    /**
     * @brief 模拟本地坐标系下的移动
     * @param localDirection 移动方向 (相对于玩家朝向)
     * @param speed 速度
     */
    MCAPI void simulateLocalMove(::Vec3 const& localDirection, float);

    /**
     * @brief 模拟移动到指定位置
     * @param position 目标位置
     * @param speed 速度
     * @param faceTarget 是否朝向目标
     */
    MCAPI void simulateMoveToLocation(::Vec3 const& position, float speed, bool faceTarget);

    /**
     * @brief 模拟导航到实体
     * @param actor 目标实体
     * @param speed 速度
     * @return 导航结果
     */
    MCAPI ::ScriptModuleGameTest::ScriptNavigationResult simulateNavigateToEntity(::Actor& actor, float speed);

    /**
     * @brief 模拟导航到位置
     * @param position 目标位置
     * @param speed 速度
     * @return 导航结果
     */
    MCAPI ::ScriptModuleGameTest::ScriptNavigationResult
    simulateNavigateToLocation(::Vec3 const& position, float speed);

    /**
     * @brief 模拟导航到一系列位置
     * @param positions 目标位置列表
     * @param speed 速度
     */
    MCAPI void simulateNavigateToLocations(::std::vector<::Vec3>&& positions, float speed);

    /**
     * @brief 模拟设置身体朝向
     * @param degY Y轴角度
     */
    MCAPI void simulateSetBodyRotation(float degY);

    /**
     * @brief 模拟停止破坏方块
     */
    MCAPI void simulateStopDestroyingBlock();

    /**
     * @brief 模拟使用指定槽位的物品
     * @param slot 物品槽位索引
     * @return 操作是否成功
     */
    MCAPI bool simulateUseItemInSlot(int slot);

    /**
     * @brief 模拟在方块上使用物品
     * @param item 使用的物品
     * @param pos 方块位置
     * @param face 交互的面
     * @param facePos 交互点的精确位置
     * @return 操作是否成功
     */
    MCAPI bool simulateUseItemOnBlock(
        ::ItemStack&                          item,
        ::BlockPos const&                     pos,
        ::ScriptModuleMinecraft::ScriptFacing face,
        ::Vec3 const&                         facePos
    );

    /**
     * @brief 模拟世界坐标系下的移动
     * @param worldDirection 移动方向 (世界坐标)
     * @param speed 速度
     */
    MCAPI void simulateWorldMove(::Vec3 const& worldDirection, float);
    // NOLINTEND

public:
    // static functions
    // 静态函数
    // NOLINTBEGIN

    /**
     * @brief 静态创建方法 (1)
     */
    MCAPI static ::SimulatedPlayer* create(
        ::std::string const&                                  name,
        ::BlockPos const&                                     spawnPos,
        ::DimensionType                                       dimensionId,
        ::Bedrock::NotNullNonOwnerPtr<::ServerNetworkHandler> serverNetworkHandler,
        ::std::string const&                                  xuid,
        ::std::optional<::ActorUniqueID>                      idOverride
    );

    /**
     * @brief 静态创建方法 (2)
     */
    MCAPI static ::SimulatedPlayer* create(
        ::std::string const&                                  name,
        ::BlockPos const&                                     spawnPos,
        ::Vec3 const&                                         spawnPosDelta,
        ::Vec2 const&                                         spawnRotation,
        bool                                                  spawnLoadedFromSave,
        ::DimensionType                                       dimensionId,
        ::Bedrock::NotNullNonOwnerPtr<::ServerNetworkHandler> serverNetworkHandler,
        ::std::string const&                                  xuid,
        ::std::optional<::ActorUniqueID>                      idOverride
    );
    // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::Level&                                           level,
        ::PacketSender&                                    packetSender,
        ::ServerNetworkSystem&                             network,
        ::ClientBlobCache::Server::ActiveTransfersManager& clientCacheMirror,
        ::GameType                                         playerGameType,
        ::NetworkIdentifier const&                         owner,
        ::SubClientId                                      subid,
        ::std::function<void(::ServerPlayer&)>             playerLoadedCallback,
        ::mce::UUID                                        uuid,
        ::std::string const&                               deviceId,
        ::GameServerToken const&                           token,
        int                                                maxChunkRadius,
        bool                                               enableItemStackNetManager,
        ::EntityContext&                                   entityContext
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
    MCAPI void $initializeComponents(::ActorInitializationMethod method, ::VariantParameterList const& params);

    MCAPI void $aiStep();

    MCFOLD bool $isSimulated() const;

    MCAPI ::std::string $getXuid() const;

    MCAPI ::PlayerMovementSettings const& $getMovementSettings() const;

    MCAPI void
    $teleportTo(::Vec3 const& pos, bool shouldStopRiding, int cause, int sourceEntityType, bool keepVelocity);

    MCFOLD int $_getSpawnChunkLimit() const;

    MCAPI ::std::shared_ptr<::ChunkViewSource> $_createChunkSource(::ChunkSource& mainChunkSource);

    MCFOLD void $_updateChunkPublisherView(::Vec3 const& position, float minDistance);
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
