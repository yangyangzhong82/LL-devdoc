#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/common/BrightnessPair.h"
#include "mc/deps/core/utility/AutomaticID.h"
#include "mc/deps/core/utility/optional_ref.h"
#include "mc/deps/game_refs/EnableGetWeakRef.h"
#include "mc/deps/game_refs/WeakRef.h"
#include "mc/world/actor/ActorType.h"
#include "mc/world/level/BlockChangedEventTarget.h"
#include "mc/world/level/BlockDataFetchResult.h"
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/ChunkPos.h"
#include "mc/world/level/IBlockSource.h"
#include "mc/world/level/ShapeType.h"
#include "mc/world/level/Tick.h"
#include "mc/world/level/TickingQueueType.h"
#include "mc/world/level/block/BlockSupportType.h"
#include "mc/world/level/block/actor/BlockActorType.h"
#include "mc/world/level/material/MaterialType.h"

// auto generated forward declare list
// clang-format off
class AABB;
class Actor;
class Biome;
class Block;
class BlockActor;
class BlockDescriptor;
class BlockLegacy;
class BlockSourceListener;
class BlockTickingQueue;
class BlockVolume;
class BoundingBox;
class ChunkSource;
class Dimension;
class EntityContext;
class GameEvent;
class GetCollisionShapeInterface;
class HitResult;
class IConstBlockSource;
class ILevel;
class ItemStackBase;
class Level;
class LevelChunk;
class LevelSeed64;
class Material;
class SubChunkPos;
class Vec3;
class WeakEntityRef;
struct ActorBlockSyncMessage;
struct ActorDefinitionIdentifier;
struct Bounds;
struct Brightness;
struct ClipParameters;
namespace BlockSourceVisitor { struct CollisionShape; }
// clang-format on

class Mob;
class Container;
class CompoundTag;

class BlockSource : public ::IBlockSource,
                    public ::EnableGetWeakRef<::BlockSource>,
                    public ::std::enable_shared_from_this<::BlockSource> {
public:
    LLNDAPI std::vector<Actor*> getEntities(
        AABB const& range,
        float       extendDistance = 2.0f,
        ActorType   actorType      = ActorType::TypeMask,
        bool        ignoreType     = false
    ) const;

    LLNDAPI optional_ref<Container> tryGetContainer(BlockPos const& pos);

    LLAPI optional_ref<Actor> spawnActor(CompoundTag const&);

  public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 拥有此 BlockSource 实例的线程ID。
    ::ll::TypedStorage<4, 4, ::std::thread::id const> mOwnerThreadID;
    // 是否允许访问未填充（未完全生成）的区块。
    ::ll::TypedStorage<1, 1, bool const> mAllowUnpopulatedChunks;
    // 是否为公共源（通常对玩家可见，会进行更多检查）。
    ::ll::TypedStorage<1, 1, bool const> mPublicSource;
    // 是否检查有效性（用于调试或特定操作）。
    ::ll::TypedStorage<1, 1, bool> mCheckValidity;
    // 此 BlockSource 所属的 Level (世界) 的引用。
    ::ll::TypedStorage<8, 8, ::Level &> mLevel;
    // 用于获取区块数据的 ChunkSource 的引用。
    ::ll::TypedStorage<8, 8, ::ChunkSource &> mChunkSource;
    // 此 BlockSource 所在的维度的引用。
    ::ll::TypedStorage<8, 8, ::Dimension &> mDimension;
    // 此方块源的最大高度。
    ::ll::TypedStorage<2, 2, short const> mMaxHeight;
    // 此方块源的最小高度。
    ::ll::TypedStorage<2, 2, short const> mMinHeight;
    // 用于临时存储方块获取结果的向量，以避免重复分配内存。
    ::ll::TypedStorage<8, 24, ::std::vector<::BlockDataFetchResult<::Block>>>
        mTempBlockFetchResult;
    // 是否允许触发计划更新（Ticking）的方块变更。
    ::ll::TypedStorage<1, 1, bool> mAllowTickingChanges;
    // 用于放置操作的区块位置缓存。
    ::ll::TypedStorage<4, 12, ::BlockPos> mPlaceChunkPos;
    // 监听此方块源事件（如方块变更）的监听器列表。
    ::ll::TypedStorage<8, 24, ::std::vector<::BlockSourceListener *>>
        mListeners;
    // 用于有效性检查的当前游戏刻（Tick）。
    ::ll::TypedStorage<8, 8, ::Tick> mCurrentTickForValidityChecks;
    // 是否为持久性方块源（例如，常加载区块）。
    ::ll::TypedStorage<1, 1, bool> mIsPersistantBlockSource;
    // 最后访问的区块位置（缓存）。
    ::ll::TypedStorage<8, 8, ::ChunkPos> mLastChunkPos;
    // 最后访问的区块的弱引用指针（缓存）。
    ::ll::TypedStorage<8, 16, ::std::weak_ptr<::LevelChunk>> mLastChunkWeakPtr;
    // 最后访问的区块的裸指针（缓存）。
    ::ll::TypedStorage<8, 8, ::LevelChunk *> mLastChunkDirectPtr;
    // 随机计划更新队列的指针。
    ::ll::TypedStorage<8, 8, ::BlockTickingQueue *> mRandomTickQueue;
    // 计划更新队列的指针。
    ::ll::TypedStorage<8, 8, ::BlockTickingQueue *> mTickQueue;
    // 默认的亮度值对（天空光和方块光）。
    ::ll::TypedStorage<1, 2, ::BrightnessPair const> mDefaultBrightness;
    // 用于临时存储获取到的实体的向量。
    ::ll::TypedStorage<8, 24, ::std::vector<::Actor *>> mTempEntityList;
    // 用于临时存储获取到的方块实体的向量。
    ::ll::TypedStorage<8, 24, ::std::vector<::BlockActor *>>
        mTempBlockEntityList;
    // 用于临时存储碰撞箱（AABB）的向量。
    ::ll::TypedStorage<8, 24, ::std::vector<::AABB>> mTempCubeList;
    // NOLINTEND

  public:
    // prevent constructor by default
    BlockSource &operator=(BlockSource const &);
    BlockSource(BlockSource const &);
    BlockSource();

  public:
    // virtual functions
    // 虚函数
    // NOLINTBEGIN
    // vIndex: 0
    virtual ~BlockSource() /*override*/; // 析构函数

    // vIndex: 27
    virtual ::WeakRef<::BlockSource>
    getWeakRef() /*override*/; // 获取自身的弱引用

    // vIndex: 41
    virtual ::Level &getLevel() /*override*/; // 获取所属的 Level

    // vIndex: 36
    virtual ::Dimension &getDimension() const
        /*override*/; // 获取所属的维度 (const)

    // vIndex: 35
    virtual ::Dimension &getDimension() /*override*/; // 获取所属的维度

    // vIndex: 37
    virtual ::Dimension const &getDimensionConst() const
        /*override*/; // 获取所属的维度 (const)

    // vIndex: 18
    virtual ::DimensionType getDimensionId() const /*override*/; // 获取维度的ID

    // vIndex: 57
    virtual bool isInstaticking(::BlockPos const &pos) const
        /*override*/; // 检查指定位置的方块是否在立即更新（instatick）

    // vIndex: 28
    virtual void
    addListener(::BlockSourceListener &l) /*override*/; // 添加一个方块源监听器

    // vIndex: 29
    virtual void removeListener(
        ::BlockSourceListener &l) /*override*/; // 移除一个方块源监听器

    // vIndex: 40
    virtual ::LevelChunk *getChunk(int x, int z) const
        /*override*/; // 通过区块坐标获取区块

    // vIndex: 39
    virtual ::LevelChunk *getChunk(::ChunkPos const &pos) const
        /*override*/; // 通过区块位置对象获取区块

    // vIndex: 38
    virtual ::LevelChunk *getChunkAt(::BlockPos const &pos) const
        /*override*/; // 通过方块位置获取区块

    // vIndex: 44
    virtual short getAboveTopSolidBlock(::BlockPos const &pos,
                                        bool includeWater, bool includeLeaves,
                                        bool iteratePastInitialBlocking) const
        /*override*/; // 获取指定位置上方第一个固体方块的高度

    // vIndex: 45
    virtual short getAboveTopSolidBlock(int x, int z, bool includeWater,
                                        bool includeLeaves) const
        /*override*/; // 获取指定坐标上方第一个固体方块的高度

    // vIndex: 47
    virtual short getHeight(::std::function<bool(::Block const &)> const &type,
                            ::BlockPos const &pos) const
        /*override*/; // 获取满足特定条件的方块的高度

    // vIndex: 46
    virtual short getHeight(::std::function<bool(::Block const &)> const &type,
                            int x, int z) const
        /*override*/; // 获取满足特定条件的方块的高度

    // vIndex: 13
    virtual ::Material const &getMaterial(::BlockPos const &pos) const
        /*override*/; // 获取指定位置的方块材质

    // vIndex: 12
    virtual ::Material const &getMaterial(int x, int y, int z) const
        /*override*/; // 获取指定坐标的方块材质

    // vIndex: 34
    virtual short getMaxHeight() const /*override*/; // 获取最大高度

    // vIndex: 33
    virtual short getMinHeight() const /*override*/; // 获取最小高度

    // vIndex: 14
    virtual bool hasBorderBlock(::BlockPos const pos) const
        /*override*/; // 检查指定位置是否有边界方块

    // vIndex: 23
    virtual float getBrightness(::BlockPos const &pos) const
        /*override*/; // 获取指定位置的亮度

    // vIndex: 6
    virtual ::Block const &getLiquidBlock(::BlockPos const &p) const
        /*override*/; // 获取指定位置的液体方块

    // vIndex: 5
    virtual ::Block const &getExtraBlock(::BlockPos const &p) const
        /*override*/; // 获取指定位置的附加方块（如水下海草）

    // vIndex: 54
    virtual bool
    mayPlace(::Block const &block, ::BlockPos const &pos, uchar face,
             ::Actor *placer, bool ignoreEntities,
             ::Vec3 clickPos) /*override*/; // 检查是否可以在指定位置放置方块

    // vIndex: 7
    virtual bool hasBlock(::BlockPos const &pos) const
        /*override*/; // 检查指定位置是否有方块（非空气）

    // vIndex: 55
    virtual bool canDoBlockDrops() const
        /*override*/; // 检查是否可以执行方块掉落

    // vIndex: 56
    virtual bool canDoContainedItemDrops() const
        /*override*/; // 检查是否可以执行容器内物品掉落

    // vIndex: 17
    virtual bool hasChunksAt(::Bounds const &bounds,
                             bool ignoreClientChunk) const
        /*override*/; // 检查指定范围内的所有区块是否存在

    // vIndex: 16
    virtual bool hasChunksAt(::BlockPos const &pos, int r,
                             bool ignoreClientChunk) const
        /*override*/; // 检查以某点为中心、r为半径的区域内的所有区块是否存在

    // vIndex: 15
    virtual bool hasChunksAt(::AABB const &bb, bool ignoreClientChunk) const
        /*override*/; // 检查指定AABB内的所有区块是否存在

    // vIndex: 53
    virtual bool areChunksFullyLoaded(::BlockPos const &pos, int r) const
        /*override*/; // 检查指定区域内的所有区块是否已完全加载

    // vIndex: 8
    virtual bool containsAnyLiquid(::AABB const &box) const
        /*override*/; // 检查指定AABB内是否含有任何液体

    // vIndex: 9
    virtual bool containsMaterial(::AABB const &box,
                                  ::MaterialType material) const
        /*override*/; // 检查指定AABB内是否含有特定材质的方块

    // vIndex: 4
    virtual ::BlockActor const *getBlockEntity(::BlockPos const &pos) const
        /*override*/; // 获取指定位置的方块实体 (const)

    // vIndex: 31
    virtual ::gsl::span<::gsl::not_null<::Actor *>>
    fetchEntities(::Actor const *except, ::AABB const &bb, bool useHitbox,
                  bool getDisplayEntities) /*override*/; // 获取实体列表

    // vIndex: 30
    virtual ::gsl::span<::gsl::not_null<::Actor *>>
    fetchEntities(::ActorType, ::AABB const &, ::Actor const *,
                  ::std::function<
                      bool(::Actor *)>) /*override*/; // 获取特定类型的实体列表

    // vIndex: 19
    virtual void fetchAABBs(::std::vector<::AABB> &shapes,
                            ::AABB const &intersectTestBox,
                            bool withUnloadedChunks) const
        /*override*/; // 获取与测试盒相交的AABB列表

    // vIndex: 25
    virtual ::std::vector<::AABB> &fetchAABBs(
        ::AABB const &intersectTestBox,
        bool withUnloadedChunks) /*override*/; // 获取与测试盒相交的AABB列表

    // vIndex: 26
    virtual ::std::vector<::AABB> &fetchCollisionShapes(
        ::AABB const &intersectTestBox, bool withUnloadedChunks,
        ::std::optional<::EntityContext const> entity,
        ::std::vector<::AABB> *tempShapes) /*override*/; // 获取碰撞箱形状

    // vIndex: 20
    virtual void fetchCollisionShapes(
        ::std::vector<::AABB> &shapes, ::AABB const &intersectTestBox,
        bool withUnloadedChunks,
        ::optional_ref<::GetCollisionShapeInterface const> entity,
        ::std::vector<::AABB> *tempShapes) const
        /*override*/; // 获取碰撞箱形状 (const)

    // vIndex: 21
    virtual void fetchCollisionShapesAndBlocks(
        ::std::vector<::BlockSourceVisitor::CollisionShape> &shapes,
        ::AABB const &intersectTestBox, bool withUnloadedChunks,
        ::optional_ref<::GetCollisionShapeInterface const> entity,
        ::std::vector<::AABB> *tempShapes) const
        /*override*/; // 获取碰撞箱形状和对应的方块

    // vIndex: 22
    virtual ::AABB getTallestCollisionShape(
        ::AABB const &intersectTestBox, float *actualSurfaceOffset,
        bool withUnloadedChunks,
        ::optional_ref<::GetCollisionShapeInterface const> entity) const
        /*override*/; // 获取最高的碰撞箱

    // vIndex: 49
    virtual ::HitResult
    clip(::Vec3 const &A, ::Vec3 const &B, bool checkAgainstLiquid,
         ::ShapeType shapeType, int maxDistance, bool ignoreBorderBlocks,
         bool fullOnly, ::Actor *actor,
         ::std::function<bool(::BlockSource const &, ::Block const &,
                              bool)> const &shouldCheckBlock) const
        /*override*/; // 进行射线检测

    // vIndex: 48
    virtual ::HitResult clip(::ClipParameters const &parameters) const
        /*override*/; // 使用参数对象进行射线检测

    // vIndex: 10
    virtual bool isInWall(::Vec3 const &pos) const
        /*override*/; // 检查一个点是否在墙内

    // vIndex: 11
    virtual bool isUnderWater(::Vec3 const &pos, ::Block const &block) const
        /*override*/; // 检查一个点是否在水下

    // vIndex: 3
    virtual ::Block const &getBlock(int x, int y, int z) const
        /*override*/; // 通过坐标获取方块

    // vIndex: 2
    virtual ::Block const &getBlock(::BlockPos const &pos) const
        /*override*/; // 通过位置对象获取方块

    // vIndex: 1
    virtual ::Block const &getBlock(::BlockPos const &pos, uint layer) const
        /*override*/; // 通过位置和层级获取方块

    // vIndex: 32
    virtual bool setBlock(::BlockPos const &pos, ::Block const &block,
                          int updateFlags,
                          ::ActorBlockSyncMessage const *syncMsg,
                          ::Actor *blockChangeSource) /*override*/; // 设置方块

    // vIndex: 51
    virtual bool isSolidBlockingBlock(int x, int y, int z) const
        /*override*/; // 检查指定坐标的方块是否为固体阻挡方块

    // vIndex: 52
    virtual bool isSolidBlockingBlock(::BlockPos const &p) const
        /*override*/; // 检查指定位置的方块是否为固体阻挡方块

    // vIndex: 60
    virtual bool removeBlock(::BlockPos const &pos) /*override*/; // 移除方块

    // vIndex: 42
    virtual ::ILevel &getILevel() const /*override*/; // 获取ILevel接口

    // vIndex: 43
    virtual ::LevelSeed64 getLevelSeed64() const
        /*override*/; // 获取64位世界种子

    // vIndex: 50
    virtual ::ChunkSource &getChunkSource() /*override*/; // 获取区块源

    // vIndex: 59
    virtual bool checkBlockPermissions(
        ::Actor &entity, ::BlockPos const &blockPos, uchar face,
        ::ItemStackBase const &item,
        bool generateParticle) /*override*/; // 检查实体对方块的操作权限

    // vIndex: 24
    virtual float getVisualLiquidHeight(::Vec3 const &pos) const
        /*override*/; // 获取视觉上的液体高度

    // vIndex: 61
    virtual void postGameEvent(
        ::Actor *source, ::GameEvent const &gameEvent,
        ::BlockPos const &originPos,
        ::Block const *affectedBlock) /*override*/; // 发送一个游戏事件

    // vIndex: 58
    virtual void updateCheckForValidityState(
        bool checkForValidity) /*override*/; // 更新有效性检查的状态
    // NOLINTEND

  public:
    // member functions
    // 成员函数
    // NOLINTBEGIN
    /**
     * @brief BlockSource 的构造函数。
     * @param level BlockSource 所属的 Level。
     * @param dimension BlockSource 所属的维度。
     * @param source BlockSource 使用的 ChunkSource。
     * @param publicSource 是否为公共源（通常用于玩家可访问的区域）。
     * @param allowUnpopulatedChunks 是否允许访问未完全生成的区块。
     * @param allowClientTickingChanges 是否允许在客户端进行方块tick更新。
     */
    MCAPI BlockSource(::Level &level, ::Dimension &dimension,
                      ::ChunkSource &source, bool publicSource,
                      bool allowUnpopulatedChunks,
                      bool allowClientTickingChanges);

    /**
     * @brief (内部使用) 将方块添加到计划更新队列。
     * @param pos 方块位置。
     * @param block 要添加的方块。
     * @param tickDelay 延迟的tick数。
     * @param priorityOffset 优先级偏移。
     * @param queueType 队列类型（普通或随机）。
     * @param skipOverrides 是否跳过覆盖检查。
     */
    MCAPI void _addToTickingQueue(::BlockPos const &pos, ::Block const &block,
                                  int tickDelay, int priorityOffset,
                                  ::TickingQueueType queueType,
                                  bool skipOverrides);

    /**
     * @brief (内部使用) 处理方块变更的逻辑。
     * @param pos 方块位置。
     * @param layer 方块所在的层。
     * @param block 新的方块状态。
     * @param previousBlock 之前的方块状态。
     * @param updateFlags 更新标志位，控制邻居更新等行为。
     * @param syncMsg 实体方块同步消息。
     * @param blockChangeSource 引起此次方块变更的实体。
     */
    MCAPI void _blockChanged(::BlockPos const &pos, uint layer,
                             ::Block const &block, ::Block const &previousBlock,
                             int updateFlags,
                             ::ActorBlockSyncMessage const *syncMsg,
                             ::Actor *blockChangeSource);

    /**
     * @brief (内部使用) 获取边界方块的碰撞箱。
     */
    MCAPI void _fetchBorderBlockCollisions(
        ::std::vector<::AABB> &shapes, ::AABB const &intersectTestBox,
        ::optional_ref<::GetCollisionShapeInterface const> entity, bool) const;

    /**
     * @brief (内部使用) 获取实体的辅助函数。
     */
    MCAPI void _fetchEntityHelper(
        ::WeakEntityRef const &entityRef,
        ::gsl::span<::gsl::not_null<::Actor const *>> const &ignoredEntities,
        ::AABB const &bb, bool useHitbox);

    /**
     * @brief (内部使用) 获取实体的辅助函数（带选择器）。
     */
    MCAPI void _fetchEntityHelper(::WeakEntityRef const &entityRef,
                                  ::ActorType entityTypeId, ::AABB const &bb,
                                  ::Actor const *except,
                                  ::std::function<bool(::Actor *)> selector);

    /**
     * @brief (内部使用) 获取方块权限。
     */
    MCAPI bool _getBlockPermissions(::BlockPos const &pos, bool currentState);

    /**
     * @brief (内部使用) 获取原始亮度值。
     */
    MCAPI ::Brightness _getRawBrightness(::BlockPos const &pos,
                                         ::Brightness skyDarken, bool propagate,
                                         bool accountForNight) const;

    /**
     * @brief (内部使用) 从计划更新队列中移除方块。
     */
    MCAPI void _removeFromTickingQueue(::BlockPos const &pos,
                                       ::Block const &block,
                                       ::TickingQueueType queueType);

    /**
     * @brief (内部使用) 用边界方块的碰撞来更新最高的碰撞箱。
     */
    MCAPI void _updateTallestCollisionShapeWithBorderBlockCollisions(
        ::AABB const &intersectTestBox,
        ::optional_ref<::GetCollisionShapeInterface const> entity,
        ::AABB &result, ::Vec3 const &posToMinimizeDistanceToIfMatchingHeight,
        float &currentDistanceSqr) const;

    /**
     * @brief 以一定百分比的几率将方块添加到随机计划更新队列。
     */
    MCAPI void addToRandomTickingQueuePercentChance(::BlockPos const &pos,
                                                    ::Block const &block,
                                                    float percentChance,
                                                    int priorityOffset,
                                                    bool skipOverrides);

    /**
     * @brief 将方块添加到计划更新队列。
     */
    MCAPI void addToTickingQueue(::BlockPos const &pos, ::Block const &block,
                                 int tickDelay, int priorityOffset,
                                 bool skipOverrides);

    /**
     * @brief 检查指定区域内的所有区块是否已完全加载。
     */
    MCAPI bool areChunksFullyLoaded(::BlockPos const &min,
                                    ::BlockPos const &max) const;

    /**
     * @brief 触发一个方块事件（如音符盒发声）。
     * @param pos 方块位置。
     * @param b0 事件ID。
     * @param b1 事件数据。
     */
    MCAPI void blockEvent(::BlockPos const &pos, int b0, int b1);

    /**
     * @brief 检查一个方块是否能为另一面提供支撑。
     */
    MCAPI bool canProvideSupport(::BlockPos const &pos, uchar face,
                                 ::BlockSupportType type) const;

    /**
     * @brief 检查指定位置是否能看到天空。
     */
    MCAPI bool canSeeSky(::BlockPos const &pos) const;

    /**
     * @brief 检查在水下的指定位置是否能看到天空。
     */
    MCAPI bool canSeeSkyFromBelowWater(::BlockPos const &pos);

    /**
     * @brief 检查实体是否有权限破坏方块。
     */
    MCAPI bool checkBlockDestroyPermissions(::Actor &entity,
                                            ::BlockPos const &pos,
                                            ::ItemStackBase const &item,
                                            bool generateParticle);

    /**
     * @brief 检查指定盒子内是否包含任何满足条件的方块。
     */
    MCAPI bool
    containsAnyBlockInBox(::BoundingBox const &box,
                          ::std::function<bool(::Block const &)> predicate);

    /**
     * @brief 检查指定区域内是否包含任何指定类型的方块。
     */
    MCAPI bool containsAnyBlockOfType(::BlockPos const &min,
                                      ::BlockPos const &max,
                                      ::Block const &type) const;

    /**
     * @brief 检查指定碰撞箱内是否包含任何固体阻挡方块。
     */
    MCAPI bool containsAnySolidBlocking(::AABB const &box) const;

    /**
     * @brief 统计指定区域内某种方块的数量。
     */
    MCAPI uint64 countBlocksOfType(::BlockDescriptor const &blockDescriptor,
                                   ::BlockPos const &min, ::BlockPos const &max,
                                   uint64 maxCount) const;

    /**
     * @brief 获取指定ID和范围内的实体。
     */
    MCAPI ::gsl::span<::gsl::not_null<::Actor *>>
    fetchActors(::ActorDefinitionIdentifier const &actorId, ::AABB const &bb);

    /**
     * @brief 获取指定类型和范围内的方块实体。
     */
    MCAPI ::std::vector<::BlockActor *>
    fetchBlockEntities(::BlockActorType blockActorTypeId,
                       ::AABB const &bb) const;

    /**
     * @brief 获取指定范围内的所有方块实体。
     */
    MCAPI ::std::vector<::BlockActor *> const &
    fetchBlockEntities(::AABB const &bb);

    /**
     * @brief 获取指定区域的方块数据到 BlockVolume 中。
     */
    MCAPI bool fetchBlocks(::BlockPos const &origin,
                           ::BlockVolume &volume) const;

    /**
     * @brief 获取指定盒子内满足条件的方块。
     */
    MCAPI ::gsl::span<::BlockDataFetchResult<::Block> const>
    fetchBlocksInBox(::BoundingBox const &box,
                     ::std::function<bool(::Block const &)> predicate);

    /**
     * @brief 获取指定盒子内满足条件的方块，并按距离排序。
     */
    MCAPI ::gsl::span<::BlockDataFetchResult<::Block> const>
    fetchBlocksInBoxSorted(::BoundingBox const &box,
                           ::std::function<bool(::Block const &)> predicate);

    /**
     * @brief 获取圆柱区域内满足条件的方块。
     */
    MCAPI ::gsl::span<::BlockDataFetchResult<::Block> const>
    fetchBlocksInCylinder(::BlockPos const &centerPos, uint radius, uint height,
                          ::std::function<bool(::Block const &)> predicate);

    /**
     * @brief 获取圆柱区域内满足条件的方块，并按距离排序。
     */
    MCAPI ::gsl::span<::BlockDataFetchResult<::Block> const>
    fetchBlocksInCylinderSorted(
        ::BlockPos const &centerPos, uint radius, uint height,
        ::std::function<bool(::Block const &)> predicate);

    /**
     * @brief 获取指定范围内的实体，可忽略特定实体。
     */
    MCAPI ::gsl::span<::gsl::not_null<::Actor *>>
    fetchEntities(::gsl::span<::gsl::not_null<::Actor const *>> ignoredEntities,
                  ::AABB const &bb, bool useHitbox, bool getDisplayEntities);

    /**
     * @brief 获取指定类型和范围内的实体（旧版或备用实现）。
     */
    MCAPI ::std::vector<::Actor *> const &
    fetchEntities2(::ActorType type, ::AABB const &aabb, bool ignoreTargetType);

    /**
     * @brief 获取指定范围内最近的某种类型的实体。
     */
    MCAPI ::Actor *fetchNearestEntityOfType(::Actor const *except,
                                            ::AABB const &bb,
                                            ::ActorType entityTypeId);

    /**
     * @brief 获取指定范围内的玩家。
     */
    MCAPI ::gsl::span<::gsl::not_null<::Actor *>>
    fetchPlayers(::AABB const &bb, ::Actor const *except,
                 ::std::function<bool(::Actor *)> selector);

    /**
     * @brief 寻找并更新位置到其下方的第一个固体方块顶部。
     */
    MCAPI bool findNextTopSolidBlockUnder(::BlockPos &pos);

    /**
     * @brief 触发方块变更事件，并通知监听器。
     */
    MCAPI void fireBlockChanged(::BlockPos const &pos, uint layer,
                                ::Block const &block, ::Block const &oldBlock,
                                int flags,
                                ::BlockChangedEventTarget eventTarget,
                                ::ActorBlockSyncMessage const *syncMsg,
                                ::Actor *source);

    /**
     * @brief 触发方块实体变更事件。
     */
    MCAPI void fireBlockEntityChanged(::BlockActor &te);

    /**
     * @brief 获取指定位置的生物群系。
     */
    MCAPI ::Biome const &getBiome(::BlockPos const &pos) const;

    /**
     * @brief 获取指定位置的方块实体。
     */
    MCAPI ::BlockActor *getBlockEntity(::BlockPos const &);

    /**
     * @brief 获取指定位置的亮度对（天空光和方块光）。
     */
    MCAPI ::BrightnessPair getBrightnessPair(::BlockPos const &pos) const;

    /**
     * @brief 获取从一个点看向一个AABB的可见百分比。
     */
    MCAPI float getSeenPercent(::Vec3 const &center, ::AABB const &bb);

    /**
     * @brief 从已卸载的区块中获取最高的碰撞箱AABB。
     */
    MCAPI void getTallestCollisionShapeFromUnloadedChunksAABBs(
        ::AABB const &intersectTestBox, ::AABB &tallestCollisionShape,
        ::Vec3 const &posToMinimizeDistanceToIfMatchingHeight,
        float &currentDistanceSqr) const;

    /**
     * @brief 检查指定矩形区域内的所有区块是否都存在。
     */
    MCAPI bool hasChunksAt(::BlockPos const &min, ::BlockPos const &max,
                           bool ignoreClientChunk) const;

    /**
     * @brief 检查指定区域内的所有子区块是否都存在。
     */
    MCAPI ::std::pair<bool, ::std::optional<::SubChunkPos>>
    hasSubChunksAt(::BlockPos const &min, ::BlockPos const &max) const;

    /**
     * @brief 检查一个方块是否在当前 tick 的计划更新队列中。
     */
    MCAPI bool hasTickInCurrentTick(::BlockPos const &pos,
                                    ::TickingQueueType queueType) const;

    /**
     * @brief 检查一个方块是否在待处理的计划更新队列中。
     */
    MCAPI bool hasTickInPendingTicks(::BlockPos const &pos,
                                     ::TickingQueueType queueType) const;

    /**
     * @brief 检查一个方块是否在待处理的计划更新队列中。
     */
    MCAPI bool hasTickInPendingTicks(::BlockPos const &pos,
                                     ::Block const &block,
                                     ::TickingQueueType queueType) const;

    /**
     * @brief 检查一个方块是否在待处理的计划更新队列中。
     */
    MCAPI bool hasTickInPendingTicks(::BlockPos const &pos,
                                     ::BlockLegacy const &block,
                                     ::TickingQueueType queueType) const;

    /**
     * @brief 检查一个区块附近是否有未进行 tick 更新的邻居区块。
     */
    MCAPI bool hasUntickedNeighborChunk(::ChunkPos const &pos,
                                        int chunkRadius) const;

    /**
     * @brief 检查指定坐标的方块是否为空（空气）。
     */
    MCAPI bool isEmptyBlock(int x, int y, int z);

    /**
     * @brief 检查一个区块是否靠近已卸载的区块。
     */
    MCAPI bool isNearUnloadedChunks(::ChunkPos const &pos) const;

    /**
     * @brief 检查指定位置的方块是否接触到某种材质。
     */
    MCAPI bool isTouchingMaterial(::BlockPos const &pos,
                                  ::MaterialType type) const;

    /**
     * @brief 检查一个AABB是否没有被任何实体阻挡。
     */
    MCAPI bool isUnobstructedByEntities(::AABB const &aabb,
                                        ::Actor const *ignoreEntity);

    /**
     * @brief 检查Y坐标是否在世界高度限制内。
     */
    MCAPI bool isWithinHeightLimits(int y) const;

    /**
     * @brief 当邻居方块发生变化时，通知指定位置的方块。
     */
    MCAPI void neighborChanged(::BlockPos const &neighPos,
                               ::BlockPos const &myPos);

    /**
     * @brief 发送一个游戏事件（用于 Sculk 感测器等）。
     */
    MCAPI void postGameEvent(::Actor *source, ::GameEvent const &gameEvent,
                             ::Vec3 const &originPos,
                             ::Block const *affectedBlock);

    /**
     * @brief 移除指定坐标的方块。
     */
    MCAPI bool removeBlock(int x, int y, int z);

    /**
     * @brief 设置指定位置的方块，并可选择设置方块实体。
     */
    MCAPI bool setBlock(::BlockPos const &pos, ::Block const &block,
                        int updateFlags,
                        ::std::shared_ptr<::BlockActor> blockEntity,
                        ::ActorBlockSyncMessage const *syncMsg,
                        ::Actor *blockChangeSource);

    /**
     * @brief 设置指定坐标的方块。
     */
    MCAPI bool setBlock(int x, int y, int z, ::Block const &block,
                        int updateFlags, ::Actor *blockChangeSource);

    /**
     * @brief 将指定位置的方块标记为边界方块（或取消标记）。
     */
    MCAPI void setBorderBlock(::BlockPos const &pos, bool val);

    /**
     * @brief 设置方块的附加层方块（如含水方块中的水）。
     */
    MCAPI bool setExtraBlock(::BlockPos const &p, ::Block const &block,
                             int updateFlags);

    /**
     * @brief 简单地设置方块的附加层方块，不进行更新。
     */
    MCAPI bool setExtraBlockSimple(::BlockPos const &pos, ::Block const &block);

    /**
     * @brief 更新指定位置的所有邻居方块。
     */
    MCAPI void updateNeighborsAt(::BlockPos const &pos);
    // NOLINTEND

  public:
    // static functions
    // 静态函数
    // NOLINTBEGIN
    // 检查指定区域内的 AABB 是否包含任何液体。
    MCAPI static bool containsAnyLiquid(::IConstBlockSource const &region,
                                        ::AABB const &box);

    // 检查指定区域内的 AABB 是否包含任何指定材质的方块。
    MCAPI static bool containsMaterial(::IConstBlockSource const &region,
                                       ::AABB const &box,
                                       ::MaterialType material);
    // NOLINTEND

  public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::Level&       level,
        ::Dimension&   dimension,
        ::ChunkSource& source,
        bool           publicSource,
        bool           allowUnpopulatedChunks,
        bool           allowClientTickingChanges
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
    MCAPI ::WeakRef<::BlockSource> $getWeakRef();

    MCFOLD ::Level& $getLevel();

    MCFOLD ::Dimension& $getDimension() const;

    MCFOLD ::Dimension& $getDimension();

    MCFOLD ::Dimension const& $getDimensionConst() const;

    MCAPI ::DimensionType $getDimensionId() const;

    MCAPI bool $isInstaticking(::BlockPos const& pos) const;

    MCAPI void $addListener(::BlockSourceListener& l);

    MCAPI void $removeListener(::BlockSourceListener& l);

    MCAPI ::LevelChunk* $getChunk(int x, int z) const;

    MCAPI ::LevelChunk* $getChunk(::ChunkPos const& pos) const;

    MCAPI ::LevelChunk* $getChunkAt(::BlockPos const& pos) const;

    MCAPI short $getAboveTopSolidBlock(
        ::BlockPos const& pos,
        bool              includeWater,
        bool              includeLeaves,
        bool              iteratePastInitialBlocking
    ) const;

    MCAPI short $getAboveTopSolidBlock(int x, int z, bool includeWater, bool includeLeaves) const;

    MCAPI short $getHeight(::std::function<bool(::Block const&)> const& type, ::BlockPos const& pos) const;

    MCAPI short $getHeight(::std::function<bool(::Block const&)> const& type, int x, int z) const;

    MCAPI ::Material const& $getMaterial(::BlockPos const& pos) const;

    MCAPI ::Material const& $getMaterial(int x, int y, int z) const;

    MCAPI short $getMaxHeight() const;

    MCAPI short $getMinHeight() const;

    MCAPI bool $hasBorderBlock(::BlockPos const pos) const;

    MCAPI float $getBrightness(::BlockPos const& pos) const;

    MCAPI ::Block const& $getLiquidBlock(::BlockPos const& p) const;

    MCAPI ::Block const& $getExtraBlock(::BlockPos const& p) const;

    MCAPI bool $mayPlace(
        ::Block const&    block,
        ::BlockPos const& pos,
        uchar             face,
        ::Actor*          placer,
        bool              ignoreEntities,
        ::Vec3            clickPos
    );

    MCAPI bool $hasBlock(::BlockPos const& pos) const;

    MCAPI bool $canDoBlockDrops() const;

    MCAPI bool $canDoContainedItemDrops() const;

    MCAPI bool $hasChunksAt(::Bounds const& bounds, bool ignoreClientChunk) const;

    MCAPI bool $hasChunksAt(::BlockPos const& pos, int r, bool ignoreClientChunk) const;

    MCAPI bool $hasChunksAt(::AABB const& bb, bool ignoreClientChunk) const;

    MCAPI bool $areChunksFullyLoaded(::BlockPos const& pos, int r) const;

    MCAPI bool $containsAnyLiquid(::AABB const& box) const;

    MCAPI bool $containsMaterial(::AABB const& box, ::MaterialType material) const;

    MCFOLD ::BlockActor const* $getBlockEntity(::BlockPos const& pos) const;

    MCAPI ::gsl::span<::gsl::not_null<::Actor*>>
    $fetchEntities(::Actor const* except, ::AABB const& bb, bool useHitbox, bool getDisplayEntities);

    MCAPI void
    $fetchAABBs(::std::vector<::AABB>& shapes, ::AABB const& intersectTestBox, bool withUnloadedChunks) const;

    MCAPI ::std::vector<::AABB>& $fetchAABBs(::AABB const& intersectTestBox, bool withUnloadedChunks);

    MCAPI ::std::vector<::AABB>& $fetchCollisionShapes(
        ::AABB const&                          intersectTestBox,
        bool                                   withUnloadedChunks,
        ::std::optional<::EntityContext const> entity,
        ::std::vector<::AABB>*                 tempShapes
    );

    MCAPI void $fetchCollisionShapes(
        ::std::vector<::AABB>&                             shapes,
        ::AABB const&                                      intersectTestBox,
        bool                                               withUnloadedChunks,
        ::optional_ref<::GetCollisionShapeInterface const> entity,
        ::std::vector<::AABB>*                             tempShapes
    ) const;

    MCAPI void $fetchCollisionShapesAndBlocks(
        ::std::vector<::BlockSourceVisitor::CollisionShape>& shapes,
        ::AABB const&                                        intersectTestBox,
        bool                                                 withUnloadedChunks,
        ::optional_ref<::GetCollisionShapeInterface const>   entity,
        ::std::vector<::AABB>*                               tempShapes
    ) const;

    MCAPI ::AABB $getTallestCollisionShape(
        ::AABB const&                                      intersectTestBox,
        float*                                             actualSurfaceOffset,
        bool                                               withUnloadedChunks,
        ::optional_ref<::GetCollisionShapeInterface const> entity
    ) const;

    MCAPI ::HitResult $clip(
        ::Vec3 const&                                                            A,
        ::Vec3 const&                                                            B,
        bool                                                                     checkAgainstLiquid,
        ::ShapeType                                                              shapeType,
        int                                                                      maxDistance,
        bool                                                                     ignoreBorderBlocks,
        bool                                                                     fullOnly,
        ::Actor*                                                                 actor,
        ::std::function<bool(::BlockSource const&, ::Block const&, bool)> const& shouldCheckBlock
    ) const;

    MCAPI ::HitResult $clip(::ClipParameters const& parameters) const;

    MCAPI bool $isInWall(::Vec3 const& pos) const;

    MCAPI bool $isUnderWater(::Vec3 const& pos, ::Block const& block) const;

    MCAPI ::Block const& $getBlock(int x, int y, int z) const;

    MCAPI ::Block const& $getBlock(::BlockPos const& pos) const;

    MCAPI ::Block const& $getBlock(::BlockPos const& pos, uint layer) const;

    MCAPI bool $setBlock(
        ::BlockPos const&              pos,
        ::Block const&                 block,
        int                            updateFlags,
        ::ActorBlockSyncMessage const* syncMsg,
        ::Actor*                       blockChangeSource
    );

    MCAPI bool $isSolidBlockingBlock(int x, int y, int z) const;

    MCAPI bool $isSolidBlockingBlock(::BlockPos const& p) const;

    MCAPI bool $removeBlock(::BlockPos const& pos);

    MCFOLD ::ILevel& $getILevel() const;

    MCAPI ::LevelSeed64 $getLevelSeed64() const;

    MCFOLD ::ChunkSource& $getChunkSource();

    MCAPI bool $checkBlockPermissions(
        ::Actor&               entity,
        ::BlockPos const&      blockPos,
        uchar                  face,
        ::ItemStackBase const& item,
        bool                   generateParticle
    );

    MCFOLD float $getVisualLiquidHeight(::Vec3 const& pos) const;

    MCAPI void $postGameEvent(
        ::Actor*           source,
        ::GameEvent const& gameEvent,
        ::BlockPos const&  originPos,
        ::Block const*     affectedBlock
    );

    MCAPI void $updateCheckForValidityState(bool checkForValidity);
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
