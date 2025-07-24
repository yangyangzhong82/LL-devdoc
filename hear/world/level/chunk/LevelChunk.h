#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/client/renderer/block/tessellation_pipeline/VolumeOf.h"
#include "mc/common/BrightnessPair.h"
#include "mc/deps/core/utility/buffer_span.h"
#include "mc/deps/game_refs/WeakRef.h"
#include "mc/network/packet/SubChunkPacket.h"
#include "mc/platform/threading/Mutex.h"
#include "mc/platform/threading/SpinLockImpl.h"
#include "mc/platform/threading/UniqueLock.h"
#include "mc/world/actor/ActorType.h"
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/ChunkLocalHeight.h"
#include "mc/world/level/ChunkPos.h"
#include "mc/world/level/Tick.h"
#include "mc/world/level/chunk/BiomeChunkData.h"
#include "mc/world/level/chunk/ChunkCachedDataState.h"
#include "mc/world/level/chunk/ChunkDebugDisplaySavedState.h"
#include "mc/world/level/chunk/ChunkState.h"
#include "mc/world/level/chunk/ChunkTerrainDataState.h"
#include "mc/world/level/chunk/ColumnCachedData.h"
#include "mc/world/level/chunk/DirtyTicksCounter.h"
#include "mc/world/level/chunk/LevelChunkBlockActorStorage.h"
#include "mc/world/level/chunk/LevelChunkFormat.h"
#include "mc/world/level/chunk/LevelChunkNeighbor.h"
#include "mc/world/level/chunk/LevelChunkVolumeData.h"
#include "mc/world/level/chunk/SubChunkInitMode.h"
#include "mc/world/level/chunk/SubChunkStorage.h"
#include "mc/world/level/chunk/level_chunk_ticking/Entity.h"
#include "mc/world/level/levelgen/structure/BoundingBox.h"
#include "mc/world/level/levelgen/v1/HardcodedSpawnAreaType.h"

// auto generated forward declare list
// clang-format off
class AABB;
class Actor;
class Biome;
class BiomeRegistry;
class Block;
class BlockActor;
class BlockSource;
class BlockTickingQueue;
class BlockVolume;
class ChunkBlockPos;
class ChunkSource;
class ChunkViewSource;
class Dimension;
class EntityContext;
class GameEventListenerRegistry;
class IDataInput;
class IDataOutput;
class ILevel;
class LevelChunkMetaData;
class Random;
class SaveContext;
class StringByteInput;
class SubChunkPos;
class Vec3;
class WeakEntityRef;
class Weather;
struct ActorDefinitionIdentifier;
struct ActorLink;
struct BiomeChunkState;
struct BlockID;
struct DeserializationChanges;
struct NibblePair;
struct SubChunk;
namespace LevelChunkTicking { struct Registry; }
// clang-format on

class LevelChunk {
public:
  // LevelChunk 内部类型声明
  // clang-format off
    class Neighbors;
    struct SpawningArea;
    struct Telemetry;
  // clang-format on

  // LevelChunk 内部类型定义
  enum class Finalization : int {
    NeedsInstaticking = 0, // 需要立即更新（Instatick）
    NeedsPopulation = 1,   // 需要填充（Population，如生成特征）
    Done = 2,              // 完成
  };

  class Neighbors {
  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 用一个字节的位域来存储8个邻居区块的可用状态。
    ::ll::TypedStorage<1, 1, uchar> mNeighbors;
    // NOLINTEND

  public:
    // static variables
    // 静态变量
    // NOLINTBEGIN
    // 邻居区块的偏移量映射表。
    MCNAPI static ::std::array<::std::pair<::LevelChunkNeighbor, ::ChunkPos>,
                               8> const &
    sOffsetMap();
    // NOLINTEND
  };

  struct Telemetry {
  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 遥测数据：此区块是否曾被存储过。
    ::ll::TypedStorage<1, 1, bool> mWasStored;
    // 遥测数据：此区块是否曾被生成过。
    ::ll::TypedStorage<1, 1, bool> mWasGenerated;
    // 遥测数据：此区块是否在Tick范围内被请求过。
    ::ll::TypedStorage<1, 1, bool> mWasRequestedInsideTickRange;
    // 遥测数据：此区块是否在Tick范围内被加载过。
    ::ll::TypedStorage<1, 1, bool> mWasLoadedInsideTickRange;
    // NOLINTEND
  };

  // 方块位置列表的类型别名
  using BlockList = ::std::vector<::BlockPos>;

  // 方块实体向量的类型别名
  using BlockActorVector = ::std::vector<::std::shared_ptr<::BlockActor>>;

  struct SpawningArea {
  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 硬编码生成区域的包围盒。
    ::ll::TypedStorage<4, 24, ::BoundingBox> aabb;
    // 硬编码生成区域的类型（如要塞）。
    ::ll::TypedStorage<1, 1, ::HardcodedSpawnAreaType> type;
    // NOLINTEND
  };

  // 边界方块的类型别名
  using BBorder = bool;

  // 反序列化实体的结果枚举
  enum class DeserializeEntityResult : int {
    FailedToLoadActor = 0,  // 加载实体失败
    FailedToAddToLevel = 1, // 添加到关卡失败
    Succeeded = 2,          // 成功
  };

public:
  // member variables
  // 成员变量
  // NOLINTBEGIN
  // 用于访问方块实体的互斥锁。
  ::ll::TypedStorage<8, 80, ::Bedrock::Threading::Mutex> mBlockEntityAccessLock;
  // 区块所属的Level的引用。
  ::ll::TypedStorage<8, 8, ::ILevel &> mLevel;
  // 区块所属的Dimension的引用。
  ::ll::TypedStorage<8, 8, ::Dimension &> mDimension;
  // 区块的最小坐标。
  ::ll::TypedStorage<4, 12, ::BlockPos> mMin;
  // 区块的最大坐标。
  ::ll::TypedStorage<4, 12, ::BlockPos> mMax;
  // 区块的位置。
  ::ll::TypedStorage<8, 8, ::ChunkPos> mPosition;
  // 标记光照修复是否完成。
  ::ll::TypedStorage<1, 1, bool> mLightingFixupDone;
  // 标记光照任务是否正在进行的原子布尔值。
  ::ll::TypedStorage<1, 1, ::std::atomic<bool>> mLightingTaskActive;
  // 标记区块是否为只读。
  ::ll::TypedStorage<1, 1, bool> mReadOnly;
  // 指向生成此区块的ChunkSource。
  ::ll::TypedStorage<8, 8, ::ChunkSource *> mGenerator;
  // 临时用于计划更新的实体。
  ::ll::TypedStorage<4, 4, ::LevelChunkTicking::Entity> mTmpTickingEntity;
  // 加载此区块时使用的格式。
  ::ll::TypedStorage<1, 2, ::std::optional<::LevelChunkFormat>> mLoadedFormat;
  // 序列化的实体数据缓冲区。
  ::ll::TypedStorage<8, 32, ::std::string> mSerializedEntitiesBuffer;
  // 序列化失败的实体数据缓冲区。
  ::ll::TypedStorage<8, 32, ::std::string> mFailedSerializedEntitiesBuffer;
  // 标记区块是否曾包含序列化的实体。
  ::ll::TypedStorage<1, 1, bool> mHadSerializedEntities;
  // 未解析的实体链接列表。
  ::ll::TypedStorage<8, 24, ::std::vector<::ActorLink>> mUnresolvedActorLinks;
  // 区块的加载状态（原子）。
  ::ll::TypedStorage<1, 1, ::std::atomic<::ChunkState>> mLoadState;
  // 区块地形数据的状态。
  ::ll::TypedStorage<1, 1, ::ChunkTerrainDataState> mTerrainDataState;
  // 区块调试显示信息的保存状态。
  ::ll::TypedStorage<1, 1, ::ChunkDebugDisplaySavedState>
      mDebugDisplaySavedState;
  // 区块缓存数据的状态。
  ::ll::TypedStorage<1, 1, ::ChunkCachedDataState> mCachedDataState;
  // 用于缓存数据状态的自旋锁。
  ::ll::TypedStorage<8, 32, ::SpinLockImpl> mCachedDataStateSpinLock;
  // 客户端请求高度图调整时的自旋锁。
  ::ll::TypedStorage<8, 32, ::SpinLockImpl>
      mClientRequestHeightmapAdjustSpinLock;
  // 上一次更新此区块的游戏刻。
  ::ll::TypedStorage<8, 8, ::Tick> mLastTick;
  // 方块计划更新队列。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BlockTickingQueue>> mTickQueue;
  // 方块随机计划更新队列。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BlockTickingQueue>>
      mRandomTickQueue;
  // 存储区块内所有子区块的向量。
  ::ll::TypedStorage<8, 24, ::std::vector<::SubChunk>> mSubChunks;
  // 每个子区块的自旋锁。
  ::ll::TypedStorage<8, 24, ::std::vector<::std::unique_ptr<::SpinLockImpl>>>
      mSubChunkSpinLocks;
  // 3D生物群系数据存储。
  ::ll::TypedStorage<
      8, 24, ::std::vector<::std::unique_ptr<::SubChunkStorage<::Biome>>>>
      mBiomes;
  // 2D生物群系数据。
  ::ll::TypedStorage<2, 512, ::std::array<::BiomeChunkData, 256>> m2DBiomes;
  // 用于访问生物群系数据的共享互斥锁。
  ::ll::TypedStorage<8, 8, ::std::shared_mutex> mBiomesMutex;
  // 缓存的列数据（如高度图）。
  ::ll::TypedStorage<4, 2048, ::std::array<::ColumnCachedData, 256>>
      mCachedData;
  // 高度图。
  ::ll::TypedStorage<2, 512, ::std::array<::ChunkLocalHeight, 256>> mHeightmap;
  // 用于渲染的高度图。
  ::ll::TypedStorage<2, 512, ::std::array<::ChunkLocalHeight, 256>>
      mRenderHeightmap;
  // 世界生成前的高度图。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::std::vector<short>>>
      mPreWorldGenHeightmap;
  // 非空气方块的最高高度。
  ::ll::TypedStorage<2, 2, ::ChunkLocalHeight> mNonAirMaxHeight;
  // 生物群系状态映射。
  ::ll::TypedStorage<8, 64, ::std::unordered_map<ushort, ::BiomeChunkState>>
      mBiomeStates;
  // 3D生物群系的堆叠大小。
  ::ll::TypedStorage<2, 2, ushort> m3dBiomeStackSize;
  // 是否缓存了温度噪声。
  ::ll::TypedStorage<1, 1, bool> mHasCachedTemperatureNoise;
  // 边界方块映射表。
  ::ll::TypedStorage<1, 256, ::std::array<bool, 256>> mBorderBlockMap;
  // 当前的立即更新（Instatick）计数。
  ::ll::TypedStorage<4, 4, int> mCurrentInstatick;
  // 区块的最终完成状态。
  ::ll::TypedStorage<4, 4, ::LevelChunk::Finalization> mFinalized;
  // 红石电路是否已加载。
  ::ll::TypedStorage<1, 1, bool> mIsRedstoneLoaded;
  // 是否由计划更新线程拥有。
  ::ll::TypedStorage<1, 1, bool> mOwnedByTickingThread;
  // 是否使用3D生物群系图。
  ::ll::TypedStorage<1, 1, bool> mUse3DBiomeMaps;
  // 区块是否带有3D生物群系标签。
  ::ll::TypedStorage<1, 1, bool> mLevelChunkHas3dBiomeTag;
  // 区块的遥测数据。
  ::ll::TypedStorage<1, 4, ::LevelChunk::Telemetry> mTelemetry;
  // 整个区块的脏刻计数器。
  ::ll::TypedStorage<4, 48, ::DirtyTicksCounter[6]>
      mFullChunkDirtyTicksCounters;
  // 区块内实体的脏刻计数器。
  ::ll::TypedStorage<4, 8, ::DirtyTicksCounter> mChunkActorsDirtyTicksCounter;
  // 降雨高度图。
  ::ll::TypedStorage<2, 512, ::std::array<::ChunkLocalHeight, 256>>
      mRainHeights;
  // 区块内的实体列表。
  ::ll::TypedStorage<8, 24, ::std::vector<::WeakEntityRef>> mEntities;
  // 已移除实体的存储键。
  ::ll::TypedStorage<8, 24, ::std::vector<::std::string>>
      mRemovedActorStorageKeys;
  // 区块内的方块实体存储。
  ::ll::TypedStorage<8, 136, ::LevelChunkBlockActorStorage> mBlockEntities;
  // 被保留的方块实体（在重新加载时不清空）。
  ::ll::TypedStorage<8, 24, ::std::vector<::std::shared_ptr<::BlockActor>>>
      mPreservedBlockEntities;
  // 区块内的体积实体。
  ::ll::TypedStorage<8, 24, ::std::vector<::WeakRef<::EntityContext>>> mVolumes;
  // 默认亮度。
  ::ll::TypedStorage<1, 2, ::BrightnessPair> mDefaultBrightness;
  // 硬编码的生成区域列表。
  ::ll::TypedStorage<8, 24, ::std::vector<::LevelChunk::SpawningArea>>
      mSpawningAreas;
  // 上次网络光照更新的时间。
  ::ll::TypedStorage<8, 8, ::std::chrono::steady_clock::time_point>
      mLastNetworkLightingTime;
  // 已加载的元数据的哈希值。
  ::ll::TypedStorage<8, 8, uint64> mLoadedMetaDataHash;
  // 区块的元数据。
  ::ll::TypedStorage<8, 16, ::std::shared_ptr<::LevelChunkMetaData>> mMetaData;
  // 客户端是否需要请求子区块。
  ::ll::TypedStorage<1, 1, bool> mClientNeedsToRequestSubChunks;
  // 区块是否已经进行过初次光照计算。
  ::ll::TypedStorage<1, 1, bool> mLevelChunkHasHadOriginalLighting;
  // 区块角点的插值。
  ::ll::TypedStorage<4, 16, float[2][2]> mChunkInterpolants;
  // 区块是否带有转换器标签。
  ::ll::TypedStorage<1, 1, bool> mbChunkHasConverterTag;
  // 已保存的邻居状态。
  ::ll::TypedStorage<1, 1, ::LevelChunk::Neighbors> mSavedNeighbors;
  // 生成此区块时使用的种子。
  ::ll::TypedStorage<4, 8, ::std::optional<uint>> mGenerationSeed;
  // 区块是否在“洞穴与山崖”更新的混合处理之前生成。
  ::ll::TypedStorage<1, 1, bool> mGeneratedPreCavesAndCliffsBlending;
  // onChunkLoaded 回调是否已被调用。
  ::ll::TypedStorage<1, 1, bool> mOnChunkLoadedCalled;
  // 所有序列化的实体是否已加载完成。
  ::ll::TypedStorage<1, 1, bool> mAllSerializedEntitiesLoaded;
  // 越界实体的序列化数据缓冲区。
  ::ll::TypedStorage<8, 32, ::std::string> mOutOfBoundsEntitiesBuffer;
  // 越界方块实体的序列化数据缓冲区。
  ::ll::TypedStorage<8, 32, ::std::string> mOutOfBoundsBlockEntitiesBuffer;
  // 如果脏了，是否保存非实体数据。
  ::ll::TypedStorage<1, 1, bool> mSaveNonActorDataIfDirty;
  // 如果从未保存过，是否保存。
  ::ll::TypedStorage<1, 1, bool> mSaveIfNeverSaved;
  // 用于雪生成的随机值（原子）。
  ::ll::TypedStorage<4, 4, ::std::atomic<int>> mSnowRandomValue;
  // 是否有待修剪的子区块。
  ::ll::TypedStorage<1, 1, bool> mHasSubChunksToPrune;
  // 子区块是否已被修剪。
  ::ll::TypedStorage<1, 1, bool> mHaveSubChunksBeenPruned;
  // 在超平坦世界中是否应该向上移动子区块。
  ::ll::TypedStorage<1, 1, bool> mShouldShiftUpFlatWorldSubChunks;
  // 用于修剪子区块的自旋锁。
  ::ll::TypedStorage<8, 32, ::SpinLockImpl> mSubChunksToPruneLock;
  // 范围外待修剪的子区块。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::std::vector<::SubChunk>>>
      mSubChunksToPruneOutsideRange;
  // 游戏事件监听器注册表（用于Sculk）。
  ::ll::TypedStorage<8, 16, ::std::shared_ptr<::GameEventListenerRegistry>>
      mGameEventListenerRegistry;
  // 是否为客户端生成的区块。
  ::ll::TypedStorage<1, 1, bool> mIsClientGenerated;
  // 是否曾经是客户端生成的区块。
  ::ll::TypedStorage<1, 1, bool> mWasClientGenerated;
  // 是否为空的客户端区块。
  ::ll::TypedStorage<1, 1, bool> mIsEmptyClientChunk;
  // 检查替换数据后，实体存储是否已更新。
  ::ll::TypedStorage<1, 1, bool>
      mActorStorageUpdatedAfterCheckingForReplacementData;
  // 区块的体积数据。
  ::ll::TypedStorage<8, 856, ::LevelChunkVolumeData> mLevelChunkVolumeData;
  // NOLINTEND

public:
  // prevent constructor by default
  LevelChunk &operator=(LevelChunk const &);
  LevelChunk(LevelChunk const &);
  LevelChunk();

public:
  // member functions
  // 成员函数
  // NOLINTBEGIN
  /**
   * @brief LevelChunk 构造函数。
   * @param dimension 区块所属的维度。
   * @param cp 区块的位置。
   * @param readOnly 是否为只读。
   * @param initBlocks 子区块的初始化模式。
   * @param initializeMetaData 是否初始化元数据。
   * @param blockActorTrackingMode 方块实体追踪模式。
   */
  MCAPI LevelChunk(
      ::Dimension &dimension, ::ChunkPos const &cp, bool readOnly,
      ::SubChunkInitMode initBlocks, bool initializeMetaData,
      ::LevelChunkBlockActorStorage::TrackingMode blockActorTrackingMode);

  // (内部) 将一个实体添加到其所在的体积实体列表中。
  MCAPI void _addEntityToVolumes(::gsl::not_null<::Actor *> actor);

  // (内部) 在反序列化后检查并推断元数据。
  MCAPI void _checkAndInferMetaDataAfterDeserialization();

  // (内部) 创建一个方块实体。
  MCAPI ::std::shared_ptr<::BlockActor>
  _createBlockEntity(::BlockPos const &block, ::BlockSource *currentSource,
                     ::Block const &current, ::Block const &old);

  // (内部) 从流中反序列化生物群系数据。
  MCAPI void _deserializeBiomes(::IDataInput &stream,
                                ::BiomeRegistry const &biomeRegistry,
                                bool fromNetwork);

  // (内部) 从流中反序列化方块实体数据。
  MCAPI void
  _deserializeBlockEntities(::IDataInput &stream,
                            ::LevelChunkBlockActorStorage &blockEntityMap);

  // (内部) 反序列化洞穴与山崖更新的子区块。
  MCAPI void _deserializeCCsubChunks(short index, ::StringByteInput &stream);

  // (内部) 从流中反序列化一个实体。
  MCAPI ::LevelChunk::DeserializeEntityResult
  _deserializeEntity(::BlockSource &source, ::IDataInput &stream,
                     ::std::vector<::ActorLink> &links);

  // (内部) 从流中反序列化一个子区块。
  MCAPI bool _deserializeSubChunk(short index, ::StringByteInput &stream);

  // (内部) 修复计划更新队列中的命令方块。
  MCAPI void _fixupCommandBlocksOnTickingQueue(::BlockSource &tickRegion);

  // (内部) 修复损坏的方块实体。
  MCAPI void
  _fixupCorruptedBlockActors(::LevelChunkBlockActorStorage &deserialized,
                             ::buffer_span_mut<::SubChunk> subchunks);

  // (内部) 生成初次光照。
  MCAPI void _generateOriginalLighting(::ChunkViewSource &neighborhood,
                                       bool enforceBorderCheck);

  // (内部) 为单个子区块生成初次光照。
  MCAPI void _generateOriginalLightingSubChunk(::BlockSource &source,
                                               uint64 subchunkIdx, bool);

  // (内部) 方块变更时的光照回调。
  MCAPI void _lightingCallbacks(::ChunkBlockPos const &pos, ::Block const &old,
                                ::Block const &current,
                                ::BlockSource *currentSource);

  // (内部) 使区块内的生物群系统一。
  MCAPI void _makeUniformBiomes(::Biome const &biome);

  // (内部) 放置一个方块实体到区块中。
  MCAPI void _placeBlockEntity(::std::shared_ptr<::BlockActor> te);

  // (内部) 重新计算高度图。
  MCAPI bool _recalcHeight(::ChunkBlockPos const &start, ::BlockSource *source);

  // (内部) 移除方块时的回调。
  MCAPI void _removeCallbacks(::ChunkBlockPos const &pos,
                              ::Block const &oldBlock, ::Block const &current,
                              ::BlockSource *currentSource);

  // (内部) 替换生物群系存储。
  MCAPI void _replaceBiomeStorage(
      ushort biomeIndex,
      ::std::unique_ptr<::SubChunkStorage<::Biome>> newStorage,
      ::Bedrock::Threading::UniqueLock<::std::shared_mutex> const &lock);

  // (内部) 从3D数据设置2D生物群系。
  MCAPI void _set2DBiomesFrom3D(::IDataInput &stream);

  // (内部) 从2D数据设置所有生物群系。
  MCAPI void
  _setAllBiomesFrom2D(::std::array<::BiomeChunkData, 256> &legacyBiomes);

  // (内部) 设置指定位置的生物群系。
  MCAPI void _setBiome(::Biome const &biome, ::ChunkBlockPos const &pos,
                       bool fillYDimension);

  // (内部) 设置指定索引的生物群系。
  MCAPI void _setBiome(
      ::Biome const &biome, ushort biomeIndex, ushort storageIndex,
      ::Bedrock::Threading::UniqueLock<::std::shared_mutex> const &writeLock);

  // (内部) 更新雪和冰的生成。
  MCAPI void _tickSnowAndIce(::BlockSource &region, ::Random &random,
                             int xOffset, int zOffset, ::Weather &weather);

  // 添加一个实体到区块中。
  MCAPI void addEntity(::WeakEntityRef entityRef);

  // 添加一个硬编码的生成区域。
  MCAPI void addHardcodedSpawningArea(::BoundingBox const &spawnerAABB,
                                      ::HardcodedSpawnAreaType type);

  // 将一个子区块的方块实体添加到本区块。
  MCAPI void addSubChunkBlockEntitiesToLevelChunk(
      ::LevelChunkBlockActorStorage &blockActorMap);

  // 应用季节相关的后处理。
  MCAPI bool applySeasonsPostProcess(::BlockSource &region);

  // 检查季节后处理是否需要更新。
  MCAPI bool checkSeasonsPostProcessDirty();

  // 客户端请求为子区块生成光照。
  MCAPI void clientSubChunkRequestGenerateLightingForSubChunk(
      ::ChunkViewSource &neighborhood, short absoluteIndex);

  // 从流中反序列化2D地图数据。
  MCAPI void deserialize2DMaps(::IDataInput &stream);

  // 从流中反序列化旧版的2D地图数据。
  MCAPI void deserialize2DMapsLegacy(::IDataInput &stream);

  // 从流中反序列化生物群系状态。
  MCAPI void deserializeBiomeStates(::IDataInput &stream);

  // 从流中反序列化方块实体。
  MCAPI void deserializeBlockEntities(::IDataInput &stream);

  // 从流中反序列化转换数据。
  MCAPI void deserializeConversionData(::IDataInput &stream);

  // 从流中反序列化最终完成状态。
  MCAPI void deserializeFinalization(::IDataInput &stream);

  // 反序列化键值对数据。
  MCAPI bool deserializeKey(::std::string_view key, ::std::string_view value);

  // 从流中反序列化加载的版本信息。
  MCAPI void deserializeLoadedVersion(::IDataInput &stream);

  // 从流中反序列化元数据哈希值。
  MCAPI void deserializeMetaDataHash(::IDataInput &stream);

  // 从流中反序列化一个子区块。
  MCAPI void deserializeSubChunk(
      uchar idx, ::IDataInput &stream, ::std::optional<schar> absoluteIndex,
      ::std::optional<::DeserializationChanges *> deserializationChanges);

  // 用指定的生物群系数据填充区块。
  MCAPI void fillBiomes(::BiomeChunkData const &biomeChunkData);

  // 完成反序列化过程。
  MCAPI void finalizeDeserialization();

  // 完成后处理。
  MCAPI void finalizePostProcessing();

  // 完成子区块的反序列化。
  MCAPI void
  finalizeSubChunkDeserialization(::LevelChunkBlockActorStorage &blockActorMap,
                                  ::buffer_span_mut<::SubChunk> subchunks);

  // 寻找暴露在外的避雷针。
  MCAPI ::std::optional<::BlockPos>
  findExposedLightningRod(::BlockPos const &pos, ::BlockSource &region);

  // 寻找闪电的目标位置。
  MCAPI ::Vec3 findLightningTarget(::BlockPos const &pos,
                                   ::BlockSource &region);

  // 生成初次光照。
  MCAPI bool generateOriginalLighting(::ChunkViewSource &neighborhood,
                                      bool enforceBorderCheck);

  // 获取指定位置上方第一个固体方块的高度。
  MCAPI ::ChunkLocalHeight
  getAboveTopSolidBlock(::ChunkBlockPos const &start,
                        bool iteratePastInitialBlocking, bool includeWater,
                        bool includeLeaves) const;

  // 获取指定类型和范围内的实体。
  MCAPI void getActors(::ActorDefinitionIdentifier const &actorDefinitionId,
                       ::AABB const &bb,
                       ::std::vector<::Actor *> &actors) const;

  // 获取指定位置的生物群系。
  MCAPI ::Biome const &getBiome(::ChunkBlockPos const &pos) const;

  // 获取指定位置的方块。
  MCAPI ::Block const &getBlock(::ChunkBlockPos const &pos) const;

  // 获取指定位置的亮度。
  MCAPI ::BrightnessPair getBrightness(::ChunkBlockPos const &pos) const;

  // 获取缓存的温度噪声值。
  MCAPI schar getCachedTemperatureNoise(::ChunkBlockPos const &pos);

  // 获取指定范围内的实体，可忽略特定实体。
  MCAPI void
  getEntities(::gsl::span<::gsl::not_null<::Actor const *>> ignoredEntities,
              ::AABB const &bb, ::std::vector<::Actor *> &entities,
              bool useHitbox) const;

  // 获取指定类型和范围内的实体。
  MCAPI void getEntities(::ActorType type, ::AABB const &bb,
                         ::std::vector<::Actor *> &es,
                         bool ignoreTargetType) const;

  // 获取指定位置的附加方块。
  MCAPI ::Block const &getExtraBlock(::ChunkBlockPos const &localPos) const;

  // 获取最高的非空气子区块的索引。
  MCAPI short getHighestNonAirSubChunkIndex() const;

  // 获取元数据的副本。
  MCAPI ::std::shared_ptr<::LevelChunkMetaData> getMetaDataCopy() const;

  // 获取顶部会下雨的方块位置。
  MCAPI ::BlockPos const getTopRainBlockPos(::ChunkBlockPos const &pos);

  // 检查区块内是否存在指定的实体。
  MCAPI bool hasEntity(::WeakEntityRef entityRef);

  // 检查是否有待修剪的子区块。
  MCAPI bool hasSubChunksToPrune() const;

  // 检查非实体数据是否为脏数据（需要保存）。
  MCAPI bool isNonActorDataDirty() const;

  // 反序列化旧版的方块附加数据。
  MCAPI void legacyDeserializeBlockExtraData(::IDataInput &stream);

  // 反序列化旧版的地形数据。
  MCAPI void legacyDeserializeTerrain(::IDataInput &stream);

  // 标记此区块在本帧需要进行计划更新。
  MCAPI void markForTickingThisFrame(::LevelChunkTicking::Registry &registry);

  // 移动赋值运算符。
  MCAPI ::LevelChunk &operator=(::LevelChunk &&otherChunk);

  // 放置方块时的回调。
  MCAPI void placeCallbacks(::ChunkBlockPos const &pos, ::Block const &old,
                            ::Block const &current,
                            ::BlockSource *currentSource,
                            ::std::shared_ptr<::BlockActor> blockEntity);

  // 为子区块数据包填充高度图数据。
  MCAPI void populateHeightMapDataForSubChunkPacket(
      short subChunkAbsoluteIndex,
      ::SubChunkPacket::SubChunkPacketData &subChunkPacketData) const;

  // 重新计算高度图。
  MCAPI void recomputeHeightMap(bool resetLighting);

  // 移除一个方块实体。
  MCAPI ::std::shared_ptr<::BlockActor>
  removeBlockEntity(::BlockPos const &blockPos);

  // 从区块中移除一个实体。
  MCAPI bool removeEntityFromChunk(::WeakEntityRef entityRef);

  // 从世界中移除一个实体。
  MCAPI bool removeEntityFromWorld(::WeakEntityRef entityRef);

  // 移除一个硬编码的生成区域。
  MCAPI void removeHardcodedSpawningArea(::HardcodedSpawnAreaType type);

  // 序列化生物群系数据到流。
  MCAPI void serializeBiomes(::IDataOutput &stream) const;

  // 序列化方块实体到流。
  MCAPI void serializeBlockEntities(::IDataOutput &stream,
                                    ::SaveContext const &saveContext) const;

  // 为单个子区块序列化方块实体。
  MCAPI void
  serializeBlockEntitiesForSubChunk(::IDataOutput &stream,
                                    ::SubChunkPos const &subChunkPos,
                                    ::SaveContext const &saveContext) const;

  // 序列化边界方块到流。
  MCAPI bool serializeBorderBlocks(::IDataOutput &stream) const;

  // 序列化实体。
  MCAPI void serializeEntities(
      ::std::string &buffer, bool markProcessedOnChunkDisard,
      ::std::function<void(::std::string const &)> addLiveActorCallback,
      ::std::function<void(::std::string const &)> addActorKeyCallback,
      ::std::function<void(::std::string const &)> addSerializedActor) const;

  // 序列化已移除的实体。
  MCAPI void serializeEntityRemovals(
      ::std::function<void(::std::string const &)> callback);

  // 设置所有旧版的方块ID和数据。
  MCAPI void setAllLegacyBlockIDAndData(::buffer_span<::BlockID> ids,
                                        ::buffer_span<::NibblePair> data);

  // 从体积数据设置生物群系。
  MCAPI void setBiomeFromVolume(
      ::ClientBlockPipeline::VolumeOf<::Biome const *> const &volume,
      uint yOffset);

  // 设置一个方块。
  MCAPI ::Block const &setBlock(::ChunkBlockPos const &pos,
                                ::Block const &block,
                                ::BlockSource *issuingSource,
                                ::std::shared_ptr<::BlockActor> blockEntity);

  // 设置一个方块体积。
  MCAPI void setBlockVolume(::BlockVolume const &box, uint yOffset);

  // 设置边界方块。
  MCAPI void setBorder(::ChunkBlockPos const &pos, bool val);

  // 设置附加方块。
  MCAPI ::Block const &setExtraBlock(::ChunkBlockPos const &localPos,
                                     ::Block const &block,
                                     ::BlockSource *issuingSource);

  // 设置元数据。
  MCAPI void setMetaData(::std::shared_ptr<::LevelChunkMetaData> metaData);

  // 设置待处理的实体数据。
  MCAPI void setPendingEntities(::std::string entitiesData);

  // 设置世界生成前的高度图。
  MCAPI void
  setPreWorldGenHeightMap(::std::unique_ptr<::std::vector<short>> heightmap);

  // 标记为已保存。
  MCAPI void setSaved();

  // 标记为未保存。
  MCAPI void setUnsaved();

  // 设置红石电路。
  MCAPI void setupRedstoneCircuit(::BlockSource &resource);

  // 更新方块实体。
  MCAPI void tickBlockEntities(::BlockSource &tickRegion);

  // 更新方块。
  MCAPI void tickBlocks(::BlockSource &region);

  // 更新区块的核心实现。
  MCAPI void tickImpl(::BlockSource &tickRegion, ::Tick const &tick,
                      ::std::function<void()> spawnerCallback);

  // 尝试生成骷髅陷阱。
  MCAPI void trySpawnSkeletonTrap(::BlockSource &region, ::BlockPos const &pos);

  // 验证并修复生物群系状态。
  MCAPI void validateAndFixBiomeStates();

  // 析构函数。
  MCAPI ~LevelChunk();
  // NOLINTEND

public:
  // static functions
  // 静态函数
  // NOLINTBEGIN
  // (静态) 反序列化2D生物群系并进行数据升级。
  MCAPI static ::std::array<::BiomeChunkData, 256>
  _deserialize2DBiomesWithDataUpgrade(
      ::IDataInput &stream, ::std::optional<::LevelChunkFormat> const &lcFormat,
      bool isClientSide);

  // (静态) 反序列化3D生物群系。
  MCAPI static ::std::pair<
      ushort, ::std::vector<::std::unique_ptr<::SubChunkStorage<::Biome>>>>
  deserialize3DBiomes(::IDataInput &stream,
                      ::BiomeRegistry const &biomeRegistry,
                      ushort dimensionHeightInSubchunks,
                      ::Biome const *defaultBiome, bool fromNetwork);

  // (静态) 序列化实体列表。
  MCAPI static void serializeEntities(
      ::std::vector<::WeakEntityRef> const &entities,
      ::std::string const &serializedEntitiesBuffer,
      ::std::string const &failedSerializedEntitiesBuffer,
      ::std::string &buffer, bool markProcessedOnChunkDisard,
      ::std::function<void(::std::string const &)> addLiveActorCallback,
      ::std::function<void(::std::string const &)> addActorKeyCallback,
      ::std::function<void(::std::string const &)> addSerializedActor);
  // NOLINTEND
};

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::Dimension&                                dimension,
        ::ChunkPos const&                           cp,
        bool                                        readOnly,
        ::SubChunkInitMode                          initBlocks,
        bool                                        initializeMetaData,
        ::LevelChunkBlockActorStorage::TrackingMode blockActorTrackingMode
    );
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN
    MCAPI void $dtor();
    // NOLINTEND
};
