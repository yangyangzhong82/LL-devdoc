#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/common/Brightness.h"
#include "mc/common/BrightnessPair.h"
#include "mc/deps/core/utility/AutomaticID.h"
#include "mc/deps/core/utility/EnableNonOwnerReferences.h"
#include "mc/deps/game_refs/EnableGetWeakRef.h"
#include "mc/deps/game_refs/OwnerPtr.h"
#include "mc/deps/game_refs/WeakRef.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/platform/brstd/function_ref.h"
#include "mc/world/level/BlockChangedEventTarget.h"
#include "mc/world/level/LevelListener.h"
#include "mc/world/level/chunk/LevelChunkGarbageCollector.h"
#include "mc/world/level/dimension/ActorReplication.h"
#include "mc/world/level/dimension/DimensionHeightRange.h"
#include "mc/world/level/dimension/IDimension.h"
#include "mc/world/level/dimension/LimboEntitiesVersion.h"
#include "mc/world/level/levelgen/v1/FeatureTerrainAdjustments.h"
#include "mc/world/level/levelgen/v2/providers/IntProvider.h"
#include "mc/world/level/saveddata/SavedData.h"
#include "mc/world/level/storage/StorageVersion.h"

// auto generated forward declare list
// clang-format off
class Actor;
class BaseLightTextureImageBuilder;
class BiomeRegistry;
class Block;
class BlockEventDispatcher;
class BlockPos;
class BlockSource;
class ChunkBuildOrderPolicyBase;
class ChunkKey;
class ChunkLoadActionList;
class ChunkPos;
class ChunkSource;
class CircuitSystem;
class CompoundTag;
class DelayActionList;
class DimensionBrightnessRamp;
class EntityContext;
class GameEventDispatcher;
class HashedString;
class ILevel;
class ILevelStorageManagerConnector;
class LevelChunk;
class LevelChunkBuilderData;
class LevelChunkMetaData;
class Packet;
class Player;
class PostprocessingManager;
class RuntimeLightingManager;
class Scheduler;
class Seasons;
class SubChunkInterlocker;
class SubChunkPos;
class TaskGroup;
class TickingAreaList;
class Vec3;
class VillageManager;
class WeakEntityRef;
class Weather;
class WireframeQueue;
class WorldGenerator;
struct ActorBlockSyncMessage;
struct ActorChunkTransferEntry;
struct ActorUnloadedChunkTransferEntry;
struct NetworkIdentifierWithSubId;
struct UpdateSubChunkBlocksChangedInfo;
namespace br::worldgen { class StructureSetRegistry; }
namespace mce { class Color; }
// clang-format on

class Dimension : public ::IDimension,
                  public ::LevelListener,
                  public ::SavedData,
                  public ::Bedrock::EnableNonOwnerReferences,
                  public ::EnableGetWeakRef<::Dimension>,
                  public ::std::enable_shared_from_this<::Dimension> {
public:
  // Dimension 内部类型声明
  // clang-format off
    struct ChaoticDirectionalLightControls;
    struct DirectionalLightState;
  // clang-format on

  // Dimension 内部类型定义
  struct DirectionalLightState {
  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 定向光状态的未知成员变量
    ::ll::UntypedStorage<4, 4> mUnkc3428f;
    ::ll::UntypedStorage<4, 4> mUnkff4708;
    ::ll::UntypedStorage<4, 4> mUnk2d8810;
    ::ll::UntypedStorage<4, 4> mUnk8baae1;
    // NOLINTEND

  public:
    // prevent constructor by default
    DirectionalLightState &operator=(DirectionalLightState const &);
    DirectionalLightState(DirectionalLightState const &);
    DirectionalLightState();
  };

  struct ChaoticDirectionalLightControls {
  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 混沌定向光控制的未知成员变量，可能用于末地等特殊维度
    ::ll::UntypedStorage<4, 4> mUnkcec13a;
    ::ll::UntypedStorage<4, 4> mUnkcf25a7;
    ::ll::UntypedStorage<4, 4> mUnkaf1fb7;
    ::ll::UntypedStorage<4, 4> mUnkb93f34;
    // NOLINTEND

  public:
    // prevent constructor by default
    ChaoticDirectionalLightControls &
    operator=(ChaoticDirectionalLightControls const &);
    ChaoticDirectionalLightControls(ChaoticDirectionalLightControls const &);
    ChaoticDirectionalLightControls();
  };

  // 定向光控制，可以是多种类型之一（例如混沌控制）
  using DirectionalLightControls =
      ::std::variant<::Dimension::ChaoticDirectionalLightControls>;

  // 实体标签列表，用于存储序列化的实体数据
  using ActorTagList = ::std::vector<::std::unique_ptr<::CompoundTag>>;

  // 从区块位置到实体列表的映射，用于存储临时滞留的实体
  using ChunkPosToActorListMap =
      ::std::unordered_map<::ChunkPos,
                           ::std::vector<::std::unique_ptr<::CompoundTag>>>;

public:
  // member variables
  // 成员变量
  // NOLINTBEGIN
  // 实体区块转移队列，用于处理实体在加载区块间的移动
  ::ll::TypedStorage<8, 24, ::std::vector<::ActorChunkTransferEntry>>
      mActorChunkTransferQueue;
  // 实体到未加载区块的转移队列
  ::ll::TypedStorage<
      8, 64,
      ::std::unordered_map<::ChunkKey,
                           ::std::vector<::ActorUnloadedChunkTransferEntry>>>
      mActorUnloadedChunkTransferQueue;
  // 维度所属的 Level (世界) 的引用
  ::ll::TypedStorage<8, 8, ::ILevel &> mLevel;
  // 维度的高度范围 (Y轴)
  ::ll::TypedStorage<2, 4, ::DimensionHeightRange> mHeightRange;
  // 维度的海平面高度
  ::ll::TypedStorage<2, 2, short> mSeaLevel;
  // 怪物生成的方块亮度限制
  ::ll::TypedStorage<1, 1, uchar> mMonsterSpawnBlockLightLimit;
  // 怪物生成的光照等级测试提供者
  ::ll::TypedStorage<4, 32, ::IntProvider> mMonsterSpawnLightTest;
  // 维度的方块源
  ::ll::TypedStorage<8, 16, ::OwnerPtr<::BlockSource>> mBlockSource;
  // 维度是否具有天气系统
  ::ll::TypedStorage<1, 1, bool> mHasWeather;
  // 地表每区块的生物数量上限（按类别）
  ::ll::TypedStorage<4, 28, float[7]> mMobsPerChunkSurface;
  // 地下每区块的生物数量上限（按类别）
  ::ll::TypedStorage<4, 28, float[7]> mMobsPerChunkUnderground;
  // 默认的亮度对（天空光和方块光）
  ::ll::TypedStorage<1, 2, ::BrightnessPair> mDefaultBrightness;
  // 光照贴图图像构建器
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BaseLightTextureImageBuilder>>
      mLightTextureImageBuilder;
  // 维度的亮度渐变控制器
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::DimensionBrightnessRamp>>
      mDimensionBrightnessRamp;
  // 目标区块的元数据
  ::ll::TypedStorage<8, 16, ::std::shared_ptr<::LevelChunkMetaData>>
      mTargetMetaData;
  // 运行时光照管理器
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::RuntimeLightingManager>>
      mRuntimeLightingManager;
  // 维度的名称
  ::ll::TypedStorage<8, 32, ::std::string> mName;
  // 维度的ID
  ::ll::TypedStorage<4, 4, ::DimensionType> mId;
  // 维度是否为超暖（例如下界，水会蒸发）
  ::ll::TypedStorage<1, 1, bool> mUltraWarm;
  // 维度是否有天花板（基岩顶）
  ::ll::TypedStorage<1, 1, bool> mHasCeiling;
  // 维度是否有天空光
  ::ll::TypedStorage<1, 1, bool> mHasSkylight;
  // 天空变暗的程度
  ::ll::TypedStorage<1, 1, ::Brightness> mSkyDarken;
  // 方块事件分发器
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BlockEventDispatcher>>
      mDispatcher;
  // 任务组
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::TaskGroup>> mTaskGroup;
  // 区块生成任务组
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::TaskGroup>> mChunkGenTaskGroup;
  // 后处理管理器
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::PostprocessingManager>>
      mPostProcessingManager;
  // 子区块互锁器，用于线程同步
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::SubChunkInterlocker>>
      mSubChunkInterlocker;
  // 区块源，负责提供区块数据
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ChunkSource>> mChunkSource;
  // 世界生成器
  ::ll::TypedStorage<8, 8, ::WorldGenerator *> mWorldGenerator;
  // 天气系统
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::Weather>> mWeather;
  // 季节系统
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::Seasons>> mSeasons;
  // 游戏事件分发器（用于Sculk等）
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::GameEventDispatcher>>
      mGameEventDispatcher;
  // 红石电路系统
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::CircuitSystem>> mCircuitSystem;
  // 红石电路的更新速率（常量）
  ::ll::TypedStorage<4, 4, int const> CIRCUIT_TICK_RATE;
  // 红石电路系统的更新速率
  ::ll::TypedStorage<4, 4, int> mCircuitSystemTickRate;
  // 实体唯一ID到实体弱引用的映射
  ::ll::TypedStorage<8, 64,
                     ::std::unordered_map<::ActorUniqueID, ::WeakEntityRef>>
      mActorIDEntityIDMap;
  // 用于显示的实体列表（客户端）
  ::ll::TypedStorage<8, 24, ::std::vector<::WeakEntityRef>> mDisplayEntities;
  // 线框队列（用于调试显示）
  ::ll::TypedStorage<8, 16, ::std::shared_ptr<::WireframeQueue>>
      mWireframeQueue;
  // 特征地形调整
  ::ll::TypedStorage<8, 72, ::FeatureTerrainAdjustments>
      mFeatureTerrainAdjustments;
  // 临时滞留的实体（位于未加载区块的实体）
  ::ll::TypedStorage<
      8, 64,
      ::std::unordered_map<::ChunkPos,
                           ::std::vector<::std::unique_ptr<::CompoundTag>>>>
      mLimboEntities;
  // 需要移动区块的实体集合
  ::ll::TypedStorage<8, 16, ::std::set<::ActorUniqueID>> mEntitiesToMoveChunks;
  // 常加载区域列表
  ::ll::TypedStorage<8, 16, ::std::shared_ptr<::TickingAreaList>>
      mTickingAreaList;
  // 关卡区块垃圾回收器
  ::ll::TypedStorage<8, 632, ::LevelChunkGarbageCollector>
      mLevelChunkGarbageCollector;
  // 凋零的ID集合
  ::ll::TypedStorage<8, 16, ::std::set<::ActorUniqueID>> mWitherIDs;
  // 关卡区块构建器数据
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::LevelChunkBuilderData>>
      mLevelChunkBuilderData;
  // 上次修剪时间
  ::ll::TypedStorage<8, 8, ::std::chrono::steady_clock::time_point>
      mLastPruneTime;
  // 上次结构修剪时间
  ::ll::TypedStorage<8, 8, ::std::chrono::steady_clock::time_point>
      mLastStructurePruneTime;
  // 区块构建顺序策略
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ChunkBuildOrderPolicyBase>>
      mChunkBuildOrderPolicy;
  // 村庄管理器
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::VillageManager>> mVillageManager;
  // 临时玩家ID列表
  ::ll::TypedStorage<8, 24, ::std::vector<::NetworkIdentifierWithSubId>>
      mTemporaryPlayerIds;
  // 区块加载行为列表
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ChunkLoadActionList>>
      mChunkLoadActionList;
  // 延迟行为列表
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::DelayActionList>>
      mDelayActionList;
  // 按子区块记录的方块变更映射
  ::ll::TypedStorage<
      8, 64,
      ::std::unordered_map<::SubChunkPos, ::UpdateSubChunkBlocksChangedInfo>>
      mBlocksChangedBySubChunkMap;
  // 实体同步管理器
  ::ll::TypedStorage<8, 112, ::ActorReplication> mActorReplication;
  // 需要同步的玩家列表
  ::ll::TypedStorage<8, 24, ::std::vector<::WeakEntityRef>> mPlayersToReplicate;
  // 是否运行区块生成看门狗（用于检测生成卡顿）
  ::ll::TypedStorage<1, 1, bool> mRunChunkGenWatchDog;
  // NOLINTEND

public:
  // prevent constructor by default
  Dimension &operator=(Dimension const &);
  Dimension(Dimension const &);
  Dimension();

public:
  // virtual functions
  // 虚函数
  // NOLINTBEGIN
  // vIndex: 0
  virtual ~Dimension() /*override*/; // 析构函数

  // vIndex: 14
  virtual void init(::br::worldgen::StructureSetRegistry const
                        &structureSetRegistry); // 初始化维度

  // vIndex: 15
  virtual void tick(); // 每个游戏刻更新维度逻辑

  // vIndex: 16
  virtual void tickRedstone(); // 每个游戏刻更新红石电路

  // vIndex: 17
  virtual ::std::unique_ptr<::WorldGenerator>
  createGenerator(::br::worldgen::StructureSetRegistry const
                      &) = 0; // 创建世界生成器（纯虚函数）

  // vIndex: 18
  virtual void
  upgradeLevelChunk(::ChunkSource &, ::LevelChunk &,
                    ::LevelChunk &) = 0; // 升级关卡区块以兼容新版本（纯虚函数）

  // vIndex: 19
  virtual void
  fixWallChunk(::ChunkSource &,
               ::LevelChunk &) = 0; // 修复区块中的墙壁连接问题（纯虚函数）

  // vIndex: 6
  virtual void initializeWithLevelStorageManagerConnector(
      ::ILevelStorageManagerConnector
          &levelStorageManagerConnector) /*override*/
      ; // 使用关卡存储管理器连接器进行初始化

  // vIndex: 20
  virtual bool levelChunkNeedsUpgrade(
      ::LevelChunk const &) const = 0; // 检查关卡区块是否需要升级（纯虚函数）

  // vIndex: 1
  virtual bool isNaturalDimension() const
      /*override*/; // 是否为自然维度（影响睡眠、怪物生成等）

  // vIndex: 21
  virtual bool isValidSpawn(int x,
                            int z) const; // 检查指定坐标是否为有效的出生点

  // vIndex: 22
  virtual ::mce::Color getBrightnessDependentFogColor(
      ::mce::Color const &baseColor,
      float brightness) const; // 获取依赖于亮度的雾颜色

  // vIndex: 23
  virtual short getCloudHeight() const; // 获取云的高度

  // vIndex: 24
  virtual ::HashedString getDefaultBiome() const; // 获取默认的生物群系

  // vIndex: 25
  virtual bool mayRespawnViaBed() const; // 是否可以通过床重生

  // vIndex: 26
  virtual ::BlockPos getSpawnPos() const; // 获取出生点位置

  // vIndex: 27
  virtual int getSpawnYPosition() const; // 获取出生点的Y坐标

  // vIndex: 28
  virtual bool showSky() const; // 是否显示天空

  // vIndex: 29
  virtual float getTimeOfDay(int time,
                             float a) const; // 获取一天中的时间（用于天空渲染）

  // vIndex: 30
  virtual void setDimensionDirectionalLightControls(
      ::std::variant<::Dimension::ChaoticDirectionalLightControls> const
          &); // 设置维度的定向光控制

  // vIndex: 31
  virtual ::Dimension::DirectionalLightState
  getDimensionDirectionalLightSourceState(
      float a) const; // 获取维度的定向光状态

  // vIndex: 2
  virtual ::DimensionType getDimensionId() const /*override*/; // 获取维度ID

  // vIndex: 10
  virtual void
  forEachPlayer(::brstd::function_ref<bool(::Player &)> callback) const
      /*override*/; // 遍历此维度中的所有玩家

  // vIndex: 8
  virtual ::BiomeRegistry &
  getBiomeRegistry() /*override*/; // 获取生物群系注册表

  // vIndex: 7
  virtual ::BiomeRegistry const &getBiomeRegistry() const
      /*override*/; // 获取生物群系注册表 (const)

  // vIndex: 12
  virtual ::BlockSource &getBlockSourceFromMainChunkSource() const
      /*override*/; // 从主区块源获取方块源

  // vIndex: 11
  virtual ::Actor *fetchEntity(::ActorUniqueID actorID, bool getRemoved) const
      /*override*/; // 通过唯一ID获取实体

  // vIndex: 20
  virtual void onChunkLoaded(::ChunkSource &source,
                             ::LevelChunk &lc) /*override*/; // 当区块加载时调用

  // vIndex: 1
  virtual void deserialize(
      ::CompoundTag const &tag) /*override*/; // 从 NBT 标签反序列化维度数据

  // vIndex: 2
  virtual void serialize(::CompoundTag &tag) const
      /*override*/; // 将维度数据序列化到 NBT 标签

  // vIndex: 32
  virtual void
  sendBroadcast(::Packet const &packet,
                ::Player *except); // 向维度中的所有玩家广播数据包（可排除一人）

  // vIndex: 33
  virtual bool is2DPositionRelevantForPlayer(
      ::BlockPos const &position,
      ::Player &player) const; // 检查一个2D位置是否与玩家相关（用于网络同步）

  // vIndex: 13
  virtual void buildPlayersForPositionPacket(
      ::BlockPos const &position, ::Player const *except,
      ::std::vector<::NetworkIdentifierWithSubId> &result) const
      /*override*/; // 为位置数据包构建目标玩家列表

  // vIndex: 3
  virtual void sendPacketForPosition(
      ::BlockPos const &position, ::Packet const &packet,
      ::Player const *except) /*override*/; // 向关心某位置的玩家发送数据包

  // vIndex: 4
  virtual void sendPacketForEntity(
      ::Actor const &actor, ::Packet const &packet,
      ::Player const *except) /*override*/; // 向关心某实体的玩家发送数据包

  // vIndex: 34
  virtual bool isActorRelevantForPlayer(::Player &player, ::Actor const &actor)
      const; // 检查一个实体是否与玩家相关

  // vIndex: 8
  virtual void onBlockEvent(::BlockSource &source, int x, int y, int z, int b0,
                            int b1) /*override*/; // 当发生方块事件时调用

  // vIndex: 4
  virtual void
  onBlockChanged(::BlockSource &source, ::BlockPos const &pos, uint layer,
                 ::Block const &block, ::Block const &oldBlock, int updateFlags,
                 ::ActorBlockSyncMessage const *syncMsg,
                 ::BlockChangedEventTarget eventTarget,
                 ::Actor *blockChangeSource) /*override*/; // 当方块变更时调用

  // vIndex: 24
  virtual void
  onLevelDestruction(::std::string const &) /*override*/; // 当关卡被销毁时调用

  // vIndex: 35
  virtual ::BaseLightTextureImageBuilder *
  getLightTextureImageBuilder() const; // 获取光照贴图图像构建器

  // vIndex: 36
  virtual ::DimensionBrightnessRamp const &
  getBrightnessRamp() const; // 获取亮度渐变控制器

  // vIndex: 37
  virtual void startLeaveGame(); // 开始离开游戏的流程

  // vIndex: 5
  virtual void
  flushLevelChunkGarbageCollector() /*override*/; // 刷新关卡区块垃圾回收器

  // vIndex: 38
  virtual ::std::unique_ptr<::ChunkBuildOrderPolicyBase>
  _createChunkBuildOrderPolicy(); // (内部) 创建区块构建顺序策略

  // vIndex: 39
  virtual void _upgradeOldLimboEntity(
      ::CompoundTag &,
      ::LimboEntitiesVersion) = 0; // (内部)
                                   // 升级旧版的临时滞留实体数据（纯虚函数）

  // vIndex: 40
  virtual ::std::unique_ptr<::ChunkSource> _wrapStorageForVersionCompatibility(
      ::std::unique_ptr<::ChunkSource>,
      ::StorageVersion) = 0; // (内部) 为了版本兼容性包装区块存储（纯虚函数）
                             // NOLINTEND

public:
  // member functions
  // 成员函数
  // NOLINTBEGIN
  /**
   * @brief Dimension 构造函数
   * @param level 维度所属的 Level
   * @param dimId 维度 ID
   * @param heightRange 维度的高度范围
   * @param callbackContext 调度器
   * @param name 维度名称
   */
  MCAPI Dimension(::ILevel &level, ::DimensionType dimId,
                  ::DimensionHeightRange heightRange,
                  ::Scheduler &callbackContext, ::std::string name);

  // (内部) 将实体到未加载区块的转移请求添加到队列中
  MCAPI void _addActorUnloadedChunkTransferToQueue(
      ::ChunkPos const &fromChunkPos, ::ChunkPos const &toChunkPos,
      ::DimensionType dimId, ::std::string &actorStorageKey,
      ::std::unique_ptr<::CompoundTag> entityTag);

  // (内部) 完成实体的转移过程
  MCAPI void _completeEntityTransfer(::OwnerPtr<::EntityContext> entity);

  // (内部) 处理实体在区块间的转移请求
  MCAPI void _processEntityChunkTransfers();

  // (内部) 发送方块变更的数据包
  MCAPI void _sendBlocksChangedPackets();

  // (内部) 更新实体的区块移动状态
  MCAPI void _tickEntityChunkMoves();

  // 添加一只凋零到维度记录中
  MCAPI void addWither(::ActorUniqueID const &id);

  // 计算到最近玩家的2D平面距离的平方
  MCAPI float distanceToNearestPlayerSqr2D(::Vec3 origin);

  // 获取任何可交互的玩家
  MCAPI ::Player *fetchAnyInteractablePlayer(::Vec3 const &searchPos,
                                             float maxDist) const;

  // 获取对指定实体而言最近的可攻击玩家
  MCAPI ::Player *fetchNearestAttackablePlayer(::Actor &source,
                                               float maxDist) const;

  // 获取最近的可交互玩家
  MCAPI ::Player *fetchNearestInteractablePlayer(::Vec3 const &searchPos,
                                                 float maxDist) const;

  // 获取最近的玩家，可附带过滤器
  MCAPI ::Player *fetchNearestPlayer(
      ::Vec3 const &searchPos, float maxDist, bool isFetchAny,
      ::brstd::function_ref<bool(::Player const &)> playerFilter) const;

  // 查找满足条件的第一个玩家
  MCAPI ::Player *
  findPlayer(::brstd::function_ref<bool(::Player const &)> pred) const;

  // 标记一个实体需要移动到另一个区块
  MCAPI void flagEntityforChunkMove(::Actor &e);

  // 获取区块源
  MCAPI ::ChunkSource &getChunkSource() const;

  // 获取维度以子区块为单位的高度
  MCAPI ushort getHeightInSubchunks() const;

  // 获取月亮亮度
  MCAPI float getMoonBrightness() const;

  // 获取旧版的天空变暗值
  MCAPI ::Brightness getOldSkyDarken(float a);

  // 检查室外是否明亮
  MCAPI bool isBrightOutside() const;

  // 比较两个维度是否相同
  MCAPI bool operator==(::Dimension const &rhs) const;

  // 通过ID移除一个实体
  MCAPI void removeActorByID(::ActorUniqueID const &id);

  // 将一个实体从一个区块转移到另一个位置
  MCAPI void transferEntity(::ChunkPos const &fromChunkPos,
                            ::Vec3 const &spawnPos,
                            ::std::unique_ptr<::CompoundTag> entityTag);

  // 将一个实体转移到未加载的区块（实体会进入“滞留”状态）
  MCAPI void transferEntityToUnloadedChunk(::Actor &actor,
                                           ::LevelChunk *fromChunk);

  // 将一个实体转移到未加载的区块
  MCAPI void transferEntityToUnloadedChunk(
      ::ChunkPos const &fromChunkPos, ::ChunkPos const &toChunkPos,
      ::DimensionType dimId, ::std::string &actorStorageKey,
      ::std::unique_ptr<::CompoundTag> entityTag);

  // 尝试垃圾回收结构数据
  MCAPI void tryGarbageCollectStructures();

  // 尝试加载指定位置的临时滞留实体
  MCAPI void tryLoadLimboEntities(::ChunkPos const &loadPos);

  // 注销一个显示实体
  MCAPI void unregisterDisplayEntity(::WeakRef<::EntityContext> entityRef);

  // 注销一个实体
  MCAPI void unregisterEntity(::ActorUniqueID const &actorID);
  // NOLINTEND

public:
  // static variables
  // 静态变量
  // NOLINTBEGIN
  // 每个月相对应的月亮亮度数组
  MCAPI static ::std::add_lvalue_reference_t<float const[]>
  MOON_BRIGHTNESS_PER_PHASE();

  // 结构数据修剪的间隔时间
  MCAPI static ::std::chrono::seconds const &STRUCTURE_PRUNE_INTERVAL();
  // NOLINTEND
public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::ILevel&              level,
        ::DimensionType        dimId,
        ::DimensionHeightRange heightRange,
        ::Scheduler&           callbackContext,
        ::std::string          name
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
    MCAPI void $init(::br::worldgen::StructureSetRegistry const& structureSetRegistry);

    MCAPI void $tick();

    MCAPI void $tickRedstone();

    MCAPI void
    $initializeWithLevelStorageManagerConnector(::ILevelStorageManagerConnector& levelStorageManagerConnector);

    MCFOLD bool $isNaturalDimension() const;

    MCFOLD bool $isValidSpawn(int x, int z) const;

    MCAPI ::mce::Color $getBrightnessDependentFogColor(::mce::Color const& baseColor, float brightness) const;

    MCFOLD short $getCloudHeight() const;

    MCAPI ::HashedString $getDefaultBiome() const;

    MCFOLD bool $mayRespawnViaBed() const;

    MCFOLD ::BlockPos $getSpawnPos() const;

    MCFOLD int $getSpawnYPosition() const;

    MCFOLD bool $showSky() const;

    MCAPI float $getTimeOfDay(int time, float a) const;

    MCFOLD void
    $setDimensionDirectionalLightControls(::std::variant<::Dimension::ChaoticDirectionalLightControls> const&);

    MCAPI ::Dimension::DirectionalLightState $getDimensionDirectionalLightSourceState(float a) const;

    MCAPI ::DimensionType $getDimensionId() const;

    MCAPI void $forEachPlayer(::brstd::function_ref<bool(::Player&)> callback) const;

    MCFOLD ::BiomeRegistry& $getBiomeRegistry();

    MCFOLD ::BiomeRegistry const& $getBiomeRegistry() const;

    MCFOLD ::BlockSource& $getBlockSourceFromMainChunkSource() const;

    MCAPI ::Actor* $fetchEntity(::ActorUniqueID actorID, bool getRemoved) const;

    MCAPI void $onChunkLoaded(::ChunkSource& source, ::LevelChunk& lc);

    MCAPI void $deserialize(::CompoundTag const& tag);

    MCAPI void $serialize(::CompoundTag& tag) const;

    MCAPI void $sendBroadcast(::Packet const& packet, ::Player* except);

    MCAPI bool $is2DPositionRelevantForPlayer(::BlockPos const& position, ::Player& player) const;

    MCAPI void $buildPlayersForPositionPacket(
        ::BlockPos const&                            position,
        ::Player const*                              except,
        ::std::vector<::NetworkIdentifierWithSubId>& result
    ) const;

    MCAPI void $sendPacketForPosition(::BlockPos const& position, ::Packet const& packet, ::Player const* except);

    MCAPI void $sendPacketForEntity(::Actor const& actor, ::Packet const& packet, ::Player const* except);

    MCAPI bool $isActorRelevantForPlayer(::Player& player, ::Actor const& actor) const;

    MCAPI void $onBlockEvent(::BlockSource& source, int x, int y, int z, int b0, int b1);

    MCAPI void $onBlockChanged(
        ::BlockSource&                 source,
        ::BlockPos const&              pos,
        uint                           layer,
        ::Block const&                 block,
        ::Block const&                 oldBlock,
        int                            updateFlags,
        ::ActorBlockSyncMessage const* syncMsg,
        ::BlockChangedEventTarget      eventTarget,
        ::Actor*                       blockChangeSource
    );

    MCAPI void $onLevelDestruction(::std::string const&);

    MCFOLD ::BaseLightTextureImageBuilder* $getLightTextureImageBuilder() const;

    MCFOLD ::DimensionBrightnessRamp const& $getBrightnessRamp() const;

    MCAPI void $startLeaveGame();

    MCAPI void $flushLevelChunkGarbageCollector();

    MCAPI ::std::unique_ptr<::ChunkBuildOrderPolicyBase> $_createChunkBuildOrderPolicy();
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftableForSavedData();

    MCNAPI static void** $vftableForEnableNonOwnerReferences();

    MCNAPI static void** $vftableForIDimension();

    MCNAPI static void** $vftableForLevelListener();
    // NOLINTEND
};
