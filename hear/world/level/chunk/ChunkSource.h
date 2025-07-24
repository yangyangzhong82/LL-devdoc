#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/utility/EnableNonOwnerReferences.h"
#include "mc/deps/core/utility/buffer_span.h"
#include "mc/deps/core/utility/pub_sub/Subscription.h"
#include "mc/util/GridArea.h"
#include "mc/world/level/chunk/ChunkSourceViewGenerateMode.h"
#include "mc/world/level/chunk/ChunkState.h"
#include "mc/world/level/chunk/LevelChunkGridAreaElement.h"

// auto generated forward declare list
// clang-format off
class BlendingDataProvider;
class BlockSource;
class BoundingBox;
class ChunkKey;
class ChunkPos;
class ChunkViewSource;
class Dimension;
class ILevelStorageManagerConnector;
class Level;
class LevelChunk;
class LevelChunkBuilderData;
class LevelChunkMetaDataDictionary;
class LevelStorage;
class Random;
struct ActorUnloadedChunkTransferEntry;
struct LevelChunkFinalDeleter;
// clang-format on

class ChunkSource : public ::Bedrock::EnableNonOwnerReferences {
public:
  // ChunkSource 内部类型定义
  enum class LoadMode : int {
    None = 0,     // 无加载模式
    Deferred = 1, // 延迟加载
  };

public:
  // member variables
  // 成员变量
  // NOLINTBEGIN
  // 区块的边长（通常为16）。
  ::ll::TypedStorage<4, 4, int> mChunkSide;
  // 指向所属 Level (世界) 的指针。
  ::ll::TypedStorage<8, 8, ::Level *> mLevel;
  // 指向所属 Dimension (维度) 的指针。
  ::ll::TypedStorage<8, 8, ::Dimension *> mDimension;
  // 指向父 ChunkSource 的指针，用于链式结构（例如，缓存层）。
  ::ll::TypedStorage<8, 8, ::ChunkSource *> mParent;
  // 独占所有权的父 ChunkSource。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ChunkSource>> mOwnedParent;
  // 用于构建区块的数据。
  ::ll::TypedStorage<8, 8, ::LevelChunkBuilderData *> mLevelChunkBuilderData;
  // 标记 ChunkSource 是否正在关闭的原子布尔值。
  ::ll::TypedStorage<1, 1, ::std::atomic<bool>> mShuttingDown;
  // 监听保存事件的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnSaveSubscription;
  // 监听应用暂停时关卡存储事件的订阅。
  ::ll::TypedStorage<8, 16, ::Bedrock::PubSub::Subscription>
      mOnLevelStorageAppSuspendSubscription;
  // NOLINTEND

public:
  // prevent constructor by default
  ChunkSource();

public:
  // virtual functions
  // 虚函数
  // NOLINTBEGIN
  // vIndex: 0
  virtual ~ChunkSource() /*override*/; // 析构函数

  // vIndex: 1
  virtual void shutdown(); // 关闭 ChunkSource，进行清理工作。

  // vIndex: 2
  virtual bool isShutdownDone(); // 检查关闭流程是否已完成。

  // vIndex: 3
  virtual ::std::shared_ptr<::LevelChunk> getExistingChunk(
      ::ChunkPos const
          &); // 获取一个已存在（已加载）的区块，如果不存在则返回 nullptr。

  // vIndex: 4
  virtual ::std::shared_ptr<::LevelChunk>
  getRandomChunk(::Random &random); // 随机获取一个已加载的区块。

  // vIndex: 5
  virtual bool
  isChunkKnown(::ChunkPos const
                   &chunkPos); // 检查一个区块是否已知（存在于缓存或存储中）。

  // vIndex: 6
  virtual bool
  isChunkSaved(::ChunkPos const &chunkPos); // 检查一个区块是否已保存到磁盘。

  // vIndex: 7
  virtual ::std::shared_ptr<::LevelChunk>
  createNewChunk(::ChunkPos const &cp, ::ChunkSource::LoadMode lm,
                 bool readOnly); // 创建一个全新的区块。

  // vIndex: 8
  virtual ::std::shared_ptr<::LevelChunk>
  getOrLoadChunk(::ChunkPos const &cp, ::ChunkSource::LoadMode lm,
                 bool readOnly); // 获取一个区块，如果不存在则从存储中加载。

  // vIndex: 9
  virtual bool postProcess(
      ::ChunkViewSource
          &neighborhood); // 对区块及其邻域进行后处理（如生成特征、植被等）。

  // vIndex: 10
  virtual void
  checkAndReplaceChunk(::ChunkViewSource &neighborhood,
                       ::LevelChunk &lc); // 检查并替换区块，可能用于数据升级。

  // vIndex: 11
  virtual void
  loadChunk(::LevelChunk &lc,
            bool forceImmediateReplacementDataLoad); // 加载区块数据到
                                                     // LevelChunk 对象中。

  // vIndex: 13
  virtual void
  postProcessMobsAt(::BlockSource &region, int chunkWestBlock,
                    int chunkNorthBlock,
                    ::Random &random); // 在指定区域进行生物后处理（生成生物）。

  // vIndex: 12
  virtual void postProcessMobsAt(
      ::BlockSource &region,
      ::BoundingBox const &chunkBB) const; // 在指定包围盒内进行生物后处理。

  // vIndex: 14
  virtual bool
  saveLiveChunk(::LevelChunk &lc); // 保存一个活跃的（已加载在内存中的）区块。

  // vIndex: 15
  virtual void writeEntityChunkTransfer(
      ::LevelChunk &
          levelChunk); // 将实体数据写入区块转移存储，用于实体移动到未加载区块时。

  // vIndex: 16
  virtual void writeEntityChunkTransfersToUnloadedChunk(
      ::ChunkKey const &chunkKey,
      ::std::vector<::ActorUnloadedChunkTransferEntry> const
          &transfers); // 将实体转移数据写入到未加载的区块。

  // vIndex: 17
  virtual void deserializeActorStorageToLevelChunk(
      ::LevelChunk &levelChunk); // 将实体存储数据反序列化到 LevelChunk 中。

  // vIndex: 18
  virtual void hintDiscardBatchBegin(); // 提示将要开始批量丢弃区块。

  // vIndex: 19
  virtual void hintDiscardBatchEnd(); // 提示批量丢弃区块结束。

  // vIndex: 20
  virtual void
  acquireDiscarded(::std::unique_ptr<::LevelChunk, ::LevelChunkFinalDeleter>
                       ptr); // 接管一个已丢弃的区块，用于内存管理。

  // vIndex: 21
  virtual void compact(); // 进行内存紧缩，释放不必要的资源。

  // vIndex: 22
  virtual void
  flushPendingDiscardedChunkWrites(); // 刷新待处理的已丢弃区块的写入操作。

  // vIndex: 23
  virtual void flushThreadBatch(); // 刷新线程的批处理操作。

  // vIndex: 24
  virtual bool isWithinWorldLimit(
      ::ChunkPos const &cp) const; // 检查区块位置是否在世界边界内。

  // vIndex: 25
  virtual ::std::unordered_map<::ChunkPos,
                               ::std::weak_ptr<::LevelChunk>> const *
  getChunkMap(); // 获取内部的区块映射表。

  // vIndex: 26
  virtual ::std::unordered_map<::ChunkPos,
                               ::std::weak_ptr<::LevelChunk>> const &
  getStorage() const; // 获取内部的区块存储（映射表）。

  // vIndex: 27
  virtual void clearDeletedEntities(); // 清理已标记为删除的实体。

  // vIndex: 28
  virtual bool canCreateViews()
      const; // 检查此 ChunkSource 是否可以创建区块视图（ChunkViewSource）。

  // vIndex: 29
  virtual ::std::unique_ptr<::BlendingDataProvider>
  tryGetBlendingDataProvider(); // 尝试获取用于平滑新旧地形的混合数据提供者。

  // vIndex: 30
  virtual ::std::shared_ptr<::LevelChunkMetaDataDictionary>
  loadLevelChunkMetaDataDictionary(); // 加载区块元数据字典。

  // vIndex: 31
  virtual void
      setLevelChunk(::std::shared_ptr<
                    ::LevelChunk>); // 将一个区块设置（添加/更新）到内部存储中。

  // vIndex: 32
  virtual bool
  canLaunchTasks() const; // 检查是否可以启动异步任务（如区块生成）。

  // vIndex: 33
  virtual bool chunkPosNeedsBlending(
      ::ChunkPos const &cp); // 检查指定位置的区块是否需要进行混合处理。
                             // NOLINTEND

public:
  // member functions
  // 成员函数
  // NOLINTBEGIN
  // 构造函数，接收一个父 ChunkSource 用于构建链式结构。
  MCAPI explicit ChunkSource(::std::unique_ptr<::ChunkSource> parent);

  // (内部) 检查并为指定的区块分发一个任务（如生成、光照等）。
  MCAPI bool _checkAndDispatchTaskForLevelChunk(
      ::std::pair<::ChunkPos, ::ChunkState> const &chunkPosAndExpectedState,
      bool areInTask);

  // (内部) 检查区块是否需要替换数据的任务。
  MCAPI void _checkForReplacementDataTask(::LevelChunk &lc,
                                          ::ChunkViewSource &chunks);

  // (内部) 当一个区块加载后，检查是否可以解除其他依赖于它的区块的阻塞状态。
  MCAPI void _checkForUnblockingChunks(::LevelChunk const &lc);

  // (内部) 检查区块是否可以进入下一个生成阶段。
  MCAPI void _checkLevelChunkForNextStage(
      ::LevelChunk const &lc,
      ::LevelChunkGridAreaElement<::std::weak_ptr<::LevelChunk>> &grid,
      ::ChunkState stateToCheck);

  // (内部) 检查区块是否可以进行后处理。
  MCAPI void _checkLevelChunkForPostProcessing(
      ::LevelChunk const &lc,
      ::LevelChunkGridAreaElement<::std::weak_ptr<::LevelChunk>> &grid);

  // (内部) 检查一个区块是否处于指定的生成阶段。
  MCAPI bool _chunkAtStage(::std::weak_ptr<::LevelChunk> lcwp,
                           ::ChunkState stateToCheck);

  // (内部) 为加载的区块创建或替换其在网格区域图中的条目。
  MCAPI void _createOrReplaceGridAreaMap(::std::shared_ptr<::LevelChunk> lc,
                                         bool createNeighbourGridsIfMissing);

  // (内部) 释放指定位置的区块生成网格图。
  MCAPI void _freeChunkGenerationGridMap(::ChunkPos const &cp,
                                         bool isLevelChunkDeletion);

  // (内部) 启动一个区块生成任务。
  MCAPI void _launchGenerationTask(::std::shared_ptr<::LevelChunk> const &lc,
                                   bool areInTask);

  // (内部) 启动一个光照计算任务。
  MCAPI void
  _launchLightingTask(::std::shared_ptr<::LevelChunk> const &lc,
                      ::std::shared_ptr<::ChunkViewSource> const &chunks,
                      bool areInTask);

  // (内部) 启动一个后处理任务。
  MCAPI void
  _launchPostProcessingTask(::std::shared_ptr<::LevelChunk> const &lc,
                            ::std::shared_ptr<::ChunkViewSource> const &chunks,
                            bool areInTask);

  // (内部) 启动一个替换数据任务。
  MCAPI void
  _launchReplacementDataTask(::std::shared_ptr<::LevelChunk> const &lc,
                             ::std::shared_ptr<::ChunkViewSource> const &chunks,
                             bool areInTask);

  // (内部) 光照计算任务的实现。
  MCAPI void _lightingTask(::std::shared_ptr<::LevelChunk> const &lc,
                           ::ChunkViewSource &chunks);

  // (内部) 加载区块任务的实现。
  MCAPI void _loadChunkTask(::LevelChunk &lc);

  // (内部) 后处理任务的实现。
  MCAPI void _postProcessingTask(::LevelChunk &lc, ::ChunkViewSource &chunks);

  // (内部) 保存所有脏区块（已修改的区块）。
  MCAPI void _saveDirtyChunks(::LevelStorage &);

  // (内部) 生成指定数量的区块生成任务。
  MCAPI void _spawnChunkGenerationTasks(int numTasks, bool calledFromTask);

  // 检查并启动待处理的区块生成任务。
  MCAPI void checkAndLaunchChunkGenerationTasks(bool calledFromTask);

  // 创建一个空的区块视图，用于填充区块数据。
  MCAPI ::GridArea<::std::shared_ptr<::LevelChunk>> createEmptyView(
      ::ChunkSource::LoadMode lm, bool circle,
      ::std::function<void(::buffer_span_mut<::std::shared_ptr<::LevelChunk>>,
                           ::buffer_span<uint>)>
          add,
      ::ChunkSourceViewGenerateMode chunkViewGenerateMode,
      float const *serverBuildRatio);

  // 获取一个可用的（已加载在内存中的）区块。
  MCAPI ::std::shared_ptr<::LevelChunk> getAvailableChunk(::ChunkPos const &cp);

  // 使用 LevelStorageManagerConnector 进行初始化。
  MCAPI void initializeWithLevelStorageManagerConnector(
      ::ILevelStorageManagerConnector &levelStorageManagerConnector);

  // 根据服务器的构建比例和视野半径，判断服务器是否应该生成指定位置的区块。
  MCAPI bool shouldServerGeneratePos(::ChunkPos const &chunkPos,
                                     float serverBuildRatio, int viewRadius);
  // NOLINTEND

public:
  // static variables
  // 静态变量
  // NOLINTBEGIN
  // 一个全局性能标志，指示当前上下文是否为客户端。
  MCAPI static bool &gPerfIsClientSide();
  // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(::std::unique_ptr<::ChunkSource> parent);
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

    MCFOLD ::std::shared_ptr<::LevelChunk> $getExistingChunk(::ChunkPos const&);

    MCFOLD ::std::shared_ptr<::LevelChunk> $getRandomChunk(::Random& random);

    MCAPI bool $isChunkKnown(::ChunkPos const& chunkPos);

    MCAPI bool $isChunkSaved(::ChunkPos const& chunkPos);

    MCAPI ::std::shared_ptr<::LevelChunk>
    $createNewChunk(::ChunkPos const& cp, ::ChunkSource::LoadMode lm, bool readOnly);

    MCAPI ::std::shared_ptr<::LevelChunk>
    $getOrLoadChunk(::ChunkPos const& cp, ::ChunkSource::LoadMode lm, bool readOnly);

    MCFOLD bool $postProcess(::ChunkViewSource& neighborhood);

    MCFOLD void $checkAndReplaceChunk(::ChunkViewSource& neighborhood, ::LevelChunk& lc);

    MCAPI void $loadChunk(::LevelChunk& lc, bool forceImmediateReplacementDataLoad);

    MCAPI void $postProcessMobsAt(::BlockSource& region, int chunkWestBlock, int chunkNorthBlock, ::Random& random);

    MCAPI void $postProcessMobsAt(::BlockSource& region, ::BoundingBox const& chunkBB) const;

    MCAPI bool $saveLiveChunk(::LevelChunk& lc);

    MCAPI void $writeEntityChunkTransfer(::LevelChunk& levelChunk);

    MCAPI void $writeEntityChunkTransfersToUnloadedChunk(
        ::ChunkKey const&                                       chunkKey,
        ::std::vector<::ActorUnloadedChunkTransferEntry> const& transfers
    );

    MCAPI void $deserializeActorStorageToLevelChunk(::LevelChunk& levelChunk);

    MCAPI void $hintDiscardBatchBegin();

    MCAPI void $hintDiscardBatchEnd();

    MCAPI void $acquireDiscarded(::std::unique_ptr<::LevelChunk, ::LevelChunkFinalDeleter> ptr);

    MCAPI void $compact();

    MCAPI void $flushPendingDiscardedChunkWrites();

    MCAPI void $flushThreadBatch();

    MCFOLD bool $isWithinWorldLimit(::ChunkPos const& cp) const;

    MCFOLD ::std::unordered_map<::ChunkPos, ::std::weak_ptr<::LevelChunk>> const* $getChunkMap();

    MCAPI ::std::unordered_map<::ChunkPos, ::std::weak_ptr<::LevelChunk>> const& $getStorage() const;

    MCFOLD void $clearDeletedEntities();

    MCFOLD bool $canCreateViews() const;

    MCAPI ::std::unique_ptr<::BlendingDataProvider> $tryGetBlendingDataProvider();

    MCAPI ::std::shared_ptr<::LevelChunkMetaDataDictionary> $loadLevelChunkMetaDataDictionary();

    MCFOLD void $setLevelChunk(::std::shared_ptr<::LevelChunk>);

    MCAPI bool $canLaunchTasks() const;

    MCAPI bool $chunkPosNeedsBlending(::ChunkPos const& cp);
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
