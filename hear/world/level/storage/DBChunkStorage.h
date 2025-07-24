#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/resources/BaseGameVersion.h"
#include "mc/world/level/ChunkPos.h"
#include "mc/world/level/chunk/ChunkSource.h"
#include "mc/world/level/chunk/LevelChunkFormat.h"
#include "mc/world/level/storage/ConsoleChunkBlender.h"
#include "mc/world/level/storage/db_helpers/Category.h"

// auto generated forward declare list
// clang-format off
class BaseGameVersion;
class BlendingData;
class BlendingDataProvider;
class ChunkKey;
class ChunkViewSource;
class DBChunkStorageKey;
class DBStorage;
class Experiments;
class IDataInput;
class LevelChunk;
class LevelChunkMetaDataDictionary;
class LevelStorageWriteBatch;
class Scheduler;
class TaskGroup;
struct ActorUnloadedChunkTransferEntry;
struct LevelChunkFinalDeleter;
struct PersistentBlendData;
// clang-format on

class DBChunkStorage : public ::ChunkSource {
public:
  // DBChunkStorage 内部类型声明
  // clang-format off
    struct PreCavesAndCliffsMetaData;
  // clang-format on

  // DBChunkStorage 内部类型定义
  struct PreCavesAndCliffsMetaData {
  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // “洞穴与山崖”更新前的元数据，用于兼容旧版世界。
    ::ll::UntypedStorage<1, 1> mUnk5cb409;
    ::ll::UntypedStorage<4, 4> mUnk75181d;
    // NOLINTEND

  public:
    // prevent constructor by default
    PreCavesAndCliffsMetaData &operator=(PreCavesAndCliffsMetaData const &);
    PreCavesAndCliffsMetaData(PreCavesAndCliffsMetaData const &);
    PreCavesAndCliffsMetaData();
  };

  // 区块缓存状态枚举
  enum class ChunkCacheStatus : int {
    Missing = 0,   // 缺失
    Available = 1, // 可用
    DontCache = 2, // 不缓存
  };

public:
  // member variables
  // 成员变量
  // NOLINTBEGIN
  // 用于缓存区块是否存在于数据库中，避免频繁的磁盘查询。
  ::ll::TypedStorage<8, 64,
                     ::std::unordered_map<::DBChunkStorageKey,
                                          ::DBChunkStorage::ChunkCacheStatus>>
      mHasChunkCache;
  // 上述缓存的共享互斥锁。
  ::ll::TypedStorage<8, 8, ::std::shared_mutex> mHasChunkCacheSharedMutex;
  // 区块地形混合数据的缓存，用于平滑新旧地形的过渡。
  ::ll::TypedStorage<
      8, 64,
      ::std::unordered_map<
          ::ChunkPos, ::std::pair<bool, ::std::shared_ptr<::BlendingData>>>>
      mChunkBlendingDataCache;
  // 地形混合数据缓存的共享互斥锁。
  ::ll::TypedStorage<8, 8, ::std::shared_mutex> mChunkBlendingDataSharedMutex;
  // 衰减器共享互斥锁，用途未知，可能与地形生成有关。
  ::ll::TypedStorage<8, 8, ::std::shared_mutex> mAttenuatorSharedMutex;
  // 对底层 DBStorage 的引用，用于实际的数据库读写。
  ::ll::TypedStorage<8, 8, ::DBStorage &> mStorage;
  // LevelDB 写入批处理对象的缓冲池，用于复用以提高性能。
  ::ll::TypedStorage<8, 24,
                     ::std::vector<::std::shared_ptr<::LevelStorageWriteBatch>>>
      mBufferPool;
  // 待丢弃区块的批处理列表。
  ::ll::TypedStorage<
      8, 24,
      ::std::vector<::std::unique_ptr<::LevelChunk, ::LevelChunkFinalDeleter>>>
      mDiscardBatch;
  // 正在被保存的活跃区块集合，用于防止并发问题。
  ::ll::TypedStorage<8, 64, ::std::unordered_set<::ChunkPos>>
      mLiveChunksBeingSaved;
  // 在活跃区块保存期间被丢弃的区块，用于处理边缘情况。
  ::ll::TypedStorage<
      8, 64,
      ::std::unordered_map<
          ::ChunkPos,
          ::std::unique_ptr<::LevelChunk, ::LevelChunkFinalDeleter>>>
      mDiscardedWhileLiveSaved;
  // 是否处于批处理模式。
  ::ll::TypedStorage<1, 1, bool> mBatch;
  // IO 任务组。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::TaskGroup>> mIOTaskGroup;
  // 当前关卡的游戏版本。
  ::ll::TypedStorage<8, 32, ::BaseGameVersion> mCurrentLevelVersion;
  // NOLINTEND

public:
  // prevent constructor by default
  DBChunkStorage &operator=(DBChunkStorage const &);
  DBChunkStorage(DBChunkStorage const &);
  DBChunkStorage();

public:
  // virtual functions
  // 虚函数
  // NOLINTBEGIN
  // vIndex: 0
  virtual ~DBChunkStorage() /*override*/; // 析构函数

  // vIndex: 1
  virtual void shutdown() /*override*/; // 关闭存储，刷新所有待处理的写入。

  // vIndex: 2
  virtual bool isShutdownDone() /*override*/; // 检查关闭过程是否完成。

  // vIndex: 11
  virtual void loadChunk(::LevelChunk &lc,
                         bool forceImmediateReplacementDataLoad) /*override*/
      ; // 从数据库加载区块数据。

  // vIndex: 5
  virtual bool
  isChunkKnown(::ChunkPos const
                   &chunkPos) /*override*/; // 检查数据库中是否存在指定的区块。

  // vIndex: 6
  virtual bool
  isChunkSaved(::ChunkPos const &
                   chunkPos) /*override*/; // 检查指定的区块是否已保存到数据库。

  // vIndex: 9
  virtual bool postProcess(
      ::ChunkViewSource &neighborhood) /*override*/; // 对区块进行后处理。

  // vIndex: 10
  virtual void checkAndReplaceChunk(
      ::ChunkViewSource &neighborhood,
      ::LevelChunk &lc) /*override*/; // 检查并替换区块数据，用于版本升级。

  // vIndex: 14
  virtual bool saveLiveChunk(
      ::LevelChunk &lc) /*override*/; // 将一个活跃的区块保存到数据库。

  // vIndex: 15
  virtual void writeEntityChunkTransfer(
      ::LevelChunk &lc) /*override*/; // 写入实体在区块间转移的数据。

  // vIndex: 16
  virtual void writeEntityChunkTransfersToUnloadedChunk(
      ::ChunkKey const &chunkKey,
      ::std::vector<::ActorUnloadedChunkTransferEntry> const
          &transfers) /*override*/; // 将实体转移数据写入到未加载的区块。

  // vIndex: 20
  virtual void acquireDiscarded(
      ::std::unique_ptr<::LevelChunk, ::LevelChunkFinalDeleter>
          ptr) /*override*/; // 接管一个被丢弃的区块，准备进行清理。

  // vIndex: 18
  virtual void hintDiscardBatchBegin() /*override*/; // 提示开始批量丢弃区块。

  // vIndex: 19
  virtual void hintDiscardBatchEnd() /*override*/; // 提示批量丢弃区块结束。

  // vIndex: 22
  virtual void flushPendingDiscardedChunkWrites() /*override*/
      ; // 刷新待处理的已丢弃区块的写入操作。

  // vIndex: 23
  virtual void flushThreadBatch() /*override*/; // 刷新当前线程的批处理写入。

  // vIndex: 29
  virtual ::std::unique_ptr<::BlendingDataProvider>
  tryGetBlendingDataProvider() /*override*/; // 尝试获取地形混合数据提供者。

  // vIndex: 30
  virtual ::std::shared_ptr<::LevelChunkMetaDataDictionary>
  loadLevelChunkMetaDataDictionary() /*override*/; // 加载关卡区块元数据字典。

  // vIndex: 17
  virtual void deserializeActorStorageToLevelChunk(
      ::LevelChunk
          &levelChunk) /*override*/; // 将实体存储数据反序列化到区块中。

  // vIndex: 33
  virtual bool chunkPosNeedsBlending(
      ::ChunkPos const
          &cp) /*override*/; // 检查指定位置的区块是否需要地形混合。
                             // NOLINTEND

public:
  // member functions
  // 成员函数
  // NOLINTBEGIN
  MCAPI DBChunkStorage(::std::unique_ptr<::ChunkSource> parent,
                       ::DBStorage &storage, ::Scheduler &scheduler,
                       ::Experiments const &experiments);

  // (内部) 将删除操作添加到批处理中。
  MCAPI void _batchDelete(::LevelStorageWriteBatch &batch,
                          ::std::string const &key,
                          ::DBHelpers::Category category,
                          ::std::string_view reason);

  // (内部) 将放置（写入）操作添加到批处理中。
  MCAPI void _batchPut(::LevelStorageWriteBatch &batch,
                       ::std::string const &key, ::std::string &&buffer,
                       ::DBHelpers::Category category,
                       ::std::string_view reason);

  // (内部) 缓存无缝区块地形混合数据。
  MCAPI ::std::pair<bool, ::std::shared_ptr<::BlendingData>>
  _cacheSeamlessChunkBlendingData(
      ::ChunkPos chunkPos, bool isCompleted,
      ::std::shared_ptr<::BlendingData> blendingData);

  // (内部) 检查子区块是否使用绝对索引（用于版本兼容性）。
  MCAPI bool _checkSubChunksUseAbsoluteIndices(::DBChunkStorageKey key,
                                               ::LevelChunk const &lc,
                                               bool &flatworldsNeedFixup) const;

  // (内部) 反序列化独立存储的实体数据。
  MCAPI void _deserializeIndependentActorStorage(
      ::LevelChunk &lc, ::std::string const &storageKeyDigestBuffer);

  // (内部) 获取关卡区块的格式。
  MCAPI ::std::optional<::LevelChunkFormat>
  _getLevelChunkFormat(::std::string_view prefix, ::std::string &buffer);

  // (内部) 检查是否存在指定的区块（使用缓存）。
  MCAPI bool _hasChunk(::DBChunkStorageKey const &key);

  // (内部) 检查是否存在指定的区块（不使用缓存）。
  MCAPI bool _hasChunkUncached(::DBChunkStorageKey const &key);

  // (内部) 检查一个关卡区块是否可以用于地形混合。
  MCAPI ::std::pair<bool, ::std::unique_ptr<::PersistentBlendData>>
  _levelChunkCanBeUsedForBlending(::DBChunkStorageKey const &lcKey);

  // (内部) 从数据库加载并进行地形混合。
  MCAPI void _loadAndBlendFromDB(::LevelChunk &lc, ::LevelChunk &generatedChunk,
                                 ::ChunkViewSource &neighborhood);

  // (内部) 从数据库加载区块。
  MCAPI bool _loadChunkFromDB(::LevelChunk &lc, ::LevelChunk &generatedChunk,
                              ::ChunkViewSource &neighborhood);

  // (内部) 保存地形混合数据。
  MCAPI void _saveBlendData(::LevelStorageWriteBatch &batch,
                            ::std::string_view prefix, ::std::string &buffer,
                            ::PersistentBlendData data) const;

  // (内部) 序列化整个区块。
  MCAPI void _serializeChunk(::LevelChunk &lc, ::LevelStorageWriteBatch &batch,
                             bool markEntitiesProcesedOnChunkDiscard);

  // (内部) 序列化区块内的实体。
  MCAPI void _serializeEntities(::LevelChunk &lc,
                                ::LevelStorageWriteBatch &batch,
                                ::std::string &buffer,
                                bool markEntitiesProcesedOnChunkDiscard);

  // (内部) 尝试获取一个区块的地形混合数据。
  MCAPI ::std::pair<bool, ::std::shared_ptr<::BlendingData>>
  _tryGetBlendingDataForChunk(::ChunkPos const &checkPosition);

  // (内部) 升级旧版的实体存储格式。
  MCAPI ::std::string _upgradeActorStorage(::ChunkKey chunkKey,
                                           ::std::string_view &legacyActorData);

  // (内部) 写入实体摘要信息。
  MCAPI void _writeActorDigest(::LevelStorageWriteBatch &batch,
                               ::ChunkKey const &chunkKey,
                               ::std::string const &digestBuffer);

  // (内部) 写入待丢弃区块的批处理。
  MCAPI void _writeDiscardChunksBatch();
  // NOLINTEND

public:
  // static functions
  // 静态函数
  // NOLINTBEGIN
  // (静态) 从流中反序列化区块的实体存储键。
  MCAPI static ::std::vector<::std::string>
  _deserializeChunkActorStorageKeys(::IDataInput &digestStream);

  // (静态) 获取区块的地形混合器模式。
  MCAPI static ::ConsoleChunkBlender::BlenderMode
  _getBlenderMode(::LevelChunk const &lc, ::Experiments const &experiments);

  // (静态) 将分散的实体存储数据反序列化到一个字符串中。
  MCAPI static ::std::string deserializeActorStorageToString(
      bool hasActorDigestVersionTag,
      ::std::string const &storageKeyDigestBuffer,
      ::std::function<bool(::std::string_view, ::std::string &)>
          loadDataCallback);
  // NOLINTEND

public:
  // static variables
  // 静态变量
  // NOLINTBEGIN
  // 获取当前线程的批处理写入对象（线程局部存储）。
  MCAPI static ::LevelStorageWriteBatch &threadBatch();

  // 获取当前线程的缓冲区（线程局部存储）。
  MCAPI static ::std::string &threadBuffer();
  // NOLINTEND
};

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::std::unique_ptr<::ChunkSource> parent,
        ::DBStorage&                     storage,
        ::Scheduler&                     scheduler,
        ::Experiments const&             experiments
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
    MCAPI void $shutdown();

    MCAPI bool $isShutdownDone();

    MCAPI void $loadChunk(::LevelChunk& lc, bool forceImmediateReplacementDataLoad);

    MCFOLD bool $isChunkKnown(::ChunkPos const& chunkPos);

    MCFOLD bool $isChunkSaved(::ChunkPos const& chunkPos);

    MCAPI bool $postProcess(::ChunkViewSource& neighborhood);

    MCAPI void $checkAndReplaceChunk(::ChunkViewSource& neighborhood, ::LevelChunk& lc);

    MCAPI bool $saveLiveChunk(::LevelChunk& lc);

    MCAPI void $writeEntityChunkTransfer(::LevelChunk& lc);

    MCAPI void $writeEntityChunkTransfersToUnloadedChunk(
        ::ChunkKey const&                                       chunkKey,
        ::std::vector<::ActorUnloadedChunkTransferEntry> const& transfers
    );

    MCAPI void $acquireDiscarded(::std::unique_ptr<::LevelChunk, ::LevelChunkFinalDeleter> ptr);

    MCAPI void $hintDiscardBatchBegin();

    MCAPI void $hintDiscardBatchEnd();

    MCAPI void $flushPendingDiscardedChunkWrites();

    MCAPI void $flushThreadBatch();

    MCAPI ::std::unique_ptr<::BlendingDataProvider> $tryGetBlendingDataProvider();

    MCAPI ::std::shared_ptr<::LevelChunkMetaDataDictionary> $loadLevelChunkMetaDataDictionary();

    MCAPI void $deserializeActorStorageToLevelChunk(::LevelChunk& levelChunk);

    MCAPI bool $chunkPosNeedsBlending(::ChunkPos const& cp);
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
