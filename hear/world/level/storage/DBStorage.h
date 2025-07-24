#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/common/CompactionStatus.h"
#include "mc/deps/core/file/LevelStorageResult.h"
#include "mc/deps/core/file/PathBuffer.h"
#include "mc/deps/core/threading/IAsyncResult.h"
#include "mc/deps/core/utility/NonOwnerPointer.h"
#include "mc/platform/brstd/flat_set.h"
#include "mc/platform/brstd/move_only_function.h"
#include "mc/platform/threading/Mutex.h"
#include "mc/world/level/storage/DBStoragePerformanceTelemetry.h"
#include "mc/world/level/storage/LevelStorage.h"
#include "mc/world/level/storage/LevelStorageWriteBatch.h"
#include "mc/world/level/storage/StorageVersion.h"
#include "mc/world/level/storage/db_helpers/Category.h"

// auto generated forward declare list
// clang-format off
class ChunkSource;
class CompoundTag;
class ContentIdentity;
class DBChunkStorage;
class DBStorageEnvironmentChain;
class DBStorageFolderWatcher;
class LevelData;
class LevelDbEnv;
class LevelStorageEventing;
class LevelStorageObserver;
class SaveTransactionManager;
class TaskGroup;
class TaskResult;
struct DBStorageConfig;
struct SnapshotFilenameAndLength;
namespace Core { class Path; }
// clang-format on

class DBStorage : public ::LevelStorage {
public:
  // DBStorage 内部类型声明
  // clang-format off
    struct CommitOperation;
    class DBStorageToken;
    class Options;
    struct PendingWriteResult;
  // clang-format on

  // DBStorage 内部类型定义
  class Options {
  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // LevelDB 的主选项。
    ::ll::TypedStorage<8, 2152, ::leveldb::Options> options;
    // LevelDB 的读取选项。
    ::ll::TypedStorage<8, 24, ::leveldb::ReadOptions> read;
    // LevelDB 的写入选项。
    ::ll::TypedStorage<1, 1, ::leveldb::WriteOptions> write;
    // NOLINTEND
  };

  struct PendingWriteResult {
  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 最新的值。
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::std::string const>>
        mLatestValue;
    // 是否已被删除。
    ::ll::TypedStorage<1, 1, bool> mIsDeleted;
    // NOLINTEND

  public:
    // member functions
    // 成员函数
    // NOLINTBEGIN
    MCNAPI ~PendingWriteResult();
    // NOLINTEND
  };

  class DBStorageToken {
  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 引用计数器，用于管理DBStorage的生命周期。
    ::ll::TypedStorage<8, 8, ::std::atomic<int> *> mRefCounter;
    // NOLINTEND

  public:
    // member functions
    // 成员函数
    // NOLINTBEGIN
    MCNAPI ~DBStorageToken();
    // NOLINTEND
  };

  struct CommitOperation {
  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 键。
    ::ll::TypedStorage<8, 32, ::std::string> mKey;
    // 值。
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::std::string>> mValue;
    // 类别。
    ::ll::TypedStorage<4, 4, ::DBHelpers::Category> mCategory;
    // 是否为删除操作。
    ::ll::TypedStorage<1, 1, bool> mIsDelete;
    // NOLINTEND

  public:
    // member functions
    // 成员函数
    // NOLINTBEGIN
    MCNAPI ~CommitOperation();
    // NOLINTEND
  };

public:
  // member variables
  // 成员变量
  // NOLINTBEGIN
  // 数据库环境链。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::DBStorageEnvironmentChain>>
      mEnvChain;
  // LevelDB 的缓存。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::leveldb::Cache>> mCache;
  // LevelDB 的过滤器策略。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::leveldb::FilterPolicy const>>
      mFilterPolicy;
  // LevelDB 的压缩器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::leveldb::Compressor>>
      mCompressor;
  // LevelDB 的旧版压缩器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::leveldb::Compressor>>
      mLegacyCompressor;
  // 数据库选项。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::DBStorage::Options>> mOptions;
  // LevelDB 的解压缩分配器。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::leveldb::DecompressAllocator>>
      mDecompressAllocator;
  // LevelDB 数据库实例。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::leveldb::DB>> mDb;
  // IO 任务组。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::TaskGroup>> mIOTaskGroup;
  // 压缩任务组。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::TaskGroup>> mCompactionTaskGroup;
  // 异步压缩任务。
  ::ll::TypedStorage<
      8, 16, ::std::shared_ptr<::Bedrock::Threading::IAsyncResult<void>>>
      mCompactionTask;
  // 异步写入任务。
  ::ll::TypedStorage<
      8, 16, ::std::shared_ptr<::Bedrock::Threading::IAsyncResult<void>>>
      mWriteTask;
  // 存储的状态。
  ::ll::TypedStorage<8, 40, ::Core::LevelStorageResult> mState;
  // 内容标识。
  ::ll::TypedStorage<8, 8, ::ContentIdentity const *> mContentIdentity;
  // 完整路径。
  ::ll::TypedStorage<8, 32, ::Core::PathBuffer<::std::string>> mFullPath;
  // 数据库路径。
  ::ll::TypedStorage<8, 32, ::Core::PathBuffer<::std::string>> mDbPath;
  // 关卡ID。
  ::ll::TypedStorage<8, 32, ::std::string> mLevelId;
  // 压缩互斥锁。
  ::ll::TypedStorage<8, 80, ::Bedrock::Threading::Mutex> mCompactionMutex;
  // 写入缓存互斥锁。
  ::ll::TypedStorage<8, 8, ::std::shared_mutex> mWriteCacheMutex;
  // 缓存刷新互斥锁。
  ::ll::TypedStorage<8, 80, ::Bedrock::Threading::Mutex> mCacheFlushMutex;
  // 上次压缩开始时间。
  ::ll::TypedStorage<8, 8, ::std::chrono::steady_clock::time_point>
      mLastCompactionStartTime;
  // 压缩间隔。
  ::ll::TypedStorage<8, 8, ::std::chrono::nanoseconds> mCompactionInterval;
  // 写入刷新间隔。
  ::ll::TypedStorage<8, 8, ::std::chrono::nanoseconds> mWriteFlushInterval;
  // 是否允许刷新。
  ::ll::TypedStorage<1, 1, ::std::atomic<bool>> mAllowFlush;
  // 保存是否正在进行中。
  ::ll::TypedStorage<1, 1, ::std::atomic<bool>> mSavingInProgress;
  // 快照是否正在进行中。
  ::ll::TypedStorage<1, 1, ::std::atomic<bool>> mSnapshotInProgress;
  // 关闭是否已开始。
  ::ll::TypedStorage<1, 1, ::std::atomic<bool>> mShutdownStarted;
  // 是否不再有写入操作。
  ::ll::TypedStorage<1, 1, ::std::atomic<bool>> mNoMoreWrites;
  // 关闭是否已完成。
  ::ll::TypedStorage<1, 1, ::std::atomic<bool>> mShutdownDone;
  // 待处理的任务数。
  ::ll::TypedStorage<4, 4, ::std::atomic<int>> mOutstandingJobs;
  // 保存事务管理器。
  ::ll::TypedStorage<8, 24,
                     ::Bedrock::NonOwnerPointer<::SaveTransactionManager>>
      mSaveTransactionManager;
  // 关键同步保存回调。
  ::ll::TypedStorage<8, 64, ::std::function<void()>> mCriticalSyncSaveCallback;
  // 外部注册的压缩回调。
  ::ll::TypedStorage<8, 64, ::std::function<void(::CompactionStatus)>>
      mExternallyRegisteredCompactionCallback;
  // 区块存储列表。
  ::ll::TypedStorage<
      8, 40,
      ::brstd::flat_set<::DBChunkStorage *, ::std::less<::DBChunkStorage *>,
                        ::std::vector<::DBChunkStorage *>>>
      mChunkStorages;
  // 观察者列表。
  ::ll::TypedStorage<8, 24,
                     ::std::vector<::std::unique_ptr<::LevelStorageObserver>>>
      mObservers;
  // 析构函数是否正在进行中。
  ::ll::TypedStorage<1, 1, ::std::atomic<bool>> mDestructorInProgress;
  // 强制标记为损坏。
  ::ll::TypedStorage<1, 1, bool> mForceCorrupt;
  // 存储是否启用。
  ::ll::TypedStorage<1, 1, bool const> mStorageEnabled;
  // 数据库子文件夹。
  ::ll::TypedStorage<8, 32, ::Core::PathBuffer<::std::string>> mDbSubfolder;
  // 单键写入批处理。
  ::ll::TypedStorage<8, 128, ::LevelStorageWriteBatch> mSingleKeyWrites;
  // 批处理写入。
  ::ll::TypedStorage<8, 24, ::std::vector<::LevelStorageWriteBatch>>
      mBatchWrites;
  // 事件系统。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::LevelStorageEventing>> mEventing;
  // LevelDB 环境。
  ::ll::TypedStorage<8, 24, ::Bedrock::NotNullNonOwnerPtr<::LevelDbEnv>>
      mLevelDbEnv;
  // 文件夹遥测监视器。
  ::ll::TypedStorage<
      8, 8, ::gsl::not_null<::std::unique_ptr<::DBStorageFolderWatcher>>>
      mFolderTelemetryWatcher;
  // 下一次大小遥测捕获时间。
  ::ll::TypedStorage<8, 8, ::std::chrono::steady_clock::time_point>
      mNextSizeTelemetryCaptureTime;
  // 大小遥测捕获间隔。
  ::ll::TypedStorage<8, 8, ::std::chrono::nanoseconds const>
      mSizeTelemetryCaptureInterval;
  // 数据库存储性能遥测。
  ::ll::TypedStorage<8, 192, ::DBStoragePerformanceTelemetry>
      mDBStoragePerformanceTelemetry;
  // NOLINTEND

public:
  // prevent constructor by default
  DBStorage();

public:
  // virtual functions
  // 虚函数
  // NOLINTBEGIN
  // vIndex: 0
  virtual ~DBStorage() /*override*/; // 析构函数

  // vIndex: 1
  virtual void addStorageObserver(::std::unique_ptr<::LevelStorageObserver>
                                      observer) /*override*/; // 添加存储观察者

  // vIndex: 2
  virtual bool loadedSuccessfully() const /*override*/; // 是否成功加载

  // vIndex: 21
  virtual ::Core::LevelStorageResult getState() const
      /*override*/; // 获取存储状态

  // vIndex: 7
  virtual ::std::unique_ptr<::ChunkSource>
      createChunkStorage(::std::unique_ptr<::ChunkSource>,
                         ::StorageVersion) /*override*/; // 创建区块存储

  // vIndex: 9
  virtual ::Core::PathBuffer<::std::string> const &getFullPath() const
      /*override*/; // 获取完整路径

  // vIndex: 3
  virtual ::std::unique_ptr<::CompoundTag> getCompoundTag(
      ::std::string const &key,
      ::DBHelpers::Category category) /*override*/; // 获取 CompoundTag

  // vIndex: 4
  virtual bool hasKey(::std::string_view key,
                      ::DBHelpers::Category category) const
      /*override*/; // 检查是否存在键

  // vIndex: 6
  virtual bool loadLevelData(::LevelData &data) /*override*/; // 加载关卡数据

  // vIndex: 8
  virtual void
  saveLevelData(::LevelData const &levelData) /*override*/; // 保存关卡数据

  // vIndex: 11
  virtual ::std::shared_ptr<::Bedrock::Threading::IAsyncResult<void>>
  saveData(::std::string const &key, ::std::string &&data,
           ::DBHelpers::Category category) /*override*/; // 保存数据

  // vIndex: 10
  virtual ::std::shared_ptr<::Bedrock::Threading::IAsyncResult<void>>
  saveData(::LevelStorageWriteBatch const &batch) /*override*/; // 批量保存数据

  // vIndex: 12
  virtual ::std::shared_ptr<::Bedrock::Threading::IAsyncResult<void>>
  deleteData(::std::string const &key,
             ::DBHelpers::Category category) /*override*/; // 删除数据

  // vIndex: 20
  virtual bool loadData(::std::string_view key, ::std::string &buffer,
                        ::DBHelpers::Category category) const
      /*override*/; // 加载数据

  // vIndex: 5
  virtual void forEachKeyWithPrefix(
      ::std::string_view prefix, ::DBHelpers::Category category,
      ::std::function<void(::std::string_view, ::std::string_view)> const
          &callback) const /*override*/; // 遍历具有指定前缀的键

  // vIndex: 15
  virtual ::Core::LevelStorageResult getLevelStorageState() const
      /*override*/; // 获取关卡存储状态

  // vIndex: 16
  virtual ::ContentIdentity const *getContentIdentity() const
      /*override*/; // 获取内容标识

  // vIndex: 17
  virtual void startShutdown() /*override*/; // 开始关闭

  // vIndex: 18
  virtual bool isShuttingDown() const /*override*/; // 是否正在关闭

  // vIndex: 19
  virtual bool checkShutdownDone() /*override*/; // 检查关闭是否完成

  // vIndex: 13
  virtual void getStatistics(::std::string &outStats,
                             ::LevelStorage::StatsType statsType) const
      /*override*/; // 获取统计信息

  // vIndex: 22
  virtual ::std::vector<::SnapshotFilenameAndLength>
  createSnapshot(::std::string const &filePrefix,
                 bool flushWriteCache) /*override*/; // 创建快照

  // vIndex: 23
  virtual void releaseSnapshot() /*override*/; // 释放快照

  // vIndex: 24
  virtual ::std::shared_ptr<::Bedrock::Threading::IAsyncResult<void>>
  compactStorage() /*override*/; // 压缩存储

  // vIndex: 25
  virtual void syncAndSuspendStorage() /*override*/; // 同步并暂停存储

  // vIndex: 26
  virtual void resumeStorage() /*override*/; // 恢复存储

  // vIndex: 27
  virtual void
  setFlushAllowed(bool flushAllowed) /*override*/; // 设置是否允许刷新

  // vIndex: 28
  virtual void flushToPermanentStorage() /*override*/; // 刷新到永久存储

  // vIndex: 29
  virtual void freeCaches() /*override*/; // 释放缓存

  // vIndex: 30
  virtual void setCompactionCallback(::std::function<void(::CompactionStatus)>
                                         callback) /*override*/; // 设置压缩回调

  // vIndex: 31
  virtual void setCriticalSyncSaveCallback(
      ::std::function<void()> callback) /*override*/; // 设置关键同步保存回调
                                                      // NOLINTEND

public:
  // member functions
  // 成员函数
  // NOLINTBEGIN
  /**
   * @brief DBStorage 构造函数。
   * @param config 数据库存储配置。
   * @param levelDbEnv LevelDB 环境。
   */
  MCAPI DBStorage(::DBStorageConfig config,
                  ::Bedrock::NotNullNonOwnerPtr<::LevelDbEnv> levelDbEnv);

  // (内部) 将写入缓存刷新到LevelDB。
  MCAPI ::TaskResult _flushWriteCacheToLevelDB();

  // (内部) 获取所有待处理的写入。
  MCAPI ::std::map<::std::string, ::DBStorage::PendingWriteResult>
  _getAllPendingWrites() const;

  // (内部) 获取遥测消息。
  MCAPI ::std::string
  _getTelemetryMessage(::leveldb::Status const &status) const;

  // (内部) 处理错误状态。
  MCAPI void _handleErrorStatus(::leveldb::Status const &status);

  // (内部) 标记为损坏。
  MCAPI void _markAsCorrupted(::std::string_view message) const;

  // (内部) 合并到写入缓存。
  MCAPI void _mergeIntoWriteCache(::LevelStorageWriteBatch const &batchToMerge);

  // (内部) 合并到写入缓存。
  MCAPI void _mergeIntoWriteCache(::std::string const &key,
                                  ::std::string &&data,
                                  ::DBHelpers::Category category);

  // (内部) 将保存回调加入队列。
  MCAPI void _queueSaveCallback(bool invokeImmediately);

  // (内部) 读取数据。
  MCAPI void
  _read(::std::string_view prefix, ::DBHelpers::Category category,
        ::std::function<void(::std::string_view, ::std::string_view)> const
            &callback) const;

  // (内部) 读取待处理的写入。
  MCAPI ::DBStorage::PendingWriteResult
  _readPendingWrite(::std::string const &key,
                    ::DBHelpers::Category category) const;

  // (内部) 移除损坏标记。
  MCAPI void _removeCorruptedMark() const;

  // (内部) 安排下一次自动压缩。
  MCAPI void _scheduleNextAutoCompaction();

  // (内部) 暂停并执行保存操作。
  MCAPI bool _suspendAndPerformSaveAction(
      ::brstd::move_only_function<::TaskResult()> action,
      ::brstd::move_only_function<void()> callback);

  // 尝试修复数据库。
  MCAPI bool tryRepair(::Core::Path const &path) const;
  // NOLINTEND
};

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(::DBStorageConfig config, ::Bedrock::NotNullNonOwnerPtr<::LevelDbEnv> levelDbEnv);
    // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN
    MCAPI void $dtor();
    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCAPI void $addStorageObserver(::std::unique_ptr<::LevelStorageObserver> observer);

    MCAPI bool $loadedSuccessfully() const;

    MCFOLD ::Core::LevelStorageResult $getState() const;

    MCFOLD ::Core::PathBuffer<::std::string> const& $getFullPath() const;

    MCAPI ::std::unique_ptr<::CompoundTag> $getCompoundTag(::std::string const& key, ::DBHelpers::Category category);

    MCAPI bool $hasKey(::std::string_view key, ::DBHelpers::Category category) const;

    MCAPI bool $loadLevelData(::LevelData& data);

    MCAPI void $saveLevelData(::LevelData const& levelData);

    MCAPI ::std::shared_ptr<::Bedrock::Threading::IAsyncResult<void>>
    $saveData(::std::string const& key, ::std::string&& data, ::DBHelpers::Category category);

    MCAPI ::std::shared_ptr<::Bedrock::Threading::IAsyncResult<void>> $saveData(::LevelStorageWriteBatch const& batch);

    MCAPI ::std::shared_ptr<::Bedrock::Threading::IAsyncResult<void>>
    $deleteData(::std::string const& key, ::DBHelpers::Category category);

    MCAPI bool $loadData(::std::string_view key, ::std::string& buffer, ::DBHelpers::Category category) const;

    MCAPI void $forEachKeyWithPrefix(
        ::std::string_view                                                   prefix,
        ::DBHelpers::Category                                                category,
        ::std::function<void(::std::string_view, ::std::string_view)> const& callback
    ) const;

    MCFOLD ::Core::LevelStorageResult $getLevelStorageState() const;

    MCFOLD ::ContentIdentity const* $getContentIdentity() const;

    MCAPI void $startShutdown();

    MCAPI bool $isShuttingDown() const;

    MCAPI bool $checkShutdownDone();

    MCAPI void $getStatistics(::std::string& outStats, ::LevelStorage::StatsType statsType) const;

    MCAPI ::std::vector<::SnapshotFilenameAndLength>
    $createSnapshot(::std::string const& filePrefix, bool flushWriteCache);

    MCAPI void $releaseSnapshot();

    MCAPI ::std::shared_ptr<::Bedrock::Threading::IAsyncResult<void>> $compactStorage();

    MCAPI void $syncAndSuspendStorage();

    MCAPI void $resumeStorage();

    MCAPI void $setFlushAllowed(bool flushAllowed);

    MCAPI void $flushToPermanentStorage();

    MCAPI void $freeCaches();

    MCAPI void $setCompactionCallback(::std::function<void(::CompactionStatus)> callback);

    MCAPI void $setCriticalSyncSaveCallback(::std::function<void()> callback);
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
