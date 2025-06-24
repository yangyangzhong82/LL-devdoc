#pragma once

#include "mc/_HeaderOutputPredefine.h"
#include "mc/entity/components/UserEntityIdentifierComponent.h"
#include "mc/network/NetworkPeer.h"
#include "mc/world/inventory/EnderChestContainer.h"

// auto generated inclusion list
#include "mc/common/SubClientId.h"
#include "mc/deps/core/math/Vec3.h"
#include "mc/deps/core/platform/BuildPlatform.h"
#include "mc/deps/core/string/HashedString.h"
#include "mc/deps/core/timing/Stopwatch.h"
#include "mc/deps/core/utility/AutomaticID.h"
#include "mc/deps/core/utility/NonOwnerPointer.h"
#include "mc/deps/core/utility/optional_ref.h"
#include "mc/deps/core/utility/pub_sub/Publisher.h"
#include "mc/deps/game_refs/OwnerPtr.h"
#include "mc/deps/game_refs/StackRefResult.h"
#include "mc/deps/shared_types/legacy/LevelSoundEvent.h"
#include "mc/deps/shared_types/legacy/actor/ActorDamageCause.h"
#include "mc/deps/shared_types/legacy/actor/ArmorSlot.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/server/commands/CommandPermissionLevel.h"
#include "mc/world/ContainerID.h"
#include "mc/world/PlayerUIContainer.h"
#include "mc/world/actor/ActorEvent.h"
#include "mc/world/actor/ActorInitializationMethod.h"
#include "mc/world/actor/ActorResetRule.h"
#include "mc/world/actor/ActorType.h"
#include "mc/world/actor/Mob.h"
#include "mc/world/actor/player/AbilitiesIndex.h"
#include "mc/world/actor/player/BedSleepingResult.h"
#include "mc/world/actor/player/PlayerItemInUse.h"
#include "mc/world/actor/player/PlayerSpawnFallbackType.h"
#include "mc/world/actor/player/PlayerUISlot.h"
#include "mc/world/inventory/InventoryOptions.h"
#include "mc/world/inventory/transaction/InventoryTransactionManager.h"
#include "mc/world/item/HandSlot.h"
#include "mc/world/item/ItemGroup.h"
#include "mc/world/item/ItemInstance.h"
#include "mc/world/item/ItemUseMethod.h"
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/GameType.h"

// auto generated forward declare list
// clang-format off
class AABB;
class Actor;
class ActorDamageSource;
class AddActorBasePacket;
class Agent;
class AnimationComponent;
class Attribute;
class Block;
class BlockActor;
class BlockSource;
class BodyControl;
class ChalkboardBlockActor;
class ChunkPos;
class ChunkSource;
class ChunkViewSource;
class ComplexInventoryTransaction;
class CompoundTag;
class Container;
class ContainerManagerModel;
class DataLoadHelper;
class Dimension;
class EnderChestContainer;
class EntityContext;
class FrameUpdateContextBase;
class GameMode;
class GameServerToken;
class GetCollisionShapeInterface;
class HudContainerManagerModel;
class IConstBlockSource;
class IContainerManager;
class IMinecraftEventing;
class InventoryTransaction;
class Item;
class ItemDescriptor;
class ItemStack;
class ItemStackBase;
class ItemStackNetManagerBase;
class LayeredAbilities;
class LegacyTelemetryEventPacket;
class Level;
class NetworkChunkPublisher;
class NetworkIdentifier;
class Packet;
class PacketSender;
class PlayerEventCoordinator;
class PlayerInventory;
class PlayerListener;
class PlayerRespawnRandomizer;
class ResolvedTextObject;
class SerializedSkin;
class ShieldItem;
class SubChunkPos;
class TextObjectRoot;
class Vec2;
struct AABBShapeComponent;
struct ActorRotationComponent;
struct INpcDialogueData;
struct MutableAttributeWithContext;
struct PlayerDestroyProgressCacheComponent;
struct PlayerMovementSettings;
struct StateVectorComponent;
struct Tick;
struct VariantParameterList;
namespace Bedrock::PubSub::ThreadModel { struct SingleThreaded; }
namespace Editor { class IEditorPlayer; }
namespace mce { class Color; }
namespace mce { class UUID; }
// clang-format on

class ConnectionRequest;

class Player : public ::Mob { // Player类继承自Mob类
public:
    // Player inner types declare
    // Player 内部类型声明
    // clang-format off
        struct CachedSpawnData;                  // 缓存的生成数据
        struct FixedSpawnPositionData;           // 固定的生成位置数据
        struct FixedSpawnPositionData_DEPRECATED; // 已弃用的固定生成位置数据
        struct PlayerSpawnPoint;                 // 玩家重生点
    // clang-format on

    // Player inner types define
    // Player 内部类型定义
    using PlayerFlagIDType = char; // 定义玩家标志ID的类型为char

    // 已弃用的固定生成位置数据结构
    struct FixedSpawnPositionData_DEPRECATED {
    public:
        // member variables
        // 成员变量
        // NOLINTBEGIN
        ::ll::TypedStorage<4, 12, ::Vec3> mPosition;      // 位置
        ::ll::TypedStorage<1, 1, bool>    mIsAboveLeaves; // 是否在树叶上方
        // NOLINTEND
    };

    // 固定的生成位置数据结构
    struct FixedSpawnPositionData {
    public:
        // member variables
        // 成员变量
        // NOLINTBEGIN
        ::ll::TypedStorage<4, 12, ::Vec3>                   mPosition;          // 位置
        ::ll::TypedStorage<4, 4, ::PlayerSpawnFallbackType> mSpawnFallbackType; // 生成备用类型
        // NOLINTEND
    };

    // 玩家生成位置状态机枚举
    enum class SpawnPositionState : int {
        InitializeSpawnPositionRandomizer = 0, // 初始化生成位置随机化器
        WaitForClientAck                  = 1, // 等待客户端确认
        DetermineDimension                = 2, // 确定维度
        ChangeDimension                   = 3, // 改变维度
        WaitForDimension                  = 4, // 等待维度加载
        ChooseSpawnArea                   = 5, // 选择生成区域
        CheckLoadedChunk                  = 6, // 检查已加载的区块
        ChooseSpawnPosition               = 7, // 选择生成位置
        SpawnComplete                     = 8, // 生成完成
    };

    // 玩家生成位置来源枚举
    enum class SpawnPositionSource : int {
        Randomizer = 0, // 随机化器
        Respawn    = 1, // 重生
        Teleport   = 2, // 传送
        Static     = 3, // 静态
    };

    // 缓存的生成数据结构
    struct CachedSpawnData {
    public:
        // member variables
        // 成员变量
        // NOLINTBEGIN
        ::ll::TypedStorage<4, 4, ::DimensionType> mRespawnDimensionId;       // 重生维度ID
        ::ll::TypedStorage<4, 12, ::Vec3>         mActualRespawnPosition;    // 实际重生位置
        ::ll::TypedStorage<4, 12, ::BlockPos>     mRequestedRespawnPosition; // 请求的重生位置
        ::ll::TypedStorage<1, 1, bool>            mHasRespawnPosition;       // 是否有重生位置
        ::ll::TypedStorage<4, 12, ::BlockPos>     mSharedSpawnPosition;      // 共享的生成位置
        ::ll::TypedStorage<1, 1, bool>            mRespawnReady;             // 重生是否准备就绪
        ::ll::TypedStorage<4, 12, ::Vec3>         mPlayerPos;                // 玩家位置
        ::ll::TypedStorage<1, 1, bool>            mIsForcedRespawn;          // 是否为强制重生
        ::ll::TypedStorage<1, 1, bool>            mIsAdventure;              // 是否为冒险模式
        ::ll::TypedStorage<1, 1, bool>            mIsFlyingOrNotOverworld;   // 是否在飞行或不在主世界
        ::ll::TypedStorage<1, 1, bool>            mPositionLoadedFromSave;   // 位置是否从存档加载
        // NOLINTEND
    };

    using PlayerListenerList = ::std::vector<::PlayerListener*>; // 玩家监听器列表类型定义

    // 玩家重生点结构
    struct PlayerSpawnPoint {
    public:
        // member variables
        // 成员变量
        // NOLINTBEGIN
        ::ll::TypedStorage<4, 12, ::BlockPos>     mSpawnBlockPos;  // 重生点方块位置
        ::ll::TypedStorage<4, 12, ::BlockPos>     mPlayerPosition; // 玩家位置
        ::ll::TypedStorage<4, 4, ::DimensionType> mDimension;      // 维度
        // NOLINTEND

    public:
        // member functions
        // 成员函数
        // NOLINTBEGIN
        /**
         * @brief 设置重生点
         * @param playerPosition 玩家位置
         * @param dimension 维度
         * @param spawnBlock 重生点方块
         * @return 是否成功设置
         */
        MCNAPI bool
        setSpawnPoint(::BlockPos const& playerPosition, ::DimensionType dimension, ::BlockPos const& spawnBlock);
        // NOLINTEND
    };

public:
    // LLAPI / LLNDAPI 函数

    /**
     * @brief 获取用户实体标识符组件
     * @return 用户实体标识符组件的常量引用
     */
    LLNDAPI UserEntityIdentifierComponent const& getUserEntityIdentifier() const;

    /**
     * @brief 获取用户实体标识符组件
     * @return 用户实体标识符组件的引用
     */
    LLNDAPI UserEntityIdentifierComponent& getUserEntityIdentifier();

    /**
     * @brief 获取连接请求 (如果存在)
     * @return 连接请求的可选常量引用
     */
    LLNDAPI optional_ref<ConnectionRequest const> getConnectionRequest() const;

    /**
     * @brief 获取网络标识符
     * @return 网络标识符的常量引用
     */
    LLNDAPI NetworkIdentifier const& getNetworkIdentifier() const;

    /**
     * @brief 获取证书 (如果存在)
     * @return 证书的可选常量引用
     */
    LLNDAPI optional_ref<Certificate const> getCertificate() const;

    /**
     * @brief 获取客户端子ID
     * @return 客户端子ID的常量引用
     */
    LLNDAPI SubClientId const& getClientSubId() const;

    /**
     * @brief 获取当前选中的物品槽位索引
     * @return 物品槽位索引
     */
    LLNDAPI int getSelectedItemSlot() const;

    /**
     * @brief 获取玩家的UUID
     * @return 玩家的UUID
     */
    LLNDAPI mce::UUID const& getUuid() const;

    /**
     * @brief 获取玩家的IP地址和端口
     * @return 包含IP和端口的字符串
     */
    LLNDAPI std::string getIPAndPort() const;

    /**
     * @brief 获取玩家真实的游戏内昵称
     * @return 玩家的真实昵称
     */
    LLNDAPI std::string getRealName() const;

    /**
     * @brief 获取玩家的语言代码
     * @return 玩家的语言代码 (例如 "en_US")
     * @warning 这不是玩家的游戏内昵称。
     */
    LLNDAPI std::string getLocaleCode() const;

    /**
     * @brief 获取网络状态
     * @return 可选的网络状态
     */
    LLNDAPI std::optional<NetworkPeer::NetworkStatus> getNetworkStatus() const;

    /**
     * @brief 断开玩家客户端的连接
     * @param reason 断开连接的原因
     */
    LLAPI void disconnect(std::string_view reason) const;

    /**
     * @brief 向玩家发送一条消息
     * @param msg 要发送的消息内容
     */
    LLAPI void sendMessage(std::string_view msg) const;

    /**
     * @brief 设置玩家的能力
     * @param index 能力的索引 (见 AbilitiesIndex)
     * @param value 是否启用该能力
     */
    LLAPI void setAbility(::AbilitiesIndex index, bool value);

    /**
     * @brief 判断玩家是否为服务器管理员 (OP)
     * @return 如果是管理员则返回true，否则返回false
     * @warning 不会考虑自定义权限。
     */
    LLNDAPI bool isOperator() const;

    /**
     * @brief 给予玩家物品并刷新背包
     * @param item 要给予的物品堆栈
     * @return 操作是否完全成功 (例如，如果给予的物品数量与预期不符，则返回false)
     * @warning 返回值不考虑刷新是否成功。你可以使用 Player::add，但它不会刷新物品，可能导致潜在问题。
     */
    LLAPI bool addAndRefresh(class ItemStack& item);

    /**
     * @brief 获取末影箱容器 (如果存在)
     * @return 末影箱容器的可选引用
     */
    LLNDAPI optional_ref<EnderChestContainer> getEnderChestContainer() const;

public:
    // member variables
    // 成员变量
    // NOLINTBEGIN

    // 玩家已探索的海洋生物群系
    ::ll::TypedStorage<8, 24, ::std::vector<ushort>> mOceanBiomes;

    // 玩家已收集的蛙明灯类型
    ::ll::TypedStorage<8, 24, ::std::vector<ushort>> mFroglights;

    // 潜行时的高度
    ::ll::TypedStorage<4, 4, float const> mSneakHeight;

    // 潜行时的偏移量
    ::ll::TypedStorage<4, 4, float const> mSneakOffset;

    // 分数
    ::ll::TypedStorage<4, 4, int> mScore;

    // 玩家客户端的构建平台 (如 Win10, iOS, Android)
    ::ll::TypedStorage<4, 4, ::BuildPlatform> mBuildPlatform;

    // 唯一的名称 (通常是Xbox Live Gamertag)
    ::ll::TypedStorage<8, 32, ::std::string> mUniqueName;

    // 服务器ID
    ::ll::TypedStorage<8, 32, ::std::string> mServerId;

    // 自签名ID
    ::ll::TypedStorage<8, 32, ::std::string> mSelfSignedId;

    // 平台离线ID
    ::ll::TypedStorage<8, 32, ::std::string> mPlatformOfflineId;

    // 客户端随机ID
    ::ll::TypedStorage<8, 8, uint64> mClientRandomId;

    // 平台ID (如 Xbox Live XUID)
    ::ll::TypedStorage<8, 32, ::std::string> mPlatformId;

    // 等待骑乘的载具ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mPendingVehicleID;

    // 等待骑在左肩的生物ID (鹦鹉)
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mPendingLeftShoulderPassengerID;

    // 等待骑在右肩的生物ID (鹦鹉)
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mPendingRightShoulderPassengerID;

    // 交互的目标实体ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mInteractTarget;

    // 交互的目标位置
    ::ll::TypedStorage<4, 12, ::Vec3> mInteractTargetPos;

    // 是否有伪造的物品栏
    ::ll::TypedStorage<1, 1, bool> mHasFakeInventory;

    // 区域是否被挂起
    ::ll::TypedStorage<1, 1, bool> mIsRegionSuspended;

    // 是否更新生物
    ::ll::TypedStorage<1, 1, bool> mUpdateMobs;

    // 区块视图源 (玩家视野范围内的区块)
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::ChunkViewSource>> mChunkSource;

    // 生成点的区块视图源
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::ChunkViewSource>> mSpawnChunkSource;

    // 上一帧的披风位置
    ::ll::TypedStorage<4, 12, ::Vec3> mCapePosO;

    // 当前帧的披风位置
    ::ll::TypedStorage<4, 12, ::Vec3> mCapePos;

    // 容器管理器模型 (管理打开的容器，如箱子、工作台)
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::ContainerManagerModel>> mContainerManager;

    // 容器管理器事件的订阅者
    ::ll::TypedStorage<
        8,
        8,
        ::std::unique_ptr<
            ::Bedrock::PubSub::
                Publisher<void(::ContainerManagerModel const*), ::Bedrock::PubSub::ThreadModel::SingleThreaded, 0>>>
        mContainerManagerSubscribers;

    // 玩家物品栏
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::PlayerInventory>> mInventory;

    // 物品栏选项
    ::ll::TypedStorage<4, 20, ::InventoryOptions> mInventoryOptions;

    // 自上次发送变换事件以来的移动距离
    ::ll::TypedStorage<4, 4, float> mDistanceSinceTransformEvent;

    // 创造模式物品列表
    ::ll::TypedStorage<8, 24, ::std::vector<::ItemInstance>> mCreativeItemList;

    // 平台在线ID
    ::ll::TypedStorage<8, 32, ::std::string> mPlatformOnlineId;

    // 生成位置状态
    ::ll::TypedStorage<4, 4, ::Player::SpawnPositionState> mSpawnPositionState;

    // 生成位置来源
    ::ll::TypedStorage<4, 4, ::Player::SpawnPositionSource> mSpawnPositionSource;

    // 用于测试的生成位置
    ::ll::TypedStorage<4, 12, ::Vec3> mSpawnPositioningTestPosition;

    // 重生区块构建策略句柄
    ::ll::TypedStorage<4, 4, uint> mRespawnChunkBuilderPolicyHandle;

    // 缓存的生成数据
    ::ll::TypedStorage<4, 64, ::Player::CachedSpawnData> mCachedSpawnData;

    // 生成点的方块源
    ::ll::TypedStorage<8, 16, ::OwnerPtr<::BlockSource>> mSpawnBlockSource;

    // 重生时搜索位置的计时器
    ::ll::TypedStorage<8, 56, ::Stopwatch> mRespawnStopwatch_Searching;

    // 重生前的原始位置
    ::ll::TypedStorage<4, 12, ::Vec3> mRespawnOriginalPosition;

    // 重生前的原始维度
    ::ll::TypedStorage<4, 4, ::DimensionType> mRespawnOriginalDimension;

    // 重生消息
    ::ll::TypedStorage<8, 32, ::std::string> mRespawnMessage;

    // 重生是否准备就绪
    ::ll::TypedStorage<1, 1, bool> mRespawnReady;

    // 初始生成是否完成
    ::ll::TypedStorage<1, 1, bool> mIsInitialSpawnDone;

    // 是否从末地重生
    ::ll::TypedStorage<1, 1, bool> mRespawningFromTheEnd;

    // 位置是否从存档加载
    ::ll::TypedStorage<1, 1, bool> mPositionLoadedFromSave;

    // 是否阻止重生直到收到客户端消息
    ::ll::TypedStorage<1, 1, bool> mBlockRespawnUntilClientMessage;

    // 是否已看过终末之诗
    ::ll::TypedStorage<1, 1, bool> mHasSeenCredits;

    // 生成备用类型
    ::ll::TypedStorage<4, 8, ::std::optional<::PlayerSpawnFallbackType>> mSpawnFallbackType;

    // 生成备用位置
    ::ll::TypedStorage<4, 16, ::std::optional<::Vec3>> mSpawnFallbackPosition;

    // 正在使用的物品的信息
    ::ll::TypedStorage<8, 168, ::PlayerItemInUse> mItemInUse;

    // 上次伤害来源的Actor类型
    ::ll::TypedStorage<4, 4, ::ActorType> mLastHurtBy;

    // 上一个交互的实体ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mPreviousInteractEntity;

    // 上一个手持物品的槽位
    ::ll::TypedStorage<4, 4, int> mPreviousCarriedItem;

    // 表情播放的剩余刻数
    ::ll::TypedStorage<4, 4, int> mEmoteTicks;

    // 区块发布者视图
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::NetworkChunkPublisher>> mChunkPublisherView;

    // 数据包发送器
    ::ll::TypedStorage<8, 8, ::PacketSender&> mPacketSender;

    // HUD容器管理器模型
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::HudContainerManagerModel>> mHudContainerManagerModel;

    // 末影箱物品栏
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::EnderChestContainer>> mEnderChestInventory;

    // 追踪的Boss实体ID列表
    ::ll::TypedStorage<8, 24, ::std::vector<::ActorUniqueID>> mTrackedBossIDs;

    // 光标选中的物品组 (创造模式)
    ::ll::TypedStorage<8, 136, ::ItemGroup> mCursorSelectedItemGroup;

    // 玩家UI容器
    ::ll::TypedStorage<8, 440, ::PlayerUIContainer> mPlayerUIContainer;

    // 物品栏交易管理器
    ::ll::TypedStorage<8, 48, ::InventoryTransactionManager> mTransactionManager;

    // 游戏模式 (生存、创造等)
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::GameMode>> mGameMode;

    // 生成位置随机化器
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::PlayerRespawnRandomizer>> mSpawnRandomizer;

    // 玩家皮肤
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::SerializedSkin>> mSkin;

    // ItemStack网络管理器
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ItemStackNetManagerBase>> mItemStackNetManager;

    // UI动画组件
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::AnimationComponent>> mUIAnimationComponent;

    // 地图动画组件
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::AnimationComponent>> mMapAnimationComponent;

    // 玩家重生点
    ::ll::TypedStorage<4, 28, ::Player::PlayerSpawnPoint> mPlayerRespawnPoint;

    // 服务器构建比率
    ::ll::TypedStorage<4, 4, float> mServerBuildRatio;

    // 客户端子ID (用于分屏)
    ::ll::TypedStorage<1, 1, ::SubClientId> mClientId;

    // 交互数据是否需要同步
    ::ll::TypedStorage<1, 1, bool> mInteractDataDirty;

    // 是否应由客户端生成区块
    ::ll::TypedStorage<1, 1, bool> mShouldClientGenerateChunks;

    // 是否使用地图动画组件
    ::ll::TypedStorage<1, 1, bool> mUseMapAnimationComponent;

    // 是否延迟渲染第一人称对象
    ::ll::TypedStorage<1, 1, bool> mIsDeferredRenderingFirstPersonObjects;

    // 是否正在破坏方块
    ::ll::TypedStorage<1, 1, bool> mDestroyingBlock;

    // 玩家等级是否已改变
    ::ll::TypedStorage<1, 1, bool> mPlayerLevelChanged;

    // 上一个等级的需求经验
    ::ll::TypedStorage<4, 4, int> mPreviousLevelRequirement;

    // 上次升级的时间
    ::ll::TypedStorage<4, 4, int> mLastLevelUpTime;

    // 第一人称动画组件
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::AnimationComponent>> mFirstPersonAnimationComponent;

    // 监听器列表
    ::ll::TypedStorage<8, 24, ::std::vector<::PlayerListener*>> mListeners;

    // 候选的重生位置
    ::ll::TypedStorage<4, 12, ::Vec3> mRespawnPositionCandidate;

    // 维度传送前的生成位置
    ::ll::TypedStorage<4, 12, ::Vec3> mPreDimensionTransferSpawnPosition;

    // 附魔种子
    ::ll::TypedStorage<4, 4, int> mEnchantmentSeed;

    // 屏幕上的动画纹理
    ::ll::TypedStorage<8, 24, ::std::vector<uint>> mOnScreenAnimationTextures;

    // 屏幕上的动画剩余刻数
    ::ll::TypedStorage<4, 4, int> mOnScreenAnimationTicks;

    // 区块加载半径
    ::ll::TypedStorage<4, 4, uint> mChunkRadius;

    // 地图索引
    ::ll::TypedStorage<4, 4, int> mMapIndex;

    // 鞘翅飞行音量
    ::ll::TypedStorage<4, 4, float> mElytraVolume;

    // 鞘翅飞行循环音效ID
    ::ll::TypedStorage<8, 8, uint64> mElytraLoop;

    // 冷却时间表
    ::ll::TypedStorage<8, 64, ::std::unordered_map<::HashedString, int>> mCooldowns;

    // 原版物品的冷却时间表
    ::ll::TypedStorage<8, 64, ::std::unordered_map<::HashedString, ::HashedString>> mVanillaCooldowns;

    // 开始格挡的时间戳
    ::ll::TypedStorage<8, 8, int64> mStartedBlockingTimeStamp;

    // 使用盾牌格挡的时间戳
    ::ll::TypedStorage<8, 8, int64> mBlockedUsingShieldTimeStamp;

    // 使用受损盾牌格挡的时间戳
    ::ll::TypedStorage<8, 8, int64> mBlockedUsingDamagedShieldTimeStamp;

    // 玩家名称
    ::ll::TypedStorage<8, 32, ::std::string> mName;

    // 上一个播放的表情
    ::ll::TypedStorage<8, 32, ::std::string> mLastEmotePlayed;

    // 表情彩蛋结束时间
    ::ll::TypedStorage<8, 8, int64> mEmoteEasterEggEndTime;

    // 表情消息计数
    ::ll::TypedStorage<4, 4, uint> mEmoteMessageCount;

    // 设备ID
    ::ll::TypedStorage<8, 32, ::std::string> mDeviceId;

    // 是否为客户端标记BAI重置
    ::ll::TypedStorage<1, 1, bool> mFlagClientForBAIReset;

    // 是否向客户端发送物品栏选项
    ::ll::TypedStorage<1, 1, bool> mSendInventoryOptionsToClient;

    // 是否是主机玩家
    ::ll::TypedStorage<1, 1, bool> mIsHostingPlayer;

    // 上一帧是否在使用盾牌格挡
    ::ll::TypedStorage<1, 1, bool> mPrevBlockedUsingShield;

    // 上一帧是否在使用受损盾牌格挡
    ::ll::TypedStorage<1, 1, bool> mPrevBlockedUsingDamagedShield;

    // 是否使用过药水
    ::ll::TypedStorage<1, 1, bool> mUsedPotion;

    // 破坏进度缓存组件
    ::ll::TypedStorage<8, 8, ::PlayerDestroyProgressCacheComponent&> mDestroyProgressCache;

    // NOLINTEND

public:
    // prevent constructor by default
    // 默认禁止拷贝构造和赋值
    Player& operator=(Player const&);
    Player(Player const&);
    Player();

public:
    // virtual functions
    // 虚函数
    // NOLINTBEGIN

    // vIndex: 0
    /**
     * @brief 析构函数
     */
    virtual ~Player() /*override*/;

    // vIndex: 4
    /**
     * @brief 初始化组件 (重写 Actor)
     */
    virtual void
    initializeComponents(::ActorInitializationMethod method, ::VariantParameterList const& params) /*override*/;

    // vIndex: 2
    /**
     * @brief 重新加载硬编码数据 (重写 Actor)
     */
    virtual void reloadHardcoded(::ActorInitializationMethod method, ::VariantParameterList const& params) /*override*/;

    // vIndex: 177
    /**
     * @brief 准备区域 (加载玩家周围的区块)
     * @param mainChunkSource 主区块源
     */
    virtual void prepareRegion(::ChunkSource& mainChunkSource);

    // vIndex: 178
    /**
     * @brief 销毁区域 (卸载玩家周围的区块)
     */
    virtual void destroyRegion();

    // vIndex: 179
    /**
     * @brief 挂起区域
     */
    virtual void suspendRegion();

    // vIndex: 180
    /**
     * @brief 触发维度改变事件
     */
    virtual void _fireDimensionChanged();

    // vIndex: 88
    /**
     * @brief 判断是否能使用传送门改变维度 (重写 Actor)
     */
    virtual bool canChangeDimensionsUsingPortal() const /*override*/;

    // vIndex: 181
    /**
     * @brief 带着终末之诗改变维度
     * @param dimensionType 目标维度
     */
    virtual void changeDimensionWithCredits(::DimensionType);

    // vIndex: 182
    /**
     * @brief 进行世界相关的更新 (World Tick)
     * @param tick 当前游戏刻信息
     */
    virtual void tickWorld(::Tick const&);

    // vIndex: 183
    /**
     * @brief 帧更新 (纯虚函数，由子类实现)
     */
    virtual void frameUpdate(::FrameUpdateContextBase&) = 0;

    // vIndex: 184
    /**
     * @brief 获取需要进行Tick更新的区块偏移列表
     */
    virtual ::std::vector<::ChunkPos> const& getTickingOffsets() const;

    // vIndex: 24
    /**
     * @brief 普通的游戏刻更新 (重写 Actor)
     */
    virtual void normalTick() /*override*/;

    // vIndex: 185
    /**
     * @brief 移动视角
     */
    virtual void moveView();

    // vIndex: 186
    /**
     * @brief 移动生成点视角
     * @param spawnPosition 生成位置
     * @param dimensionType 维度类型
     */
    virtual void moveSpawnView(::Vec3 const& spawnPosition, ::DimensionType dimensionType);

    // vIndex: 93
    /**
     * @brief 当同步数据更新时调用 (重写 Actor)
     */
    virtual void onSynchedDataUpdate(int dataId) /*override*/;

    // vIndex: 145
    /**
     * @brief AI逻辑步进 (重写 Mob)
     */
    virtual void aiStep() /*override*/;

    // vIndex: 18
    /**
     * @brief 判断是否防火 (重写 Actor)
     */
    virtual bool isFireImmune() const /*override*/;

    // vIndex: 187
    /**
     * @brief 检查移动统计数据 (如行走、游泳距离)
     */
    virtual void checkMovementStats(::Vec3 const&);

    // vIndex: 188
    /**
     * @brief 获取当前所在的结构特征
     */
    virtual ::HashedString getCurrentStructureFeature() const;

    // vIndex: 189
    /**
     * @brief 判断是否启用了自动跳跃
     */
    virtual bool isAutoJumpEnabled() const;

    // vIndex: 17
    /**
     * @brief 获取插值计算后的骑乘偏移量 (重写 Actor)
     */
    virtual ::Vec3 getInterpolatedRidingOffset(float, int const) const /*override*/;

    // vIndex: 26
    /**
     * @brief 作为乘客时的游戏刻更新 (重写 Actor)
     */
    virtual void passengerTick() /*override*/;

    // vIndex: 123
    /**
     * @brief 死亡处理 (重写 Actor)
     */
    virtual void die(::ActorDamageSource const& source) /*override*/;

    // vIndex: 11
    /**
     * @brief 移除玩家 (重写 Actor)
     */
    virtual void remove() /*override*/;

    // vIndex: 190
    /**
     * @brief 重生
     */
    virtual void respawn();

    // vIndex: 124
    /**
     * @brief 判断死亡时是否应掉落战利品 (重写 Actor)
     */
    virtual bool shouldDropDeathLoot() const /*override*/;

    // vIndex: 163
    /**
     * @brief 死亡时掉落装备 (重写 Mob)
     */
    virtual void dropEquipmentOnDeath(::ActorDamageSource const& source) /*override*/;

    // vIndex: 162
    /**
     * @brief 死亡时掉落装备 (重写 Mob)
     */
    virtual void dropEquipmentOnDeath() /*override*/;

    // vIndex: 164
    /**
     * @brief 死亡时清除带有消失诅咒的物品 (重写 Mob)
     */
    virtual void clearVanishEnchantedItemsOnDeath() /*override*/;

    // vIndex: 117
    /**
     * @brief 掉落物品 (重写 Actor)
     */
    virtual bool drop(::ItemStack const& item, bool const randomly) /*override*/;


    // vIndex: 191
    /**
     * @brief 重置旋转
     */
    virtual void resetRot();

    // vIndex: 9
    /**
     * @brief 重置玩家位置 (重写 Actor)
     */
    virtual void resetUserPos(::ActorResetRule resetRule) /*override*/;

    // vIndex: 192
    /**
     * @brief 判断是否在试玩模式
     */
    virtual bool isInTrialMode();

    // vIndex: 143
    /**
     * @brief 设置速度 (重写 Mob)
     */
    virtual void setSpeed(float speed) /*override*/;

    // vIndex: 149
    /**
     * @brief 获取物品使用时长 (重写 Mob)
     */
    virtual int getItemUseDuration() const /*override*/;

    // vIndex: 150
    /**
     * @brief 获取物品使用开始进度 (重写 Mob)
     */
    virtual float getItemUseStartupProgress() const /*override*/;

    // vIndex: 151
    /**
     * @brief 获取物品使用间隔进度 (重写 Mob)
     */
    virtual float getItemUseIntervalProgress() const /*override*/;

    // vIndex: 45
    /**
     * @brief 判断是否在格挡 (重写 Actor)
     */
    virtual bool isBlocking() const /*override*/;

    // vIndex: 46
    /**
     * @brief 判断伤害是否被格挡 (重写 Actor)
     */
    virtual bool isDamageBlocked(::ActorDamageSource const& source) const /*override*/;

    // vIndex: 69
    /**
     * @brief 处理实体事件 (重写 Actor)
     */
    virtual void handleEntityEvent(::ActorEvent eventId, int data) /*override*/;

    // vIndex: 160
    /**
     * @brief 获取所有手部物品 (主手和副手) (重写 Mob)
     */
    virtual ::std::vector<::ItemStack const*> getAllHand() const /*override*/;

    // vIndex: 161
    /**
     * @brief 获取所有装备 (盔甲和手部) (重写 Mob)
     */
    virtual ::std::vector<::ItemStack const*> getAllEquipment() const /*override*/;

    // vIndex: 116
    /**
     * @brief 添加物品到物品栏 (重写 Actor)
     */
    virtual bool add(::ItemStack& item) /*override*/;

    // vIndex: 103
    /**
     * @brief 获取命令权限等级 (重写 Actor)
     */
    virtual ::CommandPermissionLevel getCommandPermissionLevel() const /*override*/;

    // vIndex: 53
    /**
     * @brief 攻击另一个Actor (重写 Actor)
     */
    virtual bool attack(::Actor&, ::SharedTypes::Legacy::ActorDamageCause const&) /*override*/;

    // vIndex: 78
    /**
     * @brief 获取手持物品 (重写 Actor)
     */
    virtual ::ItemStack const& getCarriedItem() const /*override*/;

    // vIndex: 77
    /**
     * @brief 设置手持物品 (重写 Actor)
     */
    virtual void setCarriedItem(::ItemStack const& item) /*override*/;

    // vIndex: 193
    /**
     * @brief 打开作品集 (教育版功能)
     */
    virtual void openPortfolio();

    // vIndex: 194
    /**
     * @brief 打开书
     */
    virtual void openBook(int, bool, int, ::BlockActor*);

    // vIndex: 195
    /**
     * @brief 打开交易界面
     */
    virtual void openTrading(::ActorUniqueID const&, bool);

    // vIndex: 196
    /**
     * @brief 打开黑板 (教育版功能)
     */
    virtual void openChalkboard(::ChalkboardBlockActor&, bool);

    // vIndex: 197
    /**
     * @brief 打开NPC交互界面
     */
    virtual void openNpcInteractScreen(::std::shared_ptr<::INpcDialogueData> npc);

    // vIndex: 198
    /**
     * @brief 打开物品栏
     */
    virtual void openInventory();

    // vIndex: 199
    /**
     * @brief 显示聊天消息
     */
    virtual void displayChatMessage(
        ::std::string const&                 author,
        ::std::string const&                 message,
        ::std::optional<::std::string> const filteredMessage
    );

    // vIndex: 200
    /**
     * @brief 显示客户端消息 (通常是系统消息)
     */
    virtual void
    displayClientMessage(::std::string const& message, ::std::optional<::std::string> const filteredMessage);

    // vIndex: 201
    /**
     * @brief 显示文本对象消息 (JSON格式的消息)
     */
    virtual void displayTextObjectMessage(
        ::TextObjectRoot const& textObject,
        ::std::string const&    fromXuid,
        ::std::string const&    fromPlatformId
    );

    // vIndex: 203
    /**
     * @brief 显示文本对象私聊消息 (ResolvedTextObject版本)
     */
    virtual void displayTextObjectWhisperMessage(
        ::ResolvedTextObject const& resolvedTextObject,
        ::std::string const&        xuid,
        ::std::string const&        platformId
    );

    // vIndex: 202
    /**
     * @brief 显示文本对象私聊消息 (字符串版本)
     */
    virtual void displayTextObjectWhisperMessage(
        ::std::string const& message,
        ::std::string const& xuid,
        ::std::string const& platformId
    );

    // vIndex: 204
    /**
     * @brief 显示私聊消息
     */
    virtual void displayWhisperMessage(
        ::std::string const&                 author,
        ::std::string const&                 message,
        ::std::optional<::std::string> const filteredMessage,
        ::std::string const&                 xuid,
        ::std::string const&                 platformId
    );

    // vIndex: 35
    /**
     * @brief 获取阴影半径 (重写 Actor)
     */
    virtual float getShadowRadius() const /*override*/;

    // vIndex: 42
    /**
     * @brief 判断是否在睡觉 (重写 Actor)
     */
    virtual bool isSleeping() const /*override*/;

    // vIndex: 43
    /**
     * @brief 设置睡眠状态 (重写 Actor)
     */
    virtual void setSleeping(bool val) /*override*/;

    // vIndex: 205
    /**
     * @brief 开始在床上睡觉
     */
    virtual ::BedSleepingResult startSleepInBed(::BlockPos const& bedBlockPos);

    // vIndex: 206
    /**
     * @brief 停止在床上睡觉
     */
    virtual void stopSleepInBed(bool forcefulWakeUp, bool updateLevelList);

    // vIndex: 207
    /**
     * @brief 判断是否可以开始睡觉
     */
    virtual bool canStartSleepInBed();

    // vIndex: 165
    /**
     * @brief 发送物品栏 (重写 Mob)
     */
    virtual void sendInventory(bool) /*override*/;

    // vIndex: 208
    /**
     * @brief 打开告示牌编辑界面
     */
    virtual void openSign(::BlockPos const&, bool);

    // vIndex: 209
    /**
     * @brief 播放表情
     */
    virtual void playEmote(::std::string const&, bool const);

    // vIndex: 41
    /**
     * @brief 判断是否为沉默的观察者 (重写 Actor)
     */
    virtual bool isSilentObserver() const /*override*/;

    // vIndex: 112
    /**
     * @brief 使用物品 (重写 Actor)
     */
    virtual void useItem(::ItemStackBase& item, ::ItemUseMethod itemUseMethod, bool consumeItem) /*override*/;

    // vIndex: 210
    /**
     * @brief 判断是否正在加载中
     */
    virtual bool isLoading() const;

    // vIndex: 211
    /**
     * @brief 判断玩家是否已初始化完成
     */
    virtual bool isPlayerInitialized() const;

    // vIndex: 212
    /**
     * @brief 停止加载
     */
    virtual void stopLoading();

    // vIndex: 142
    /**
     * @brief 获取速度 (重写 Mob)
     */
    virtual float getSpeed() const /*override*/;

    // vIndex: 213
    /**
     * @brief 设置玩家游戏模式
     */
    virtual void setPlayerGameType(::GameType);

    // vIndex: 214
    /**
     * @brief 初始化HUD容器管理器
     */
    virtual void initHUDContainerManager();

    // vIndex: 215
    /**
     * @brief 对目标造成暴击
     */
    virtual void _crit(::Actor& actor);

    // vIndex: 40
    /**
     * @brief 判断是否无法移动 (重写 Actor)
     */
    virtual bool isImmobile() const /*override*/;

    // vIndex: 98
    /**
     * @brief 如果需要，发送移动数据包 (重写 Actor)
     */
    virtual void sendMotionPacketIfNeeded() /*override*/;

    // vIndex: 216
    /**
     * @brief 获取事件系统接口
     */
    virtual ::IMinecraftEventing* getEventing() const;

    // vIndex: 217
    /**
     * @brief 获取用户ID (已废弃)
     */
    virtual uint getUserId() const;

    // vIndex: 218
    /**
     * @brief 增加经验值
     */
    virtual void addExperience(int xp);

    // vIndex: 219
    /**
     * @brief 增加等级
     */
    virtual void addLevels(int levels);

    // vIndex: 72
    /**
     * @brief 设置盔甲 (重写 Actor)
     */
    virtual void setArmor(::SharedTypes::Legacy::ArmorSlot slot, ::ItemStack const& item) /*override*/;

    // vIndex: 79
    /**
     * @brief 设置副手物品 (重写 Actor)
     */
    virtual void setOffhandSlot(::ItemStack const& item) /*override*/;

    // vIndex: 23
    /**
     * @brief 尝试创建添加Actor的数据包 (重写 Actor)
     */
    virtual ::std::unique_ptr<::AddActorBasePacket> tryCreateAddActorPacket() /*override*/;

    // vIndex: 64
    /**
     * @brief 判断是否对某个伤害源无敌 (重写 Actor)
     */
    virtual bool isInvulnerableTo(::ActorDamageSource const& source) const /*override*/;

    // vIndex: 220
    /**
     * @brief 设置容器数据 (纯虚函数)
     */
    virtual void setContainerData(::IContainerManager&, int, int) = 0;

    // vIndex: 221
    /**
     * @brief 容器中槽位发生变化时调用 (纯虚函数)
     */
    virtual void slotChanged(::IContainerManager&, ::Container&, int, ::ItemStack const&, ::ItemStack const&, bool) = 0;

    // vIndex: 222
    /**
     * @brief 刷新容器 (纯虚函数)
     */
    virtual void refreshContainer(::IContainerManager&) = 0;

    // vIndex: 223
    /**
     * @brief 删除容器管理器
     */
    virtual void deleteContainerManager();

    // vIndex: 80
    /**
     * @brief 获取装备的图腾 (重写 Actor)
     */
    virtual ::ItemStack const& getEquippedTotem() const /*override*/;

    // vIndex: 81
    /**
     * @brief 消耗图腾 (重写 Actor)
     */
    virtual bool consumeTotem() /*override*/;

    // vIndex: 224
    /**
     * @brief 判断一个Actor是否与此玩家相关 (例如，是否在视野内)
     */
    virtual bool isActorRelevant(::Actor const&);

    // vIndex: 114
    /**
     * @brief 获取在地图上的装饰物旋转角度 (重写 Actor)
     */
    virtual float getMapDecorationRotation() const /*override*/;

    // vIndex: 21
    /**
     * @brief 传送到指定位置 (重写 Actor)
     */
    virtual void teleportTo(
        ::Vec3 const& pos,
        bool          shouldStopRiding,
        int           cause,
        int           sourceEntityType,
        bool          keepVelocity
    ) /*override*/;

    // vIndex: 27
    /**
     * @brief 开始骑乘 (重写 Actor)
     */
    virtual bool startRiding(::Actor& vehicle, bool forceRiding) /*override*/;

    // vIndex: 100
    /**
     * @brief 开始游泳 (重写 Actor)
     */
    virtual void startSwimming() /*override*/;

    // vIndex: 101
    /**
     * @brief 停止游泳 (重写 Actor)
     */
    virtual void stopSwimming() /*override*/;

    // vIndex: 225
    /**
     * @brief 判断是否是教师 (教育版功能，纯虚函数)
     */
    virtual bool isTeacher() const = 0;

    // vIndex: 226
    /**
     * @brief 当被挂起时调用
     */
    virtual void onSuspension();

    // vIndex: 227
    /**
     * @brief 当链接的槽位改变时调用
     */
    virtual void onLinkedSlotsChanged();

    // vIndex: 96
    /**
     * @brief 判断是否能被拉入载具 (重写 Actor)
     */
    virtual bool canBePulledIntoVehicle() const /*override*/;

    // vIndex: 68
    /**
     * @brief 喂食 (重写 Actor)
     */
    virtual void feed(int itemId) /*override*/;

    // vIndex: 228
    /**
     * @brief 发送物品栏交易 (纯虚函数)
     */
    virtual void sendInventoryTransaction(::InventoryTransaction const&) const = 0;

    // vIndex: 229
    /**
     * @brief 发送复杂的物品栏交易 (纯虚函数)
     */
    virtual void sendComplexInventoryTransaction(::std::unique_ptr<::ComplexInventoryTransaction>) const = 0;

    // vIndex: 230
    /**
     * @brief 发送网络数据包
     */
    virtual void sendNetworkPacket(::Packet& packet) const;

    // vIndex: 172
    /**
     * @brief 判断在禁止生物生成时是否可以存在 (重写 Mob)
     */
    virtual bool canExistWhenDisallowMob() const /*override*/;

    // vIndex: 34
    /**
     * @brief 获取名字标签文本颜色 (重写 Actor)
     */
    virtual ::mce::Color getNameTagTextColor() const /*override*/;

    // vIndex: 94
    /**
     * @brief 判断是否可以添加乘客 (重写 Actor)
     */
    virtual bool canAddPassenger(::Actor& passenger) const /*override*/;

    // vIndex: 231
    /**
     * @brief 获取玩家事件协调器 (纯虚函数)
     */
    virtual ::PlayerEventCoordinator& getPlayerEventCoordinator() = 0;

    // vIndex: 232
    /**
     * @brief 判断是否是模拟玩家
     */
    virtual bool isSimulated() const;

    // vIndex: 233
    /**
     * @brief 获取XUID
     */
    virtual ::std::string getXuid() const;

    // vIndex: 234
    /**
     * @brief 获取移动设置
     */
    virtual ::PlayerMovementSettings const& getMovementSettings() const;

    // vIndex: 85
    /**
     * @brief 判断是否能被冻结 (重写 Actor)
     */
    virtual bool canFreeze() const /*override*/;

    // vIndex: 37
    /**
     * @brief 判断是否能与游戏中的其他实体交互 (重写 Actor)
     */
    virtual bool canInteractWithOtherEntitiesInGame() const /*override*/;

    // vIndex: 108
    /**
     * @brief 判断是否能阻碍生成和方块放置 (重写 Actor)
     */
    virtual bool canObstructSpawningAndBlockPlacement() const /*override*/;

    // vIndex: 127
    /**
     * @brief 获取上次死亡位置 (重写 Actor)
     */
    virtual ::std::optional<::BlockPos> getLastDeathPos() const /*override*/;

    // vIndex: 128
    /**
     * @brief 获取上次死亡维度 (重写 Actor)
     */
    virtual ::std::optional<::DimensionType> getLastDeathDimension() const /*override*/;

    // vIndex: 129
    /**
     * @brief 判断之前是否死亡过 (重写 Actor)
     */
    virtual bool hasDiedBefore() const /*override*/;

    // vIndex: 130
    /**
     * @brief 执行入水溅水效果 (重写 Actor)
     */
    virtual void doEnterWaterSplashEffect() /*override*/;

    // vIndex: 131
    /**
     * @brief 执行出水溅水效果 (重写 Actor)
     */
    virtual void doExitWaterSplashEffect() /*override*/;

    // vIndex: 235
    /**
     * @brief 请求缺失的子区块
     */
    virtual void requestMissingSubChunk(::SubChunkPos const&);

    // vIndex: 236
    /**
     * @brief 获取最大区块构建半径
     */
    virtual uchar getMaxChunkBuildRadius() const;

    // vIndex: 92
    /**
     * @brief 对Actor造成摔落伤害 (重写 Actor)
     */
    virtual float causeFallDamageToActor(float distance, float multiplier, ::ActorDamageSource source) /*override*/;

    // vIndex: 135
    /**
     * @brief 内部受伤处理 (重写 Actor)
     */
    virtual bool _hurt(::ActorDamageSource const& source, float damage, bool knock, bool ignite) /*override*/;

    // vIndex: 136
    /**
     * @brief 读取额外的存档数据 (重写 Actor)
     */
    virtual void readAdditionalSaveData(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper) /*override*/;

    // vIndex: 137
    /**
     * @brief 添加额外的存档数据 (重写 Actor)
     */
    virtual void addAdditionalSaveData(::CompoundTag& entityTag) const /*override*/;

    // vIndex: 237
    /**
     * @brief 处理普通移动数据包
     */
    virtual void onMovePlayerPacketNormal(::Vec3 const& pos, ::Vec2 const& rot, float yHeadRot);

    // vIndex: 133
    /**
     * @brief 判断在手部容器物品设置时是否应提供反馈 (重写 Actor)
     */
    virtual bool _shouldProvideFeedbackOnHandContainerItemSet(::HandSlot handSlot, ::ItemStack const& item) const
        /*override*/;

    // vIndex: 134
    /**
     * @brief 判断在盔甲设置时是否应提供反馈 (重写 Actor)
     */
    virtual bool _shouldProvideFeedbackOnArmorSet(::SharedTypes::Legacy::ArmorSlot slot, ::ItemStack const& item) const
        /*override*/;

    // vIndex: 238
    /**
     * @brief 创建区块源
     */
    virtual ::std::shared_ptr<::ChunkViewSource> _createChunkSource(::ChunkSource& mainChunkSource);

    // vIndex: 239
    /**
     * @brief 设置能力
     */
    virtual void setAbilities(::LayeredAbilities const& newAbilities);

    // vIndex: 109
    /**
     * @brief 获取动画组件 (重写 Actor)
     */
    virtual ::AnimationComponent& getAnimationComponent() /*override*/;

    // vIndex: 70
    /**
     * @brief 获取Actor渲染器ID (重写 Actor)
     */
    virtual ::HashedString const& getActorRendererId() const /*override*/;

    // vIndex: 240
    /**
     * @brief 获取编辑器玩家接口 (纯虚函数, 编辑器功能)
     */
    virtual ::Bedrock::NonOwnerPointer<::Editor::IEditorPlayer> getEditorPlayer() const = 0;

    // vIndex: 241
    /**
     * @brief 销毁编辑器玩家 (纯虚函数, 编辑器功能)
     */
    virtual void destroyEditorPlayer() = 0;

    // vIndex: 6
    /**
     * @brief 服务器端初始化ItemStack ID (重写 Actor)
     */
    virtual void _serverInitItemStackIds() /*override*/;

    // vIndex: 174
    /**
     * @brief 初始化身体控制器 (重写 Mob)
     */
    virtual ::std::unique_ptr<::BodyControl> initBodyControl() /*override*/;
    // NOLINTEND

public:
    // member functions
    // 成员函数
    // NOLINTBEGIN

    /**
     * @brief Player 构造函数
     * @param level 关卡
     * @param packetSender 数据包发送器
     * @param playerGameType 玩家游戏模式
     * @param isHostingPlayer 是否是主机玩家
     * @param owner 网络标识符
     * @param subid 子客户端ID
     * @param uuid 玩家UUID
     * @param playFabId PlayFab ID
     * @param deviceId 设备ID
     * @param gameServerToken 游戏服务器令牌
     * @param entityContext 实体上下文
     * @param platformId 平台ID
     * @param platformOnlineId 平台在线ID
     */
    MCAPI Player(
        ::Level&                   level,
        ::PacketSender&            packetSender,
        ::GameType                 playerGameType,
        bool                       isHostingPlayer,
        ::NetworkIdentifier const& owner,
        ::SubClientId              subid,
        ::mce::UUID                uuid,
        ::std::string const&       playFabId,
        ::std::string const&       deviceId,
        ::GameServerToken const&   gameServerToken,
        ::EntityContext&           entityContext,
        ::std::string const&       platformId,
        ::std::string const&       platformOnlineId
    );

    /**
     * @brief 内部方法，增加玩家等级
     * @param levels 增加的等级数
     */
    MCAPI void _addLevels(int levels);

    /**
     * @brief 内部方法，攻击一个实体
     * @param actor 目标实体
     * @param cause 伤害原因
     * @param doPredictiveSound 是否播放预测性音效
     * @return 攻击是否成功
     */
    MCAPI bool _attack(::Actor& actor, ::SharedTypes::Legacy::ActorDamageCause const& cause, bool doPredictiveSound);

    /**
     * @brief 内部方法，使用盾牌格挡
     * @param source 伤害源
     * @param damage 伤害值
     * @return 是否成功格挡
     */
    MCAPI bool _blockUsingShield(::ActorDamageSource const& source, float damage);

    /**
     * @brief 内部方法，检查并修正生成位置
     * @param spawnPosition 生成位置 (输入输出)
     * @param regions 区域列表
     * @param adjustYToSolidGround 是否调整Y坐标到坚实地面
     * @param searchUp 是否向上搜索
     * @param positionFromSave 位置是否来自存档
     * @return 是否成功找到并修正位置
     */
    MCAPI bool _checkAndFixSpawnPosition(
        ::Vec3&                                        spawnPosition,
        ::std::vector<::gsl::not_null<::BlockSource*>> regions,
        bool                                           adjustYToSolidGround,
        bool                                           searchUp,
        bool                                           positionFromSave
    );

    /**
     * @brief 内部方法，选择生成区域
     */
    MCAPI void _chooseSpawnArea();

    /**
     * @brief 内部方法，在生成区域内选择生成位置
     * @return 是否成功选择
     */
    MCAPI bool _chooseSpawnPositionWithinArea();

    /**
     * @brief 内部方法，确保生成位置安全
     * @param pos 位置 (输入输出)
     */
    MCAPI void _ensureSafeSpawnPosition(::Vec3& pos);

    /**
     * @brief 内部方法，寻找备用的生成位置
     * @param spawnPosition 生成位置 (输入输出)
     * @param regions 区域列表
     * @param maxDistance 最大搜索距离
     * @param checkStoredFallback 是否检查已存储的备用位置
     * @return 是否成功找到
     */
    MCAPI bool _findFallbackSpawnPosition(
        ::Vec3&                                        spawnPosition,
        ::std::vector<::gsl::not_null<::BlockSource*>> regions,
        uint                                           maxDistance,
        bool                                           checkStoredFallback
    );

    /**
     * @brief 内部方法，寻找有足够垂直空间的有效位置
     * @param spawnPosition 搜索起始位置
     * @return 可选的有效位置
     */
    MCAPI ::std::optional<::BlockPos> _findValidPosWithVerticalSpace(::BlockPos spawnPosition);

    /**
     * @brief 内部方法，处理手持物品的交互文本
     */
    MCAPI void _handleCarriedItemInteractText();

    /**
     * @brief 内部方法，检查区块源是否已加载
     * @param spawnPosition 生成位置
     * @param region 方块源
     * @return 如果已加载则返回true
     */
    MCAPI bool _isChunkSourceLoaded(::Vec3 const& spawnPosition, ::BlockSource const& region) const;

    /**
     * @brief 内部方法，从NBT加载物品栏选项
     * @param tag NBT数据
     */
    MCAPI void _loadInventoryOptions(::CompoundTag const& tag);

    /**
     * @brief 内部方法，在生成前构建生成数据缓存
     */
    MCAPI void _preSpawnBuildSpawnDataCache();

    /**
     * @brief 内部方法，注册鞘翅飞行的循环音效
     */
    MCAPI void _registerElytraLoopSound();

    /**
     * @brief 内部方法，注册玩家属性 (如饥饿、饱和度等)
     */
    MCAPI void _registerPlayerAttributes();

    /**
     * @brief 内部方法，重置客户端动画
     */
    MCAPI void _resetClientAnimations();

    /**
     * @brief 内部方法，保存物品栏选项到NBT
     * @param tag 输出的NBT标签
     */
    MCAPI void _saveInventoryOptions(::CompoundTag& tag) const;

    /**
     * @brief 内部方法，发送盾牌更新数据包
     * @param shieldItem 盾牌物品
     * @param before 更新前的物品
     * @param after 更新后的物品
     * @param container 容器ID
     * @param slot 槽位
     */
    MCAPI void _sendShieldUpdatePacket(
        ::ShieldItem const& shieldItem,
        ::ItemStack const&  before,
        ::ItemStack const&  after,
        ::ContainerID       container,
        int                 slot
    );

    /**
     * @brief 内部方法，设置玩家游戏模式
     * @param gameType 游戏模式
     */
    MCAPI void _setPlayerGameType(::GameType gameType);

    /**
     * @brief 内部方法，判断对目标攻击是否应为暴击
     * @param target 目标实体
     * @return 如果应为暴击则返回true
     */
    MCAPI bool _shouldCrit(::Actor const& target) const;

    /**
     * @brief 内部方法，更新交互状态
     */
    MCAPI void _updateInteraction();

    /**
     * @brief 内部方法，验证生成位置的可用性
     * @param pos 位置
     * @param blockSourceChunkCheck 用于检查的方块源
     * @param AABBoffset 碰撞箱偏移
     * @return 如果可用则返回true
     */
    MCAPI bool _validateSpawnPositionAvailability(
        ::Vec3 const&       pos,
        ::BlockSource*      blockSourceChunkCheck,
        ::Vec3 const* const AABBoffset
    ) const;

    /**
     * @brief 判断玩家是否能在地图上被看到
     * @return 如果能则返回true
     */
    MCAPI bool canBeSeenOnMap() const;

    /**
     * @brief 判断玩家是否可以跳跃
     * @return 如果可以则返回true
     */
    MCAPI bool canJump();

    /**
     * @brief 判断玩家是否可以打开容器界面
     * @return 如果可以则返回true
     */
    MCAPI bool canOpenContainerScreen();

    /**
     * @brief 判断玩家是否可以睡觉
     * @return 如果可以则返回true
     */
    MCAPI bool canSleep() const;

    /**
     * @brief 判断一个物品是否可以堆叠在副手
     * @param item 物品
     * @return 如果可以则返回true
     */
    MCAPI bool canStackInOffhand(::ItemStack const& item) const;

    /**
     * @brief 判断玩家是否可以使用指定能力
     * @param abilityIndex 能力索引
     * @return 如果可以使用则返回true
     */
    MCAPI bool canUseAbility(::AbilitiesIndex abilityIndex) const;

    /**
     * @brief 判断玩家是否可以使用OP方块 (命令方块等)
     * @return 如果可以则返回true
     */
    MCAPI bool canUseOperatorBlocks() const;

    /**
     * @brief 消耗食物饱食度
     * @param exhaustionAmount 消耗量
     */
    MCAPI void causeFoodExhaustion(float exhaustionAmount);

    /**
     * @brief 检查床是否有效
     * @param spawnBlockSource 生成点的方块源
     * @param positionToCheck 要检查的位置
     * @return 如果床有效则返回true
     */
    MCAPI bool checkBed(::BlockSource* spawnBlockSource, ::Vec3 const* const positionToCheck);

    /**
     * @brief 检查是否需要自动跳跃
     * @param inputMoveX X轴移动输入
     * @param inputMoveZ Z轴移动输入
     * @return 如果需要则返回true
     */
    MCAPI bool checkNeedAutoJump(float inputMoveX, float inputMoveZ);

    /**
     * @brief 检查生成点方块是否有效
     * @param region 区域
     * @return 如果有效则返回true
     */
    MCAPI bool checkSpawnBlock(::BlockSource const& region) const;

    /**
     * @brief 完成使用物品（例如吃完食物）
     */
    MCAPI void completeUsingItem();

    /**
     * @brief 吃下食物
     * @param instance 食物物品实例
     */
    MCAPI void eat(::ItemStack const& instance);

    /**
     * @brief 吃东西，直接增加饥饿和饱和度
     * @param hungerValue 增加的饥饿值
     * @param saturationModifier 饱和度修正值
     */
    MCAPI void eat(int hungerValue, float saturationModifier);

    /**
     * @brief 判断已装备的盔甲是否可以被移动
     * @param item 盔甲物品
     * @return 如果可以则返回true
     */
    MCAPI bool equippedArmorItemCanBeMoved(::ItemStack const& item) const;

    /**
     * @brief 触发维度改变事件
     * @param fromDimension 起始维度
     * @param toDimension 目标维度
     */
    MCAPI void fireDimensionChangedEvent(::DimensionType fromDimension, ::DimensionType toDimension);

    /**
     * @brief 获取玩家的能力 (常量版本)
     * @return 能力对象的常量引用
     */
    MCAPI ::LayeredAbilities const& getAbilities() const;

    /**
     * @brief 获取玩家的能力
     * @return 能力对象的引用
     */
    MCFOLD ::LayeredAbilities& getAbilities();

    /**
     * @brief 获取玩家的Agent (教育版功能)
     * @return 指向Agent的指针
     */
    MCAPI ::Agent* getAgent() const;

    /**
     * @brief 获取当前激活的盾牌
     * @return 盾牌物品的常量引用
     */
    MCAPI ::ItemStack const& getCurrentActiveShield() const;

    /**
     * @brief 获取对指定方块的破坏进度
     * @param block 目标方块
     * @return 进度值 (0.0-1.0)
     */
    MCAPI float getDestroyProgress(::Block const& block);

    /**
     * @brief 获取预期的生成维度ID
     * @return 维度ID
     */
    MCAPI ::DimensionType getExpectedSpawnDimensionId() const;

    /**
     * @brief 获取预期的生成位置
     * @return 生成位置的常量引用
     */
    MCAPI ::BlockPos const& getExpectedSpawnPosition() const;

    /**
     * @brief 获取交互文本 (例如 "轻按以打开")
     * @return 交互文本字符串
     */
    MCAPI ::std::string getInteractText() const;

    /**
     * @brief 获取指定类型物品的剩余冷却时间
     * @param type 物品类型哈希
     * @return 剩余冷却时间 (ticks)
     */
    MCAPI int getItemCooldownLeft(::HashedString const& type) const;

    /**
     * @brief 获取与指定物品交互的文本
     * @param item 物品
     * @return 交互文本字符串
     */
    MCAPI ::std::string getItemInteractText(::Item const& item) const;

    /**
     * @brief 获取玩家的拾取范围
     * @return 拾取范围的碰撞箱
     */
    MCAPI ::AABB getPickupArea() const;

    /**
     * @brief 获取玩家的游戏模式
     * @return 游戏模式
     */
    MCAPI ::GameType getPlayerGameType() const;

    /**
     * @brief 获取当前选中的物品
     * @return 物品的常量引用
     */
    MCFOLD ::ItemStack const& getSelectedItem() const;

    /**
     * @brief 获取睡觉时的旋转角度
     * @return 旋转角度
     */
    MCAPI float getSleepRotation() const;

    /**
     * @brief 获取升到下一级所需的经验值
     * @return 经验值
     */
    MCAPI int getXpNeededForNextLevel() const;

    /**
     * @brief 判断玩家是否拥有自己的区块源
     * @return 如果拥有则返回true
     */
    MCFOLD bool hasOwnedChunkSource() const;

    /**
     * @brief 判断玩家是否有指定的资源
     * @param resource 资源描述符
     * @return 如果有则返回true
     */
    MCAPI bool hasResource(::ItemDescriptor const& resource);

    /**
     * @brief 判断玩家是否有重生点
     * @return 如果有则返回true
     */
    MCAPI bool hasRespawnPosition() const;

    /**
     * @brief 与一个实体交互
     * @param actor 目标实体
     * @param location 交互位置
     * @return 是否成功交互
     */
    MCAPI bool interact(::Actor& actor, ::Vec3 const& location);

    /**
     * @brief 当物品栏变化时调用
     * @param container 容器
     * @param slot 槽位
     * @param oldItem 旧物品
     * @param newItem 新物品
     * @param forceBalanced 是否强制平衡
     */
    MCAPI void inventoryChanged(
        ::Container&,
        int                slot,
        ::ItemStack const& oldItem,
        ::ItemStack const& newItem,
        bool               forceBalanced
    );

    /**
     * @brief 判断一个二维位置是否与玩家相关
     * @param dimension 维度
     * @param position 位置
     * @return 如果相关则返回true
     */
    MCAPI bool is2DPositionRelevant(::DimensionType dimension, ::BlockPos const& position);

    /**
     * @brief 判断玩家是否在飞行
     * @return 如果在飞行则返回true
     */
    MCAPI bool isFlying() const;

    /**
     * @brief 判断是否是强制重生
     * @return 如果是则返回true
     */
    MCAPI bool isForcedRespawn() const;

    /**
     * @brief 判断是否对指定生物隐身
     * @param target 目标生物
     * @return 如果隐身则返回true
     */
    MCAPI bool isHiddenFrom(::Mob& target) const;

    /**
     * @brief 判断是否在袭击中
     * @return 如果是则返回true
     */
    MCAPI bool isInRaid() const;

    /**
     * @brief 判断指定类型的物品是否在冷却中
     * @param type 物品类型哈希
     * @return 如果在冷却中则返回true
     */
    MCAPI bool isItemOnCooldown(::HashedString const& type) const;

    /**
     * @brief 从NBT加载上次死亡的位置
     * @param tag NBT数据
     */
    MCAPI void loadLastDeathLocation(::CompoundTag const& tag);

    /**
     * @brief 播放预测性的同步音效
     * @param type 音效类型
     * @param pos 位置
     * @param data 数据
     * @param isGlobal 是否全局
     */
    MCAPI void playPredictiveSynchronizedSound(
        ::SharedTypes::Legacy::LevelSoundEvent type,
        ::Vec3 const&                          pos,
        int                                    data,
        bool                                   isGlobal
    );

    /**
     * @brief 重新检查生成位置
     */
    MCAPI void recheckSpawnPosition();

    /**
     * @brief 释放正在使用的物品
     */
    MCAPI void releaseUsingItem();

    /**
     * @brief 重置玩家等级
     */
    MCAPI void resetPlayerLevel();

    /**
     * @brief 保存上次死亡的位置到NBT
     * @param tag 输出的NBT标签
     */
    MCAPI void saveLastDeathLocation(::CompoundTag& tag) const;

    /**
     * @brief 发送事件数据包 (遥测)
     * @param packet 数据包
     */
    MCAPI void sendEventPacket(::LegacyTelemetryEventPacket& packet) const;

    /**
     * @brief 设置床为重生点
     * @param bedPosition 床的位置
     */
    MCAPI void setBedRespawnPosition(::BlockPos const& bedPosition);

    /**
     * @brief 设置容器管理器模型
     * @param manager 容器管理器模型
     */
    MCAPI void setContainerManagerModel(::std::shared_ptr<::ContainerManagerModel> manager);

    /**
     * @brief 设置玩家是否死亡过
     * @param hasDied 是否死亡过
     */
    MCAPI void setHasDied(bool hasDied);

    /**
     * @brief 设置上次死亡的维度
     * @param dimension 维度ID
     */
    MCAPI void setLastDeathDimension(::DimensionType dimension);

    /**
     * @brief 设置上次死亡的位置
     * @param pos 位置
     */
    MCAPI void setLastDeathPos(::BlockPos pos);

    /**
     * @brief 设置玩家名称
     * @param newName 新名称
     */
    MCAPI void setName(::std::string const& newName);

    /**
     * @brief 设置平台在线ID
     * @param platformOnlineId 平台在线ID
     */
    MCAPI void setPlatformOnlineId(::std::string const& platformOnlineId);

    /**
     * @brief 设置玩家UI中的物品
     * @param slot UI槽位
     * @param item 物品
     * @param forceBalance 是否强制平衡
     */
    MCAPI void setPlayerUIItem(::PlayerUISlot slot, ::ItemStack const& item, bool forceBalance);

    /**
     * @brief 设置重生位置
     * @param inRespawnPosition 重生位置
     * @param dimension 维度
     */
    MCAPI void setRespawnPosition(::BlockPos const& inRespawnPosition, ::DimensionType dimension);

    /**
     * @brief 设置候选的重生位置
     */
    MCAPI void setRespawnPositionCandidate();

    /**
     * @brief 设置选中的物品
     * @param item 物品
     */
    MCAPI void setSelectedItem(::ItemStack const& item);

    /**
     * @brief 设置选中的槽位
     * @param slot 槽位索引
     * @return 槽位中的物品
     */
    MCAPI ::ItemStack const& setSelectedSlot(int slot);

    /**
     * @brief 设置生成方块为重生点
     * @param spawnBlockPosition 生成方块位置
     * @param dimension 维度
     * @return 是否成功设置
     */
    MCAPI bool setSpawnBlockRespawnPosition(::BlockPos const& spawnBlockPosition, ::DimensionType dimension);

    /**
     * @brief 开始物品的冷却
     * @param item 物品
     * @param updateClient 是否通知客户端
     */
    MCAPI void startCooldown(::Item const* item, bool updateClient);

    /**
     * @brief 开始一个类型的冷却
     * @param type 类型哈希
     * @param tickDuration 冷却时长
     * @param updateClient 是否通知客户端
     */
    MCAPI void startCooldown(::HashedString const& type, int tickDuration, bool updateClient);

    /**
     * @brief 开始滑翔
     */
    MCAPI void startGliding();

    /**
     * @brief 开始在方块上使用物品
     */
    MCAPI void
    startItemUseOn(uchar face, ::BlockPos const& blockPos, ::BlockPos const& buildBlockPos, ::ItemStack const& item);

    /**
     * @brief 开始使用物品
     */
    MCAPI void startUsingItem(::ItemStack const& instance, int duration);

    /**
     * @brief 停止滑翔
     */
    MCAPI void stopGliding();

    /**
     * @brief 停止在方块上使用物品
     */
    MCAPI void stopItemUseOn(::BlockPos const& blockPos, ::ItemStack const& item);

    /**
     * @brief 停止使用物品
     */
    MCAPI void stopUsingItem();

    /**
     * @brief 从另一个实体处拿取物品
     * @param favoredSlot 偏好的槽位
     */
    MCAPI bool take(::Actor& actor, int, int favoredSlot);

    /**
     * @brief 更新盔甲逻辑
     */
    MCAPI void tickArmor();

    /**
     * @brief 尝试开始滑翔
     */
    MCAPI bool tryStartGliding();

    /**
     * @brief 取消追踪一个Boss
     */
    MCAPI void unRegisterTrackedBoss(::ActorUniqueID mob);

    /**
     * @brief 更新物品栏交易
     */
    MCAPI void updateInventoryTransactions();

    /**
     * @brief 更新皮肤
     */
    MCAPI void updateSkin(::SerializedSkin const& skin, int clientSubID);

    /**
     * @brief 更新追踪的Boss列表
     */
    MCAPI void updateTrackedBosses();

    /**
     * @brief 使用当前选中的物品
     */
    MCAPI void useSelectedItem(::ItemUseMethod itemUseMethod, bool consumeItem);
    // NOLINTEND

public:
    // static functions
    // 静态函数
    // NOLINTBEGIN

    /**
     * @brief 静态内部方法：消耗饥饿度
     */
    MCAPI static void _causeFoodExhaustion(::MutableAttributeWithContext& attribute, float exhaustionAmount);

    /**
     * @brief 静态方法：检查并修正生成位置 (已弃用)
     */
    MCAPI static ::std::optional<::Player::FixedSpawnPositionData_DEPRECATED> checkAndFixSpawnPosition_DEPRECATED(
        ::Vec3 const&                                  spawnPosition,
        ::std::vector<::gsl::not_null<::BlockSource*>> regions,
        ::AABB                                         aabb,
        bool                                           adjustYToSolidGround,
        bool,
        bool  searchUp,
        bool  positionFromSave,
        bool  spawningAtForcedSpawn,
        short dimensionHeight
    );

    /**
     * @brief 静态方法：检查是否需要自动跳跃
     */
    MCAPI static bool checkNeedAutoJump(
        ::IConstBlockSource const&                         region,
        ::AABBShapeComponent const&                        aabbShape,
        ::ActorRotationComponent const&                    actorRotation,
        float                                              movementSpeed,
        ::StateVectorComponent const&                      stateVector,
        ::optional_ref<::GetCollisionShapeInterface const> collisionShapeInterface,
        float                                              inputMoveX,
        float                                              inputMoveZ
    );

    /**
     * @brief 静态方法：获取自定义受伤音效
     */
    MCAPI static ::std::optional<::SharedTypes::Legacy::LevelSoundEvent>
    getCustomHurtSound(::Mob& mob, ::SharedTypes::Legacy::ActorDamageCause cause);

    /**
     * @brief 静态方法：判断生成区域是否危险
     */
    MCAPI static bool isDangerousVolumeForSpawn(::BlockSource& region, ::AABB const& centeredAABB);

    /**
     * @brief 静态方法：判断区域是否危险 (已弃用)
     */
    MCAPI static bool
    isDangerousVolume_DEPRECATED(::BlockSource& region, ::AABB const& centeredAABB, bool checkForLava);

    /**
     * @brief 静态方法：尝试从实体上下文获取Player指针
     */
    MCAPI static ::Player* tryGetFromEntity(::EntityContext& entity, bool includeRemoved);

    /**
     * @brief 静态方法：尝试从实体上下文获取Player指针 (StackRefResult版本)
     */
    MCAPI static ::Player* tryGetFromEntity(::StackRefResult<::EntityContext> entity, bool includeRemoved);

    /**
     * @brief 静态方法：更新玩家游戏模式的实体数据
     */
    MCAPI static void
    updatePlayerGameTypeEntityData(::EntityContext& entity, ::GameType gameType, ::GameType defaultGameType);
    // NOLINTEND

public:
    // static variables
    // 静态变量
    // NOLINTBEGIN
    MCAPI static float const&       DEFAULT_BB_HEIGHT();            // 默认碰撞箱高度
    MCAPI static float const&       DEFAULT_BB_WIDTH();             // 默认碰撞箱宽度
    MCAPI static float const&       DEFAULT_PLAYER_EYE_OFFSET();    // 默认玩家眼睛偏移
    MCAPI static float const&       DEFAULT_PLAYER_HEIGHT_OFFSET(); // 默认玩家高度偏移
    MCAPI static float const&       DISTANCE_TO_TRANSFORM_EVENT();  // 触发变换事件的距离
    MCAPI static ::Attribute const& EXHAUSTION();                   // 饥饿度消耗属性
    MCAPI static ::Attribute const& EXPERIENCE();                   // 经验值属性
    MCAPI static int const&         GLIDE_STOP_DELAY();             // 停止滑翔的延迟
    MCAPI static ::Attribute const& HUNGER();                       // 饥饿度属性
    MCAPI static ::Attribute const& LEVEL();                        // 等级属性
    MCAPI static float const&       PLAYER_SLEEPING_HEIGHT();       // 玩家睡觉时的高度
    MCAPI static ::Attribute const& SATURATION();                   // 饱和度属性
    // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::Level&                   level,
        ::PacketSender&            packetSender,
        ::GameType                 playerGameType,
        bool                       isHostingPlayer,
        ::NetworkIdentifier const& owner,
        ::SubClientId              subid,
        ::mce::UUID                uuid,
        ::std::string const&       playFabId,
        ::std::string const&       deviceId,
        ::GameServerToken const&   gameServerToken,
        ::EntityContext&           entityContext,
        ::std::string const&       platformId,
        ::std::string const&       platformOnlineId
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

    MCAPI void $reloadHardcoded(::ActorInitializationMethod method, ::VariantParameterList const& params);

    MCAPI void $prepareRegion(::ChunkSource& mainChunkSource);

    MCAPI void $destroyRegion();

    MCAPI void $suspendRegion();

    MCAPI void $_fireDimensionChanged();

    MCAPI bool $canChangeDimensionsUsingPortal() const;

    MCFOLD void $changeDimensionWithCredits(::DimensionType);

    MCAPI void $tickWorld(::Tick const&);

    MCAPI ::std::vector<::ChunkPos> const& $getTickingOffsets() const;

    MCAPI void $normalTick();

    MCAPI void $moveView();

    MCAPI void $moveSpawnView(::Vec3 const& spawnPosition, ::DimensionType dimensionType);

    MCFOLD void $onSynchedDataUpdate(int dataId);

    MCAPI void $aiStep();

    MCAPI bool $isFireImmune() const;

    MCFOLD void $checkMovementStats(::Vec3 const&);

    MCFOLD ::HashedString $getCurrentStructureFeature() const;

    MCFOLD bool $isAutoJumpEnabled() const;

    MCAPI ::Vec3 $getInterpolatedRidingOffset(float, int const) const;

    MCAPI void $passengerTick();

    MCAPI void $die(::ActorDamageSource const& source);

    MCAPI void $remove();

    MCAPI void $respawn();

    MCAPI bool $shouldDropDeathLoot() const;

    MCAPI void $dropEquipmentOnDeath(::ActorDamageSource const& source);

    MCAPI void $dropEquipmentOnDeath();

    MCFOLD void $clearVanishEnchantedItemsOnDeath();

    MCAPI bool $drop(::ItemStack const& item, bool const randomly);

    MCFOLD void $resetRot();

    MCAPI void $resetUserPos(::ActorResetRule resetRule);

    MCFOLD bool $isInTrialMode();

    MCAPI void $setSpeed(float speed);

    MCAPI int $getItemUseDuration() const;

    MCAPI float $getItemUseStartupProgress() const;

    MCAPI float $getItemUseIntervalProgress() const;

    MCAPI bool $isBlocking() const;

    MCAPI bool $isDamageBlocked(::ActorDamageSource const& source) const;

    MCAPI void $handleEntityEvent(::ActorEvent eventId, int data);

    MCAPI ::std::vector<::ItemStack const*> $getAllHand() const;

    MCAPI ::std::vector<::ItemStack const*> $getAllEquipment() const;

    MCAPI bool $add(::ItemStack& item);

    MCFOLD ::ItemStack const& $getCarriedItem() const;

    MCAPI void $setCarriedItem(::ItemStack const& item);

    MCFOLD void $openPortfolio();

    MCFOLD void $openBook(int, bool, int, ::BlockActor*);

    MCFOLD void $openTrading(::ActorUniqueID const&, bool);

    MCFOLD void $openChalkboard(::ChalkboardBlockActor&, bool);

    MCFOLD void $openNpcInteractScreen(::std::shared_ptr<::INpcDialogueData> npc);

    MCFOLD void $openInventory();

    MCFOLD void $displayChatMessage(
        ::std::string const&                 author,
        ::std::string const&                 message,
        ::std::optional<::std::string> const filteredMessage
    );

    MCAPI void
    $displayClientMessage(::std::string const& message, ::std::optional<::std::string> const filteredMessage);

    MCFOLD void $displayTextObjectMessage(
        ::TextObjectRoot const& textObject,
        ::std::string const&    fromXuid,
        ::std::string const&    fromPlatformId
    );

    MCFOLD void $displayTextObjectWhisperMessage(
        ::ResolvedTextObject const& resolvedTextObject,
        ::std::string const&        xuid,
        ::std::string const&        platformId
    );

    MCFOLD void $displayTextObjectWhisperMessage(
        ::std::string const& message,
        ::std::string const& xuid,
        ::std::string const& platformId
    );

    MCFOLD void $displayWhisperMessage(
        ::std::string const&                 author,
        ::std::string const&                 message,
        ::std::optional<::std::string> const filteredMessage,
        ::std::string const&                 xuid,
        ::std::string const&                 platformId
    );

    MCAPI float $getShadowRadius() const;

    MCAPI bool $isSleeping() const;

    MCAPI void $setSleeping(bool val);

    MCAPI ::BedSleepingResult $startSleepInBed(::BlockPos const& bedBlockPos);

    MCAPI void $stopSleepInBed(bool forcefulWakeUp, bool updateLevelList);

    MCAPI bool $canStartSleepInBed();

    MCFOLD void $sendInventory(bool);

    MCFOLD void $openSign(::BlockPos const&, bool);

    MCFOLD void $playEmote(::std::string const&, bool const);

    MCAPI bool $isSilentObserver() const;

    MCAPI void $useItem(::ItemStackBase& item, ::ItemUseMethod itemUseMethod, bool consumeItem);

    MCFOLD bool $isLoading() const;

    MCFOLD bool $isPlayerInitialized() const;

    MCFOLD void $stopLoading();

    MCAPI float $getSpeed() const;

    MCAPI void $initHUDContainerManager();

    MCAPI void $_crit(::Actor& actor);

    MCAPI bool $isImmobile() const;

    MCFOLD void $sendMotionPacketIfNeeded();

    MCAPI ::IMinecraftEventing* $getEventing() const;

    MCFOLD uint $getUserId() const;

    MCAPI void $addExperience(int xp);

    MCAPI void $addLevels(int levels);

    MCAPI void $setOffhandSlot(::ItemStack const& item);

    MCAPI ::std::unique_ptr<::AddActorBasePacket> $tryCreateAddActorPacket();

    MCAPI bool $isInvulnerableTo(::ActorDamageSource const& source) const;

    MCAPI void $deleteContainerManager();

    MCAPI ::ItemStack const& $getEquippedTotem() const;

    MCAPI bool $consumeTotem();

    MCFOLD bool $isActorRelevant(::Actor const&);

    MCAPI float $getMapDecorationRotation() const;

    MCAPI void
    $teleportTo(::Vec3 const& pos, bool shouldStopRiding, int cause, int sourceEntityType, bool keepVelocity);

    MCAPI bool $startRiding(::Actor& vehicle, bool forceRiding);

    MCAPI void $startSwimming();

    MCAPI void $stopSwimming();

    MCFOLD void $onSuspension();

    MCFOLD void $onLinkedSlotsChanged();

    MCFOLD bool $canBePulledIntoVehicle() const;

    MCAPI void $feed(int itemId);

    MCFOLD void $sendNetworkPacket(::Packet& packet) const;

    MCFOLD bool $canExistWhenDisallowMob() const;

    MCAPI ::mce::Color $getNameTagTextColor() const;

    MCAPI bool $canAddPassenger(::Actor& passenger) const;

    MCFOLD bool $isSimulated() const;

    MCAPI ::std::string $getXuid() const;

    MCAPI ::PlayerMovementSettings const& $getMovementSettings() const;

    MCAPI bool $canFreeze() const;

    MCAPI bool $canInteractWithOtherEntitiesInGame() const;

    MCAPI bool $canObstructSpawningAndBlockPlacement() const;

    MCAPI ::std::optional<::BlockPos> $getLastDeathPos() const;

    MCAPI ::std::optional<::DimensionType> $getLastDeathDimension() const;

    MCAPI bool $hasDiedBefore() const;

    MCAPI void $doEnterWaterSplashEffect();

    MCAPI void $doExitWaterSplashEffect();

    MCFOLD void $requestMissingSubChunk(::SubChunkPos const&);

    MCFOLD uchar $getMaxChunkBuildRadius() const;

    MCAPI float $causeFallDamageToActor(float distance, float multiplier, ::ActorDamageSource source);

    MCAPI bool $_hurt(::ActorDamageSource const& source, float damage, bool knock, bool ignite);

    MCAPI void $readAdditionalSaveData(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper);

    MCAPI void $addAdditionalSaveData(::CompoundTag& entityTag) const;

    MCAPI void $onMovePlayerPacketNormal(::Vec3 const& pos, ::Vec2 const& rot, float yHeadRot);

    MCAPI bool $_shouldProvideFeedbackOnHandContainerItemSet(::HandSlot handSlot, ::ItemStack const& item) const;

    MCAPI ::std::shared_ptr<::ChunkViewSource> $_createChunkSource(::ChunkSource& mainChunkSource);

    MCAPI void $setAbilities(::LayeredAbilities const& newAbilities);

    MCAPI ::AnimationComponent& $getAnimationComponent();

    MCAPI ::HashedString const& $getActorRendererId() const;

    MCFOLD void $_serverInitItemStackIds();

    MCAPI ::std::unique_ptr<::BodyControl> $initBodyControl();
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
