#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/utility/optional_ref.h"
#include "mc/world/item/FertilizerType.h"
#include "mc/world/level/block/BlockLegacy.h"

// auto generated forward declare list
// clang-format off
class AABB;
class Block;
class BlockPos;
class BlockSource;
class Experiments;
class GetCollisionShapeInterface;
class IConstBlockSource;
class Vec3;
namespace BlockEvents { class BlockQueuedTickEvent; }
// clang-format on

// 代表植物类方块的基类，如花、草、作物、树苗等。
// 继承自 BlockLegacy，并提供了植物通用的行为。
class FoliageBlock : public ::BlockLegacy {
public:
    // virtual functions
    // 虚函数
    // NOLINTBEGIN
    // vIndex: 86
    // 当邻居方块发生变化时调用。通常用于检查下方的支撑方块是否仍然存在。
    virtual void neighborChanged(::BlockSource& region, ::BlockPos const& pos, ::BlockPos const& neighborPos) const
        /*override*/;

    // vIndex: 147
    // 当方块被计划更新时调用（通过 BlockQueuedTickEvent）。
    virtual void tick(::BlockEvents::BlockQueuedTickEvent& eventData) const;

    // vIndex: 138
    // 检查方块是否能在当前位置存活。例如，树苗需要放在泥土上。
    virtual bool canSurvive(::BlockSource& region, ::BlockPos const& pos) const /*override*/;

    // vIndex: 5
    // 获取方块的碰撞箱。对于大多数植物来说，这个碰撞箱是空的，因为实体可以穿过它们。
    virtual ::AABB
    getCollisionShape(::Block const&, ::IConstBlockSource const&, ::BlockPos const&, ::optional_ref<::GetCollisionShapeInterface const>)
        const /*override*/;

    // vIndex: 130
    // 添加硬编码的方块组件。
    virtual void _addHardCodedBlockComponents(::Experiments const&) /*override*/;

    // vIndex: 80
    // 检查此方块是否可以放置在目标方块上。
    virtual bool mayPlaceOn(::BlockSource& region, ::BlockPos const& pos) const /*override*/;

    // vIndex: 148
    // 检查方块是否存活，如果不存活则破坏自身。
    virtual void checkAlive(::BlockSource& region, ::BlockPos const& pos) const;

    // vIndex: 149
    // 设置方块的生长阶段。
    virtual ::Block const&
    setGrowth(::BlockSource& region, ::BlockPos const& pos, ::Block const& baseBlock, ushort newGrowth, int updateFlags)
        const;

    // vIndex: 0
    virtual ~FoliageBlock() /*override*/;
    // NOLINTEND

public:
    // member functions
    // 成员函数
    // NOLINTBEGIN
    // 尝试使作物生长，通常是使用骨粉等肥料的结果。
    MCAPI bool growCrops(::BlockSource& region, ::BlockPos const& pos, ::FertilizerType fType) const;
    // NOLINTEND

public:
    // static variables
    // 静态变量
    // NOLINTBEGIN
    // 定义了像灌木一样的植物的可视形状的AABB（包围盒）的最大值。
    MCAPI static ::Vec3 const& BUSH_VISUAL_SHAPE_MAX();

    // 定义了像灌木一样的植物的可视形状的AABB（包围盒）的最小值。
    MCAPI static ::Vec3 const& BUSH_VISUAL_SHAPE_MIN();
    // NOLINTEND
public:
    // destructor thunk
    // NOLINTBEGIN
    MCFOLD void $dtor();
    // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCFOLD void $neighborChanged(::BlockSource& region, ::BlockPos const& pos, ::BlockPos const& neighborPos) const;

    MCFOLD void $tick(::BlockEvents::BlockQueuedTickEvent& eventData) const;

    MCFOLD bool $canSurvive(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD ::AABB
    $getCollisionShape(::Block const&, ::IConstBlockSource const&, ::BlockPos const&, ::optional_ref<::GetCollisionShapeInterface const>)
        const;

    MCFOLD void $_addHardCodedBlockComponents(::Experiments const&);

    MCAPI bool $mayPlaceOn(::BlockSource& region, ::BlockPos const& pos) const;

    MCFOLD void $checkAlive(::BlockSource& region, ::BlockPos const& pos) const;

    MCAPI ::Block const& $setGrowth(
        ::BlockSource&    region,
        ::BlockPos const& pos,
        ::Block const&    baseBlock,
        ushort            newGrowth,
        int               updateFlags
    ) const;
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
