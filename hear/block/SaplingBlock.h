#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/world/item/FertilizerType.h"
#include "mc/world/level/block/FoliageBlock.h"

// auto generated forward declare list
// clang-format off
class Actor;
class Block;
class BlockPos;
class BlockSource;
class Experiments;
class Random;
namespace BlockEvents { class BlockRandomTickEvent; }
// clang-format on

// 代表树苗方块的类。
// 继承自 FoliageBlock，并实现了树苗特有的生长逻辑，包括自然生长和使用骨粉催生。
class SaplingBlock : public ::FoliageBlock {
public:
    // member variables
    // 成员变量
    // NOLINTBEGIN
    // 单个树苗生长成的树的特征名称（在数据驱动的世界生成中使用）。
    ::ll::TypedStorage<8, 40, ::std::optional<::std::string>> mSingleSaplingTree;
    // 单个树苗生长成的带蜂巢的树的特征名称。
    ::ll::TypedStorage<8, 40, ::std::optional<::std::string>> mSingleSaplingTreeWithBeehive;
    // 2x2 的树苗组合生长成的巨型树的特征名称。
    ::ll::TypedStorage<8, 40, ::std::optional<::std::string>> mQuadrupleSaplingTree;
    // NOLINTEND

public:
    // prevent constructor by default
    // 默认禁止构造函数
    SaplingBlock();

public:
    // virtual functions
    // 虚函数
    // NOLINTBEGIN
    // vIndex: 78
    // 检查树苗是否可以在指定位置放置。
    virtual bool mayPlace(::BlockSource& region, ::BlockPos const& pos) const /*override*/;

    // vIndex: 73
    // 当被施肥（如使用骨粉）时调用，尝试催生树木。
    virtual bool
    onFertilized(::BlockSource& region, ::BlockPos const& pos, ::Actor* actor, ::FertilizerType fType) const
        /*override*/;

    // vIndex: 75
    // 检查树苗是否可以被施肥（是否能被催生）。
    virtual bool canBeFertilized(::BlockSource& region, ::BlockPos const& pos, ::Block const& aboveBlock) const
        /*override*/;

    // vIndex: 130
    // 添加硬编码的方块组件。
    virtual void _addHardCodedBlockComponents(::Experiments const& experiments) /*override*/;

    // vIndex: 0
    virtual ~SaplingBlock() /*override*/ = default;
    // NOLINTEND

public:
    // member functions
    // 成员函数
    // NOLINTBEGIN
    // 构造函数
    MCAPI SaplingBlock(
        ::std::string const&           nameId,
        int                            id,
        ::std::optional<::std::string> singleSaplingTree,
        ::std::optional<::std::string> singleSaplingTreeWithBeehive,
        ::std::optional<::std::string> quadrupleSaplingTree
    );

    // 内部函数，处理树苗的生长逻辑。
    MCAPI bool _age(::BlockSource& region, ::BlockPos const& pos, ::Random& random) const;

    // 内部函数，获取 2x2 树苗组合的左上角位置。
    MCAPI ::std::optional<::BlockPos>
    _getQuadrupleSaplingOffset(::BlockSource const& region, ::BlockPos const& pos) const;

    // 内部函数，根据特征名称在指定位置放置树木。
    MCAPI bool _placeFeature(
        ::BlockSource&              region,
        ::BlockPos const&           pos,
        ::std::optional<::BlockPos> quadrupleSaplingOffset,
        ::std::string const&        featureName,
        ::Random&                   random
    ) const;

    // 内部函数，放置树木。
    MCAPI bool _placeTree(::BlockSource& region, ::BlockPos const& pos, ::Random& random) const;

    // 内部函数，在不触发方块更新的情况下设置方块（用于生成树木时）。
    MCAPI void _setBlockNoUpdate(
        ::BlockSource&              region,
        ::BlockPos const&           pos,
        ::std::optional<::BlockPos> quadrupleSaplingOffset,
        ::Block const&              block
    ) const;

    // 当接收到随机刻时调用，尝试自然生长。
    MCAPI void randomTick(::BlockEvents::BlockRandomTickEvent& eventData) const;
    // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::std::string const&           nameId,
        int                            id,
        ::std::optional<::std::string> singleSaplingTree,
        ::std::optional<::std::string> singleSaplingTreeWithBeehive,
        ::std::optional<::std::string> quadrupleSaplingTree
    );
    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCAPI bool $mayPlace(::BlockSource& region, ::BlockPos const& pos) const;

    MCAPI bool
    $onFertilized(::BlockSource& region, ::BlockPos const& pos, ::Actor* actor, ::FertilizerType fType) const;

    MCFOLD bool $canBeFertilized(::BlockSource& region, ::BlockPos const& pos, ::Block const& aboveBlock) const;

    MCAPI void $_addHardCodedBlockComponents(::Experiments const& experiments);
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
