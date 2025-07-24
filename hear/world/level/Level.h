#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/common/SubClientId.h"
#include "mc/comprehensive/ParticleType.h"
#include "mc/deps/core/file/PathBuffer.h"
#include "mc/deps/core/utility/AutomaticID.h"
#include "mc/deps/core/utility/NonOwnerPointer.h"
#include "mc/deps/core/utility/UniqueOwnerPointer.h"
#include "mc/deps/core/utility/pub_sub/Subscription.h"
#include "mc/deps/game_refs/OwnerPtr.h"
#include "mc/deps/game_refs/StackRefResult.h"
#include "mc/deps/game_refs/WeakRef.h"
#include "mc/deps/shared_types/legacy/Difficulty.h"
#include "mc/deps/shared_types/legacy/LevelEvent.h"
#include "mc/deps/shared_types/legacy/LevelSoundEvent.h"
#include "mc/network/GamePublishSetting.h"
#include "mc/platform/Result.h"
#include "mc/server/commands/CurrentCmdVersion.h"
#include "mc/util/Factory.h"
#include "mc/util/IDType.h"
#include "mc/util/OwnerPtrFactory.h"
#include "mc/util/TagRegistry.h"
#include "mc/world/actor/ActorEvent.h"
#include "mc/world/item/registry/ItemRegistryRef.h"
#include "mc/world/level/ActorValidationError.h"
#include "mc/world/level/BlockSourceListener.h"
#include "mc/world/level/CommandOriginSystem.h"
#include "mc/world/level/GameType.h"
#include "mc/world/level/ILevel.h"
#include "mc/world/level/IWorldRegistriesProvider.h"
#include "mc/world/level/storage/StorageVersion.h"

// auto generated forward declare list
// clang-format off
class Abilities;
class Actor;
class ActorAnimationControllerGroup;
class ActorAnimationGroup;
class ActorDamageSource;
class ActorDefinitionGroup;
class ActorDimensionTransferManager;
class ActorEventBroadcaster;
class ActorEventCoordinator;
class ActorFactory;
class ActorFetcher;
class ActorGarbageCollector;
class ActorInfoRegistry;
class ActorManager;
class ActorRuntimeID;
class ActorRuntimeIDManager;
class ActorSoundIdentifier;
class ArmorTrimUnloader;
class AutomationBehaviorTreeGroup;
class AutonomousActorManager;
class BaseLightTextureImageBuilder;
class BehaviorFactory;
class BiomeComponentFactory;
class BiomeManager;
class BiomeRegistry;
class Block;
class BlockActorLevelListener;
class BlockDefinitionGroup;
class BlockEventCoordinator;
class BlockLegacy;
class BlockPalette;
class BlockPos;
class BlockReducer;
class BlockSource;
class BlockSourceValidityManager;
class BlockTypeRegistry;
class BossEventSubscriptionManager;
class CameraPresets;
class CameraRegistry;
class ChangeDimensionRequest;
class ChunkGenerationManager;
class ChunkPos;
class ChunkSource;
class ChunkTickOffsetManager;
class ChunkTickRangeManager;
class ChunkViewSource;
class ChunkViewTrackerManager;
class ClientPlayerEventCoordinator;
class Command;
class CommandOrigin;
class CompoundTag;
class ContainerRegistry;
class Dimension;
class DimensionConversionData;
class DimensionDefinitionGroup;
class DimensionFactory;
class DimensionManager;
class DisplayActorManager;
class EducationSettingsManager;
class EntityContext;
class EntityRegistry;
class EntitySystems;
class EntitySystemsManager;
class EventCoordinatorManager;
class Experiments;
class Explosion;
class FeatureRegistry;
class FeatureTypeFactory;
class GameRules;
class GameplayUserManager;
class HashedString;
class HitResult;
class HitResultWrapper;
class IConstBlockSource;
class IEntityRegistryOwner;
class ILevelRandom;
class IMinecraftEventing;
class IRandom;
class IUnknownBlockTypeRegistry;
class InternalComponentRegistry;
class ItemEventCoordinator;
class JigsawStructureRegistry;
class LayeredAbilities;
class LevelBlockDestroyer;
class LevelChunk;
class LevelChunkEventManager;
class LevelChunkMetaDataManager;
class LevelChunkPerformanceTelemetry;
class LevelChunkSaveManager;
class LevelCrashDumpManager;
class LevelData;
class LevelEventCoordinator;
class LevelEventManager;
class LevelListener;
class LevelSeed64;
class LevelSettings;
class LevelSoundManager;
class LevelStorage;
class LevelStorageManager;
class LinkedAssetValidator;
class LoadingScreenIdManager;
class LootTables;
class MapItemSavedData;
class Mob;
class MolangVariableMap;
class NavigationComponent;
class NetEventCallback;
class NetworkIdentifier;
class NpcDialogueStorage;
class PacketSender;
class Particle;
class ParticleProvider;
class Path;
class PauseManager;
class PermissionsHandler;
class PhotoItemSavedDataCollection;
class PhotoManager;
class PhotoStorage;
class Player;
class PlayerAbilitiesManager;
class PlayerDeathManager;
class PlayerDimensionTransferManager;
class PlayerEventCoordinator;
class PlayerLimboActorManager;
class PlayerListEntry;
class PlayerListManager;
class PlayerLocationReceiver;
class PlayerLocationSender;
class PlayerMovementSettingsManager;
class PlayerPermissionsManager;
class PlayerPermissionsSynchroniser;
class PlayerSleepManager;
class PlayerTickManager;
class PortalForcer;
class ProjectileFactory;
class PropertyGroupManager;
class Random;
class Recipes;
class ResourcePackManager;
class SavedDataStorage;
class Scheduler;
class Scoreboard;
class ScriptDeferredEventCoordinator;
class ScriptingEventCoordinator;
class SerializedSkin;
class ServerLevelEventCoordinator;
class ServerNetworkEventCoordinator;
class ServerParticleManager;
class ServerPlayerEventCoordinator;
class ServerPlayerSleepManager;
class SoundPlayerInterface;
class Spawner;
class StrictEntityContext;
class StructureManager;
class StructureSpawnRegistry;
class SubChunkManager;
class SubChunkPacket;
class SubChunkRequestManager;
class SurfaceBuilderRegistry;
class TagCacheManager;
class TaskGroup;
class TempEPtrManager;
class TickDeltaTimeManager;
class TickTimeManager;
class TickingAreaList;
class TickingAreasManager;
class TradeTables;
class TrimMaterialRegistry;
class TrimPatternRegistry;
class TrustedSkinHelper;
class UniqueIDManager;
class UserEntityIdentifierComponent;
class VanillaActorEventListenerManager;
class Vec3;
class VolumeEntityManagerServer;
class WeakEntityRef;
class WeatherManager;
class _TickPtr;
struct ActorUniqueID;
struct AdventureSettings;
struct Bounds;
struct BreakingItemParticleData;
struct LevelTagIDType;
struct LevelTagSetIDType;
struct NetworkPermissions;
struct PlayerMovementSettings;
struct PlayerSleepStatus;
struct ResolvedItemIconInfo;
struct ScreenshotOptions;
struct Tick;
namespace PlayerCapabilities { struct ISharedController; }
namespace PositionTrackingDB { class PositionTrackingDBClient; }
namespace PositionTrackingDB { class PositionTrackingDBServer; }
namespace cereal { struct ReflectionCtx; }
namespace cg { class ImageBuffer; }
namespace mce { class Color; }
namespace mce { class UUID; }
// clang-format on

class ServerLevel;

/**
 * @brief Level (关卡/世界) 类是 Minecraft 游戏世界的核心。
 *
 * 这个类管理着游戏世界中的几乎所有方面，包括但不限于：
 * - 实体（Actor）的生命周期和交互
 * - 维度（Dimension）的管理
 * - 方块和区块（Chunk）数据
 * - 游戏规则（GameRules）、难度（Difficulty）和时间
 * - 玩家（Player）的管理和数据
 * - 事件协调和分发（如方块更新、实体生成等）
 * - 数据的加载和保存（LevelStorage）
 * - 各种游戏对象的注册表（Registry）
 *
 * 它继承自 ILevel (关卡接口), BlockSourceListener (方块源监听器), 和
 * IWorldRegistriesProvider (世界注册表提供者)。
 */
class Level : public ::ILevel,
              public ::BlockSourceListener,
              public ::IWorldRegistriesProvider {
public:
  // 将当前 Level 实例转换为 ServerLevel 的引用。仅在服务器端有效。
  [[nodiscard]] ServerLevel &asServer() {
    return *reinterpret_cast<ServerLevel *>(this);
  }

public:
  // Level 内部类型定义
  using RegionSet =
      ::std::unordered_set<::BlockSource *>; // 用于存储方块源（世界区域）的集合

public:
  // member variables
  // 成员变量
  // NOLINTBEGIN
  // 用于发送网络数据包的发送器。这是一个非所有权指针。
  ::ll::TypedStorage<8, 24, ::Bedrock::NotNullNonOwnerPtr<::PacketSender> const>
      mPacketSender;
  // 标签注册表，用于管理游戏内的各种标签（如方块、物品、实体标签）。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::TagRegistry<
          ::IDType<::LevelTagIDType>, ::IDType<::LevelTagSetIDType>>>>>
      mTagRegistry;
  // 实体信息注册表，存储实体的基本定义信息。
  ::ll::TypedStorage<8, 16, ::std::shared_ptr<::ActorInfoRegistry>>
      mActorInfoRegistry;
  // 关卡监听器列表，用于监听关卡事件。
  ::ll::TypedStorage<8, 24, ::std::vector<::LevelListener *>> mListeners;
  // 关卡存储管理器，负责世界的保存和加载。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::LevelStorageManager>>
      mLevelStorageManager;
  // 关卡数据，包含世界的基本信息（如种子、名称、游戏模式等）。这是一个非所有权指针。
  ::ll::TypedStorage<8, 24, ::Bedrock::NotNullNonOwnerPtr<::LevelData> const>
      mLevelData;
  // 当前关卡中活跃的方块源（区域）集合。
  ::ll::TypedStorage<8, 64, ::std::unordered_set<::BlockSource *>> mRegions;
  // 关联资源验证器，用于验证资源包中的资源链接。
  ::ll::TypedStorage<8, 24, ::Bedrock::NonOwnerPointer<::LinkedAssetValidator>>
      mLinkedAssetValidator;
  // 实体定义组，存储所有实体（Actor）的定义。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ActorDefinitionGroup>>
      mEntityDefinitions;
  // 实体动画组。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ActorAnimationGroup>>
      mActorAnimationGroup;
  // 实体动画控制器组。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ActorAnimationControllerGroup>>
      mActorAnimationControllerGroup;
  // 方块定义组，存储所有方块的定义。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BlockDefinitionGroup>>
      mBlockDefinitions;
  // 盔甲纹饰图案注册表。
  ::ll::TypedStorage<8, 16, ::std::shared_ptr<::TrimPatternRegistry>>
      mTrimPatternRegistry;
  // 盔甲纹饰材料注册表。
  ::ll::TypedStorage<8, 16, ::std::shared_ptr<::TrimMaterialRegistry>>
      mTrimMaterialRegistry;
  // 生物生成器，负责自然生物的生成逻辑。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::Spawner>> mMobSpawner;
  // 投掷物工厂，用于创建投掷物实体。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ProjectileFactory>>
      mProjectileFactory;
  // 实体属性组管理器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::PropertyGroupManager>>
      mActorPropertyGroups;
  // 相机预设。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::CameraPresets>> mCameraPresets;
  // 行为工厂，用于创建实体的行为（AI）。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BehaviorFactory>>
      mBehaviorFactory;
  // 自动化行为树定义组。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::AutomationBehaviorTreeGroup>>
      mAutomationBehaviorTreeDefinitions;
  // 全局方块调色板，管理方块状态到ID的映射。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BlockPalette>>
      mGlobalBlockPalette;
  // 合成配方管理器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::Recipes>> mRecipes;
  // 方块转换器，用于处理化学更新中的方块。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BlockReducer>> mBlockReducer;
  // NPC 对话存储。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::NpcDialogueStorage>>
      mNpcDialogueStorage;
  // 内部组件注册表。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::InternalComponentRegistry>>
      mInternalComponentRegistry;
  // 传送门强制生成器，处理实体通过传送门的逻辑。
  ::ll::TypedStorage<
      8, 16, ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::PortalForcer>>>
      mPortalForcer;
  // 物品注册表的引用。
  ::ll::TypedStorage<8, 16, ::ItemRegistryRef const> mItemRegistry;
  // 方块类型注册表的弱引用。
  ::ll::TypedStorage<8, 16, ::std::weak_ptr<::BlockTypeRegistry>>
      mBlockRegistry;
  // 未知方块类型注册表。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::IUnknownBlockTypeRegistry>>
      mUnknownBlockTypeRegistry;
  // Boss 事件订阅管理器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BossEventSubscriptionManager>>
      mBossEventSubscriptionManager;
  // 容器注册表。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::OwnerPtr<::ContainerRegistry>> const>
      mContainerRegistry;
  // 命中结果包装器。
  ::ll::TypedStorage<
      8, 16, ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::HitResultWrapper>>>
      mHitResultWrapper;
  // 沉浸式阅读器字符串。
  ::ll::TypedStorage<8, 32, ::std::string> mImmersiveReaderString;
  // 关卡级别的随机数生成器。
  ::ll::TypedStorage<8, 16, ::gsl::not_null<::OwnerPtr<::ILevelRandom>>>
      mLevelRandom;
  // 网络事件回调。
  ::ll::TypedStorage<8, 24, ::Bedrock::NonOwnerPointer<::NetEventCallback>>
      mNetEventCallback;
  // 标记当前关卡是否为客户端侧。
  ::ll::TypedStorage<1, 1, bool const> mIsClientSide;
  // 子客户端ID。
  ::ll::TypedStorage<1, 1, ::SubClientId> mSubClientId;
  // 标记关卡当前是否正在导出。
  ::ll::TypedStorage<1, 1, bool> mIsExporting;
  // 标记是否禁用玩家交互。
  ::ll::TypedStorage<1, 1, bool> mDisablePlayerInteractions;
  // 标记模拟是否暂停。
  ::ll::TypedStorage<1, 1, bool> mSimPaused;
  // 主线程任务组。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::TaskGroup>> mMainThreadTaskGroup;
  // IO 任务组。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::TaskGroup>> mIOTaskGroup;
  // 调度器引用。
  ::ll::TypedStorage<8, 8, ::Scheduler &> mScheduler;
  // 关卡ID字符串。
  ::ll::TypedStorage<8, 32, ::std::string> mLevelId;
  // 常加载区块管理器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::TickingAreasManager>>
      mTickingAreasMgr;
  // 临时实体指针管理器。
  ::ll::TypedStorage<
      8, 16, ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::TempEPtrManager>>>
      mTempEPtrManager;
  // 照片物品保存数据集合。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::PhotoItemSavedDataCollection>>
      mPhotoItemSavedDataCollection;
  // 标记关卡是否正在被拆除/关闭。
  ::ll::TypedStorage<1, 1, bool> mTearingDown;
  // Minecraft 事件系统接口。
  ::ll::TypedStorage<8, 8, ::IMinecraftEventing &> mEventing;
  // 事件协调器管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::EventCoordinatorManager>>>
      mEventCoordinatorManager;
  // 关卡声音管理器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::LevelSoundManager>>
      mLevelSoundManager;
  // 结构管理器，用于处理结构（如村庄、神殿等）。
  ::ll::TypedStorage<8, 24, ::Bedrock::NotNullNonOwnerPtr<::StructureManager>>
      mStructureManager;
  // 关卡区块性能遥测。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::Bedrock::UniqueOwnerPointer<
                         ::LevelChunkPerformanceTelemetry>>>
      mLevelChunkPerformanceTelemetry;
  // 战利品表管理器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::LootTables>> mLootTables;
  // 注册的边界方块（如屏障方块）。
  ::ll::TypedStorage<8, 8, ::BlockLegacy const *> mRegisteredBorderBlock;
  // 拼图结构注册表。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::JigsawStructureRegistry>>>
      mJigsawStructureRegistry;
  // 结构生成注册表。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::StructureSpawnRegistry>>>
      mStructureSpawnRegistry;
  // 维度工厂。
  ::ll::TypedStorage<
      8, 16, ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::DimensionFactory>>>
      mDimensionFactory;
  // 维度管理器。
  ::ll::TypedStorage<
      8, 16, ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::DimensionManager>>>
      mDimensionManager;
  // 关卡实体上下文的弱引用。
  ::ll::TypedStorage<8, 24, ::WeakRef<::EntityContext>> mLevelEntity;
  // 实体注册表所有者的非所有权指针。
  ::ll::TypedStorage<8, 24,
                     ::Bedrock::NotNullNonOwnerPtr<::IEntityRegistryOwner>>
      mEntityRegistryOwner;
  // 暂停管理器。
  ::ll::TypedStorage<8, 16, ::OwnerPtr<::PauseManager>> mPauseManager;
  // 实体系统管理器。
  ::ll::TypedStorage<8, 16, ::gsl::not_null<::OwnerPtr<::EntitySystemsManager>>>
      mEntitySystemsManager;
  // 地形特征注册表。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::FeatureRegistry>>
      mFeatureRegistry;
  // 地形特征类型工厂。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::FeatureTypeFactory>>
      mFeatureTypeFactory;
  // 光照贴图图像构建器工厂。
  ::ll::TypedStorage<
      8, 64,
      ::Factory<::BaseLightTextureImageBuilder, ::Level &, ::Scheduler &>>
      mLightTextureImageBuilderFactory;
  // 教育版设置管理器。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::Bedrock::UniqueOwnerPointer<
                         ::EducationSettingsManager>>>
      mEducationSettingsManager;
  // 玩家能力共享控制器。
  ::ll::TypedStorage<8, 8,
                     ::std::unique_ptr<::PlayerCapabilities::ISharedController>>
      mCapabilities;
  // 方块实体关卡监听器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BlockActorLevelListener>>
      mBlockActorLevelListener;
  // 原版实体事件监听器管理器。
  ::ll::TypedStorage<8, 8,
                     ::std::unique_ptr<::VanillaActorEventListenerManager>>
      mVanillaActorEventListenerManager;
  // 位置追踪数据库客户端。
  ::ll::TypedStorage<
      8, 8, ::std::unique_ptr<::PositionTrackingDB::PositionTrackingDBClient>>
      mPositionTrackerDBClient;
  // 是否启用客户端侧区块生成。
  ::ll::TypedStorage<1, 1, bool> mClientSideChunkGenEnabled;
  // 方块网络ID是否为哈希值。
  ::ll::TypedStorage<1, 1, bool> mBlockNetworkIdsAreHashes;
  // 生物群系管理器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BiomeManager>> mBiomeManager;
  // 实体垃圾回收器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::ActorGarbageCollector>>>
      mActorGarbageCollector;
  // 实体管理器。
  ::ll::TypedStorage<
      8, 16, ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::ActorManager>>>
      mActorManager;
  // 当移除实体时，用于处理实体引用的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnRemoveActorEntityReferences;
  // 自治实体管理器（通常用于服务器上的非玩家控制实体）。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::AutonomousActorManager>>>
      mAutonomousActorManager;
  // 实体获取器。
  ::ll::TypedStorage<
      8, 16, ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::ActorFetcher>>>
      mActorFetcher;
  // 游戏性用户（玩家）管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::GameplayUserManager>>>
      mGameplayUserManager;
  // 添加游戏性用户的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnGameplayUserAddedSubscription;
  // 移除游戏性用户的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnGameplayUserRemovedSubscription;
  // 任何游戏性用户被移除时的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnAnyGameplayUsersRemovedSubscription;
  // 计分板。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::Scoreboard>> mScoreboard;
  // 实体运行时ID管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::ActorRuntimeIDManager>>>
      mActorRuntimeIDManager;
  // 玩家位置接收器。
  ::ll::TypedStorage<8, 16,
                     ::Bedrock::UniqueOwnerPointer<::PlayerLocationReceiver>>
      mPlayerLocationReceiver;
  // 玩家位置发送器。
  ::ll::TypedStorage<8, 16,
                     ::Bedrock::UniqueOwnerPointer<::PlayerLocationSender>>
      mPlayerLocationSender;
  // 玩家列表管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::PlayerListManager>>>
      mPlayerListManager;
  // 玩家Tick管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::PlayerTickManager>>>
      mPlayerTickManager;
  // 服务器粒子效果管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::ServerParticleManager>>>
      mServerParticleManager;
  // 粒子效果提供者。
  ::ll::TypedStorage<
      8, 16, ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::ParticleProvider>>>
      mParticleProvider;
  // 发送旧版服务器粒子效果的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnSendServerLegacyParticleSubscription;
  // 添加地形粒子效果的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnAddTerrainParticleEffectSubscription;
  // 添加地形滑动效果的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnAddTerrainSlideEffectSubscription;
  // 添加物品破坏粒子效果的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnAddBreakingItemParticleEffectSubscription;
  // 添加生物群系着色粒子效果的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnAddBiomeTintedParticleEffectSubscription;
  // 区块Tick范围管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::ChunkTickRangeManager>>>
      mChunkTickRangeManager;
  // 区块视野追踪器管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::ChunkViewTrackerManager>>>
      mChunkViewTrackerManager;
  // 实体事件广播器。
  ::ll::TypedStorage<
      8, 16, ::Bedrock::UniqueOwnerPointer<::ActorEventBroadcaster> const>
      mActorEventBroadcaster;
  // 序列化上下文（用于Cereal库）。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::OwnerPtr<::cereal::ReflectionCtx>>>
      mCerealContext;
  // 实体工厂。
  ::ll::TypedStorage<
      8, 16, ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::ActorFactory>>>
      mActorFactory;
  // 加载屏幕ID管理器。
  ::ll::TypedStorage<8, 16,
                     ::Bedrock::UniqueOwnerPointer<::LoadingScreenIdManager>>
      mLoadingScreenIdManager;
  // 玩家维度传送管理器。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::Bedrock::UniqueOwnerPointer<
                         ::PlayerDimensionTransferManager>>>
      mPlayerDimensionTransferManager;
  // 关卡崩溃转储管理器。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::Bedrock::UniqueOwnerPointer<
                         ::LevelCrashDumpManager>> const>
      mLevelCrashDumpManager;
  // 唯一ID管理器。
  ::ll::TypedStorage<8, 16, ::gsl::not_null<::OwnerPtr<::UniqueIDManager>>>
      mUniqueIDManager;
  // 拍照事件的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnPictureTakenSubscription;
  // 照片管理器。
  ::ll::TypedStorage<
      8, 16, ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::PhotoManager>>>
      mPhotoManager;
  // 关卡事件管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::LevelEventManager>>>
      mLevelEventManager;
  // 关卡事件数据订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mLevelEventDataSubscription;
  // 关卡事件CompoundTag订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mLevelEventCompoundTagSubscription;
  // 区块Tick偏移管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::ChunkTickOffsetManager>>>
      mChunkTickOffsetManager;
  // 玩家移动设置管理器。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::Bedrock::UniqueOwnerPointer<
                         ::PlayerMovementSettingsManager>>>
      mPlayerMovementSettingsManager;
  // 玩家能力管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::PlayerAbilitiesManager>>>
      mPlayerAbilitiesManager;
  // 玩家权限管理器。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::Bedrock::UniqueOwnerPointer<
                         ::PlayerPermissionsManager>>>
      mPlayerPermissionsManager;
  // 玩家权限同步器。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::Bedrock::UniqueOwnerPointer<
                         ::PlayerPermissionsSynchroniser>>>
      mPlayerPermissionsSynchroniser;
  // 关卡区块事件管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::LevelChunkEventManager>>>
      mLevelChunkEventManager;
  // 区块加载事件的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnChunkLoadedSubscription;
  // 区块重载事件的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnChunkReloadedSubscription;
  // 区块丢弃事件的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnChunkDiscardedSubscription;
  // 实体维度传送管理器。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::Bedrock::UniqueOwnerPointer<
                         ::ActorDimensionTransferManager>>>
      mActorDimensionTransferManager;
  // 关卡方块破坏器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::LevelBlockDestroyer>>>
      mLevelBlockDestroyer;
  // Tick增量时间管理器。
  ::ll::TypedStorage<
      8, 16,
      ::gsl::not_null<::Bedrock::UniqueOwnerPointer<::TickDeltaTimeManager>>>
      mTickDeltaTimeManager;
  // Tick时间管理器。
  ::ll::TypedStorage<8, 16, ::gsl::not_null<::OwnerPtr<::TickTimeManager>>>
      mTickTimeManager;
  // 方块源有效性管理器。
  ::ll::TypedStorage<8, 16,
                     ::gsl::not_null<::Bedrock::UniqueOwnerPointer<
                         ::BlockSourceValidityManager>>>
      mBlockSourceValidityManager;
  // 关卡区块保存管理器。
  ::ll::TypedStorage<8, 16, ::OwnerPtr<::LevelChunkSaveManager>>
      mLevelChunkSaveManager;
  // 天气管理器。
  ::ll::TypedStorage<8, 16, ::gsl::not_null<::OwnerPtr<::WeatherManager>>>
      mWeatherManager;
  // 在Tick时处理低内存情况的原子布尔值。
  ::ll::TypedStorage<1, 1, ::std::atomic<bool>> mHandleLowMemoryOnTick;
  // 低内存事件的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mLowMemorySubscription;
  // NOLINTEND
public:
    // prevent constructor by default
    Level& operator=(Level const&);
    Level(Level const&);
    Level();

  public:
    // virtual functions
    // 虚函数
    // NOLINTBEGIN
    // vIndex: 0
    virtual ~Level() /*override*/; // 析构函数

    // vIndex: 1
    // 初始化关卡。设置关卡名称、设置、实验性功能等。
    virtual bool initialize(::std::string const &levelName,
                            ::LevelSettings const &levelSettings,
                            ::Experiments const &experiments,
                            ::std::string const *levelId) /*override*/;

    // vIndex: 2
    // 开始离开游戏的流程。
    virtual void startLeaveGame() /*override*/;

    // vIndex: 3
    // 检查离开游戏的流程是否已完成。
    virtual bool isLeaveGameDone() /*override*/;

    // vIndex: 4
    // 获取或创建一个指定类型的维度（例如主世界、下界、末地）。返回维度的弱引用。
    virtual ::WeakRef<::Dimension>
    getOrCreateDimension(::DimensionType dimensionType) /*override*/;

    // vIndex: 5
    // 获取指定ID的维度。返回维度的弱引用。
    virtual ::WeakRef<::Dimension> getDimension(::DimensionType id) const
        /*override*/;

    // vIndex: 6
    // 获取最后或默认的生成维度ID。
    virtual ::DimensionType
    getLastOrDefaultSpawnDimensionId(::DimensionType lastDimensionId) const
        /*override*/;

    // vIndex: 8
    // 遍历所有维度（可修改）。
    virtual void forEachDimension(
        ::std::function<bool(::Dimension &)> callback) /*override*/;

    // vIndex: 7
    // 遍历所有维度（只读）。
    virtual void
    forEachDimension(::std::function<bool(::Dimension const &)> callback) const
        /*override*/;

    // vIndex: 11
    // 获取区块的Tick范围。
    virtual uint getChunkTickRange() const /*override*/;

    // vIndex: 12
    // 获取区块Tick范围管理器。
    virtual ::ChunkTickRangeManager const &getChunkTickRangeManager() const
        /*override*/;

    // vIndex: 13
    // 获取传送门强制生成器。
    virtual ::PortalForcer &getPortalForcer() /*override*/;

    // vIndex: 14
    // 请求玩家变更维度。
    virtual void requestPlayerChangeDimension(
        ::Player &player,
        ::ChangeDimensionRequest &&changeRequest) /*override*/;

    // vIndex: 15
    // 获取玩家维度传送管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::PlayerDimensionTransferManager>
    getPlayerDimensionTransferManager() /*override*/;

    // vIndex: 16
    // 实体变更维度。
    virtual void
    entityChangeDimension(::Actor &entity, ::DimensionType toId,
                          ::std::optional<::Vec3> entityPos) /*override*/;

    // vIndex: 17
    // 获取实体维度传送管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::ActorDimensionTransferManager>
    getActorDimensionTransferManager() /*override*/;

    // vIndex: 18
    // 获取生物生成器（Spawner）。
    virtual ::Spawner &getSpawner() const /*override*/;

    // vIndex: 19
    // 获取Boss事件订阅管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::BossEventSubscriptionManager>
    getBossEventSubscriptionManager() /*override*/;

    // vIndex: 20
    // 获取投掷物工厂。
    virtual ::ProjectileFactory &getProjectileFactory() const /*override*/;

    // vIndex: 21
    // 获取实体定义组。
    virtual ::ActorDefinitionGroup *getEntityDefinitions() const /*override*/;

    // vIndex: 22
    // 获取实体动画组。
    virtual ::Bedrock::NotNullNonOwnerPtr<::ActorAnimationGroup>
    getActorAnimationGroup() const /*override*/;

    // vIndex: 23
    // 获取实体动画控制器组。
    virtual ::Bedrock::NonOwnerPointer<::ActorAnimationControllerGroup>
    getActorAnimationControllerGroup() const
        /*override*/;

    // vIndex: 24
    // 获取方块定义组。
    virtual ::BlockDefinitionGroup *getBlockDefinitions() const /*override*/;

    // vIndex: 25
    // 获取实体属性组管理器。
    virtual ::PropertyGroupManager &getActorPropertyGroup() const /*override*/;

    // vIndex: 27
    // 获取相机预设（只读）。
    virtual ::CameraPresets const &getCameraPresets() const /*override*/;

    // vIndex: 26
    // 获取相机预设。
    virtual ::CameraPresets &getCameraPresets() /*override*/;

    // vIndex: 28
    // 获取是否禁用玩家交互。
    virtual bool getDisablePlayerInteractions() const /*override*/;

    // vIndex: 29
    // 设置是否禁用玩家交互。
    virtual void setDisablePlayerInteractions(bool const disable) /*override*/;

    // vIndex: 30
    // 获取自动化行为树组。
    virtual ::AutomationBehaviorTreeGroup &
    getAutomationBehaviorTreeGroup() const /*override*/;

    // vIndex: 31
    // 获取行为工厂。
    virtual ::BehaviorFactory &getBehaviorFactory() const /*override*/;

    // vIndex: 32
    // 获取游戏难度。
    virtual ::SharedTypes::Legacy::Difficulty getDifficulty() const
        /*override*/;

    // vIndex: 34
    // 获取维度转换数据。
    virtual ::DimensionConversionData getDimensionConversionData() const
        /*override*/;

    // vIndex: 35
    // 获取特定维度的特殊乘数（例如，下界坐标与主世界的换算比例）。
    virtual float getSpecialMultiplier(::DimensionType dimensionType) const
        /*override*/;

    // vIndex: 36
    // 检查命令是否已启用。
    virtual bool hasCommandsEnabled() const /*override*/;

    // vIndex: 37
    // 检查是否仅使用MSA（微软账户）玩家代号。
    virtual bool useMsaGamertagsOnly() const /*override*/;

    // vIndex: 38
    // 设置是否仅使用MSA玩家代号。
    virtual void setMsaGamertagsOnly(bool msaGamertagsOnly) /*override*/;

    // vIndex: 39
    // 在指定区域（Region）添加一个普通实体。
    virtual ::Actor *addEntity(::BlockSource ®ion,
                               ::OwnerPtr<::EntityContext> entity) /*override*/;

    // vIndex: 40
    // 在指定区域添加一个全局实体（不受常规卸载影响）。
    virtual ::Actor *
    addGlobalEntity(::BlockSource ®ion,
                    ::OwnerPtr<::EntityContext> entity) /*override*/;

    // vIndex: 41
    // 在指定区域添加一个自治实体。
    virtual ::Actor *
    addAutonomousEntity(::BlockSource ®ion,
                        ::OwnerPtr<::EntityContext> entity) /*override*/;

    // vIndex: 42
    // 添加一个用户实体（通常是玩家）。
    virtual void addUser(::OwnerPtr<::EntityContext> userEntity) /*override*/;

    // vIndex: 43
    // 添加一个用于显示的实体（通常在客户端）。
    virtual ::Actor *addDisplayEntity(::BlockSource &,
                                      ::OwnerPtr<::EntityContext>) /*override*/;

    // vIndex: 44
    // 移除一个显示实体。
    virtual void removeDisplayEntity(::WeakEntityRef) /*override*/;

    // vIndex: 45
    // 获取显示实体管理器。
    virtual ::Bedrock::NonOwnerPointer<::DisplayActorManager>
    getDisplayActorManager() /*override*/;

    // vIndex: 46
    // 暂停一个玩家（例如，当玩家暂时离开游戏时）。
    virtual void suspendPlayer(::Player &player) /*override*/;

    // vIndex: 47
    // 恢复一个玩家。
    virtual void resumePlayer(::Player &player) /*override*/;

    // vIndex: 48
    // 检查一个玩家是否被暂停。
    virtual bool isPlayerSuspended(::Player &player) const /*override*/;

    // vIndex: 50
    // 获取游戏性用户（玩家）管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::GameplayUserManager>
    getGameplayUserManager() /*override*/;

    // vIndex: 49
    // 获取游戏性用户（玩家）管理器（只读）。
    virtual ::Bedrock::NotNullNonOwnerPtr<::GameplayUserManager const>
    getGameplayUserManager() const /*override*/;

    // vIndex: 51
    // 获取玩家位置接收器。
    virtual ::Bedrock::NonOwnerPointer<::PlayerLocationReceiver>
    getPlayerLocationReceiver() /*override*/;

    // vIndex: 52
    // 移除一个实体并获取其实体上下文的所有权。
    virtual ::OwnerPtr<::EntityContext>
    removeActorAndTakeEntity(::WeakEntityRef entityRef) /*override*/;

    // vIndex: 53
    // 从世界中移除一个实体并获取其实体上下文的所有权。
    virtual ::OwnerPtr<::EntityContext>
    removeActorFromWorldAndTakeEntity(::WeakEntityRef entityRef) /*override*/;

    // vIndex: 54
    // 从指定的区块中获取一个实体的所有权。
    virtual ::OwnerPtr<::EntityContext>
    takeEntity(::WeakEntityRef entityRef, ::LevelChunk &lc) /*override*/;

    // vIndex: 55
    // 通过唯一ID获取严格的实体上下文。
    virtual ::StrictEntityContext fetchStrictEntity(::ActorUniqueID actorId,
                                                    bool getRemoved) const
        /*override*/;

    // vIndex: 56
    // 通过唯一ID获取实体指针。
    virtual ::Actor *fetchEntity(::ActorUniqueID actorId, bool getRemoved) const
        /*override*/;

    // vIndex: 57
    // 获取实体获取器（只读）。
    virtual ::Bedrock::NotNullNonOwnerPtr<::ActorFetcher const>
    getActorFetcher() const /*override*/;

    // vIndex: 58
    // 通过运行时ID获取实体指针。
    virtual ::Actor *getRuntimeEntity(::ActorRuntimeID actorId,
                                      bool getRemoved) const /*override*/;

    // vIndex: 60
    // 获取实体运行时ID管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::ActorRuntimeIDManager>
    getActorRuntimeIDManager() /*override*/;

    // vIndex: 59
    // 获取实体运行时ID管理器（只读）。
    virtual ::Bedrock::NotNullNonOwnerPtr<::ActorRuntimeIDManager const>
    getActorRuntimeIDManager() const /*override*/;

    // vIndex: 61
    // 通过唯一ID获取生物（Mob）指针。
    virtual ::Mob *getMob(::ActorUniqueID mobId) const /*override*/;

    // vIndex: 64
    // 通过玩家名称获取玩家指针。
    virtual ::Player *getPlayer(::std::string const &name) const /*override*/;

    // vIndex: 63
    // 通过UUID获取玩家指针。
    virtual ::Player *getPlayer(::mce::UUID const &uuid) const /*override*/;

    // vIndex: 62
    // 通过实体唯一ID获取玩家指针。
    virtual ::Player *getPlayer(::ActorUniqueID entityID) const /*override*/;

    // vIndex: 65
    // 通过XUID（Xbox用户ID）获取玩家指针。
    virtual ::Player *getPlayerByXuid(::std::string const &xuid) const
        /*override*/;

    // vIndex: 66
    // 通过平台在线ID获取玩家指针。
    virtual ::Player *
    getPlatformPlayer(::std::string const &platformOnlineId) const /*override*/;

    // vIndex: 67
    // 通过服务器ID获取玩家指针。
    virtual ::Player *getPlayerFromServerId(::std::string const &serverId) const
        /*override*/;

    // vIndex: 68
    // 通过运行时ID获取玩家指针。
    virtual ::Player *getRuntimePlayer(::ActorRuntimeID runtimeId) const
        /*override*/;

    // vIndex: 69
    // 获取远程玩家的数量。
    virtual int getNumRemotePlayers() const /*override*/;

    // vIndex: 70
    // 获取主本地玩家（通常在客户端上）。
    virtual ::Player *getPrimaryLocalPlayer() const /*override*/;

    // vIndex: 71
    // 获取事件系统接口。
    virtual ::IMinecraftEventing &getEventing() /*override*/;

    // vIndex: 72
    // 获取玩家的颜色（用于地图等）。
    virtual ::mce::Color getPlayerColor(::Player const &player) const
        /*override*/;

    // vIndex: 73
    // 获取当前的游戏刻（Tick）。
    virtual ::Tick const &getCurrentTick() const /*override*/;

    // vIndex: 74
    // 获取当前的服务器游戏刻。
    virtual ::Tick const getCurrentServerTick() const /*override*/;

    // vIndex: 75
    // 获取Tick增量时间管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::TickDeltaTimeManager const>
    getTickDeltaTimeManager() const /*override*/;

    // vIndex: 384
    // 获取盔甲纹饰卸载器。
    virtual ::ArmorTrimUnloader *getArmorTrimUnloader();

    // vIndex: 77
    // 获取生物群系注册表（只读）。
    virtual ::BiomeRegistry const &getBiomeRegistry() const /*override*/;

    // vIndex: 76
    // 获取生物群系注册表。
    virtual ::BiomeRegistry &getBiomeRegistry() /*override*/;

    // vIndex: 79
    // 获取方块调色板（只读）。
    virtual ::BlockPalette const &getBlockPalette() const /*override*/;

    // vIndex: 78
    // 获取方块调色板。
    virtual ::BlockPalette &getBlockPalette() /*override*/;

    // vIndex: 81
    // 获取地形特征注册表（只读）。
    virtual ::FeatureRegistry const &getFeatureRegistry() const /*override*/;

    // vIndex: 80
    // 获取地形特征注册表。
    virtual ::FeatureRegistry &getFeatureRegistry() /*override*/;

    // vIndex: 83
    // 获取地形特征类型工厂（只读）。
    virtual ::FeatureTypeFactory const &getFeatureTypeFactory() const
        /*override*/;

    // vIndex: 82
    // 获取地形特征类型工厂。
    virtual ::FeatureTypeFactory &getFeatureTypeFactory() /*override*/;

    // vIndex: 85
    // 获取拼图结构注册表（只读）。
    virtual ::JigsawStructureRegistry const &getJigsawStructureRegistry() const
        /*override*/;

    // vIndex: 84
    // 获取拼图结构注册表。
    virtual ::JigsawStructureRegistry &
    getJigsawStructureRegistry() /*override*/;

    // vIndex: 87
    // 获取结构生成注册表（只读）。
    virtual ::StructureSpawnRegistry const &getStructureSpawnRegistry() const
        /*override*/;

    // vIndex: 86
    // 获取结构生成注册表。
    virtual ::StructureSpawnRegistry &getStructureSpawnRegistry() /*override*/;

    // vIndex: 89
    // 获取结构管理器（只读）。
    virtual ::Bedrock::NotNullNonOwnerPtr<::StructureManager> const
    getStructureManager() const /*override*/;

    // vIndex: 88
    // 获取结构管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::StructureManager>
    getStructureManager() /*override*/;

    // vIndex: 91
    // 获取生物群系组件工厂（只读）。
    virtual ::BiomeComponentFactory const &getBiomeComponentFactory() const
        /*override*/;

    // vIndex: 90
    // 获取生物群系组件工厂。
    virtual ::BiomeComponentFactory &getBiomeComponentFactory() /*override*/;

    // vIndex: 93
    // 获取地表构建器注册表（只读）。
    virtual ::SurfaceBuilderRegistry const &getSurfaceBuilderRegistry() const
        /*override*/;

    // vIndex: 92
    // 获取地表构建器注册表。
    virtual ::SurfaceBuilderRegistry &getSurfaceBuilderRegistry() /*override*/;

    // vIndex: 95
    // 获取生物群系管理器（只读）。
    virtual ::BiomeManager const &getBiomeManager() const /*override*/;

    // vIndex: 94
    // 获取生物群系管理器。
    virtual ::BiomeManager &getBiomeManager() /*override*/;

    // vIndex: 97
    // 获取维度工厂（只读）。
    virtual ::OwnerPtrFactory<::Dimension, ::ILevel &, ::Scheduler &> const &
    getDimensionFactory() const /*override*/;

    // vIndex: 96
    // 获取维度工厂。
    virtual ::OwnerPtrFactory<::Dimension, ::ILevel &, ::Scheduler &> &
    getDimensionFactory() /*override*/;

    // vIndex: 99
    // 获取光照贴图图像构建器工厂（只读）。
    virtual ::Factory<::BaseLightTextureImageBuilder, ::Level &,
                      ::Scheduler &> const &
    getLightTextureImageBuilderFactory() const /*override*/;

    // vIndex: 98
    // 获取光照贴图图像构建器工厂。
    virtual ::Factory<::BaseLightTextureImageBuilder, ::Level &,
                      ::Scheduler &> &
    getLightTextureImageBuilderFactory() /*override*/;

    // vIndex: 33
    // 获取内部组件注册表。
    virtual ::InternalComponentRegistry &getInternalComponentRegistry() const
        /*override*/;

    // vIndex: 101
    // 获取世界注册表提供者（只读）。
    virtual ::IWorldRegistriesProvider const &getWorldRegistriesProvider() const
        /*override*/;

    // vIndex: 100
    // 获取世界注册表提供者。
    virtual ::IWorldRegistriesProvider &
    getWorldRegistriesProvider() /*override*/;

    // vIndex: 102
    // 添加一个关卡监听器。
    virtual void addListener(::LevelListener &listener) /*override*/;

    // vIndex: 103
    // 移除一个关卡监听器。
    virtual void removeListener(::LevelListener &listener) /*override*/;

    // vIndex: 104
    // 更新关卡中的所有实体。
    virtual void tickEntities() /*override*/;

    // vIndex: 105
    // 更新关卡中的所有实体系统。
    virtual void tickEntitySystems() /*override*/;

    // vIndex: 108
    // 处理玩家死亡事件。
    virtual void onPlayerDeath(::Player &player,
                               ::ActorDamageSource const &source) /*override*/;

    // vIndex: 109
    // 执行一个游戏刻（Tick）的逻辑。
    virtual void tick() /*override*/;

    // vIndex: 111
    // 在指定位置和参数下创建一个爆炸。
    virtual bool explode(::BlockSource &region, ::Actor *source,
                         ::Vec3 const &pos, float explosionRadius, bool fire,
                         bool breaksBlocks, float maxResistance,
                         bool allowUnderwater) /*override*/;

    // vIndex: 110
    // 通过 Explosion 对象创建一个爆炸。
    virtual bool explode(::Explosion &explosion) /*override*/;

    // vIndex: 114
    // 在指定位置生成一个拒绝效果（例如，屏障粒子）。
    virtual void denyEffect(::BlockSource &region,
                            ::Vec3 const &pos) /*override*/;

    // vIndex: 115
    // 播放药水溅射效果。
    virtual void potionSplash(::Vec3 const &pos, ::mce::Color const &color,
                              bool instantaneousEffect) /*override*/;

    // vIndex: 116
    // 熄灭指定位置的火。
    virtual bool extinguishFire(::BlockSource &region, ::BlockPos const &pos,
                                uchar face, ::Actor *source) /*override*/;

    // vIndex: 118
    // 为实体寻找一条到指定坐标的路径。
    virtual ::std::unique_ptr<::Path>
    findPath(::Actor &from, int xBest, int yBest, int zBest,
             ::NavigationComponent &navigation) /*override*/;

    // vIndex: 117
    // 为实体寻找一条到另一个实体的路径。
    virtual ::std::unique_ptr<::Path>
    findPath(::Actor &from, ::Actor const &to,
             ::NavigationComponent &navigation) /*override*/;

    // vIndex: 120
    // 设置玩家的睡眠状态。
    virtual void setSleepStatus(::PlayerSleepStatus const &status) /*override*/;

    // vIndex: 121
    // 获取玩家的睡眠状态。
    virtual ::PlayerSleepStatus getSleepStatus() const /*override*/;

    // vIndex: 119
    // 更新正在睡觉的玩家列表。
    virtual void updateSleepingPlayerList() /*override*/;

    // vIndex: 386
    // 获取玩家睡眠管理器（只读）。
    virtual ::PlayerSleepManager const &getPlayerSleepManager() const = 0;

    // vIndex: 385
    // 获取玩家睡眠管理器。
    virtual ::PlayerSleepManager &getPlayerSleepManager() = 0;

    // vIndex: 155
    // 获取服务器端的玩家睡眠管理器。
    virtual ::Bedrock::NonOwnerPointer<::ServerPlayerSleepManager>
    getServerPlayerSleepManager() /*override*/;

    // vIndex: 154
    // 获取服务器端的玩家睡眠管理器（只读）。
    virtual ::Bedrock::NonOwnerPointer<::ServerPlayerSleepManager const>
    getServerPlayerSleepManager() const
        /*override*/;

    // vIndex: 122
    // 获取当前世界时间。
    virtual int getTime() const /*override*/;

    // vIndex: 123
    // 设置当前世界时间。
    virtual void setTime(int time) /*override*/;

    // vIndex: 124
    // 获取世界种子（32位）。
    virtual uint getSeed() /*override*/;

    // vIndex: 125
    // 获取世界种子（64位）。
    virtual ::LevelSeed64 getLevelSeed64() const /*override*/;

    // vIndex: 126
    // 获取共享的出生点位置。
    virtual ::BlockPos const &getSharedSpawnPos() const /*override*/;

    // vIndex: 127
    // 设置默认的出生点位置。
    virtual void setDefaultSpawn(::BlockPos const &spawnPos) /*override*/;

    // vIndex: 128
    // 获取默认的出生点位置。
    virtual ::BlockPos const &getDefaultSpawn() const /*override*/;

    // vIndex: 129
    // 设置默认的游戏模式。
    virtual void setDefaultGameType(::GameType) /*override*/;

    // vIndex: 130
    // 获取默认的游戏模式。
    virtual ::GameType getDefaultGameType() const /*override*/;

    // vIndex: 131
    // 设置游戏难度。
    virtual void
    setDifficulty(::SharedTypes::Legacy::Difficulty difficulty) /*override*/;

    // vIndex: 132
    // 设置多人游戏意图。
    virtual void setMultiplayerGameIntent(bool multiplayerGame) /*override*/;

    // vIndex: 133
    // 获取多人游戏意图。
    virtual bool getMultiplayerGameIntent() const /*override*/;

    // vIndex: 134
    // 设置是否为多人游戏。
    virtual void setMultiplayerGame(bool multiplayerGame) /*override*/;

    // vIndex: 135
    // 检查是否为多人游戏。
    virtual bool isMultiplayerGame() const /*override*/;

    // vIndex: 136
    // 设置局域网广播意图。
    virtual void setLANBroadcastIntent(bool broadcast) /*override*/;

    // vIndex: 137
    // 获取局域网广播意图。
    virtual bool getLANBroadcastIntent() const /*override*/;

    // vIndex: 138
    // 设置是否进行局域网广播。
    virtual void setLANBroadcast(bool broadcast) /*override*/;

    // vIndex: 139
    // 获取是否正在进行局域网广播。
    virtual bool getLANBroadcast() const /*override*/;

    // vIndex: 140
    // 设置 Xbox Live 广播意图。
    virtual void
        setXBLBroadcastIntent(::Social::GamePublishSetting) /*override*/;

    // vIndex: 141
    // 获取 Xbox Live 广播意图。
    virtual ::Social::GamePublishSetting getXBLBroadcastIntent() const
        /*override*/;

    // vIndex: 142
    // 检查是否有 Xbox Live 广播意图。
    virtual bool hasXBLBroadcastIntent() const /*override*/;

    // vIndex: 143
    // 设置 Xbox Live 广播模式。
    virtual void setXBLBroadcastMode(::Social::GamePublishSetting) /*override*/;

    // vIndex: 144
    // 获取 Xbox Live 广播模式。
    virtual ::Social::GamePublishSetting getXBLBroadcastMode() const
        /*override*/;

    // vIndex: 145
    // 检查是否正在进行 Xbox Live 广播。
    virtual bool hasXBLBroadcast() const /*override*/;

    // vIndex: 146
    // 设置平台广播意图。
    virtual void
        setPlatformBroadcastIntent(::Social::GamePublishSetting) /*override*/;

    // vIndex: 147
    // 获取平台广播意图。
    virtual ::Social::GamePublishSetting getPlatformBroadcastIntent() const
        /*override*/;

    // vIndex: 148
    // 检查是否有平台广播意图。
    virtual bool hasPlatformBroadcastIntent() const /*override*/;

    // vIndex: 149
    // 设置平台广播模式。
    virtual void
        setPlatformBroadcastMode(::Social::GamePublishSetting) /*override*/;

    // vIndex: 150
    // 获取平台广播模式。
    virtual ::Social::GamePublishSetting getPlatformBroadcastMode() const
        /*override*/;

    // vIndex: 151
    // 检查是否正在进行平台广播。
    virtual bool hasPlatformBroadcast() const /*override*/;

    // vIndex: 152
    // 设置世界是否具有锁定的行为包。
    virtual void setHasLockedBehaviorPack(bool hasLocked) /*override*/;

    // vIndex: 153
    // 设置世界是否具有锁定的资源包。
    virtual void setHasLockedResourcePack(bool hasLocked) /*override*/;

    // vIndex: 156
    // 设置是否启用命令。
    virtual void setCommandsEnabled(bool commandsEnabled) /*override*/;

    // vIndex: 157
    // 解锁世界模板选项。
    virtual void setWorldTemplateOptionsUnlocked() /*override*/;

    // vIndex: 158
    // 检查关卡是否有存储系统。
    virtual bool hasLevelStorage() const /*override*/;

    // vIndex: 160
    // 获取关卡存储系统。
    virtual ::LevelStorage &getLevelStorage() /*override*/;

    // vIndex: 159
    // 获取关卡存储系统（只读）。
    virtual ::LevelStorage const &getLevelStorage() const /*override*/;

    // vIndex: 162
    // 获取关卡数据。
    virtual ::LevelData &getLevelData() /*override*/;

    // vIndex: 161
    // 获取关卡数据（只读）。
    virtual ::LevelData const &getLevelData() const /*override*/;

    // vIndex: 163
    // 获取照片存储。
    virtual ::PhotoStorage &getPhotoStorage() const /*override*/;

    // vIndex: 164
    // 创建照片存储。
    virtual void createPhotoStorage() /*override*/;

    // vIndex: 166
    // 获取照片管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::PhotoManager>
    getPhotoManager() /*override*/;

    // vIndex: 165
    // 获取照片管理器（只读）。
    virtual ::Bedrock::NotNullNonOwnerPtr<::PhotoManager const>
    getPhotoManager() const /*override*/;

    // vIndex: 168
    // 获取教育版设置管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::EducationSettingsManager>
    getEducationSettingsManager() /*override*/;

    // vIndex: 167
    // 获取教育版设置管理器（只读）。
    virtual ::Bedrock::NotNullNonOwnerPtr<::EducationSettingsManager const>
    getEducationSettingsManager() const
        /*override*/;

    // vIndex: 169
    // 保存整个关卡。
    virtual void save() /*override*/;

    // vIndex: 170
    // 保存关卡数据（level.dat）。
    virtual void saveLevelData() /*override*/;

    // vIndex: 171
    // 保存游戏数据（如玩家数据、地图数据等）。
    virtual void saveGameData() /*override*/;

    // vIndex: 172
    // 请求一个定时的存储延迟。
    virtual ::std::shared_ptr<void *>
    requestTimedStorageDeferment() /*override*/;

    // vIndex: 173
    // 获取常加载区块管理器。
    virtual ::TickingAreasManager &getTickingAreasMgr() /*override*/;

    // vIndex: 174
    // 为指定维度添加一个常加载区域列表。
    virtual void addTickingAreaList(
        ::DimensionType dimensionId,
        ::std::shared_ptr<::TickingAreaList> const &tickingAreas) /*override*/;

    // vIndex: 180
    // 播放一个关卡声音事件。
    virtual void playSound(::SharedTypes::Legacy::LevelSoundEvent type,
                           ::Vec3 const &pos, int data,
                           ::ActorSoundIdentifier const &actorSoundIdentifier,
                           bool isGlobal) /*override*/;

    // vIndex: 179
    // 播放一个关卡声音事件，可指定音量和音高。
    virtual void playSound(::SharedTypes::Legacy::LevelSoundEvent type,
                           ::Vec3 const &pos, float const volume,
                           float const pitch) /*override*/;

    // vIndex: 178
    // 通过名称播放声音。
    virtual void playSound(::std::string const &name, ::Vec3 const &pos,
                           float volume, float pitch) /*override*/;

    // vIndex: 177
    // 在指定区域播放一个关卡声音事件。
    virtual void playSound(::IConstBlockSource const &region,
                           ::SharedTypes::Legacy::LevelSoundEvent type,
                           ::Vec3 const &pos, int data,
                           ::ActorSoundIdentifier const &actorSoundIdentifier,
                           bool isGlobal) /*override*/;

    // vIndex: 176
    // 在指定维度播放一个关卡声音事件。
    virtual void playSound(::DimensionType dimension,
                           ::SharedTypes::Legacy::LevelSoundEvent type,
                           ::Vec3 const &pos, int data,
                           ::ActorSoundIdentifier const &actorSoundIdentifier,
                           bool isGlobal) /*override*/;

    // vIndex: 181
    // 获取远程玩家事件协调器。
    virtual ::PlayerEventCoordinator &
    getRemotePlayerEventCoordinator() /*override*/;

    // vIndex: 182
    // 获取服务器玩家事件协调器。
    virtual ::ServerPlayerEventCoordinator &
    getServerPlayerEventCoordinator() /*override*/;

    // vIndex: 183
    // 获取客户端玩家事件协调器。
    virtual ::ClientPlayerEventCoordinator &
    getClientPlayerEventCoordinator() /*override*/;

    // vIndex: 184
    // 获取实体事件协调器。
    virtual ::ActorEventCoordinator &getActorEventCoordinator() /*override*/;

    // vIndex: 185
    // 获取方块事件协调器。
    virtual ::BlockEventCoordinator &getBlockEventCoordinator() /*override*/;

    // vIndex: 186
    // 获取物品事件协调器。
    virtual ::ItemEventCoordinator &getItemEventCoordinator() /*override*/;

    // vIndex: 187
    // 获取服务器网络事件协调器。
    virtual ::ServerNetworkEventCoordinator &
    getServerNetworkEventCoordinator() /*override*/;

    // vIndex: 188
    // 获取脚本事件协调器。
    virtual ::ScriptingEventCoordinator &
    getScriptingEventCoordinator() /*override*/;

    // vIndex: 189
    // 获取脚本延迟事件协调器。
    virtual ::ScriptDeferredEventCoordinator &
    getScriptDeferredEventCoordinator() /*override*/;

    // vIndex: 190
    // 获取关卡事件协调器。
    virtual ::LevelEventCoordinator &getLevelEventCoordinator() /*override*/;

    // vIndex: 192
    // 处理一个关卡事件（带位置和数据）。
    virtual void handleLevelEvent(::SharedTypes::Legacy::LevelEvent type,
                                  ::Vec3 const &pos, int data) /*override*/;

    // vIndex: 191
    // 处理一个关卡事件（带 CompoundTag 数据）。
    virtual void handleLevelEvent(::SharedTypes::Legacy::LevelEvent type,
                                  ::CompoundTag const &data) /*override*/;

    // vIndex: 193
    // 获取关卡事件管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::LevelEventManager>
    getLevelEventManager() /*override*/;

    // vIndex: 194
    // 处理停止指定名称的声音事件。
    virtual void handleStopSoundEvent(::std::string const &name) /*override*/;

    // vIndex: 195
    // 处理停止所有声音的事件。
    virtual void handleStopAllSounds() /*override*/;

    // vIndex: 196
    // 处理停止音乐的事件。
    virtual void handleStopMusicEvent() /*override*/;

    // vIndex: 198
    // 广播一个关卡事件（带位置和数据）。
    virtual void broadcastLevelEvent(
        ::SharedTypes::Legacy::LevelEvent type, ::Vec3 const &pos, int data,
        ::UserEntityIdentifierComponent const *userIdentifier) /*override*/;

    // vIndex: 197
    // 广播一个关卡事件（带 CompoundTag 数据）。
    virtual void broadcastLevelEvent(
        ::SharedTypes::Legacy::LevelEvent type, ::CompoundTag const &tag,
        ::UserEntityIdentifierComponent const *userIdentifier) /*override*/;

    // vIndex: 200
    // 在指定区域广播一个本地事件（对区域内玩家可见）。
    virtual void broadcastLocalEvent(::BlockSource &region,
                                     ::SharedTypes::Legacy::LevelEvent type,
                                     ::Vec3 const &pos, int data) /*override*/;

    // vIndex: 199
    // 在指定区域广播一个与方块相关的本地事件。
    virtual void broadcastLocalEvent(::BlockSource &region,
                                     ::SharedTypes::Legacy::LevelEvent type,
                                     ::Vec3 const &pos,
                                     ::Block const &block) /*override*/;

    // vIndex: 203
    // 在指定区域广播一个与方块相关的声音事件。
    virtual void
    broadcastSoundEvent(::BlockSource &region,
                        ::SharedTypes::Legacy::LevelSoundEvent type,
                        ::Vec3 const &pos, ::Block const &block,
                        ::ActorSoundIdentifier const &actorSoundIdentifier,
                        bool isGlobal) /*override*/;

    // vIndex: 202
    // 在指定区域广播一个声音事件。
    virtual void
    broadcastSoundEvent(::BlockSource &region,
                        ::SharedTypes::Legacy::LevelSoundEvent type,
                        ::Vec3 const &pos, int data,
                        ::ActorSoundIdentifier const &actorSoundIdentifier,
                        bool isGlobal) /*override*/;

    // vIndex: 201
    // 在指定维度广播一个声音事件。
    virtual void
    broadcastSoundEvent(::Dimension &dimension,
                        ::SharedTypes::Legacy::LevelSoundEvent type,
                        ::Vec3 const &pos, int data,
                        ::ActorSoundIdentifier const &actorSoundIdentifier,
                        bool isGlobal) /*override*/;

    // vIndex: 204
    // 广播一个实体事件。
    virtual void broadcastActorEvent(::Actor &actor, ::ActorEvent eventId,
                                     int data) const /*override*/;

    // vIndex: 205
    // 获取实体事件广播器。
    virtual ::Bedrock::NonOwnerPointer<::ActorEventBroadcaster const>
    getActorEventBroadcaster() const /*override*/;

    // vIndex: 206
    // 添加一个区块视野追踪器。
    virtual void addChunkViewTracker(
        ::std::weak_ptr<::ChunkViewSource> chunkViewSource) /*override*/;

    // vIndex: 207
    // 当一个区域的区块被重载时调用。
    virtual void onChunkReload(::Bounds const &bound) /*override*/;

    // vIndex: 209
    // 获取活跃玩家数量。
    virtual int getActivePlayerCount() const /*override*/;

    // vIndex: 210
    // 获取活跃用户数量。
    virtual int getActiveUsersCount() const /*override*/;

    // vIndex: 212
    // 遍历所有玩家（可修改）。
    virtual void
    forEachPlayer(::std::function<bool(::Player &)> callback) /*override*/;

    // vIndex: 211
    // 遍历所有玩家（只读）。
    virtual void
    forEachPlayer(::std::function<bool(::Player const &)> callback) const
        /*override*/;

    // vIndex: 214
    // 遍历所有用户（可修改）。
    virtual void
    forEachUser(::std::function<bool(::EntityContext &)> callback) /*override*/;

    // vIndex: 213
    // 遍历所有用户（只读）。
    virtual void
    forEachUser(::std::function<bool(::EntityContext const &)> callback) const
        /*override*/;

    // vIndex: 216
    // 查找满足条件的第一个玩家。
    virtual ::Player *
    findPlayer(::std::function<bool(::Player const &)> pred) const /*override*/;

    // vIndex: 215
    // 通过实体引用查找满足条件的第一个玩家。
    virtual ::Player *
    findPlayer(::std::function<bool(::WeakEntityRef const &)> pred) const
        /*override*/;

    // vIndex: 217
    // 获取用户总数。
    virtual int getUserCount() const /*override*/;

    // vIndex: 218
    // 计算具有匹配网络标识符的用户数量。
    virtual int
    countUsersWithMatchingNetworkId(::NetworkIdentifier const &networkId) const
        /*override*/;

    // vIndex: 219
    // 获取所有用户的列表（只读）。
    virtual ::std::vector<::OwnerPtr<::EntityContext>> const &getUsers() const
        /*override*/;

    // vIndex: 220
    // 获取所有实体的列表（只读）。
    virtual ::std::vector<::OwnerPtr<::EntityContext>> const &
    getEntities() const /*override*/;

    // vIndex: 1
    // 当一个方块源被创建时调用。
    virtual void onSourceCreated(::BlockSource &source) /*override*/;

    // vIndex: 2
    // 当一个方块源被销毁时调用。
    virtual void onSourceDestroyed(::BlockSource &source) /*override*/;

    // vIndex: 221
    // 当一个子区块被加载时调用。
    virtual void onSubChunkLoaded(::ChunkSource &source, ::LevelChunk &lc,
                                  short absoluteSubChunkIndex,
                                  bool subChunkVisibilityChanged) /*override*/;

    // vIndex: 222
    // 获取子区块管理器。
    virtual ::Bedrock::NonOwnerPointer<::SubChunkManager>
    getSubChunkManager() /*override*/;

    // vIndex: 223
    // 当一个区块被加载时调用。
    virtual void onChunkLoaded(::ChunkSource &source,
                               ::LevelChunk &lc) /*override*/;

    // vIndex: 208
    // 当一个区块被重载时调用。
    virtual void onChunkReloaded(::ChunkSource &source,
                                 ::LevelChunk &lc) /*override*/;

    // vIndex: 226
    // 获取关卡区块元数据管理器。
    virtual ::LevelChunkMetaDataManager *
    getLevelChunkMetaDataManager() /*override*/;

    // vIndex: 224
    // 当一个区块被丢弃时调用。
    virtual void onChunkDiscarded(::LevelChunk &lc) /*override*/;

    // vIndex: 225
    // 获取关卡区块事件管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::LevelChunkEventManager>
    getLevelChunkEventManager() /*override*/;

    // vIndex: 227
    // 将一个实体加入销毁队列。
    virtual void
    queueEntityDestruction(::OwnerPtr<::EntityContext> entity) /*override*/;

    // vIndex: 229
    // 移除一个实体并返回其所有权。
    virtual ::OwnerPtr<::EntityContext>
    removeEntity(::Actor &actor) /*override*/;

    // vIndex: 228
    // 通过弱引用移除一个实体并返回其所有权。
    virtual ::OwnerPtr<::EntityContext>
    removeEntity(::WeakEntityRef entityRef) /*override*/;

    // vIndex: 230
    // 强制移除一个实体。
    virtual void forceRemoveEntity(::Actor &actor) /*override*/;

    // vIndex: 231
    // 强制从世界中移除一个实体。
    virtual void forceRemoveEntityfromWorld(::Actor &actor) /*override*/;

    // vIndex: 232
    // 强制刷新已移除的玩家。
    virtual void forceFlushRemovedPlayers() /*override*/;

    // vIndex: 233
    // 加载函数管理器。
    virtual void loadFunctionManager() /*override*/;

    // vIndex: 234
    // 在关卡清理阶段将实体加入移除队列。
    virtual void levelCleanupQueueEntityRemoval(
        ::OwnerPtr<::EntityContext> entity) /*override*/;

    // vIndex: 235
    // 注册一个临时指针（用于Tick期间的引用管理）。
    virtual void registerTemporaryPointer(::_TickPtr &ptr) /*override*/;

    // vIndex: 236
    // 取消注册一个临时指针。
    virtual void unregisterTemporaryPointer(::_TickPtr &ptr) /*override*/;

    // vIndex: 237
    // 获取临时实体指针管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::TempEPtrManager>
    getTempEPtrManager() /*override*/;

    // vIndex: 238
    // 销毁一个方块。
    virtual bool destroyBlock(::BlockSource &region, ::BlockPos const &pos,
                              bool dropResources) /*override*/;

    // vIndex: 239
    // 获取关卡方块销毁器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::LevelBlockDestroyer>
    getLevelBlockDestroyer() /*override*/;

    // vIndex: 240
    // 升级存储版本。
    virtual void upgradeStorageVersion(::StorageVersion) /*override*/;

    // vIndex: 241
    // 暂停并保存游戏。
    virtual void suspendAndSave() /*override*/;

    // vIndex: 175
    // 发送一个旧版的服务器粒子效果。
    virtual void sendServerLegacyParticle(::ParticleType id, ::Vec3 const &pos,
                                          ::Vec3 const &dir,
                                          int data) /*override*/;

    // vIndex: 242
    // 添加一个粒子效果。
    virtual ::Particle *addParticle(::ParticleType id, ::Vec3 const &pos,
                                    ::Vec3 const &dir, int data,
                                    ::CompoundTag const *tag,
                                    bool isGlobal) /*override*/;

    // vIndex: 112
    // 生成一个粒子效果。
    virtual void spawnParticleEffect(::std::string const &effectName,
                                     ::Vec3 const &spawnLocation,
                                     ::Dimension *dimension) /*override*/;

    // vIndex: 113
    // 获取服务器粒子管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::ServerParticleManager>
    getServerParticleManager() /*override*/;

    // vIndex: 243
    // 添加一个粒子效果。
    virtual void
    addParticleEffect(::HashedString const &effect,
                      ::Vec3 const &emitterPosition,
                      ::MolangVariableMap const &molangVariables) /*override*/;

    // vIndex: 244
    // 添加地形粒子效果（如方块破坏粒子）。
    virtual void addTerrainParticleEffect(::BlockPos const &pos,
                                          ::Block const &block,
                                          ::Vec3 const &emitterPosition,
                                          float intensity, float velocityScalar,
                                          float emitterRadius) /*override*/;

    // vIndex: 245
    // 添加地形滑落效果（如沙子、沙砾）。
    virtual void addTerrainSlideEffect(::BlockPos const &pos,
                                       ::Block const &block,
                                       ::Vec3 const &emitterPosition,
                                       float intensity, float velocityScalar,
                                       float emitterRadius) /*override*/;

    // vIndex: 246
    // 添加物品破坏粒子效果。
    virtual void addBreakingItemParticleEffect(
        ::Vec3 const &pos, ::BreakingItemParticleData const &data,
        ::ResolvedItemIconInfo const &textureInfo) /*override*/;

    // vIndex: 247
    // 添加带生物群系着色的粒子效果。
    virtual void addBiomeTintedParticleEffect(
        ::HashedString const &effect, ::BlockPos const &pos,
        ::Block const &block,
        ::std::optional<::mce::Color> overrideColor) /*override*/;

    // vIndex: 248
    // 获取一个新的实体唯一ID。
    virtual ::ActorUniqueID getNewUniqueID() /*override*/;

    // vIndex: 249
    // 获取下一个实体运行时ID。
    virtual ::ActorRuntimeID getNextRuntimeID() /*override*/;

    // vIndex: 250
    // 获取Tick偏移量列表。
    virtual ::std::vector<::ChunkPos> const &getTickingOffsets() const
        /*override*/;

    // vIndex: 251
    // 获取客户端的Tick偏移量列表。
    virtual ::std::vector<::ChunkPos> const &getClientTickingOffsets() const
        /*override*/;

    // vIndex: 252
    // 根据客户端偏移量获取排序后的位置列表。
    virtual ::std::vector<::ChunkPos> getSortedPositionsFromClientOffsets(
        ::std::vector<::ChunkPos> const &centers) const /*override*/;

    // vIndex: 253
    // 获取区块Tick偏移管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::ChunkTickOffsetManager const>
    getChunkTickOffsetManager() const
        /*override*/;

    // vIndex: 254
    // 检查关卡是否正在导出。
    virtual bool isExporting() const /*override*/;

    // vIndex: 255
    // 设置关卡是否正在导出。
    virtual void setIsExporting(bool IsExporting) /*override*/;

    // vIndex: 256
    // 获取已保存数据存储。
    virtual ::SavedDataStorage &getSavedData() /*override*/;

    // vIndex: 259
    // 通过UUID获取地图的已保存数据。
    virtual ::MapItemSavedData *
    getMapSavedData(::ActorUniqueID const uuid) /*override*/;

    // vIndex: 258
    // 通过CompoundTag实例获取地图的已保存数据。
    virtual ::MapItemSavedData *
    getMapSavedData(::CompoundTag const &instance) /*override*/;

    // vIndex: 257
    // 通过CompoundTag指针获取地图的已保存数据。
    virtual ::MapItemSavedData *
    getMapSavedData(::CompoundTag const *instance) /*override*/;

    // vIndex: 260
    // 请求地图信息。
    virtual void requestMapInfo(::ActorUniqueID const uuid,
                                bool forceUpdate) /*override*/;

    // vIndex: 261
    // 通过ID扩展地图。
    virtual ::ActorUniqueID expandMapByID(::ActorUniqueID const uuid,
                                          bool wasInit) /*override*/;

    // vIndex: 262
    // 复制并锁定地图。
    virtual bool copyAndLockMap(::ActorUniqueID const originalMapUuid,
                                ::ActorUniqueID const newMapUuid) /*override*/;

    // vIndex: 264
    // 创建一个新的地图已保存数据。
    virtual ::MapItemSavedData &
    createMapSavedData(::ActorUniqueID const &uuid, ::BlockPos const &origin,
                       ::DimensionType dimension,
                       int returnScaleLevel) /*override*/;

    // vIndex: 263
    // 为一组地图ID创建新的地图已保存数据。
    virtual ::MapItemSavedData &
    createMapSavedData(::std::vector<::ActorUniqueID> const &mapIds,
                       ::BlockPos const &origin, ::DimensionType dimension,
                       int returnScaleLevel) /*override*/;

    // vIndex: 265
    // 获取截图文件夹路径。
    virtual ::Core::PathBuffer<::std::string> getScreenshotsFolder() const
        /*override*/;

    // vIndex: 266
    // 获取关卡ID。
    virtual ::std::string getLevelId() const /*override*/;

    // vIndex: 267
    // 设置关卡ID。
    virtual void setLevelId(::std::string LevelId) /*override*/;

    // vIndex: 268
    // 获取同步任务组。
    virtual ::TaskGroup &getSyncTasksGroup() /*override*/;

    // vIndex: 269
    // 获取IO任务组。
    virtual ::TaskGroup &getIOTasksGroup() /*override*/;

    // vIndex: 270
    // 获取客户端资源包管理器。
    virtual ::ResourcePackManager *getClientResourcePackManager() const
        /*override*/;

    // vIndex: 271
    // 获取服务器资源包管理器。
    virtual ::ResourcePackManager *getServerResourcePackManager() const
        /*override*/;

    // vIndex: 272
    // 获取交易表。
    virtual ::TradeTables *getTradeTables() /*override*/;

    // vIndex: 273
    // 减少标签缓存计数。
    virtual void decrementTagCache(
        ::std::string const &tag,
        ::TagRegistry<::IDType<::LevelTagIDType>, ::IDType<::LevelTagSetIDType>>
            &tagRegistry) /*override*/;

    // vIndex: 274
    // 增加标签缓存计数。
    virtual void incrementTagCache(
        ::std::string const &tag,
        ::TagRegistry<::IDType<::LevelTagIDType>, ::IDType<::LevelTagSetIDType>>
            &tagRegistry) /*override*/;

    // vIndex: 275
    // 获取标签缓存管理器。
    virtual ::Bedrock::NonOwnerPointer<::TagCacheManager>
    getTagCacheManager() /*override*/;

    // vIndex: 276
    // 检查是否为教育版。
    virtual bool isEdu() const /*override*/;

    // vIndex: 278
    // 获取实体工厂。
    virtual ::ActorFactory &getActorFactory() /*override*/;

    // vIndex: 277
    // 获取实体工厂（只读）。
    virtual ::ActorFactory const &getActorFactory() const /*override*/;

    // vIndex: 279
    // 获取实体信息注册表。
    virtual ::ActorInfoRegistry *getActorInfoRegistry() /*override*/;

    // vIndex: 281
    // 获取实体注册表。
    virtual ::StackRefResult<::EntityRegistry> getEntityRegistry() /*override*/;

    // vIndex: 280
    // 获取实体注册表（只读）。
    virtual ::StackRefResult<::EntityRegistry const> getEntityRegistry() const
        /*override*/;

    // vIndex: 282
    // 获取实体系统。
    virtual ::EntitySystems &getEntitySystems() /*override*/;

    // vIndex: 284
    // 获取关卡实体上下文的弱引用。
    virtual ::WeakRef<::EntityContext> getLevelEntity() /*override*/;

    // vIndex: 283
    // 获取关卡实体上下文的弱引用（只读）。
    virtual ::WeakRef<::EntityContext const> getLevelEntity() const
        /*override*/;

    // vIndex: 285
    // 尝试获取服务器端的体积实体管理器。
    virtual ::Bedrock::NonOwnerPointer<::VolumeEntityManagerServer>
    tryGetVolumeEntityManagerServer() const
        /*override*/;

    // vIndex: 287
    // 运行一个命令（通过字符串）。
    virtual void
    runCommand(::HashedString const &commandStr, ::CommandOrigin &origin,
               ::CommandOriginSystem originSystem,
               ::CurrentCmdVersion const commandVersion) /*override*/;

    // vIndex: 286
    // 运行一个命令（通过命令对象）。
    virtual void runCommand(::Command &command, ::CommandOrigin &origin,
                            ::CommandOriginSystem originSystem) /*override*/;

    // vIndex: 288
    // 获取玩家能力共享控制器。
    virtual ::PlayerCapabilities::ISharedController const &
    getCapabilities() const /*override*/;

    // vIndex: 289
    // 获取标签注册表。
    virtual ::TagRegistry<::IDType<::LevelTagIDType>,
                          ::IDType<::LevelTagSetIDType>> &
    getTagRegistry() /*override*/;

    // vIndex: 290
    // 获取玩家移动设置。
    virtual ::PlayerMovementSettings const &getPlayerMovementSettings() const
        /*override*/;

    // vIndex: 291
    // 设置玩家移动设置。
    virtual void setPlayerMovementSettings(
        ::PlayerMovementSettings const &settings) /*override*/;

    // vIndex: 293
    // 获取玩家移动设置管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::PlayerMovementSettingsManager>
    getPlayerMovementSettingsManager() /*override*/;

    // vIndex: 292
    // 获取玩家移动设置管理器（只读）。
    virtual ::Bedrock::NotNullNonOwnerPtr<::PlayerMovementSettingsManager const>
    getPlayerMovementSettingsManager() const /*override*/;

    // vIndex: 294
    // 检查是否可以使用指定的皮肤。
    virtual bool canUseSkin(::SerializedSkin const &skin,
                            ::NetworkIdentifier const &networkIdentifier,
                            ::ActorUniqueID const &playerId) const /*override*/;

    // vIndex: 295
    // 获取受信任的皮肤助手。
    virtual ::Bedrock::NonOwnerPointer<::TrustedSkinHelper const>
    getTrustedSkinHelper() const /*override*/;

    // vIndex: 371
    // 获取相机注册表（只读）。
    virtual ::Bedrock::NonOwnerPointer<::CameraRegistry const>
    getCameraRegistry() const /*override*/;

    // vIndex: 370
    // 获取相机注册表。
    virtual ::Bedrock::NonOwnerPointer<::CameraRegistry>
    getCameraRegistry() /*override*/;

    // vIndex: 372
    // 获取相机系统。
    virtual ::Bedrock::NonOwnerPointer<::EntitySystems>
    getCameraSystems() /*override*/;

    // vIndex: 296
    // 获取位置追踪数据库客户端。
    virtual ::PositionTrackingDB::PositionTrackingDBClient *
    getPositionTrackerDBClient() const /*override*/;

    // vIndex: 297
    // 获取位置追踪数据库服务器。
    virtual ::PositionTrackingDB::PositionTrackingDBServer *
    getPositionTrackerDBServer() const /*override*/;

    // vIndex: 298
    // 刷新运行时光照。
    virtual void flushRunTimeLighting() /*override*/;

    // vIndex: 299
    // 加载方块定义组。
    virtual void
    loadBlockDefinitionGroup(::Experiments const &experiments) /*override*/;

    // vIndex: 300
    // 初始化方块定义组。
    virtual void initializeBlockDefinitionGroup() /*override*/;

    // vIndex: 301
    // 获取未知方块类型注册表。
    virtual ::Bedrock::NonOwnerPointer<::IUnknownBlockTypeRegistry>
    getUnknownBlockTypeRegistry() /*override*/;

    // vIndex: 373
    // 检查客户端侧区块生成是否启用。
    virtual bool isClientSideGenerationEnabled() /*override*/;

    // vIndex: 374
    // 检查方块网络ID是否为哈希值。
    virtual bool blockNetworkIdsAreHashes() /*override*/;

    // vIndex: 375
    // 获取物品注册表引用。
    virtual ::ItemRegistryRef getItemRegistry() const /*override*/;

    // vIndex: 376
    // 获取方块类型注册表的弱引用。
    virtual ::std::weak_ptr<::BlockTypeRegistry> getBlockRegistry() const
        /*override*/;

    // vIndex: 368
    // 将自身转换为 Level 指针。
    virtual ::Level *asLevel() /*override*/;

    // vIndex: 361
    // 检查是否使用3D生物群系地图。
    virtual bool use3DBiomeMaps() const /*override*/;

    // vIndex: 362
    // 为有效性追踪添加一个方块源。
    virtual void
    addBlockSourceForValidityTracking(::BlockSource *region) /*override*/;

    // vIndex: 363
    // 从有效性追踪中移除一个方块源。
    virtual void
    removeBlockSourceFromValidityTracking(::BlockSource *region) /*override*/;

    // vIndex: 364
    // 获取方块源有效性管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::BlockSourceValidityManager>
    getBlockSourceValidityManager() /*override*/;

    // vIndex: 377
    // 暂停并刷新任务组。
    virtual void pauseAndFlushTaskGroups() /*override*/;

    // vIndex: 10
    // 获取维度管理器。
    virtual ::DimensionManager &getDimensionManager() /*override*/;

    // vIndex: 9
    // 获取维度管理器（只读）。
    virtual ::DimensionManager const &getDimensionManager() const /*override*/;

    // vIndex: 379
    // 对子区块进行Tick并发送请求。
    virtual void subChunkTickAndSendRequests() /*override*/;

    // vIndex: 387
    // 执行子Tick逻辑。
    virtual void _subTick();

    // vIndex: 107
    // 获取暂停管理器。
    virtual ::StackRefResult<::PauseManager> getPauseManager() /*override*/;

    // vIndex: 106
    // 获取暂停管理器（只读）。
    virtual ::StackRefResult<::PauseManager const> getPauseManager() const
        /*override*/;

    // vIndex: 302
    // 检查是否为客户端侧。
    virtual bool isClientSide() const /*override*/;

    // vIndex: 303
    // 获取玩家列表。
    virtual ::std::unordered_map<::mce::UUID, ::PlayerListEntry> const &
    getPlayerList() const /*override*/;

    // vIndex: 304
    // 通过UUID获取玩家的XUID。
    virtual ::std::string const &getPlayerXUID(::mce::UUID const &uuid) const
        /*override*/;

    // vIndex: 305
    // 通过UUID获取玩家的平台在线ID。
    virtual ::std::string const &
    getPlayerPlatformOnlineId(::mce::UUID const &uuid) const /*override*/;

    // vIndex: 307
    // 获取玩家列表管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::PlayerListManager>
    getPlayerListManager() /*override*/;

    // vIndex: 306
    // 获取玩家列表管理器（只读）。
    virtual ::Bedrock::NotNullNonOwnerPtr<::PlayerListManager const>
    getPlayerListManager() const /*override*/;

    // vIndex: 308
    // 获取活跃用户的弱引用列表。
    virtual ::std::vector<::WeakEntityRef> const &getActiveUsers() const
        /*override*/;

    // vIndex: 310
    // 通知子区块请求管理器。
    virtual void
    notifySubChunkRequestManager(::SubChunkPacket const &packet) /*override*/;

    // vIndex: 311
    // 获取子区块请求管理器。
    virtual ::SubChunkRequestManager *getSubChunkRequestManager() /*override*/;

    // vIndex: 309
    // 获取运行时实体列表。
    virtual ::std::vector<::Actor *> getRuntimeActorList() const /*override*/;

    // vIndex: 312
    // 获取网络数据包发送器。
    virtual ::PacketSender *getPacketSender() const /*override*/;

    // vIndex: 313
    // 获取网络事件回调。
    virtual ::Bedrock::NonOwnerPointer<::NetEventCallback>
    getNetEventCallback() const /*override*/;

    // vIndex: 314
    // 设置网络事件回调。
    virtual void setNetEventCallback(
        ::Bedrock::NonOwnerPointer<::NetEventCallback> val) /*override*/;

    // vIndex: 315
    // 获取关卡随机数生成器接口。
    virtual ::gsl::not_null<::StackRefResult<::ILevelRandom>>
    getILevelRandom() /*override*/;

    // vIndex: 316
    // 获取随机数生成器接口。
    virtual ::IRandom &getIRandom() const /*override*/;

    // vIndex: 317
    // 获取随机数生成器。
    virtual ::Random &getRandom() const /*override*/;

    // vIndex: 318
    // 获取线程随机数生成器。
    virtual ::Random &getThreadRandom() const /*override*/;

    // vIndex: 319
    // 获取命中结果。
    virtual ::HitResult &getHitResult() /*override*/;

    // vIndex: 320
    // 获取液体命中结果。
    virtual ::HitResult &getLiquidHitResult() /*override*/;

    // vIndex: 321
    // 获取命中结果包装器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::HitResultWrapper>
    getHitResultWrapper() /*override*/;

    // vIndex: 322
    // 获取沉浸式阅读器字符串。
    virtual ::std::string const &getImmersiveReaderString() const /*override*/;

    // vIndex: 323
    // 设置沉浸式阅读器字符串。
    virtual void setImmersiveReaderString(::std::string newString) /*override*/;

    // vIndex: 325
    // 获取冒险设置。
    virtual ::AdventureSettings &getAdventureSettings() /*override*/;

    // vIndex: 324
    // 获取冒险设置（只读）。
    virtual ::AdventureSettings const &getAdventureSettings() const
        /*override*/;

    // vIndex: 327
    // 获取游戏规则（只读）。
    virtual ::GameRules const &getGameRules() const /*override*/;

    // vIndex: 326
    // 获取游戏规则。
    virtual ::GameRules &getGameRules() /*override*/;

    // vIndex: 328
    // 检查是否启用了“开局带地图”。
    virtual bool hasStartWithMapEnabled() const /*override*/;

    // vIndex: 329
    // 检查是否为编辑器世界。
    virtual bool isEditorWorld() const /*override*/;

    // vIndex: 330
    // 检查是否为极限模式。
    virtual bool isHardcore() const /*override*/;

    // vIndex: 331
    // 获取默认能力。
    virtual ::Abilities &getDefaultAbilities() /*override*/;

    // vIndex: 333
    // 获取默认权限。
    virtual ::PermissionsHandler &getDefaultPermissions() /*override*/;

    // vIndex: 332
    // 获取默认权限（只读）。
    virtual ::PermissionsHandler const &getDefaultPermissions() const
        /*override*/;

    // vIndex: 334
    // 获取关卡是否正在被关闭。
    virtual bool getTearingDown() const /*override*/;

    // vIndex: 335
    // 拍照。
    virtual void takePicture(
        ::cg::ImageBuffer &outImage, ::Actor *camera, ::Actor *target,
        ::ScreenshotOptions &screenshotOptions,
        ::std::function<void(::cg::ImageBuffer &, ::ScreenshotOptions &)>
            completedScreenshotCallback) /*override*/;

    // vIndex: 336
    // 获取关卡声音管理器。
    virtual ::LevelSoundManager &getLevelSoundManager() /*override*/;

    // vIndex: 337
    // 获取声音播放器接口。
    virtual ::Bedrock::NotNullNonOwnerPtr<::SoundPlayerInterface>
    getSoundPlayer() const /*override*/;

    // vIndex: 338
    // 设置模拟是否暂停。
    virtual void setSimPaused(bool value) /*override*/;

    // vIndex: 339
    // 获取模拟是否暂停。
    virtual bool getSimPaused() /*override*/;

    // vIndex: 340
    // 设置已完成初始化。
    virtual void setFinishedInitializing() /*override*/;

    // vIndex: 341
    // 获取战利品表。
    virtual ::LootTables &getLootTables() /*override*/;

    // vIndex: 342
    // 更新天气。
    virtual void updateWeather(float rainLevel, int rainTime,
                               float lightningLevel,
                               int lightningTime) /*override*/;

    // vIndex: 343
    // 获取下界缩放比例。
    virtual int getNetherScale() const /*override*/;

    // vIndex: 345
    // 获取计分板。
    virtual ::Scoreboard &getScoreboard() /*override*/;

    // vIndex: 344
    // 获取计分板（只读）。
    virtual ::Scoreboard const &getScoreboard() const /*override*/;

    // vIndex: 346
    // 尝试获取计分板。
    virtual ::Scoreboard *tryGetScoreboard() /*override*/;

    // vIndex: 347
    // 获取指定玩家的分层能力。
    virtual ::LayeredAbilities *
    getPlayerAbilities(::ActorUniqueID const &playerId) /*override*/;

    // vIndex: 348
    // 设置指定玩家的分层能力。
    virtual void
    setPlayerAbilities(::ActorUniqueID const &playerId,
                       ::LayeredAbilities const &abilities) /*override*/;

    // vIndex: 349
    // 发送指定玩家的所有能力给客户端。
    virtual void
    sendAllPlayerAbilities(::Player const &playerReference) /*override*/;

    // vIndex: 350
    // 获取玩家能力管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::PlayerAbilitiesManager>
    getPlayerAbilitiesManager() /*override*/;

    // vIndex: 351
    // 获取玩家权限管理器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::PlayerPermissionsManager>
    getPlayerPermissionsManager() /*override*/;

    // vIndex: 352
    // 获取玩家权限同步器。
    virtual ::Bedrock::NotNullNonOwnerPtr<::PlayerPermissionsSynchroniser>
    getPlayerPermissionsSynchroniser() /*override*/;

    // vIndex: 353
    // 获取配方。
    virtual ::Recipes &getRecipes() const /*override*/;

    // vIndex: 354
    // 获取方块转换器。
    virtual ::BlockReducer *getBlockReducer() const /*override*/;

    // vIndex: 356
    // 获取盔甲纹饰图案注册表的弱引用（只读）。
    virtual ::std::weak_ptr<::TrimPatternRegistry const>
    getTrimPatternRegistry() const /*override*/;

    // vIndex: 355
    // 获取盔甲纹饰图案注册表的弱引用。
    virtual ::std::weak_ptr<::TrimPatternRegistry>
    getTrimPatternRegistry() /*override*/;

    // vIndex: 358
    // 获取盔甲纹饰材料注册表的弱引用（只读）。
    virtual ::std::weak_ptr<::TrimMaterialRegistry const>
    getTrimMaterialRegistry() const /*override*/;

    // vIndex: 357
    // 获取盔甲纹饰材料注册表的弱引用。
    virtual ::std::weak_ptr<::TrimMaterialRegistry>
    getTrimMaterialRegistry() /*override*/;

    // vIndex: 359
    // 获取已注册的边界方块。
    virtual ::BlockLegacy const &getRegisteredBorderBlock() const /*override*/;

    // vIndex: 360
    // 获取关卡区块性能遥测。
    virtual ::Bedrock::NotNullNonOwnerPtr<::LevelChunkPerformanceTelemetry>
    getLevelChunkPerformanceTelemetry() /*override*/;

    // vIndex: 378
    // 获取序列化上下文（只读）。
    virtual ::cereal::ReflectionCtx const &cerealContext() const /*override*/;

    // vIndex: 366
    // 获取区块生成管理器。
    virtual ::Bedrock::NonOwnerPointer<::ChunkGenerationManager>
    getChunkGenerationManager() /*override*/;

    // vIndex: 365
    // 获取区块生成管理器（只读）。
    virtual ::Bedrock::NonOwnerPointer<::ChunkGenerationManager const>
    getChunkGenerationManager() const /*override*/;

    // vIndex: 380
    // 获取玩家死亡管理器。
    virtual ::PlayerDeathManager *_getPlayerDeathManager() /*override*/;

    // vIndex: 388
    // 初始化地图数据管理器。
    virtual void _initializeMapDataManager();

    // vIndex: 382
    // 获取序列化上下文。
    virtual ::cereal::ReflectionCtx &_cerealContext() /*override*/;

    // vIndex: 383
    // 在低内存时调用。
    virtual void _onLowMemory() /*override*/;
    // NOLINTEND

  public:
    // member functions
    // 成员函数
    // NOLINTBEGIN
    /**
     * @brief Level 类的构造函数。
     * @param packetSender 用于发送网络数据包的发送器。
     * @param soundPlayer 声音播放器接口。
     * @param levelStorage 关卡存储，用于加载和保存世界数据。
     * @param levelData 关卡数据，包含世界的基本设置。
     * @param eventing Minecraft 事件系统接口。
     * @param isClientSide 标记是否为客户端侧的 Level 实例。
     * @param subClientId 子客户端ID。
     * @param callbackContext 调度器，用于任务调度。
     * @param structureManager 结构管理器。
     * @param addOnResourcePackManager 附加包资源管理器。
     * @param entityRegistryOwner 实体注册表的所有者。
     * @param levelEntity 关卡自身的实体上下文。
     * @param itemRegistry 物品注册表。
     * @param blockRegistry 方块类型注册表。
     * @param clientSideChunkGenerationEnabled 是否启用客户端侧区块生成。
     * @param blockNetworkIdsAreHashes 方块网络ID是否为哈希值。
     * @param networkPermissions 网络权限。
     * @param dimensionDefinitionGroup 维度定义组。
     * @param validator 关联资源验证器。
     */
    MCAPI
    Level(::Bedrock::NotNullNonOwnerPtr<::PacketSender> packetSender,
          ::Bedrock::NotNullNonOwnerPtr<::SoundPlayerInterface> const
              &soundPlayer,
          ::Bedrock::UniqueOwnerPointer<::LevelStorage> levelStorage,
          ::Bedrock::NotNullNonOwnerPtr<::LevelData> levelData,
          ::IMinecraftEventing &eventing, bool isClientSide,
          ::SubClientId subClientId, ::Scheduler &callbackContext,
          ::Bedrock::NotNullNonOwnerPtr<::StructureManager> structureManager,
          ::ResourcePackManager &addOnResourcePackManager,
          ::Bedrock::NotNullNonOwnerPtr<::IEntityRegistryOwner> const
              &entityRegistryOwner,
          ::WeakRef<::EntityContext> levelEntity,
          ::ItemRegistryRef itemRegistry,
          ::std::weak_ptr<::BlockTypeRegistry> blockRegistry,
          bool clientSideChunkGenerationEnabled, bool blockNetworkIdsAreHashes,
          ::NetworkPermissions const &networkPermissions,
          ::std::optional<::DimensionDefinitionGroup> dimensionDefinitionGroup,
          ::Bedrock::NonOwnerPointer<::LinkedAssetValidator> validator);

    // 创建照片管理器。
    MCAPI ::Bedrock::UniqueOwnerPointer<::PhotoManager> _createPhotoManager();

    // 初始化实体管理器。
    MCAPI void _initializeActorManager();

    // 初始化生物群系管理器。
    MCAPI void _initializeBiomeManager();

    // 初始化事件协调器管理器。
    MCAPI void _initializeEventCoordinatorManager();

    // 初始化游戏性用户（玩家）管理器。
    MCAPI void _initializeGameplayUserManager();

    // 初始化关卡区块事件管理器。
    MCAPI void _initializeLevelChunkEventManager();

    // 初始化关卡事件管理器。
    MCAPI void _initializeLevelEventManager();

    // 初始化粒子效果提供者。
    MCAPI void _initializeParticleProvider();

    // 处理添加带生物群系着色的粒子效果的事件。
    MCAPI void _onAddBiomeTintedParticleEffect(
        ::HashedString const &effect, ::BlockPos const &pos,
        ::Block const &block, ::std::optional<::mce::Color> overrideColor);

    // 处理添加物品破坏粒子效果的事件。
    MCAPI void
    _onAddBreakingItemParticleEffect(::Vec3 const &pos,
                                     ::BreakingItemParticleData const &data,
                                     ::ResolvedItemIconInfo const &textureInfo);

    // 处理添加地形粒子效果的事件。
    MCAPI void _onAddTerrainParticleEffect(::BlockPos const &pos,
                                           ::Block const &block,
                                           ::Vec3 const &emitterPosition,
                                           float particleCount,
                                           float velocityScalar,
                                           float emitterRadius);

    // 处理添加地形滑落效果的事件。
    MCAPI void
    _onAddTerrainSlideEffect(::BlockPos const &pos, ::Block const &block,
                             ::Vec3 const &emitterPosition, float particleCount,
                             float velocityScalar, float emitterRadius);

    // 当任何游戏性用户被移除时调用的内部函数。
    MCAPI void _onAnyGameplayUsersRemoved();

    // 当区块被丢弃时调用的内部函数。
    MCAPI void _onChunkDiscarded(::LevelChunk &levelChunk);

    // 当区块被加载时调用的内部函数。
    MCAPI void _onChunkLoaded(::ChunkSource &chunkSource,
                              ::LevelChunk &levelChunk, int);

    // 当区块被重载时调用的内部函数。
    MCAPI void _onChunkReloaded(::ChunkSource &chunkSource,
                                ::LevelChunk &levelChunk);

    // 当游戏性用户被添加时调用的内部函数。
    MCAPI void _onGameplayUserAdded(::EntityContext &entity);

    // 当游戏性用户被移除时调用的内部函数。
    MCAPI void _onGameplayUserRemoved(::EntityContext &entity);

    // 处理带有 CompoundTag 数据的关卡事件的内部函数。
    MCAPI void _onLevelEventCompoundTag(::SharedTypes::Legacy::LevelEvent type,
                                        ::CompoundTag const &data);

    // 处理带有基本数据的关卡事件的内部函数。
    MCAPI void _onLevelEventData(::SharedTypes::Legacy::LevelEvent type,
                                 ::Vec3 const &pos, int data);

    // 拍照完成时调用的内部回调函数。
    MCAPI void _onPictureTaken(
        ::cg::ImageBuffer &outImage, ::Actor *camera, ::Actor *target,
        ::ScreenshotOptions &screenshotOptions,
        ::std::function<void(::cg::ImageBuffer &, ::ScreenshotOptions &)>
            completedScreenshotCallback);

    // 当实体被移除时，处理其相关引用的内部函数。
    MCAPI void _onRemoveActorEntityReferences(::Actor &actor);

    // 处理发送旧版服务器粒子效果的内部函数。
    MCAPI void _onSendServerLegacyParticle(::ParticleType id, ::Vec3 const &pos,
                                           ::Vec3 const &dir, int data);

    // 添加一个实体，并返回一个包含实体指针或验证错误的结果。
    MCAPI ::Bedrock::Result<::Actor *, ::ActorValidationError>
    addEntityWithError(::BlockSource &region,
                       ::OwnerPtr<::EntityContext> entity);

    // 提前关闭主线程相关组件。
    MCAPI void earlyShutdownMainthread();

    // 获取实体管理器。
    MCAPI ::Bedrock::NotNullNonOwnerPtr<::ActorManager> getActorManager();

    // 获取服务器关卡事件协调器。
    MCAPI ::ServerLevelEventCoordinator &getServerLevelEventCoordinator();
    // NOLINTEND

  public:
    // static functions
    // 静态函数
    // NOLINTBEGIN
    /**
     * @brief 创建一个关卡存储管理器。
     * @param levelStorage 关卡存储的唯一所有权指针。
     * @param scheduler 调度器引用。
     * @param eventing Minecraft 事件系统接口引用。
     * @return 返回一个 LevelStorageManager 的唯一所有权指针。
     */
    MCAPI static ::std::unique_ptr<::LevelStorageManager>
    _createLevelStorageManager(
        ::Bedrock::UniqueOwnerPointer<::LevelStorage> levelStorage,
        ::Scheduler &scheduler, ::IMinecraftEventing &eventing);

    /**
     * @brief 创建一个玩家临时滞留实体管理器。
     * @details
     * 这个管理器用于处理那些暂时离开游戏（例如切换维度）但其数据仍需保留的玩家实体。
     * @param levelStorageManager 关卡存储管理器指针。
     * @param actorManager 实体管理器的非所有权指针。
     * @param actorFactory 实体工厂的非所有权指针。
     * @return 返回一个 PlayerLimboActorManager 的唯一所有权指针。
     */
    MCAPI static ::std::unique_ptr<::PlayerLimboActorManager>
    _createPlayerLimboActorManager(
        ::LevelStorageManager *levelStorageManager,
        ::Bedrock::NotNullNonOwnerPtr<::ActorManager> actorManager,
        ::Bedrock::NotNullNonOwnerPtr<::ActorFactory> actorFactory);
    // NOLINTEND

  public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::Bedrock::NotNullNonOwnerPtr<::PacketSender>                packetSender,
        ::Bedrock::NotNullNonOwnerPtr<::SoundPlayerInterface> const& soundPlayer,
        ::Bedrock::UniqueOwnerPointer<::LevelStorage>                levelStorage,
        ::Bedrock::NotNullNonOwnerPtr<::LevelData>                   levelData,
        ::IMinecraftEventing&                                        eventing,
        bool                                                         isClientSide,
        ::SubClientId                                                subClientId,
        ::Scheduler&                                                 callbackContext,
        ::Bedrock::NotNullNonOwnerPtr<::StructureManager>            structureManager,
        ::ResourcePackManager&                                       addOnResourcePackManager,
        ::Bedrock::NotNullNonOwnerPtr<::IEntityRegistryOwner> const& entityRegistryOwner,
        ::WeakRef<::EntityContext>                                   levelEntity,
        ::ItemRegistryRef                                            itemRegistry,
        ::std::weak_ptr<::BlockTypeRegistry>                         blockRegistry,
        bool                                                         clientSideChunkGenerationEnabled,
        bool                                                         blockNetworkIdsAreHashes,
        ::NetworkPermissions const&                                  networkPermissions,
        ::std::optional<::DimensionDefinitionGroup>                  dimensionDefinitionGroup,
        ::Bedrock::NonOwnerPointer<::LinkedAssetValidator>           validator
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
    MCAPI bool $initialize(
        ::std::string const&   levelName,
        ::LevelSettings const& levelSettings,
        ::Experiments const&   experiments,
        ::std::string const*   levelId
    );

    MCAPI void $startLeaveGame();

    MCAPI bool $isLeaveGameDone();

    MCAPI ::WeakRef<::Dimension> $getOrCreateDimension(::DimensionType dimensionType);

    MCAPI ::WeakRef<::Dimension> $getDimension(::DimensionType id) const;

    MCAPI ::DimensionType $getLastOrDefaultSpawnDimensionId(::DimensionType lastDimensionId) const;

    MCFOLD void $forEachDimension(::std::function<bool(::Dimension&)> callback);

    MCFOLD void $forEachDimension(::std::function<bool(::Dimension const&)> callback) const;

    MCAPI uint $getChunkTickRange() const;

    MCAPI ::ChunkTickRangeManager const& $getChunkTickRangeManager() const;

    MCAPI ::PortalForcer& $getPortalForcer();

    MCAPI void $requestPlayerChangeDimension(::Player& player, ::ChangeDimensionRequest&& changeRequest);

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::PlayerDimensionTransferManager> $getPlayerDimensionTransferManager();

    MCAPI void $entityChangeDimension(::Actor& entity, ::DimensionType toId, ::std::optional<::Vec3> entityPos);

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::ActorDimensionTransferManager> $getActorDimensionTransferManager();

    MCAPI ::Spawner& $getSpawner() const;

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::BossEventSubscriptionManager> $getBossEventSubscriptionManager();

    MCAPI ::ProjectileFactory& $getProjectileFactory() const;

    MCFOLD ::ActorDefinitionGroup* $getEntityDefinitions() const;

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::ActorAnimationGroup> $getActorAnimationGroup() const;

    MCAPI ::Bedrock::NonOwnerPointer<::ActorAnimationControllerGroup> $getActorAnimationControllerGroup() const;

    MCFOLD ::BlockDefinitionGroup* $getBlockDefinitions() const;

    MCFOLD ::PropertyGroupManager& $getActorPropertyGroup() const;

    MCFOLD ::CameraPresets const& $getCameraPresets() const;

    MCFOLD ::CameraPresets& $getCameraPresets();

    MCAPI bool $getDisablePlayerInteractions() const;

    MCAPI void $setDisablePlayerInteractions(bool const disable);

    MCFOLD ::AutomationBehaviorTreeGroup& $getAutomationBehaviorTreeGroup() const;

    MCAPI ::BehaviorFactory& $getBehaviorFactory() const;

    MCAPI ::SharedTypes::Legacy::Difficulty $getDifficulty() const;

    MCAPI ::DimensionConversionData $getDimensionConversionData() const;

    MCAPI float $getSpecialMultiplier(::DimensionType dimensionType) const;

    MCAPI bool $hasCommandsEnabled() const;

    MCAPI bool $useMsaGamertagsOnly() const;

    MCAPI void $setMsaGamertagsOnly(bool msaGamertagsOnly);

    MCAPI ::Actor* $addEntity(::BlockSource& region, ::OwnerPtr<::EntityContext> entity);

    MCAPI ::Actor* $addGlobalEntity(::BlockSource& region, ::OwnerPtr<::EntityContext> entity);

    MCAPI ::Actor* $addAutonomousEntity(::BlockSource& region, ::OwnerPtr<::EntityContext> entity);

    MCAPI void $addUser(::OwnerPtr<::EntityContext> userEntity);

    MCAPI ::Actor* $addDisplayEntity(::BlockSource&, ::OwnerPtr<::EntityContext>);

    MCFOLD void $removeDisplayEntity(::WeakEntityRef);

    MCFOLD ::Bedrock::NonOwnerPointer<::DisplayActorManager> $getDisplayActorManager();

    MCAPI void $suspendPlayer(::Player& player);

    MCAPI void $resumePlayer(::Player& player);

    MCAPI bool $isPlayerSuspended(::Player& player) const;

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::GameplayUserManager> $getGameplayUserManager();

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::GameplayUserManager const> $getGameplayUserManager() const;

    MCAPI ::Bedrock::NonOwnerPointer<::PlayerLocationReceiver> $getPlayerLocationReceiver();

    MCAPI ::OwnerPtr<::EntityContext> $removeActorAndTakeEntity(::WeakEntityRef entityRef);

    MCAPI ::OwnerPtr<::EntityContext> $removeActorFromWorldAndTakeEntity(::WeakEntityRef entityRef);

    MCAPI ::OwnerPtr<::EntityContext> $takeEntity(::WeakEntityRef entityRef, ::LevelChunk& lc);

    MCAPI ::StrictEntityContext $fetchStrictEntity(::ActorUniqueID actorId, bool getRemoved) const;

    MCAPI ::Actor* $fetchEntity(::ActorUniqueID actorId, bool getRemoved) const;

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::ActorFetcher const> $getActorFetcher() const;

    MCAPI ::Actor* $getRuntimeEntity(::ActorRuntimeID actorId, bool getRemoved) const;

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::ActorRuntimeIDManager> $getActorRuntimeIDManager();

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::ActorRuntimeIDManager const> $getActorRuntimeIDManager() const;

    MCAPI ::Mob* $getMob(::ActorUniqueID mobId) const;

    MCAPI ::Player* $getPlayer(::std::string const& name) const;

    MCAPI ::Player* $getPlayer(::mce::UUID const& uuid) const;

    MCAPI ::Player* $getPlayer(::ActorUniqueID entityID) const;

    MCAPI ::Player* $getPlayerByXuid(::std::string const& xuid) const;

    MCAPI ::Player* $getPlatformPlayer(::std::string const& platformOnlineId) const;

    MCAPI ::Player* $getPlayerFromServerId(::std::string const& serverId) const;

    MCAPI ::Player* $getRuntimePlayer(::ActorRuntimeID runtimeId) const;

    MCAPI int $getNumRemotePlayers() const;

    MCAPI ::Player* $getPrimaryLocalPlayer() const;

    MCAPI ::IMinecraftEventing& $getEventing();

    MCAPI ::mce::Color $getPlayerColor(::Player const& player) const;

    MCAPI ::Tick const& $getCurrentTick() const;

    MCAPI ::Tick const $getCurrentServerTick() const;

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::TickDeltaTimeManager const> $getTickDeltaTimeManager() const;

    MCFOLD ::ArmorTrimUnloader* $getArmorTrimUnloader();

    MCFOLD ::BiomeRegistry const& $getBiomeRegistry() const;

    MCFOLD ::BiomeRegistry& $getBiomeRegistry();

    MCFOLD ::BlockPalette const& $getBlockPalette() const;

    MCFOLD ::BlockPalette& $getBlockPalette();

    MCFOLD ::FeatureRegistry const& $getFeatureRegistry() const;

    MCFOLD ::FeatureRegistry& $getFeatureRegistry();

    MCFOLD ::FeatureTypeFactory const& $getFeatureTypeFactory() const;

    MCFOLD ::FeatureTypeFactory& $getFeatureTypeFactory();

    MCFOLD ::JigsawStructureRegistry const& $getJigsawStructureRegistry() const;

    MCFOLD ::JigsawStructureRegistry& $getJigsawStructureRegistry();

    MCFOLD ::StructureSpawnRegistry const& $getStructureSpawnRegistry() const;

    MCFOLD ::StructureSpawnRegistry& $getStructureSpawnRegistry();

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::StructureManager> const $getStructureManager() const;

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::StructureManager> $getStructureManager();

    MCFOLD ::BiomeComponentFactory const& $getBiomeComponentFactory() const;

    MCFOLD ::BiomeComponentFactory& $getBiomeComponentFactory();

    MCFOLD ::SurfaceBuilderRegistry const& $getSurfaceBuilderRegistry() const;

    MCFOLD ::SurfaceBuilderRegistry& $getSurfaceBuilderRegistry();

    MCAPI ::BiomeManager const& $getBiomeManager() const;

    MCAPI ::BiomeManager& $getBiomeManager();

    MCFOLD ::OwnerPtrFactory<::Dimension, ::ILevel&, ::Scheduler&> const& $getDimensionFactory() const;

    MCFOLD ::OwnerPtrFactory<::Dimension, ::ILevel&, ::Scheduler&>& $getDimensionFactory();

    MCFOLD ::Factory<::BaseLightTextureImageBuilder, ::Level&, ::Scheduler&> const&
    $getLightTextureImageBuilderFactory() const;

    MCFOLD ::Factory<::BaseLightTextureImageBuilder, ::Level&, ::Scheduler&>& $getLightTextureImageBuilderFactory();

    MCAPI ::InternalComponentRegistry& $getInternalComponentRegistry() const;

    MCFOLD ::IWorldRegistriesProvider const& $getWorldRegistriesProvider() const;

    MCFOLD ::IWorldRegistriesProvider& $getWorldRegistriesProvider();

    MCAPI void $addListener(::LevelListener& listener);

    MCAPI void $removeListener(::LevelListener& listener);

    MCAPI void $tickEntities();

    MCAPI void $tickEntitySystems();

    MCAPI void $onPlayerDeath(::Player& player, ::ActorDamageSource const& source);

    MCAPI void $tick();

    MCAPI bool $explode(
        ::BlockSource& region,
        ::Actor*       source,
        ::Vec3 const&  pos,
        float          explosionRadius,
        bool           fire,
        bool           breaksBlocks,
        float          maxResistance,
        bool           allowUnderwater
    );

    MCAPI bool $explode(::Explosion& explosion);

    MCAPI void $denyEffect(::BlockSource& region, ::Vec3 const& pos);

    MCAPI void $potionSplash(::Vec3 const& pos, ::mce::Color const& color, bool instantaneousEffect);

    MCAPI bool $extinguishFire(::BlockSource& region, ::BlockPos const& pos, uchar face, ::Actor* source);

    MCAPI ::std::unique_ptr<::Path>
    $findPath(::Actor& from, int xBest, int yBest, int zBest, ::NavigationComponent& navigation);

    MCAPI ::std::unique_ptr<::Path> $findPath(::Actor& from, ::Actor const& to, ::NavigationComponent& navigation);

    MCAPI void $setSleepStatus(::PlayerSleepStatus const& status);

    MCAPI ::PlayerSleepStatus $getSleepStatus() const;

    MCAPI void $updateSleepingPlayerList();

    MCFOLD ::Bedrock::NonOwnerPointer<::ServerPlayerSleepManager> $getServerPlayerSleepManager();

    MCFOLD ::Bedrock::NonOwnerPointer<::ServerPlayerSleepManager const> $getServerPlayerSleepManager() const;

    MCAPI int $getTime() const;

    MCAPI void $setTime(int time);

    MCAPI uint $getSeed();

    MCAPI ::LevelSeed64 $getLevelSeed64() const;

    MCFOLD ::BlockPos const& $getSharedSpawnPos() const;

    MCAPI void $setDefaultSpawn(::BlockPos const& spawnPos);

    MCFOLD ::BlockPos const& $getDefaultSpawn() const;

    MCAPI ::GameType $getDefaultGameType() const;

    MCAPI void $setDifficulty(::SharedTypes::Legacy::Difficulty difficulty);

    MCAPI void $setMultiplayerGameIntent(bool multiplayerGame);

    MCAPI bool $getMultiplayerGameIntent() const;

    MCAPI void $setMultiplayerGame(bool multiplayerGame);

    MCAPI bool $isMultiplayerGame() const;

    MCAPI void $setLANBroadcastIntent(bool broadcast);

    MCAPI bool $getLANBroadcastIntent() const;

    MCAPI void $setLANBroadcast(bool broadcast);

    MCAPI bool $getLANBroadcast() const;

    MCAPI ::Social::GamePublishSetting $getXBLBroadcastIntent() const;

    MCAPI bool $hasXBLBroadcastIntent() const;

    MCAPI ::Social::GamePublishSetting $getXBLBroadcastMode() const;

    MCAPI bool $hasXBLBroadcast() const;

    MCAPI ::Social::GamePublishSetting $getPlatformBroadcastIntent() const;

    MCAPI bool $hasPlatformBroadcastIntent() const;

    MCAPI ::Social::GamePublishSetting $getPlatformBroadcastMode() const;

    MCAPI bool $hasPlatformBroadcast() const;

    MCAPI void $setHasLockedBehaviorPack(bool hasLocked);

    MCAPI void $setHasLockedResourcePack(bool hasLocked);

    MCAPI void $setCommandsEnabled(bool commandsEnabled);

    MCAPI void $setWorldTemplateOptionsUnlocked();

    MCAPI bool $hasLevelStorage() const;

    MCFOLD ::LevelStorage& $getLevelStorage();

    MCFOLD ::LevelStorage const& $getLevelStorage() const;

    MCFOLD ::LevelData& $getLevelData();

    MCFOLD ::LevelData const& $getLevelData() const;

    MCAPI ::PhotoStorage& $getPhotoStorage() const;

    MCAPI void $createPhotoStorage();

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::PhotoManager> $getPhotoManager();

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::PhotoManager const> $getPhotoManager() const;

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::EducationSettingsManager> $getEducationSettingsManager();

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::EducationSettingsManager const> $getEducationSettingsManager() const;

    MCAPI void $save();

    MCAPI void $saveLevelData();

    MCAPI void $saveGameData();

    MCAPI ::std::shared_ptr<void*> $requestTimedStorageDeferment();

    MCFOLD ::TickingAreasManager& $getTickingAreasMgr();

    MCAPI void
    $addTickingAreaList(::DimensionType dimensionId, ::std::shared_ptr<::TickingAreaList> const& tickingAreas);

    MCAPI void $playSound(
        ::SharedTypes::Legacy::LevelSoundEvent type,
        ::Vec3 const&                          pos,
        int                                    data,
        ::ActorSoundIdentifier const&          actorSoundIdentifier,
        bool                                   isGlobal
    );

    MCAPI void
    $playSound(::SharedTypes::Legacy::LevelSoundEvent type, ::Vec3 const& pos, float const volume, float const pitch);

    MCAPI void $playSound(::std::string const& name, ::Vec3 const& pos, float volume, float pitch);

    MCAPI void $playSound(
        ::IConstBlockSource const&             region,
        ::SharedTypes::Legacy::LevelSoundEvent type,
        ::Vec3 const&                          pos,
        int                                    data,
        ::ActorSoundIdentifier const&          actorSoundIdentifier,
        bool                                   isGlobal
    );

    MCAPI void $playSound(
        ::DimensionType                        dimension,
        ::SharedTypes::Legacy::LevelSoundEvent type,
        ::Vec3 const&                          pos,
        int                                    data,
        ::ActorSoundIdentifier const&          actorSoundIdentifier,
        bool                                   isGlobal
    );

    MCAPI ::PlayerEventCoordinator& $getRemotePlayerEventCoordinator();

    MCAPI ::ServerPlayerEventCoordinator& $getServerPlayerEventCoordinator();

    MCAPI ::ClientPlayerEventCoordinator& $getClientPlayerEventCoordinator();

    MCAPI ::ActorEventCoordinator& $getActorEventCoordinator();

    MCAPI ::BlockEventCoordinator& $getBlockEventCoordinator();

    MCAPI ::ItemEventCoordinator& $getItemEventCoordinator();

    MCAPI ::ServerNetworkEventCoordinator& $getServerNetworkEventCoordinator();

    MCAPI ::ScriptingEventCoordinator& $getScriptingEventCoordinator();

    MCAPI ::ScriptDeferredEventCoordinator& $getScriptDeferredEventCoordinator();

    MCAPI ::LevelEventCoordinator& $getLevelEventCoordinator();

    MCAPI void $handleLevelEvent(::SharedTypes::Legacy::LevelEvent type, ::Vec3 const& pos, int data);

    MCAPI void $handleLevelEvent(::SharedTypes::Legacy::LevelEvent type, ::CompoundTag const& data);

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::LevelEventManager> $getLevelEventManager();

    MCAPI void $handleStopSoundEvent(::std::string const& name);

    MCAPI void $handleStopAllSounds();

    MCAPI void $handleStopMusicEvent();

    MCAPI void $broadcastLevelEvent(
        ::SharedTypes::Legacy::LevelEvent      type,
        ::Vec3 const&                          pos,
        int                                    data,
        ::UserEntityIdentifierComponent const* userIdentifier
    );

    MCAPI void $broadcastLevelEvent(
        ::SharedTypes::Legacy::LevelEvent      type,
        ::CompoundTag const&                   tag,
        ::UserEntityIdentifierComponent const* userIdentifier
    );

    MCAPI void
    $broadcastLocalEvent(::BlockSource& region, ::SharedTypes::Legacy::LevelEvent type, ::Vec3 const& pos, int data);

    MCAPI void $broadcastLocalEvent(
        ::BlockSource&                    region,
        ::SharedTypes::Legacy::LevelEvent type,
        ::Vec3 const&                     pos,
        ::Block const&                    block
    );

    MCAPI void $broadcastSoundEvent(
        ::BlockSource&                         region,
        ::SharedTypes::Legacy::LevelSoundEvent type,
        ::Vec3 const&                          pos,
        ::Block const&                         block,
        ::ActorSoundIdentifier const&          actorSoundIdentifier,
        bool                                   isGlobal
    );

    MCAPI void $broadcastSoundEvent(
        ::BlockSource&                         region,
        ::SharedTypes::Legacy::LevelSoundEvent type,
        ::Vec3 const&                          pos,
        int                                    data,
        ::ActorSoundIdentifier const&          actorSoundIdentifier,
        bool                                   isGlobal
    );

    MCAPI void $broadcastSoundEvent(
        ::Dimension&                           dimension,
        ::SharedTypes::Legacy::LevelSoundEvent type,
        ::Vec3 const&                          pos,
        int                                    data,
        ::ActorSoundIdentifier const&          actorSoundIdentifier,
        bool                                   isGlobal
    );

    MCAPI void $broadcastActorEvent(::Actor& actor, ::ActorEvent eventId, int data) const;

    MCAPI ::Bedrock::NonOwnerPointer<::ActorEventBroadcaster const> $getActorEventBroadcaster() const;

    MCAPI void $addChunkViewTracker(::std::weak_ptr<::ChunkViewSource> chunkViewSource);

    MCAPI void $onChunkReload(::Bounds const& bound);

    MCAPI int $getActivePlayerCount() const;

    MCAPI int $getActiveUsersCount() const;

    MCAPI void $forEachPlayer(::std::function<bool(::Player&)> callback);

    MCAPI void $forEachPlayer(::std::function<bool(::Player const&)> callback) const;

    MCAPI void $forEachUser(::std::function<bool(::EntityContext&)> callback);

    MCAPI void $forEachUser(::std::function<bool(::EntityContext const&)> callback) const;

    MCAPI ::Player* $findPlayer(::std::function<bool(::Player const&)> pred) const;

    MCAPI ::Player* $findPlayer(::std::function<bool(::WeakEntityRef const&)> pred) const;

    MCAPI int $getUserCount() const;

    MCAPI int $countUsersWithMatchingNetworkId(::NetworkIdentifier const& networkId) const;

    MCAPI ::std::vector<::OwnerPtr<::EntityContext>> const& $getUsers() const;

    MCAPI ::std::vector<::OwnerPtr<::EntityContext>> const& $getEntities() const;

    MCAPI void $onSourceCreated(::BlockSource& source);

    MCAPI void $onSourceDestroyed(::BlockSource& source);

    MCFOLD void $onSubChunkLoaded(
        ::ChunkSource& source,
        ::LevelChunk&  lc,
        short          absoluteSubChunkIndex,
        bool           subChunkVisibilityChanged
    );

    MCFOLD ::Bedrock::NonOwnerPointer<::SubChunkManager> $getSubChunkManager();

    MCAPI void $onChunkLoaded(::ChunkSource& source, ::LevelChunk& lc);

    MCAPI void $onChunkReloaded(::ChunkSource& source, ::LevelChunk& lc);

    MCFOLD ::LevelChunkMetaDataManager* $getLevelChunkMetaDataManager();

    MCAPI void $onChunkDiscarded(::LevelChunk& lc);

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::LevelChunkEventManager> $getLevelChunkEventManager();

    MCAPI void $queueEntityDestruction(::OwnerPtr<::EntityContext> entity);

    MCAPI ::OwnerPtr<::EntityContext> $removeEntity(::Actor& actor);

    MCAPI ::OwnerPtr<::EntityContext> $removeEntity(::WeakEntityRef entityRef);

    MCAPI void $forceRemoveEntity(::Actor& actor);

    MCAPI void $forceRemoveEntityfromWorld(::Actor& actor);

    MCAPI void $forceFlushRemovedPlayers();

    MCFOLD void $loadFunctionManager();

    MCAPI void $levelCleanupQueueEntityRemoval(::OwnerPtr<::EntityContext> entity);

    MCAPI void $registerTemporaryPointer(::_TickPtr& ptr);

    MCAPI void $unregisterTemporaryPointer(::_TickPtr& ptr);

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::TempEPtrManager> $getTempEPtrManager();

    MCAPI bool $destroyBlock(::BlockSource& region, ::BlockPos const& pos, bool dropResources);

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::LevelBlockDestroyer> $getLevelBlockDestroyer();

    MCAPI void $suspendAndSave();

    MCAPI void $sendServerLegacyParticle(::ParticleType id, ::Vec3 const& pos, ::Vec3 const& dir, int data);

    MCAPI ::Particle* $addParticle(
        ::ParticleType       id,
        ::Vec3 const&        pos,
        ::Vec3 const&        dir,
        int                  data,
        ::CompoundTag const* tag,
        bool                 isGlobal
    );

    MCAPI void
    $spawnParticleEffect(::std::string const& effectName, ::Vec3 const& spawnLocation, ::Dimension* dimension);

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::ServerParticleManager> $getServerParticleManager();

    MCAPI void $addParticleEffect(
        ::HashedString const&      effect,
        ::Vec3 const&              emitterPosition,
        ::MolangVariableMap const& molangVariables
    );

    MCAPI void $addTerrainParticleEffect(
        ::BlockPos const& pos,
        ::Block const&    block,
        ::Vec3 const&     emitterPosition,
        float             intensity,
        float             velocityScalar,
        float             emitterRadius
    );

    MCAPI void $addTerrainSlideEffect(
        ::BlockPos const& pos,
        ::Block const&    block,
        ::Vec3 const&     emitterPosition,
        float             intensity,
        float             velocityScalar,
        float             emitterRadius
    );

    MCAPI void $addBreakingItemParticleEffect(
        ::Vec3 const&                     pos,
        ::BreakingItemParticleData const& data,
        ::ResolvedItemIconInfo const&     textureInfo
    );

    MCAPI void $addBiomeTintedParticleEffect(
        ::HashedString const&         effect,
        ::BlockPos const&             pos,
        ::Block const&                block,
        ::std::optional<::mce::Color> overrideColor
    );

    MCAPI ::ActorUniqueID $getNewUniqueID();

    MCAPI ::ActorRuntimeID $getNextRuntimeID();

    MCAPI ::std::vector<::ChunkPos> const& $getTickingOffsets() const;

    MCAPI ::std::vector<::ChunkPos> const& $getClientTickingOffsets() const;

    MCAPI ::std::vector<::ChunkPos>
    $getSortedPositionsFromClientOffsets(::std::vector<::ChunkPos> const& centers) const;

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::ChunkTickOffsetManager const> $getChunkTickOffsetManager() const;

    MCAPI bool $isExporting() const;

    MCAPI void $setIsExporting(bool IsExporting);

    MCAPI ::SavedDataStorage& $getSavedData();

    MCAPI ::MapItemSavedData* $getMapSavedData(::ActorUniqueID const uuid);

    MCFOLD ::MapItemSavedData* $getMapSavedData(::CompoundTag const& instance);

    MCFOLD ::MapItemSavedData* $getMapSavedData(::CompoundTag const* instance);

    MCAPI void $requestMapInfo(::ActorUniqueID const uuid, bool forceUpdate);

    MCAPI ::ActorUniqueID $expandMapByID(::ActorUniqueID const uuid, bool wasInit);

    MCAPI bool $copyAndLockMap(::ActorUniqueID const originalMapUuid, ::ActorUniqueID const newMapUuid);

    MCAPI ::MapItemSavedData& $createMapSavedData(
        ::ActorUniqueID const& uuid,
        ::BlockPos const&      origin,
        ::DimensionType        dimension,
        int                    returnScaleLevel
    );

    MCAPI ::MapItemSavedData& $createMapSavedData(
        ::std::vector<::ActorUniqueID> const& mapIds,
        ::BlockPos const&                     origin,
        ::DimensionType                       dimension,
        int                                   returnScaleLevel
    );

    MCAPI ::Core::PathBuffer<::std::string> $getScreenshotsFolder() const;

    MCAPI ::std::string $getLevelId() const;

    MCAPI void $setLevelId(::std::string LevelId);

    MCFOLD ::TaskGroup& $getSyncTasksGroup();

    MCFOLD ::TaskGroup& $getIOTasksGroup();

    MCFOLD ::ResourcePackManager* $getClientResourcePackManager() const;

    MCFOLD ::ResourcePackManager* $getServerResourcePackManager() const;

    MCFOLD ::TradeTables* $getTradeTables();

    MCFOLD void $decrementTagCache(
        ::std::string const&                                                      tag,
        ::TagRegistry<::IDType<::LevelTagIDType>, ::IDType<::LevelTagSetIDType>>& tagRegistry
    );

    MCFOLD void $incrementTagCache(
        ::std::string const&                                                      tag,
        ::TagRegistry<::IDType<::LevelTagIDType>, ::IDType<::LevelTagSetIDType>>& tagRegistry
    );

    MCFOLD ::Bedrock::NonOwnerPointer<::TagCacheManager> $getTagCacheManager();

    MCAPI bool $isEdu() const;

    MCFOLD ::ActorFactory& $getActorFactory();

    MCFOLD ::ActorFactory const& $getActorFactory() const;

    MCFOLD ::ActorInfoRegistry* $getActorInfoRegistry();

    MCAPI ::StackRefResult<::EntityRegistry> $getEntityRegistry();

    MCAPI ::StackRefResult<::EntityRegistry const> $getEntityRegistry() const;

    MCAPI ::EntitySystems& $getEntitySystems();

    MCFOLD ::WeakRef<::EntityContext> $getLevelEntity();

    MCFOLD ::WeakRef<::EntityContext const> $getLevelEntity() const;

    MCFOLD ::Bedrock::NonOwnerPointer<::VolumeEntityManagerServer> $tryGetVolumeEntityManagerServer() const;

    MCFOLD void $runCommand(
        ::HashedString const&     commandStr,
        ::CommandOrigin&          origin,
        ::CommandOriginSystem     originSystem,
        ::CurrentCmdVersion const commandVersion
    );

    MCFOLD void $runCommand(::Command& command, ::CommandOrigin& origin, ::CommandOriginSystem originSystem);

    MCAPI ::PlayerCapabilities::ISharedController const& $getCapabilities() const;

    MCAPI ::TagRegistry<::IDType<::LevelTagIDType>, ::IDType<::LevelTagSetIDType>>& $getTagRegistry();

    MCAPI ::PlayerMovementSettings const& $getPlayerMovementSettings() const;

    MCAPI void $setPlayerMovementSettings(::PlayerMovementSettings const& settings);

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::PlayerMovementSettingsManager> $getPlayerMovementSettingsManager();

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::PlayerMovementSettingsManager const>
    $getPlayerMovementSettingsManager() const;

    MCFOLD bool $canUseSkin(
        ::SerializedSkin const&    skin,
        ::NetworkIdentifier const& networkIdentifier,
        ::ActorUniqueID const&     playerId
    ) const;

    MCFOLD ::Bedrock::NonOwnerPointer<::TrustedSkinHelper const> $getTrustedSkinHelper() const;

    MCFOLD ::Bedrock::NonOwnerPointer<::CameraRegistry const> $getCameraRegistry() const;

    MCFOLD ::Bedrock::NonOwnerPointer<::CameraRegistry> $getCameraRegistry();

    MCFOLD ::Bedrock::NonOwnerPointer<::EntitySystems> $getCameraSystems();

    MCAPI ::PositionTrackingDB::PositionTrackingDBClient* $getPositionTrackerDBClient() const;

    MCFOLD ::PositionTrackingDB::PositionTrackingDBServer* $getPositionTrackerDBServer() const;

    MCAPI void $flushRunTimeLighting();

    MCAPI void $loadBlockDefinitionGroup(::Experiments const& experiments);

    MCAPI void $initializeBlockDefinitionGroup();

    MCAPI ::Bedrock::NonOwnerPointer<::IUnknownBlockTypeRegistry> $getUnknownBlockTypeRegistry();

    MCAPI bool $isClientSideGenerationEnabled();

    MCAPI bool $blockNetworkIdsAreHashes();

    MCAPI ::ItemRegistryRef $getItemRegistry() const;

    MCAPI ::std::weak_ptr<::BlockTypeRegistry> $getBlockRegistry() const;

    MCFOLD ::Level* $asLevel();

    MCAPI bool $use3DBiomeMaps() const;

    MCAPI void $addBlockSourceForValidityTracking(::BlockSource* region);

    MCAPI void $removeBlockSourceFromValidityTracking(::BlockSource* region);

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::BlockSourceValidityManager> $getBlockSourceValidityManager();

    MCAPI void $pauseAndFlushTaskGroups();

    MCFOLD ::DimensionManager& $getDimensionManager();

    MCFOLD ::DimensionManager const& $getDimensionManager() const;

    MCFOLD void $subChunkTickAndSendRequests();

    MCAPI void $_subTick();

    MCFOLD ::StackRefResult<::PauseManager> $getPauseManager();

    MCFOLD ::StackRefResult<::PauseManager const> $getPauseManager() const;

    MCAPI bool $isClientSide() const;

    MCAPI ::std::unordered_map<::mce::UUID, ::PlayerListEntry> const& $getPlayerList() const;

    MCAPI ::std::string const& $getPlayerXUID(::mce::UUID const& uuid) const;

    MCAPI ::std::string const& $getPlayerPlatformOnlineId(::mce::UUID const& uuid) const;

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::PlayerListManager> $getPlayerListManager();

    MCFOLD ::Bedrock::NotNullNonOwnerPtr<::PlayerListManager const> $getPlayerListManager() const;

    MCAPI ::std::vector<::WeakEntityRef> const& $getActiveUsers() const;

    MCFOLD void $notifySubChunkRequestManager(::SubChunkPacket const& packet);

    MCFOLD ::SubChunkRequestManager* $getSubChunkRequestManager();

    MCAPI ::std::vector<::Actor*> $getRuntimeActorList() const;

    MCAPI ::PacketSender* $getPacketSender() const;

    MCAPI ::Bedrock::NonOwnerPointer<::NetEventCallback> $getNetEventCallback() const;

    MCAPI void $setNetEventCallback(::Bedrock::NonOwnerPointer<::NetEventCallback> val);

    MCAPI ::gsl::not_null<::StackRefResult<::ILevelRandom>> $getILevelRandom();

    MCAPI ::IRandom& $getIRandom() const;

    MCAPI ::Random& $getRandom() const;

    MCFOLD ::Random& $getThreadRandom() const;

    MCAPI ::HitResult& $getHitResult();

    MCAPI ::HitResult& $getLiquidHitResult();

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::HitResultWrapper> $getHitResultWrapper();

    MCAPI ::std::string const& $getImmersiveReaderString() const;

    MCAPI void $setImmersiveReaderString(::std::string newString);

    MCAPI ::AdventureSettings& $getAdventureSettings();

    MCAPI ::AdventureSettings const& $getAdventureSettings() const;

    MCAPI ::GameRules const& $getGameRules() const;

    MCAPI ::GameRules& $getGameRules();

    MCAPI bool $hasStartWithMapEnabled() const;

    MCAPI bool $isEditorWorld() const;

    MCAPI bool $isHardcore() const;

    MCAPI ::Abilities& $getDefaultAbilities();

    MCAPI ::PermissionsHandler& $getDefaultPermissions();

    MCAPI ::PermissionsHandler const& $getDefaultPermissions() const;

    MCAPI bool $getTearingDown() const;

    MCAPI void $takePicture(
        ::cg::ImageBuffer&                                              outImage,
        ::Actor*                                                        camera,
        ::Actor*                                                        target,
        ::ScreenshotOptions&                                            screenshotOptions,
        ::std::function<void(::cg::ImageBuffer&, ::ScreenshotOptions&)> completedScreenshotCallback
    );

    MCAPI ::LevelSoundManager& $getLevelSoundManager();

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::SoundPlayerInterface> $getSoundPlayer() const;

    MCAPI void $setSimPaused(bool value);

    MCFOLD bool $getSimPaused();

    MCAPI void $setFinishedInitializing();

    MCAPI ::LootTables& $getLootTables();

    MCAPI void $updateWeather(float rainLevel, int rainTime, float lightningLevel, int lightningTime);

    MCAPI int $getNetherScale() const;

    MCFOLD ::Scoreboard& $getScoreboard();

    MCFOLD ::Scoreboard const& $getScoreboard() const;

    MCFOLD ::Scoreboard* $tryGetScoreboard();

    MCAPI ::LayeredAbilities* $getPlayerAbilities(::ActorUniqueID const& playerId);

    MCAPI void $setPlayerAbilities(::ActorUniqueID const& playerId, ::LayeredAbilities const& abilities);

    MCAPI void $sendAllPlayerAbilities(::Player const& playerReference);

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::PlayerAbilitiesManager> $getPlayerAbilitiesManager();

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::PlayerPermissionsManager> $getPlayerPermissionsManager();

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::PlayerPermissionsSynchroniser> $getPlayerPermissionsSynchroniser();

    MCFOLD ::Recipes& $getRecipes() const;

    MCFOLD ::BlockReducer* $getBlockReducer() const;

    MCFOLD ::std::weak_ptr<::TrimPatternRegistry const> $getTrimPatternRegistry() const;

    MCFOLD ::std::weak_ptr<::TrimPatternRegistry> $getTrimPatternRegistry();

    MCFOLD ::std::weak_ptr<::TrimMaterialRegistry const> $getTrimMaterialRegistry() const;

    MCFOLD ::std::weak_ptr<::TrimMaterialRegistry> $getTrimMaterialRegistry();

    MCAPI ::BlockLegacy const& $getRegisteredBorderBlock() const;

    MCAPI ::Bedrock::NotNullNonOwnerPtr<::LevelChunkPerformanceTelemetry> $getLevelChunkPerformanceTelemetry();

    MCFOLD ::cereal::ReflectionCtx const& $cerealContext() const;

    MCFOLD ::Bedrock::NonOwnerPointer<::ChunkGenerationManager> $getChunkGenerationManager();

    MCFOLD ::Bedrock::NonOwnerPointer<::ChunkGenerationManager const> $getChunkGenerationManager() const;

    MCFOLD ::PlayerDeathManager* $_getPlayerDeathManager();

    MCAPI void $_initializeMapDataManager();

    MCFOLD ::cereal::ReflectionCtx& $_cerealContext();

    MCAPI void $_onLowMemory();
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftableForIWorldRegistriesProvider();

    MCNAPI static void** $vftableForBlockSourceListener();

    MCNAPI static void** $vftableForILevel();
    // NOLINTEND
};
