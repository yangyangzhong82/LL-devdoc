#pragma once

#include "mc/_HeaderOutputPredefine.h"
#include "mc/world/level/block/AttachmentType.h"
#include "mc/world/level/block/BigDripleafTilt.h"
#include "mc/world/level/block/states/BlockState.h"
#include "mc/world/level/block/states/BlockStateInstance.h"

// auto generated inclusion list
#include "mc/common/Brightness.h"
#include "mc/common/NewBlockID.h"
#include "mc/common/WeakPtr.h"
#include "mc/deps/core/container/Cache.h"
#include "mc/deps/core/container/EnumSet.h"
#include "mc/deps/core/math/Color.h"
#include "mc/deps/core/string/HashedString.h"
#include "mc/deps/core/utility/optional_ref.h"
#include "mc/resources/BaseGameVersion.h"
#include "mc/util/IntRange.h"
#include "mc/world/Direction.h"
#include "mc/world/Flip.h"
#include "mc/world/item/CreativeItemCategory.h"
#include "mc/world/item/FertilizerType.h"
#include "mc/world/level/ShapeType.h"
#include "mc/world/level/block/BlockClientPredictionOverrides.h"
#include "mc/world/level/block/BlockProperty.h"
#include "mc/world/level/block/BlockRenderLayer.h"
#include "mc/world/level/block/BlockSupportType.h"
#include "mc/world/level/block/BurnOdds.h"
#include "mc/world/level/block/FlameOdds.h"
#include "mc/world/level/block/LavaFlammable.h"
#include "mc/world/level/block/NoteBlockInstrument.h"
#include "mc/world/level/block/TintMethod.h"
#include "mc/world/level/block/actor/BlockActorType.h"
#include "mc/world/level/block/block_events/BlockEventManager.h"
#include "mc/world/level/block/components/BlockComponentStorage.h"
#include "mc/world/level/block/components/NetEaseBlockComponentStorage.h"
#include "mc/world/phys/AABB.h"

// auto generated forward declare list
// clang-format off
class Actor;
class Block;
class BlockActor;
class BlockItem;
class BlockPos;
class BlockSource;
class BlockState;
class BlockStateGroup;
class BlockStateInstance;
class Container;
class CopperBehavior;
class DefinitionEvent;
class DefinitionTrigger;
class EntityContext;
class Experiments;
class GetCollisionShapeInterface;
class HitResult;
class IConstBlockSource;
class IResourceDropsStrategy;
class ItemActor;
class ItemInstance;
class ItemStack;
class Material;
class MobSpawnerData;
class Player;
class Random;
class Randomize;
class RenderParams;
class ScriptBlockCustomComponentsFinalizer;
class SemVersion;
class SpawnConditions;
class Vec3;
struct ActorBlockSyncMessage;
struct BlockAnimateTickData;
struct BlockComponentDescription;
struct BlockGraphicsModeChangeContext;
struct CommandName;
struct ResourceDrops;
struct ResourceDropsContext;
struct UpdateEntityAfterFallOnInterface;
namespace BlockEvents { class BlockEntityFallOnEvent; }
namespace BlockTrait { class IGetPlacementBlockCallback; }
namespace BlockTrait { class ITrait; }
namespace br::spawn { struct EntityType; }
// clang-format on

// 代表一个方块的 "传统" 定义，例如 "minecraft:stone"。
// 它包含了所有可能的方块状态（排列组合），并定义了该方块类型的通用行为。
class BlockLegacy {
public:
    // 模板函数：根据状态 ID 和数据值获取一个特定的方块状态属性值。
    template <typename T>
    std::optional<T> getState(uint64 id, ushort data) const {
        auto it = mStates->find(id);

        if (it == mStates->end()) {
            {
                // 检查已变更的状态集合，用于向后兼容
                for (const auto& collection : *mAlteredStateCollections) {
                    if (collection && collection->mBlockState->get().mID == id) {
                        auto result = collection->getState(*this, data);
                        if (result) {
                            return result;
                        }
                    }
                }

                return std::nullopt; // 未找到
            }
        }

        return it->second.get<T>(data);
    }

    // 模板函数：根据 BlockState 对象和数据值获取一个特定的方块状态属性值。
    template <typename T>
    std::optional<T> getState(BlockState const& stateType, ushort data) const {
        return getState<T>(stateType.mID, data);
    }

    // 模板函数：尝试为一个方块设置一个新的状态属性值，并返回代表新状态的方块。
    // 要求 T 是整数类型或枚举类型。
    template <typename T>
        requires(std::is_integral_v<T> || std::is_enum_v<T>)
    optional_ref<Block const> trySetState(uint64 id, T val, ushort data) {
        auto it = mStates->find(id);

        if (it != mStates->end()) {
            auto& stateInstance = it->second;

            if (static_cast<uchar>(val) < stateInstance.mVariationCount) {
                // 计算新的数据值
                ushort maskedData = (data & ~stateInstance.mMask)
                                  | (static_cast<ushort>(val) << (stateInstance.mEndBit - stateInstance.mNumBits + 1));

                if (maskedData < mBlockPermutations->size()) {
                    return *mBlockPermutations->at(maskedData);
                }
                return nullptr;
            }
        }

        // 检查已变更的状态集合
        for (auto& collection : *mAlteredStateCollections) {
            if (collection && collection->mBlockState->get().mID == id) {
                auto result = collection->setState(*this, data, val);
                if (result) {
                    return result;
                }
            }
        }

        // 如果找不到状态，根据设置返回默认方块或空
        return mReturnDefaultBlockOnUnidentifiedBlockState ? mDefaultState : nullptr;
    }

    // 模板函数：通过 BlockState 对象尝试设置状态。
    template <typename T>
    optional_ref<Block const> trySetState(BlockState const& stateType, T val, ushort data) {
        return trySetState(stateType.mID, val, data);
    }

public:
    // BlockLegacy inner types declare
    // BlockLegacy 内部类型声明
    // clang-format off
        struct AlteredStateCollection;
        struct HorizontalDirectionBits;
        struct NameInfo;
        struct RearrangedStateCollection;
        struct RemovedStateCollection;
    // clang-format on

    // BlockLegacy inner types define
    // BlockLegacy 内部类型定义

    // 存储方块的各种名称信息
    struct NameInfo {
    public:
        // member variables
        // 成员变量
        // NOLINTBEGIN
        ::ll::TypedStorage<8, 48, ::HashedString> mRawName;           // 原始名称
        ::ll::TypedStorage<8, 32, ::std::string>  mNamespaceName;     // 命名空间名称
        ::ll::TypedStorage<8, 48, ::HashedString> mFullName;          // 完整名称 (例如 "minecraft:stone")
        ::ll::TypedStorage<8, 48, ::HashedString> mPreFlatteningName; // "扁平化" 之前的旧名称
        // NOLINTEND

    public:
        // prevent constructor by default
        // 默认禁止构造函数
        NameInfo& operator=(NameInfo const&);
        NameInfo(NameInfo const&);
        NameInfo();

    public:
        // member functions
        // 成员函数
        // NOLINTBEGIN
        MCAPI ::BlockLegacy::NameInfo& operator=(::BlockLegacy::NameInfo&&);

        MCAPI ~NameInfo();
        // NOLINTEND

    public:
        // destructor thunk
        // 析构函数（Thunk）
        // NOLINTBEGIN
        MCAPI void $dtor();
        // NOLINTEND
    };

    // 存储水平方向的连接信息（通常用于墙、栅栏等）
    struct HorizontalDirectionBits {
    public:
        // member variables
        // 成员变量
        // NOLINTBEGIN
        ::ll::TypedStorage<1, 1, bool> mNorth; // 北
        ::ll::TypedStorage<1, 1, bool> mEast;  // 东
        ::ll::TypedStorage<1, 1, bool> mSouth; // 南
        ::ll::TypedStorage<1, 1, bool> mWest;  // 西
        // NOLINTEND
    };

    // 用于处理在游戏更新中被更改过的方块状态的集合的基类。
    // 主要用于向后兼容旧版本的世界数据。
    struct AlteredStateCollection {
    public:
        // member variables
        // 成员变量
        // NOLINTBEGIN
        ::ll::TypedStorage<8, 8, ::std::reference_wrapper<::BlockState const>> mBlockState; // 关联的方块状态
        // NOLINTEND

    public:
        // virtual functions
        // 虚函数
        // NOLINTBEGIN
        // vIndex: 0
        // 从旧的方块数据值获取新的状态值
        virtual ::std::optional<int> getState(::BlockLegacy const&, int) const = 0;

        // vIndex: 1
        // 根据旧的方块数据值和新的状态值设置并返回正确的方块排列
        virtual ::Block const* setState(::BlockLegacy const&, int, int) const = 0;

        // vIndex: 2
        virtual ~AlteredStateCollection() = default;
        // NOLINTEND

    public:
        // static functions
        // 静态函数
        // NOLINTBEGIN
        MCNAPI static bool _checkVersioningRequirements(::SemVersion const& removedSupportVersion);
        // NOLINTEND

    public:
        // virtual function thunks
        // 虚函数（Thunk）
        // NOLINTBEGIN

        // NOLINTEND
    };

    // 用于处理被移除的方块状态的集合。
    struct RemovedStateCollection : public ::BlockLegacy::AlteredStateCollection {
    public:
        // RemovedStateCollection inner types declare
        // RemovedStateCollection 内部类型声明
        // clang-format off
            struct SplitBlock;
        // clang-format on

        // RemovedStateCollection inner types define
        // RemovedStateCollection 内部类型定义
        struct SplitBlock {
        public:
            // member variables
            // 成员变量
            // NOLINTBEGIN
            ::ll::TypedStorage<4, 4, int>                                     mData;        // 数据值
            ::ll::TypedStorage<8, 8, ::std::reference_wrapper<::BlockLegacy>> mBlockLegacy; // 对应的 BlockLegacy
            // NOLINTEND
        };

    public:
        // member variables
        // 成员变量
        // NOLINTBEGIN
        ::ll::TypedStorage<8, 24, ::std::vector<::BlockLegacy::RemovedStateCollection::SplitBlock>>
            mSplitBlocks; // 分离出的方块列表
        // NOLINTEND

    public:
        // virtual functions
        // 虚函数
        // NOLINTBEGIN
        // vIndex: 0
        virtual ::std::optional<int> getState(::BlockLegacy const& blockLegacy, int) const /*override*/;

        // vIndex: 1
        virtual ::Block const* setState(::BlockLegacy const& blockLegacy, int blockData, int stateData) const
            /*override*/;

        // vIndex: 2
        virtual ~RemovedStateCollection() /*override*/ = default;
        // NOLINTEND

    public:
        // static functions
        // 静态函数
        // NOLINTBEGIN
        MCNAPI static void
        add(::BlockState const&                                                stateRef,
            ::std::vector<::BlockLegacy::RemovedStateCollection::SplitBlock>&& splitBlocks,
            ::SemVersion const&                                                removedSupportVersion);
        // NOLINTEND

    public:
        // virtual function thunks
        // 虚函数（Thunk）
        // NOLINTBEGIN
        MCNAPI ::std::optional<int> $getState(::BlockLegacy const& blockLegacy, int) const;

        MCNAPI ::Block const* $setState(::BlockLegacy const& blockLegacy, int blockData, int stateData) const;
        // NOLINTEND

    public:
        // vftables
        // 虚函数表
        // NOLINTBEGIN
        MCNAPI static void** $vftable();
        // NOLINTEND
    };

    // 用于处理被重排（例如，位域改变）的方块状态的集合。
    struct RearrangedStateCollection : public ::BlockLegacy::AlteredStateCollection {
    public:
        // RearrangedStateCollection inner types define
        // RearrangedStateCollection 内部类型定义
        using GetterType = ::std::function<::std::optional<int>(::BlockLegacy const&, int)>; // 获取器类型

        using SetterType = ::std::function<::Block const*(::BlockLegacy const&, int, int)>; // 设置器类型

    public:
        // member variables
        // 成员变量
        // NOLINTBEGIN
        ::ll::TypedStorage<8, 64, ::std::function<::std::optional<int>(::BlockLegacy const&, int)>>
            mGetter; // 获取器函数
        ::ll::TypedStorage<8, 64, ::std::function<::Block const*(::BlockLegacy const&, int, int)>>
            mSetter; // 设置器函数
        // NOLINTEND

    public:
        // prevent constructor by default
        // 默认禁止构造函数
        RearrangedStateCollection();

    public:
        // virtual functions
        // 虚函数
        // NOLINTBEGIN
        // vIndex: 0
        virtual ::std::optional<int> getState(::BlockLegacy const& blockLegacy, int blockData) const /*override*/;

        // vIndex: 1
        virtual ::Block const* setState(::BlockLegacy const& blockLegacy, int blockData, int stateData) const
            /*override*/;

        // vIndex: 2
        virtual ~RearrangedStateCollection() /*override*/ = default;
        // NOLINTEND

    public:
        // member functions
        // 成员函数
        // NOLINTBEGIN
        MCNAPI RearrangedStateCollection(
            ::BlockState const&                                              stateRef,
            ::std::function<::std::optional<int>(::BlockLegacy const&, int)> getter,
            ::std::function<::Block const*(::BlockLegacy const&, int, int)>  setter
        );
        // NOLINTEND

    public:
        // static functions
        // 静态函数
        // NOLINTBEGIN
        MCNAPI static void
        add(::BlockLegacy&                                                   blockLegacy,
            ::BlockState const&                                              stateRef,
            ::std::function<::std::optional<int>(::BlockLegacy const&, int)> getter,
            ::std::function<::Block const*(::BlockLegacy const&, int, int)>  setter,
            ::SemVersion const&                                              removedSupportVersion);
        // NOLINTEND

    public:
        // constructor thunks
        // 构造函数（Thunk）
        // NOLINTBEGIN
        MCNAPI void* $ctor(
            ::BlockState const&                                              stateRef,
            ::std::function<::std::optional<int>(::BlockLegacy const&, int)> getter,
            ::std::function<::Block const*(::BlockLegacy const&, int, int)>  setter
        );
        // NOLINTEND

    public:
        // virtual function thunks
        // 虚函数（Thunk）
        // NOLINTBEGIN
        MCNAPI ::std::optional<int> $getState(::BlockLegacy const& blockLegacy, int blockData) const;

        MCNAPI ::Block const* $setState(::BlockLegacy const& blockLegacy, int blockData, int stateData) const;
        // NOLINTEND

    public:
        // vftables
        // 虚函数表
        // NOLINTBEGIN
        MCNAPI static void** $vftable();
        // NOLINTEND
    };

public:
    // 获取方块类型的名称 (例如 "stone")
    LLNDAPI std::string const& getTypeName() const;

    // 尝试从注册表中通过名称获取 BlockLegacy
    LLNDAPI static optional_ref<BlockLegacy> tryGetFromRegistry(std::string_view name);
    // 尝试从注册表中通过旧版ID获取 BlockLegacy
    LLNDAPI static optional_ref<BlockLegacy const> tryGetFromRegistry(uint legacyBlockID);

public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    ::ll::TypedStorage<8, 32, ::std::string> mDescriptionId; // 方块的描述ID（用于本地化，例如 "tile.stone.name"）
    ::ll::TypedStorage<8, 104, ::BlockComponentStorage> mComponents; // 方块组件存储
    ::ll::TypedStorage<8, 176, ::BlockLegacy::NameInfo> mNameInfo;   // 方块的名称信息
    ::ll::TypedStorage<8, 8, ::BlockProperty>           mProperties; // 方块属性的位掩码
    ::ll::TypedStorage<1, 1, bool>                      mFancy; // 是否为 "高级" 渲染模式（例如，树叶）
    ::ll::TypedStorage<1, 1, ::BlockRenderLayer>        mRenderLayer; // 方块的渲染层级
    ::ll::TypedStorage<1, 1, bool> mRenderLayerCanRenderAsOpaque;     // 渲染层是否可以作为不透明层渲染
    ::ll::TypedStorage<4, 4, ::BlockActorType> mBlockEntityType;      // 方块实体的类型
    ::ll::TypedStorage<4, 4, float>            mThickness;            // 方块厚度
    ::ll::TypedStorage<1, 1, bool>             mCanSlide;             // 实体是否可以在其上滑动
    ::ll::TypedStorage<1, 1, bool> mCanReactToNeighborsDuringInstatick; // 是否可以在 Instatick 期间响应邻居变化
    ::ll::TypedStorage<1, 1, bool>                   mIsInteraction;          // 是否是一个交互方块
    ::ll::TypedStorage<4, 4, float>                  mGravity;                // 重力
    ::ll::TypedStorage<8, 8, ::Material const&>      mMaterial;               // 方块的材质
    ::ll::TypedStorage<1, 1, bool>                   mFalling;                // 是否是可下落方块
    ::ll::TypedStorage<4, 4, float>                  mParticleQuantityScalar; // 粒子数量缩放系数
    ::ll::TypedStorage<4, 4, ::CreativeItemCategory> mCreativeCategory;       // 创造模式物品栏分类
    ::ll::TypedStorage<8, 32, ::std::string>         mCreativeGroup;          // 创造模式物品栏分组
    ::ll::TypedStorage<1, 1, bool>                   mIsHiddenInCommands;     // 在命令中是否隐藏
    ::ll::TypedStorage<1, 1, bool>                   mAllowsRunes;            // 是否允许符文
    ::ll::TypedStorage<1, 1, bool>                   mCanBeBrokenFromFalling; // 是否能被下落的方块砸坏
    ::ll::TypedStorage<1, 1, bool>                   mCanBeOriginalSurface;   // 是否可以是原始地表
    ::ll::TypedStorage<1, 1, bool>                   mSolid;                  // 是否为固体方块
    ::ll::TypedStorage<1, 1, bool>                   mPushesOutItems;         // 是否会推出物品
    ::ll::TypedStorage<1, 1, bool> mIgnoreBlockForInsideCubeRenderer; // 在渲染内部立方体时是否忽略此方块
    ::ll::TypedStorage<1, 1, bool>         mIsTrapdoor;               // 是否是活板门
    ::ll::TypedStorage<1, 1, bool>         mIsDoor;                   // 是否是门
    ::ll::TypedStorage<1, 1, bool>         mIsOpaqueFullBlock;        // 是否是完整的不透明方块
    ::ll::TypedStorage<4, 4, float>        mTranslucency;             // 透明度
    ::ll::TypedStorage<1, 1, bool>         mShouldRandomTick;         // 是否应该接收随机刻更新
    ::ll::TypedStorage<1, 1, bool>         mShouldRandomTickExtraLayer; // 额外层面是否应该接收随机刻更新
    ::ll::TypedStorage<1, 1, bool>         mIsMobPiece;                 // 是否是生物生成结构的一部分
    ::ll::TypedStorage<1, 1, bool>         mCanBeExtraBlock;            // 是否可以是附加方块
    ::ll::TypedStorage<1, 1, bool>         mCanPropagateBrightness;     // 是否可以传播亮度
    ::ll::TypedStorage<1, 1, ::Brightness> mLightBlock;                 // 阻挡光线的等级
    ::ll::TypedStorage<1, 1, ::Brightness> mLightEmission;              // 发光亮度
    ::ll::TypedStorage<4, 4, ::FlameOdds>  mFlameOdds;                  // 着火几率
    ::ll::TypedStorage<4, 4, ::BurnOdds>   mBurnOdds;                   // 燃烧几率
    ::ll::TypedStorage<1, 1, ::LavaFlammable>       mLavaFlammable;     // 是否可被岩浆点燃
    ::ll::TypedStorage<4, 16, ::mce::Color>         mMapColor;          // 地图上显示的颜色
    ::ll::TypedStorage<4, 4, float>                 mFriction;          // 摩擦力
    ::ll::TypedStorage<4, 4, ::NoteBlockInstrument> mNoteBlockInstrument; // 音符盒乐器类型
    ::ll::TypedStorage<1, 1, ::TintMethod>          mTintMethod;          // 染色方法
    ::ll::TypedStorage<1, 1, bool>
        mReturnDefaultBlockOnUnidentifiedBlockState;  // 当遇到无法识别的方块状态时是否返回默认方块
    ::ll::TypedStorage<2, 2, ::NewBlockID>       mID; // 方块的数字ID
    ::ll::TypedStorage<8, 32, ::BaseGameVersion> mMinRequiredBaseGameVersion; // 所需的最低基础游戏版本
    ::ll::TypedStorage<1, 1, bool>               mIsVanilla;                  // 是否是原版方块
    ::ll::TypedStorage<8, 24, ::std::vector<::HashedString>>                          mTags;          // 方块标签
    ::ll::TypedStorage<8, 64, ::std::unordered_map<::std::string, ::DefinitionEvent>> mEventHandlers; // 事件处理器
    ::ll::TypedStorage<1, 1, bool> mDataDrivenVanillaBlocksAndItemsEnabled; // 是否启用了数据驱动的原版方块和物品
    ::ll::TypedStorage<4, 24, ::AABB>                                       mVisualShape; // 可视形状（碰撞箱）
    ::ll::TypedStorage<4, 4, uint>                                          mBitsUsed;    // 已使用的位数
    ::ll::TypedStorage<4, 4, uint>                                          mTotalBitsUsed; // 总共使用的位数
    ::ll::TypedStorage<8, 16, ::std::map<uint64, ::BlockStateInstance>>     mStates; // 方块状态实例的映射
    ::ll::TypedStorage<8, 64, ::std::unordered_map<::HashedString, uint64>> mStateNameMap; // 状态名称到ID的映射
    ::ll::TypedStorage<8, 8, uint64> mCreativeEnumState;                                   // 创造模式枚举状态
    ::ll::TypedStorage<8, 24, ::std::vector<::std::unique_ptr<::Block>>> mBlockPermutations; // 方块的所有排列组合
    ::ll::TypedStorage<8, 8, ::Block const*> mDefaultState;                                  // 默认的方块状态
    ::ll::TypedStorage<8, 24, ::std::vector<::std::unique_ptr<::BlockTrait::IGetPlacementBlockCallback>>>
        mGetPlacementBlockCallbacks; // 获取放置方块的回调
    ::ll::TypedStorage<8, 72, ::Core::Cache<ushort, ::Block const*, ::Block const*>>
        mLegacyDataLookupTable; // 旧版数据查找表缓存
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::BlockStateGroup>>        mBlockStateGroup;       // 方块状态组
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::IResourceDropsStrategy>> mResourceDropsStrategy; // 资源掉落策略
    ::ll::TypedStorage<4, 8, ::IntRange>                                  mExperienceDropRange;   // 经验掉落范围
    ::ll::TypedStorage<1, 1, bool> mRequiresCorrectToolForDrops; // 掉落物是否需要正确的工具
    ::ll::TypedStorage<8, 104, ::NetEaseBlockComponentStorage> mNetEaseComponentStorage; // 网易版方块组件存储
    ::ll::TypedStorage<8, 24, ::std::vector<::std::shared_ptr<::BlockLegacy::AlteredStateCollection>>>
        mAlteredStateCollections; // 已变更的状态集合
    ::ll::TypedStorage<1, 1, ::Bedrock::EnumSet<::BlockClientPredictionOverrides, 7>>
                                                                mClientPredictionOverrides; // 客户端预测覆写
    ::ll::TypedStorage<8, 32, ::BlockEvents::BlockEventManager> mEventManager;              // 方块事件管理器
    // NOLINTEND

public:
    // prevent constructor by default
    // 默认禁止构造函数
    BlockLegacy& operator=(BlockLegacy const&);
    BlockLegacy(BlockLegacy const&);
    BlockLegacy();

public:
    // virtual functions
    // 虚函数
    // NOLINTBEGIN
    // vIndex: 0
    virtual ~BlockLegacy();

    // vIndex: 1
    // 创建一个新的方块实体（BlockEntity/BlockActor），如箱子、熔炉。
    virtual ::std::shared_ptr<::BlockActor> newBlockEntity(::BlockPos const& pos, ::Block const& block) const;

    // vIndex: 2
    // 获取当前方块排列的下一个排列。用于调试屏幕切换方块状态。
    virtual ::Block const* getNextBlockPermutation(::Block const& currentBlock) const;

    // vIndex: 3
    // 检查方块是否具有指定的标签。
    virtual bool
    hasTag(::BlockSource& region, ::BlockPos const& pos, ::Block const& block, ::std::string const& tagName) const;

    // vIndex: 4
    // 计算从点A到点B的射线与方块的碰撞点。
    virtual ::HitResult clip(
        ::Block const&                                     block,
        ::BlockSource const&                               region,
        ::BlockPos const&                                  pos,
        ::Vec3 const&                                      A,
        ::Vec3 const&                                      B,
        ::ShapeType                                        shapeType,
        ::optional_ref<::GetCollisionShapeInterface const> entity
    ) const;

    // vIndex: 5
    // 获取方块的碰撞箱。
    virtual ::AABB
    getCollisionShape(::Block const& block, ::IConstBlockSource const&, ::BlockPos const& pos, ::optional_ref<::GetCollisionShapeInterface const>)
        const;

    // vIndex: 6
    // 获取用于相机碰撞的碰撞箱。
    virtual bool getCollisionShapeForCamera(
        ::AABB&                    outAABB,
        ::Block const&             block,
        ::IConstBlockSource const& region,
        ::BlockPos const&          pos
    ) const;

    // vIndex: 7
    // 向列表中添加与指定AABB相交的碰撞箱。
    virtual bool addCollisionShapes(
        ::Block const&                                     block,
        ::IConstBlockSource const&                         region,
        ::BlockPos const&                                  pos,
        ::AABB const*                                      intersectTestBox,
        ::std::vector<::AABB>&                             inoutBoxes,
        ::optional_ref<::GetCollisionShapeInterface const> entity
    ) const;

    // vIndex: 8
    // 向列表中添加方块的AABB（包围盒）。
    virtual void addAABBs(
        ::Block const&             block,
        ::IConstBlockSource const& region,
        ::BlockPos const&          pos,
        ::AABB const*              intersectTestBox,
        ::std::vector<::AABB>&     inoutBoxes
    ) const;

    // vIndex: 9
    // 获取方块的轮廓线（选中时显示的黑框）。
    virtual ::AABB const&
    getOutline(::Block const& block, ::IConstBlockSource const&, ::BlockPos const& pos, ::AABB& bufferValue) const;

    // vIndex: 10
    // 获取方块在世界中的可视形状。
    virtual ::AABB const&
    getVisualShapeInWorld(::Block const& block, ::IConstBlockSource const&, ::BlockPos const&, ::AABB& bufferAABB)
        const;

    // vIndex: 11
    // 获取方块的可视形状。
    virtual ::AABB const& getVisualShape(::Block const&, ::AABB&) const;

    // vIndex: 12
    // 获取在UI中显示的形状。
    virtual ::AABB const& getUIShape(::Block const& block, ::AABB& bufferAABB) const;

    // vIndex: 13
    // 获取液体的裁剪体积。
    virtual bool
    getLiquidClipVolume(::Block const& block, ::BlockSource& region, ::BlockPos const& pos, ::AABB& includeBox) const;

    // vIndex: 14
    // 检查此方块是否会阻挡箱子打开。
    virtual bool isObstructingChests(::BlockSource& region, ::BlockPos const& pos, ::Block const& thisBlock) const;

    // vIndex: 15
    // 随机地修改一个位置（通常用于粒子效果）。
    virtual ::Vec3 randomlyModifyPosition(::BlockPos const& pos) const;

    // vIndex: 16
    // 当弹射物击中方块时调用。
    virtual void onProjectileHit(::BlockSource&, ::BlockPos const&, ::Actor const&) const;

    // vIndex: 17
    // 当被闪电击中时调用。
    virtual void onLightningHit(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 18
    // 液体是否可以从指定方向流入此方块。
    virtual bool liquidCanFlowIntoFromDirection(
        uchar                                                     flowIntoFacing,
        ::std::function<::Block const&(::BlockPos const&)> const& getBlock,
        ::BlockPos const&                                         pos
    ) const;

    // vIndex: 19
    // 是否具有可变的光照（例如红石矿石被踩踏时）。
    virtual bool hasVariableLighting() const;

    // vIndex: 20
    // 是否可以被斧头“剥皮”。
    virtual bool isStrippable(::Block const& srcBlock) const;

    // vIndex: 21
    // 获取被“剥皮”后的方块。
    virtual ::Block const& getStrippedBlock(::Block const& srcBlock) const;

    // vIndex: 22
    // 是否能提供支撑。
    virtual bool canProvideSupport(::Block const&, uchar, ::BlockSupportType) const;

    // vIndex: 23
    // 是否能为多面方块（如苔藓）提供支撑。
    virtual bool canProvideMultifaceSupport(::Block const& block, uchar face) const;

    // vIndex: 24
    // 是否能与另一个方块连接（如栅栏、墙）。
    virtual bool canConnect(::Block const&, uchar toOther, ::Block const& thisBlock) const;

    // vIndex: 25
    // 是否是移动方块（活塞臂）。
    virtual bool isMovingBlock() const;

    // vIndex: 26
    // 尝试获取铜块行为（用于氧化）。
    virtual ::CopperBehavior const* tryGetCopperBehavior() const;

    // vIndex: 27
    // 是否是茎方块（如西瓜茎）。
    virtual bool isStemBlock() const;

    // vIndex: 28
    // 是否是容器方块（如箱子、发射器）。
    virtual bool isContainerBlock() const;

    // vIndex: 29
    // 是否是合成方块（如工作台）。
    virtual bool isCraftingBlock() const;

    // vIndex: 30
    // 是否能阻挡岩浆流动。
    virtual bool isLavaBlocking() const;

    // vIndex: 31
    // 是否是栅栏方块。
    virtual bool isFenceBlock() const;

    // vIndex: 32
    // 是否是栅栏门方块。
    virtual bool isFenceGateBlock() const;

    // vIndex: 33
    // 是否是细栅栏（如铁栏杆）。
    virtual bool isThinFenceBlock() const;

    // vIndex: 34
    // 是否是墙方块。
    virtual bool isWallBlock() const;

    // vIndex: 35
    // 是否是楼梯方块。
    virtual bool isStairBlock() const;

    // vIndex: 36
    // 是否是台阶方块。
    virtual bool isSlabBlock() const;

    // vIndex: 37
    // 是否是门方块。
    virtual bool isDoorBlock() const;

    // vIndex: 38
    // 是否是铁轨方块。
    virtual bool isRailBlock() const;

    // vIndex: 39
    // 是否是按钮方块。
    virtual bool isButtonBlock() const;

    // vIndex: 40
    // 是否是拉杆方块。
    virtual bool isLeverBlock() const;

    // vIndex: 41
    // 是否是插上蜡烛的蛋糕。
    virtual bool isCandleCakeBlock() const;

    // vIndex: 42
    // 是否是多面方块。
    virtual bool isMultifaceBlock() const;

    // vIndex: 43
    // 是否是信号源（能发出红石信号）。
    virtual bool isSignalSource() const;

    // vIndex: 44
    // 是否是消耗性组件（能接收红石信号）。
    virtual bool isConsumerComponent() const;

    // vIndex: 45
    // 是否可以是原始地表（用于世界生成）。
    virtual bool canBeOriginalSurface() const;

    // vIndex: 46
    // 从上面跳下时是否无声。
    virtual bool isSilentWhenJumpingOff() const;

    // vIndex: 47
    // 给定的附加值（data value）是否有效。
    virtual bool isValidAuxValue(int value) const;

    // vIndex: 48
    // 是否可以在指定位置填充此方块。
    virtual bool canFillAtPos(::BlockSource& region, ::BlockPos const& pos, ::Block const& block) const;

    // vIndex: 49
    // 净化用于填充的方块状态。
    virtual ::Block const& sanitizeFillBlock(::Block const& block) const;

    // vIndex: 50
    // 当填充方块时调用。
    virtual void onFillBlock(::BlockSource& region, ::BlockPos const& pos, ::Block const& block) const;

    // vIndex: 51
    // 获取直接的红石信号强度。
    virtual int getDirectSignal(::BlockSource& region, ::BlockPos const& pos, int dir) const;

    // vIndex: 52
    // 获取所需的介质（例如，火把需要附着在固体方块上）。
    virtual ::std::optional<::HashedString> getRequiredMedium() const;

    // vIndex: 53
    // 是否应该连接到红石线。
    virtual bool
    shouldConnectToRedstone(::BlockSource& region, ::BlockPos const& pos, ::Direction::Type direction) const;

    // vIndex: 54
    // 处理降水（雨、雪）。
    virtual void
    handlePrecipitation(::BlockSource& region, ::BlockPos const& pos, float downfallAmount, float temperature) const;

    // vIndex: 55
    // 是否可以在命令中使用（例如 /setblock）。
    virtual bool canBeUsedInCommands(::BaseGameVersion const& baseGameVersion) const;

    // vIndex: 56
    // 检查实体是否可以将其作为路径通过。
    virtual bool checkIsPathable(::Actor& entity, ::BlockPos const& lastPathPos, ::BlockPos const& pathPos) const;

    // vIndex: 57
    // 发射器是否应该发射此物品。
    virtual bool shouldDispense(::BlockSource& region, ::Container& container) const;

    // vIndex: 58
    // 执行发射行为。
    virtual bool dispense(::BlockSource& region, ::Container& container, int slot, ::Vec3 const& pos, uchar face) const;

    // vIndex: 59
    // 当实体掉落在此方块上时，转换此方块（如耕地变回泥土）。
    virtual void
    transformOnFall(::BlockSource& region, ::BlockPos const& pos, ::Actor* entity, float fallDistance) const;

    // vIndex: 60
    // 当接收到红石更新时调用。
    virtual void onRedstoneUpdate(::BlockSource& region, ::BlockPos const& pos, int strength, bool isFirstTime) const;

    // vIndex: 61
    // 当方块被（活塞）移动时调用。
    virtual void onMove(::BlockSource& region, ::BlockPos const& from, ::BlockPos const& to) const;

    // vIndex: 62
    // 当被活塞推动时，此方块是否会脱落（如火把）。
    virtual bool detachesOnPistonMove(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 63
    // 当被活塞移动后调用。
    virtual void movedByPiston(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 64
    // 当结构方块放置此方块时调用。
    virtual void onStructureBlockPlace(::BlockSource& region, ::BlockPos const& pos) const;


    // vIndex: 65
    // 当此方块的邻居被结构方块放置时调用。
    virtual void onStructureNeighborBlockPlace(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 66
    // 设置红石组件。
    virtual void setupRedstoneComponent(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 67
    // 当实体掉落在上面后，更新实体状态。
    virtual void updateEntityAfterFallOn(::BlockPos const& pos, ::UpdateEntityAfterFallOnInterface& entity) const;

    // vIndex: 68
    // 是否是弹跳方块（如史莱姆方块）。
    virtual bool isBounceBlock() const;

    // vIndex: 69
    // 放置时是否保留原有的介质（如水中的海草）。
    virtual bool isPreservingMediumWhenPlaced(::BlockLegacy const* medium) const;

    // vIndex: 70
    // 在指定的渲染层中是否被过滤掉。
    virtual bool isFilteredOut(::BlockRenderLayer) const;

    // vIndex: 71
    // 是否可以渲染选中时的覆盖层（黑框）。
    virtual bool canRenderSelectionOverlay(::BlockRenderLayer) const;

    // vIndex: 72
    // 在被活塞推动时是否忽略实体。
    virtual bool ignoreEntitiesOnPistonMove(::Block const& block) const;

    // vIndex: 73
    // 当被施肥时（如使用骨粉）调用。
    virtual bool
    onFertilized(::BlockSource& region, ::BlockPos const& pos, ::Actor* actor, ::FertilizerType fType) const;

    // vIndex: 74
    // 是否会消耗肥料。
    virtual bool mayConsumeFertilizer(::BlockSource& region) const;

    // vIndex: 75
    // 是否可以被施肥。
    virtual bool canBeFertilized(::BlockSource& region, ::BlockPos const& pos, ::Block const& aboveBlock) const;

    // vIndex: 77
    // 是否可以被拾取（中键）。
    virtual bool mayPick() const;

    // vIndex: 76
    // 是否可以被拾取（中键），带更多上下文。
    virtual bool mayPick(::BlockSource const& region, ::Block const& block, bool liquid) const;

    // vIndex: 79
    // 是否可以在指定位置和朝向放置。
    virtual bool mayPlace(::BlockSource& region, ::BlockPos const& pos, uchar face) const;

    // vIndex: 78
    // 是否可以在指定位置放置。
    virtual bool mayPlace(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 80
    // 是否可以放置在目标方块上。
    virtual bool mayPlaceOn(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 81
    // 尝试放置方块。
    virtual bool tryToPlace(
        ::BlockSource&                 region,
        ::BlockPos const&              pos,
        ::Block const&                 block,
        ::ActorBlockSyncMessage const* syncMsg
    ) const;

    // vIndex: 82
    // 尝试用锄耕地。
    virtual bool tryToTill(::BlockSource& region, ::BlockPos const& pos, ::Actor& entity, ::ItemStack& item) const;

    // vIndex: 83
    // 此方块是否会破坏掉落在其上的下落方块（如火把）。
    virtual bool breaksFallingBlocks(::Block const& block, ::BaseGameVersion const version) const;

    // vIndex: 84
    // 破坏方块（不掉落物品）。
    virtual void
    destroy(::BlockSource& region, ::BlockPos const& pos, ::Block const& block, ::Actor* entitySource) const;

    // vIndex: 85
    // 实体破坏此方块时是否忽略权限检查。
    virtual bool getIgnoresDestroyPermissions(::Actor& entity, ::BlockPos const& pos) const;

    // vIndex: 86
    // 当邻居方块发生变化时调用。
    virtual void neighborChanged(::BlockSource& region, ::BlockPos const& pos, ::BlockPos const& neighborPos) const;

    // vIndex: 87
    // 获取方块的第二部分（如门的上半部分）。
    virtual bool getSecondPart(::IConstBlockSource const& region, ::BlockPos const& pos, ::BlockPos& out) const;

    // vIndex: 88
    // 当玩家即将破坏方块时调用，返回破坏后应设置的方块（通常是空气）。
    virtual ::Block const* playerWillDestroy(::Player& player, ::BlockPos const& pos, ::Block const& block) const;

    // vIndex: 89
    // 将此方块转换为物品实例（ItemInstance）。
    virtual ::ItemInstance asItemInstance(::Block const&, ::BlockActor const*) const;

    // vIndex: 90
    // 在方块被破坏后生成掉落物。
    virtual void
    spawnAfterBreak(::BlockSource&, ::Block const&, ::BlockPos const&, ::ResourceDropsContext const&) const;

    // vIndex: 91
    // 根据放置者、位置、朝向等信息，获取实际应放置的方块状态。
    virtual ::Block const&
    getPlacementBlock(::Actor const& by, ::BlockPos const& pos, uchar face, ::Vec3 const& clickPos, int itemValue)
        const;

    // vIndex: 92
    // 计算方块的变种（通常用于颜色，如羊毛）。
    virtual int calcVariant(::BlockSource& region, ::BlockPos const& pos, ::mce::Color const& baseColor) const;

    // vIndex: 93
    // 检查此方块是否附着在另一个方块上。
    virtual bool isAttachedTo(::BlockSource& region, ::BlockPos const& pos, ::BlockPos& outAttachedTo) const;

    // vIndex: 94
    // 当玩家攻击（左键点击）方块时调用。
    virtual bool attack(::Player* player, ::BlockPos const& pos) const;

    // vIndex: 95
    // 实体在方块内部时，是否应该触发效果。
    virtual bool shouldTriggerEntityInside(::BlockSource& region, ::BlockPos const& pos, ::Actor& entity) const;

    // vIndex: 97
    // （重载）是否可以被另一个方块（以物品形式）覆盖。
    virtual bool
    canBeBuiltOver(::Block const& block, ::BlockSource& region, ::BlockPos const& pos, ::BlockItem const& newItem)
        const;

    // vIndex: 96
    // 是否可以被覆盖（例如，被水流）。
    virtual bool canBeBuiltOver(::Block const& block, ::BlockSource&, ::BlockPos const&) const;

    // vIndex: 98
    // 触发方块事件（通常由服务器发送给客户端，用于动画等）。
    virtual void triggerEvent(::BlockSource& region, ::BlockPos const& pos, int b0, int b1) const;

    // vIndex: 99
    // 执行一个由数据驱动的事件。
    virtual void executeEvent(
        ::BlockSource&       region,
        ::BlockPos const&    pos,
        ::Block const&       block,
        ::std::string const& eventName,
        ::Actor&             sourceEntity
    ) const;

    // vIndex: 100
    // 获取此方块（作为刷怪笼时）应该生成的生物。
    virtual ::MobSpawnerData const* getMobToSpawn(::SpawnConditions const& conditions, ::BlockSource& region) const;

    // vIndex: 101
    // 是否应该阻止实体下落（如蜘蛛网）。
    virtual bool shouldStopFalling(::Actor& entity) const;

    // vIndex: 102
    // 是否会将下落的方块向上推。
    virtual bool pushesUpFallingBlocks() const;

    // vIndex: 103
    // 是否可以有额外的方块实体数据。
    virtual bool canHaveExtraData() const;

    // vIndex: 104
    // 是否能被红石比较器检测。
    virtual bool hasComparatorSignal() const;

    // vIndex: 105
    // 获取红石比较器的信号强度。
    virtual int
    getComparatorSignal(::BlockSource& region, ::BlockPos const& pos, ::Block const& block, uchar dir) const;

    // vIndex: 106
    // 实体是否可以在其上滑动（如冰）。
    virtual bool canSlide(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 107
    // 是否可以被“瞬间刻”（Instatick）。
    virtual bool canInstatick() const;

    // vIndex: 108
    // 是否可以在此位置生成（用于世界生成）。
    virtual bool canSpawnAt(::BlockSource const& region, ::BlockPos const& pos) const;

    // vIndex: 109
    // 通知此方块它已在某处生成。
    virtual void notifySpawnedAt(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 110
    // 是否会造成冰冻效果（如细雪）。
    virtual bool causesFreezeEffect() const;

    // vIndex: 111
    // 构建方块的描述ID（用于本地化）。
    virtual ::std::string buildDescriptionId(::Block const&) const;

    // vIndex: 112
    // 拾取方块时，附加值是否相关。
    virtual bool isAuxValueRelevantForPicking() const;

    // vIndex: 113
    // 颜色是否受季节/生物群系影响。
    virtual bool isSeasonTinted(::Block const& block, ::BlockSource& region, ::BlockPos const& p) const;

    // vIndex: 114
    // 当图形模式改变时调用。
    virtual void onGraphicsModeChanged(::BlockGraphicsModeChangeContext const& context);

    // vIndex: 115
    // 获取方块的阴影亮度。
    virtual float getShadeBrightness(::Block const& block) const;

    // vIndex: 116
    // 获取用于遥测的方块变种。
    virtual int telemetryVariant(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 117
    // 获取方块的变种。
    virtual int getVariant(::Block const& block) const;

    // vIndex: 118
    // 生物是否可以生成在此方块上。
    virtual bool canSpawnOn(::Actor*) const;

    // vIndex: 119
    // 获取用于渲染的方块。
    virtual ::Block const& getRenderBlock() const;

    // vIndex: 120
    // 获取映射后的面（用于旋转等）。
    virtual uchar getMappedFace(uchar face, ::Block const& block) const;

    // vIndex: 121
    // 获取面的翻转状态。
    virtual ::Flip getFaceFlip(uchar face, ::Block const& block) const;

    // vIndex: 122
    // [已弃用] 基岩版旧版的方块动画tick。
    virtual void animateTickBedrockLegacy(::BlockAnimateTickData const&) const;

    // vIndex: 123
    // 方块动画tick（用于粒子效果等）。
    virtual void animateTick(::BlockAnimateTickData const&) const;

    // vIndex: 124
    // 初始化方块。
    virtual ::BlockLegacy& init();

    // vIndex: 125
    // 获取方块的发光亮度。
    virtual ::Brightness getLightEmission(::Block const&) const;

    // vIndex: 126
    // 尝试从旧版ID升级到新版方块。
    virtual ::Block const* tryLegacyUpgrade(ushort) const;

    // vIndex: 127
    // 实体接触时是否会造成伤害。
    virtual bool dealsContactDamage(::Actor const& actor, ::Block const& block, bool isPathFinding) const;

    // vIndex: 128
    // 尝试获取被“侵染”的版本（如石头 -> 蠹虫石头）。
    virtual ::Block const* tryGetInfested(::Block const&) const;

    // vIndex: 129
    // 尝试获取未被“侵染”的版本。
    virtual ::Block const* tryGetUninfested(::Block const&) const;

    // vIndex: 130
    // 添加硬编码的方块组件。
    virtual void _addHardCodedBlockComponents(::Experiments const&);

    // vIndex: 131
    // 当方块被移除时调用。
    virtual void onRemove(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 132
    // 当方块被爆炸摧毁时调用。
    virtual void onExploded(::BlockSource& region, ::BlockPos const& pos, ::Actor* entitySource) const;

    // vIndex: 133
    // 当实体站立在上面时调用。
    virtual void onStandOn(::EntityContext& entity, ::BlockPos const& pos) const;

    // vIndex: 134
    // 在被放置时是否应该触发tick。
    virtual bool shouldTickOnSetBlock() const;

    // vIndex: 135
    // 随机刻更新。
    virtual void randomTick(::BlockSource&, ::BlockPos const&, ::Random&) const;

    // vIndex: 136
    // 是否是交互方块（可以右键）。
    virtual bool isInteractiveBlock() const;

    // vIndex: 137
    // 放置时是否允许客户端和服务端状态不匹配。
    virtual bool allowStateMismatchOnPlacement(::Block const& clientTarget, ::Block const& serverTarget) const;

    // vIndex: 138
    // 是否可以在当前位置存活（如火把需要附着物）。
    virtual bool canSurvive(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 139
    // 获取方块的渲染层级。
    virtual ::BlockRenderLayer getRenderLayer(::Block const& block, ::BlockSource&, ::BlockPos const& pos) const;

    // vIndex: 140
    // 获取额外的渲染层级数量。
    virtual int getExtraRenderLayers() const;

    // vIndex: 141
    // 获取用于剔除的层。
    virtual ::HashedString const& getCullingLayer() const;

    // vIndex: 142
    // 获取方块的光照亮度（穿过方块后的）。
    virtual ::Brightness getLight(::Block const&) const;

    // vIndex: 143
    // 获取方块的发光亮度。
    virtual ::Brightness getEmissiveBrightness(::Block const&) const;

    // vIndex: 144
    // 获取地图上显示的颜色。
    virtual ::mce::Color getMapColor(::BlockSource&, ::BlockPos const&, ::Block const&) const;

    // vIndex: 145
    // 当被激活性攻击（如三叉戟附魔引雷）击中时调用。
    virtual void _onHitByActivatingAttack(::BlockSource&, ::BlockPos const&, ::Actor*) const;

    // vIndex: 146
    // 当实体在方块内部时调用。
    virtual void entityInside(::BlockSource&, ::BlockPos const&, ::Actor&) const;
    // NOLINTEND

public:
    // member functions
    // 成员函数
    // NOLINTBEGIN
    MCAPI BlockLegacy(::std::string const& nameId, int id, ::Material const& material);

    MCAPI void _executeEvent(
        ::std::string const&                                                  name,
        ::std::vector<::std::pair<::std::string const, ::std::string const>>& eventStack,
        ::RenderParams&                                                       params
    ) const;

    MCAPI void _forceExecuteTrigger(
        ::DefinitionTrigger const&                                            trigger,
        ::std::vector<::std::pair<::std::string const, ::std::string const>>& eventStack,
        ::RenderParams&                                                       params
    ) const;

    // 添加方块属性。
    MCAPI ::BlockLegacy& addBlockProperties(::BlockProperty addedProperties);

    // 添加方块组件。
    MCAPI ::BlockLegacy& addComponent(::BlockComponentDescription const& blockComponentDescription);

    // 添加一个方块状态。
    MCAPI ::BlockLegacy& addState(::BlockState const& state);

    // 添加一个有指定变化数量的方块状态。
    MCAPI ::BlockLegacy& addState(::BlockState const& state, uint64 variationCount);

    // 添加一个标签。
    MCAPI ::BlockLegacy& addTag(::HashedString const& tag);

    // 添加一个特性（Trait）。
    MCAPI ::BlockLegacy& addTrait(::BlockTrait::ITrait const& trait);

    // 检查此方块是否是给定列表中的任何一种。
    MCAPI bool anyOf(::gsl::span<::std::reference_wrapper<::HashedString const> const> const& blockTypeIdList) const;

    // 构建方块的描述名称（用于显示）。
    MCAPI ::std::string buildDescriptionName(::Block const& block) const;

    // 创建方块的所有排列组合。
    MCAPI void createBlockPermutations(uint latestUpdaterVersion);

    // 创建一个指向此BlockLegacy的弱指针。
    MCAPI ::WeakPtr<::BlockLegacy> createWeakPtr() const;

    // 执行一个事件。
    MCAPI void executeEvent(::std::string const& name, ::RenderParams& params) const;

    // 完成方块组件存储的最终化处理。
    MCAPI void finalizeBlockComponentStorage();

    // 完成脚本自定义组件的最终化处理。
    MCAPI void finalizeScriptCustomComponents(::ScriptBlockCustomComponentsFinalizer& finalizer);

    // 遍历此方块的所有排列组合。
    MCAPI void forEachBlockPermutation(::std::function<bool(::Block const&)> callback) const;

    // 遍历并可能修改此方块的所有排列组合。
    MCAPI bool forEachBlockPermutationMutable(::std::function<bool(::Block&)> callback);

    // 遍历此方块的所有状态实例。
    MCAPI void forEachBlockStateInstance(::std::function<bool(::BlockStateInstance const&)> callback) const;

    // 获取此方块对应的物品ID。
    MCAPI short getBlockItemId() const;

    // 通过名称获取方块状态。
    MCAPI ::BlockState const* getBlockState(::HashedString const& name) const;

    // 获取此方块的命令名称。
    MCAPI ::std::vector<::CommandName> getCommandNames() const;

    // 获取调试文本信息。
    MCAPI void getDebugText(::std::vector<::std::string>& outputInfo, ::BlockPos const& debugPos) const;

    // 获取资源掉落物。
    MCAPI ::ResourceDrops
    getResourceDrops(::Block const& block, ::Randomize& randomize, ::ResourceDropsContext const& resourceDropsContext)
        const;

    // 检查是否拥有指定的方块状态类型。
    MCAPI bool hasState(::BlockState const& stateType) const;

    // 检查是否拥有指定的标签。
    MCAPI bool hasTag(::HashedString const& tag) const;

    // 检查指定实体类型是否可以在此方块上有效生成。
    MCAPI bool
    isValidSpawn(::BlockSource& region, ::Block const& state, ::BlockPos pos, ::br::spawn::EntityType const& entityType)
        const;

    // 当实体掉落在上面时的基础处理。
    MCAPI void onFallOnBase(::BlockEvents::BlockEntityFallOnEvent& eventData) const;

    // 覆写方块属性。
    MCAPI ::BlockLegacy& overrideBlockProperties(::BlockProperty newProperties);

    // 设置是否允许符文。
    MCAPI ::BlockLegacy& setAllowsRunes(bool interference);

    // 设置是否可以是附加方块。
    MCAPI ::BlockLegacy& setCanBeExtraBlock(bool state);

    // 设置是否可以是原始地表。
    MCAPI ::BlockLegacy& setCanBeOriginalSurface(bool canBeOriginalSurface);

    // 设置创造模式物品栏分类。
    MCAPI ::BlockLegacy& setCategory(::CreativeItemCategory creativeCategory);

    // 设置创造模式物品栏分组。
    MCAPI ::BlockLegacy& setCreativeGroup(::std::string const& value);

    // 设置经验掉落范围。
    MCAPI ::BlockLegacy& setExperienceDrop(::IntRange dropRange);

    // 设置可燃性。
    MCAPI ::BlockLegacy& setFlammable(::FlameOdds flameOdds, ::BurnOdds burnOdds, ::LavaFlammable lavaFlammable);

    // 设置摩擦力。
    MCAPI ::BlockLegacy& setFriction(float f);

    // 设置音符盒乐器。
    MCAPI ::BlockLegacy& setInstrument(::NoteBlockInstrument instrument);

    // 设置在命令中是否隐藏。
    MCAPI ::BlockLegacy& setIsHiddenInCommands(bool isHiddenInCommands);

    // 设置一个谓词来判断是否为有效生成点。
    MCAPI ::BlockLegacy&
    setIsValidSpawn(bool (*predicate)(::BlockSource const&, ::Block const&, ::BlockPos, ::br::spawn::EntityType const&)
    );

    // 设置阻挡光线的等级。
    MCAPI ::BlockLegacy& setLightBlock(::Brightness brightness);

    // 设置发光亮度。
    MCAPI ::BlockLegacy& setLightEmission(::Brightness brightness);

    // 设置地图颜色。
    MCAPI ::BlockLegacy& setMapColor(::mce::Color const& color);

    // 设置所需的最低基础游戏版本。
    MCAPI ::BlockLegacy& setMinRequiredBaseGameVersion(::BaseGameVersion const& baseGameVersion);

    // 设置名称ID。
    MCAPI ::BlockLegacy& setNameId(::std::string const& id);

    // 设置掉落物需要正确的工具。
    MCAPI ::BlockLegacy& setRequiresCorrectToolForDrops();

    // 设置染色方法。
    MCAPI ::BlockLegacy& setTintMethod(::TintMethod tintMethod);

    // 设置透明度。
    MCAPI ::BlockLegacy& setTranslucency(float translucency);

    // 实体站立时是否应该触发效果。
    MCAPI bool shouldTriggerOnStandOn(::Actor& entity, ::BlockPos const& pos) const;

    // 生成资源（掉落物）。
    MCAPI void spawnResources(
        ::BlockSource&                region,
        ::BlockPos const&             pos,
        ::Block const&                block,
        ::Randomize&                  randomize,
        ::ResourceDropsContext const& resourceDropsContext
    ) const;

    // 尝试从旧版数据值获取方块状态。
    MCAPI ::Block const* tryGetStateFromLegacyData(ushort data) const;

    // 更新最高的碰撞箱形状。
    MCAPI bool updateTallestCollisionShape(
        ::Block const&                                     block,
        ::BlockSource const&                               region,
        ::BlockPos const&                                  pos,
        ::AABB const&                                      intersectTestBox,
        ::optional_ref<::GetCollisionShapeInterface const> entity,
        ::AABB&                                            result,
        ::Vec3 const&                                      posToMinimizeDistanceToIfMatchingHeight,
        float&                                             currentDistanceSqr
    ) const;
    // NOLINTEND

public:
    // static functions
    // 静态函数
    // NOLINTBEGIN
    // 从名称信息构建描述ID。
    MCAPI static ::std::string buildDescriptionIdFromNameInfo(::BlockLegacy::NameInfo const& nameInfo);

    // 从字符串名称中提取方块名称信息。
    MCAPI static ::BlockLegacy::NameInfo extractBlockNameInfo(::std::string const& name);

    // 获取方块的连接方向。
    MCAPI static ::BlockLegacy::HorizontalDirectionBits
    getConnectedDirections(::Block const& thisBlock, ::BlockPos const& pos, ::IConstBlockSource const& region);

    // 获取全方位的放置朝向。
    MCAPI static uchar getPlacementFacingAll(::Actor const& entity, ::BlockPos const& pos, float yRotOffsetDegree);

    // 在指定位置生成一个物品实体作为掉落物。
    MCAPI static ::ItemActor* popResource(::BlockSource& region, ::BlockPos const& pos, ::ItemStack const& item);

    // 在指定位置生成一个物品实体作为掉落物。
    MCAPI static ::ItemActor*
    popResource(::BlockSource& region, ::BlockPos const& pos, ::ItemInstance const& itemInstance);
    // NOLINTEND

public:
    // static variables
    // 静态变量
    // NOLINTBEGIN
    MCAPI static ::std::string const& BLOCK_DESCRIPTION_PREFIX(); // 方块描述前缀 ("tile.")

    MCAPI static float const& SIZE_OFFSET(); // 尺寸偏移量
    // NOLINTEND


    public :
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void*
    $ctor(::std::string const& nameId, int id, ::Material const& material);
// NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN
    MCAPI void $dtor();
    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCAPI ::std::shared_ptr<::BlockActor> $newBlockEntity(::BlockPos const& pos, ::Block const& block) const;

    MCAPI ::Block const* $getNextBlockPermutation(::Block const& currentBlock) const;

    MCFOLD bool
    $hasTag(::BlockSource& region, ::BlockPos const& pos, ::Block const& block, ::std::string const& tagName) const;

    MCAPI ::HitResult $clip(
        ::Block const&                                     block,
        ::BlockSource const&                               region,
        ::BlockPos const&                                  pos,
        ::Vec3 const&                                      A,
        ::Vec3 const&                                      B,
        ::ShapeType                                        shapeType,
        ::optional_ref<::GetCollisionShapeInterface const> entity
    ) const;

    MCAPI ::AABB $getCollisionShape(
        ::Block const& block,
        ::IConstBlockSource const&,
        ::BlockPos const& pos,
        ::optional_ref<::GetCollisionShapeInterface const>
    ) const;

    MCAPI bool $getCollisionShapeForCamera(
        ::AABB&                    outAABB,
        ::Block const&             block,
        ::IConstBlockSource const& region,
        ::BlockPos const&          pos
    ) const;

    MCAPI bool $addCollisionShapes(
        ::Block const&                                     block,
        ::IConstBlockSource const&                         region,
        ::BlockPos const&                                  pos,
        ::AABB const*                                      intersectTestBox,
        ::std::vector<::AABB>&                             inoutBoxes,
        ::optional_ref<::GetCollisionShapeInterface const> entity
    ) const;

    MCAPI void $addAABBs(
        ::Block const&             block,
        ::IConstBlockSource const& region,
        ::BlockPos const&          pos,
        ::AABB const*              intersectTestBox,
        ::std::vector<::AABB>&     inoutBoxes
    ) const;

    MCAPI ::AABB const&
    $getOutline(::Block const& block, ::IConstBlockSource const&, ::BlockPos const& pos, ::AABB& bufferValue) const;

    MCFOLD ::AABB const& $getVisualShapeInWorld(
        ::Block const& block,
        ::IConstBlockSource const&,
        ::BlockPos const&,
        ::AABB& bufferAABB
    ) const;

    MCAPI ::AABB const& $getVisualShape(::Block const&, ::AABB&) const;

    MCAPI ::AABB const& $getUIShape(::Block const& block, ::AABB& bufferAABB) const;

    MCAPI bool
    $getLiquidClipVolume(::Block const& block, ::BlockSource& region, ::BlockPos const& pos, ::AABB& includeBox) const;

    MCAPI bool $isObstructingChests(::BlockSource& region, ::BlockPos const& pos, ::Block const& thisBlock) const;

    MCAPI ::Vec3 $randomlyModifyPosition(::BlockPos const& pos) const;

    MCFOLD void $onProjectileHit(::BlockSource&, ::BlockPos const&, ::Actor const&) const;

    MCFOLD void $onLightningHit(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD bool $liquidCanFlowIntoFromDirection(
        uchar                                                     flowIntoFacing,
        ::std::function<::Block const&(::BlockPos const&)> const& getBlock,
        ::BlockPos const&                                         pos
    ) const;

    MCFOLD bool $hasVariableLighting() const;

    MCFOLD bool $isStrippable(::Block const& srcBlock) const;

    MCFOLD ::Block const& $getStrippedBlock(::Block const& srcBlock) const;

    MCAPI bool $canProvideMultifaceSupport(::Block const& block, uchar face) const;

    MCAPI bool $canConnect(::Block const&, uchar toOther, ::Block const& thisBlock) const;

    MCFOLD bool $isMovingBlock() const;

    MCFOLD ::CopperBehavior const* $tryGetCopperBehavior() const;

    MCFOLD bool $isStemBlock() const;

    MCFOLD bool $isContainerBlock() const;

    MCFOLD bool $isCraftingBlock() const;

    MCAPI bool $isLavaBlocking() const;

    MCFOLD bool $isFenceBlock() const;

    MCFOLD bool $isFenceGateBlock() const;

    MCFOLD bool $isThinFenceBlock() const;

    MCFOLD bool $isWallBlock() const;

    MCFOLD bool $isStairBlock() const;

    MCFOLD bool $isSlabBlock() const;

    MCFOLD bool $isDoorBlock() const;

    MCFOLD bool $isRailBlock() const;

    MCFOLD bool $isButtonBlock() const;

    MCFOLD bool $isLeverBlock() const;

    MCFOLD bool $isCandleCakeBlock() const;

    MCFOLD bool $isMultifaceBlock() const;

    MCFOLD bool $isSignalSource() const;

    MCFOLD bool $isConsumerComponent() const;

    MCAPI bool $canBeOriginalSurface() const;

    MCFOLD bool $isSilentWhenJumpingOff() const;

    MCFOLD bool $isValidAuxValue(int value) const;

    MCFOLD bool $canFillAtPos(::BlockSource& region, ::BlockPos const& pos, ::Block const& block) const;

    MCFOLD ::Block const& $sanitizeFillBlock(::Block const& block) const;

    MCFOLD void $onFillBlock(::BlockSource& region, ::BlockPos const& pos, ::Block const& block) const;

    MCFOLD int $getDirectSignal(::BlockSource& region, ::BlockPos const& pos, int dir) const;

    MCAPI ::std::optional<::HashedString> $getRequiredMedium() const;

    MCFOLD bool
    $shouldConnectToRedstone(::BlockSource& region, ::BlockPos const& pos, ::Direction::Type direction) const;

    MCFOLD void
    $handlePrecipitation(::BlockSource& region, ::BlockPos const& pos, float downfallAmount, float temperature) const;

    MCAPI bool $canBeUsedInCommands(::BaseGameVersion const& baseGameVersion) const;

    MCFOLD bool $checkIsPathable(::Actor& entity, ::BlockPos const& lastPathPos, ::BlockPos const& pathPos) const;

    MCFOLD bool $shouldDispense(::BlockSource& region, ::Container& container) const;

    MCFOLD bool $dispense(::BlockSource& region, ::Container& container, int slot, ::Vec3 const& pos, uchar face) const;

    MCFOLD void
    $transformOnFall(::BlockSource& region, ::BlockPos const& pos, ::Actor* entity, float fallDistance) const;

    MCFOLD void $onRedstoneUpdate(::BlockSource& region, ::BlockPos const& pos, int strength, bool isFirstTime) const;

    MCFOLD void $onMove(::BlockSource& region, ::BlockPos const& from, ::BlockPos const& to) const;

    MCFOLD bool $detachesOnPistonMove(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD void $movedByPiston(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD void $onStructureBlockPlace(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD void $onStructureNeighborBlockPlace(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD void $setupRedstoneComponent(::BlockSource& region, ::BlockPos const& pos) const;

    MCAPI void $updateEntityAfterFallOn(::BlockPos const& pos, ::UpdateEntityAfterFallOnInterface& entity) const;

    MCFOLD bool $isBounceBlock() const;

    MCFOLD bool $isPreservingMediumWhenPlaced(::BlockLegacy const* medium) const;

    MCFOLD bool $isFilteredOut(::BlockRenderLayer) const;

    MCFOLD bool $canRenderSelectionOverlay(::BlockRenderLayer) const;

    MCFOLD bool $ignoreEntitiesOnPistonMove(::Block const& block) const;

    MCFOLD bool
    $onFertilized(::BlockSource& region, ::BlockPos const& pos, ::Actor* actor, ::FertilizerType fType) const;

    MCFOLD bool $mayConsumeFertilizer(::BlockSource& region) const;

    MCFOLD bool $canBeFertilized(::BlockSource& region, ::BlockPos const& pos, ::Block const& aboveBlock) const;

    MCFOLD bool $mayPick() const;

    MCAPI bool $mayPick(::BlockSource const& region, ::Block const& block, bool liquid) const;

    MCFOLD bool $mayPlace(::BlockSource& region, ::BlockPos const& pos, uchar face) const;

    MCAPI bool $mayPlace(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD bool $mayPlaceOn(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD bool $tryToPlace(
        ::BlockSource&                 region,
        ::BlockPos const&              pos,
        ::Block const&                 block,
        ::ActorBlockSyncMessage const* syncMsg
    ) const;

    MCFOLD bool $tryToTill(::BlockSource& region, ::BlockPos const& pos, ::Actor& entity, ::ItemStack& item) const;

    MCFOLD bool $breaksFallingBlocks(::Block const& block, ::BaseGameVersion const version) const;

    MCFOLD void
    $destroy(::BlockSource& region, ::BlockPos const& pos, ::Block const& block, ::Actor* entitySource) const;

    MCFOLD bool $getIgnoresDestroyPermissions(::Actor& entity, ::BlockPos const& pos) const;

    MCFOLD void $neighborChanged(::BlockSource& region, ::BlockPos const& pos, ::BlockPos const& neighborPos) const;

    MCFOLD bool $getSecondPart(::IConstBlockSource const& region, ::BlockPos const& pos, ::BlockPos& out) const;

    MCAPI ::Block const* $playerWillDestroy(::Player& player, ::BlockPos const& pos, ::Block const& block) const;

    MCAPI ::ItemInstance $asItemInstance(::Block const&, ::BlockActor const*) const;

    MCFOLD void
    $spawnAfterBreak(::BlockSource&, ::Block const&, ::BlockPos const&, ::ResourceDropsContext const&) const;

    MCAPI ::Block const& $getPlacementBlock(
        ::Actor const&    by,
        ::BlockPos const& pos,
        uchar             face,
        ::Vec3 const&     clickPos,
        int               itemValue
    ) const;

    MCAPI int $calcVariant(::BlockSource& region, ::BlockPos const& pos, ::mce::Color const& baseColor) const;

    MCFOLD bool $isAttachedTo(::BlockSource& region, ::BlockPos const& pos, ::BlockPos& outAttachedTo) const;

    MCFOLD bool $attack(::Player* player, ::BlockPos const& pos) const;

    MCAPI bool $shouldTriggerEntityInside(::BlockSource& region, ::BlockPos const& pos, ::Actor& entity) const;

    MCAPI bool $canBeBuiltOver(
        ::Block const&     block,
        ::BlockSource&     region,
        ::BlockPos const&  pos,
        ::BlockItem const& newItem
    ) const;

    MCAPI bool $canBeBuiltOver(::Block const& block, ::BlockSource&, ::BlockPos const&) const;

    MCFOLD void $triggerEvent(::BlockSource& region, ::BlockPos const& pos, int b0, int b1) const;

    MCAPI void $executeEvent(
        ::BlockSource&       region,
        ::BlockPos const&    pos,
        ::Block const&       block,
        ::std::string const& eventName,
        ::Actor&             sourceEntity
    ) const;

    MCAPI ::MobSpawnerData const* $getMobToSpawn(::SpawnConditions const& conditions, ::BlockSource& region) const;

    MCAPI bool $shouldStopFalling(::Actor& entity) const;

    MCFOLD bool $pushesUpFallingBlocks() const;

    MCFOLD bool $canHaveExtraData() const;

    MCFOLD bool $hasComparatorSignal() const;

    MCFOLD int
    $getComparatorSignal(::BlockSource& region, ::BlockPos const& pos, ::Block const& block, uchar dir) const;

    MCAPI bool $canSlide(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD bool $canInstatick() const;

    MCFOLD bool $canSpawnAt(::BlockSource const& region, ::BlockPos const& pos) const;

    MCFOLD void $notifySpawnedAt(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD bool $causesFreezeEffect() const;

    MCFOLD ::std::string $buildDescriptionId(::Block const&) const;

    MCFOLD bool $isAuxValueRelevantForPicking() const;

    MCFOLD bool $isSeasonTinted(::Block const& block, ::BlockSource& region, ::BlockPos const& p) const;

    MCAPI void $onGraphicsModeChanged(::BlockGraphicsModeChangeContext const& context);

    MCAPI float $getShadeBrightness(::Block const& block) const;

    MCAPI int $telemetryVariant(::BlockSource& region, ::BlockPos const& pos) const;

    MCAPI int $getVariant(::Block const& block) const;

    MCFOLD bool $canSpawnOn(::Actor*) const;

    MCFOLD ::Block const& $getRenderBlock() const;

    MCFOLD uchar $getMappedFace(uchar face, ::Block const& block) const;

    MCFOLD ::Flip $getFaceFlip(uchar face, ::Block const& block) const;

    MCFOLD void $animateTickBedrockLegacy(::BlockAnimateTickData const&) const;

    MCFOLD void $animateTick(::BlockAnimateTickData const&) const;

    MCFOLD ::BlockLegacy& $init();

    MCAPI ::Brightness $getLightEmission(::Block const&) const;

    MCFOLD ::Block const* $tryLegacyUpgrade(ushort) const;

    MCFOLD bool $dealsContactDamage(::Actor const& actor, ::Block const& block, bool isPathFinding) const;

    MCFOLD ::Block const* $tryGetInfested(::Block const&) const;

    MCFOLD ::Block const* $tryGetUninfested(::Block const&) const;

    MCFOLD void $_addHardCodedBlockComponents(::Experiments const&);

    MCFOLD void $onRemove(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD void $onExploded(::BlockSource& region, ::BlockPos const& pos, ::Actor* entitySource) const;

    MCFOLD void $onStandOn(::EntityContext& entity, ::BlockPos const& pos) const;

    MCFOLD bool $shouldTickOnSetBlock() const;

    MCFOLD void $randomTick(::BlockSource&, ::BlockPos const&, ::Random&) const;

    MCFOLD bool $isInteractiveBlock() const;

    MCFOLD bool $allowStateMismatchOnPlacement(::Block const& clientTarget, ::Block const& serverTarget) const;

    MCFOLD bool $canSurvive(::BlockSource& region, ::BlockPos const& pos) const;

    MCAPI ::BlockRenderLayer $getRenderLayer(::Block const& block, ::BlockSource&, ::BlockPos const& pos) const;

    MCFOLD int $getExtraRenderLayers() const;

    MCAPI ::HashedString const& $getCullingLayer() const;

    MCAPI ::Brightness $getLight(::Block const&) const;

    MCFOLD ::Brightness $getEmissiveBrightness(::Block const&) const;

    MCFOLD ::mce::Color $getMapColor(::BlockSource&, ::BlockPos const&, ::Block const&) const;

    MCFOLD void $_onHitByActivatingAttack(::BlockSource&, ::BlockPos const&, ::Actor*) const;

    MCFOLD void $entityInside(::BlockSource&, ::BlockPos const&, ::Actor&) const;
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
