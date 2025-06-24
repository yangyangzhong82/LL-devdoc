#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/core/math/Color.h"
#include "mc/deps/core/math/Vec3.h"
#include "mc/deps/core/string/HashedString.h"
#include "mc/deps/core/utility/AutomaticID.h"
#include "mc/deps/core/utility/optional_ref.h"
#include "mc/deps/ecs/gamerefs_entity/EntityContext.h"
#include "mc/deps/game_refs/StackRefResult.h"
#include "mc/deps/game_refs/WeakRef.h"
#include "mc/deps/input/InputMode.h"
#include "mc/deps/shared_types/legacy/LevelSoundEvent.h"
#include "mc/deps/shared_types/legacy/actor/ActorDamageCause.h"
#include "mc/deps/shared_types/legacy/actor/ActorLocation.h"
#include "mc/deps/shared_types/legacy/actor/ArmorSlot.h"
#include "mc/deps/shared_types/legacy/item/EquipmentSlot.h"
#include "mc/input/NewInteractionModel.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/server/commands/CommandPermissionLevel.h"
#include "mc/util/MolangVariableMap.h"
#include "mc/util/VariantParameterList.h"
#include "mc/world/actor/ActorCategory.h"
#include "mc/world/actor/ActorDefinitionPtr.h"
#include "mc/world/actor/ActorEvent.h"
#include "mc/world/actor/ActorFlags.h"
#include "mc/world/actor/ActorInitializationMethod.h"
#include "mc/world/actor/ActorResetRule.h"
#include "mc/world/actor/ActorTerrainInterlockData.h"
#include "mc/world/actor/ActorType.h"
#include "mc/world/actor/ArmorMaterialType.h"
#include "mc/world/actor/BuiltInActorComponents.h"
#include "mc/world/actor/SpawnRuleEnum.h"
#include "mc/world/actor/SynchedActorDataEntityWrapper.h"
#include "mc/world/actor/animation/AnimationComponentGroupType.h"
#include "mc/world/item/HandSlot.h"
#include "mc/world/item/ItemUseMethod.h"
#include "mc/world/level/ShapeType.h"
#include "mc/world/level/material/MaterialType.h"

// auto generated forward declare list
// clang-format off
class AABB;
class ActionEvent;
class ActionQueue;
class ActorDamageSource;
class ActorDefinitionDescriptor;
class ActorDefinitionDiffList;
class ActorDefinitionGroup;
class ActorInteraction;
class ActorRuntimeID;
class AddActorBasePacket;
class AnimationComponent;
class Attribute;
class AttributeInstance;
class BaseAttributeMap;
class Block;
class BlockPos;
class BlockSource;
class ChangeDimensionPacket;
class CompoundTag;
class DataLoadHelper;
class Dimension;
class DynamicProperties;
class EntityRegistry;
class GameEvent;
class GetCollisionShapeInterface;
class IConstBlockSource;
class ILevel;
class ItemActor;
class ItemDescriptor;
class ItemStack;
class ItemStackBase;
class ListTag;
class LootTable;
class MerchantRecipeList;
class Mob;
class MobEffect;
class MobEffectInstance;
class Options;
class Player;
class Random;
class RenderParams;
class RideableComponent;
class RopeSystem;
class SpatialActorNetworkData;
class StrictEntityContext;
class UpdateEquipPacket;
class Vec2;
struct ActorDefinitionIdentifier;
struct ActorLink;
struct DistanceSortedActor;
struct EquipmentTable;
struct MutableAttributeWithContext;
namespace Bedrock::Safety { class RedactableString; }
namespace MovementDataExtractionUtility { class SnapshotAccessor; }
// clang-format on

class Level;

class Actor {
public:
    // Actor 内部类型定义
    using EntityBlockCollisionCallback =
        ::std::function<void(::BlockSource&, ::Block const&, ::BlockPos const&, ::Actor&)>;
    // 定义一个名为 EntityBlockCollisionCallback 的回调函数类型
    // 用于处理实体与方块的碰撞事件

public:
    // LLAPI/LLNDAPI 函数

    /**
     * @brief 获取实体上下文
     * @return 实体上下文的引用
     */
    LLNDAPI class EntityContext& getEntityContext();

    /**
     * @brief 获取实体上下文 (常量版本)
     * @return 实体上下文的常量引用
     */
    LLNDAPI class EntityContext const& getEntityContext() const;

    /**
     * @brief 刷新Actor
     * @remarks 通常用于重新加载组件或属性
     */
    LLAPI void refresh();

    /**
     * @brief 克隆此Actor
     * @param pos 克隆体生成的位置
     * @param dimId (可选) 克隆体生成的目标维度ID。如果为nullopt，则在当前维度生成
     * @return 克隆出的Actor的可选引用 (optional_ref)。如果克隆失败，则为空
     */
    LLAPI optional_ref<Actor> clone(Vec3 const& pos, std::optional<DimensionType> dimId = std::nullopt) const;

    /**
     * @brief 获取Actor的类型名称
     * @return Actor的类型名称字符串 (例如 "minecraft:creeper")
     */
    LLNDAPI std::string const& getTypeName() const;

    /**
     * @brief 获取Actor脚部的位置
     * @return 一个表示脚部位置的Vec3向量
     */
    LLNDAPI class Vec3 getFeetPos() const;

    /**
     * @brief 获取Actor头部的位置
     * @return 一个表示头部位置的Vec3向量
     */
    LLNDAPI class Vec3 getHeadPos() const;

    /**
     * @brief 获取Actor脚部所在的方块位置
     * @return 一个表示脚部方块位置的BlockPos
     */
    LLNDAPI class BlockPos getFeetBlockPos() const;

    /**
     * @brief 判断此Actor是否为模拟玩家 (Simulated Player)
     * @return 如果是模拟玩家则返回true，否则返回false
     */
    LLNDAPI bool isSimulatedPlayer() const;

    /**
     * @brief 判断Actor是否在地面上
     * @return 如果在地面上则返回true，否则返回false
     */
    LLNDAPI bool isOnGround() const;

    /**
     * @brief 使Actor着火
     * @param time 着火的持续时间 (单位：刻 tick)
     * @param isEffect (可选) 是否作为效果施加。默认为true
     */
    LLAPI void setOnFire(int time, bool isEffect = true);

    /**
     * @brief 熄灭Actor身上的火
     */
    LLAPI void stopFire();

    /**
     * @brief 获取Actor的速度
     * @return 一个表示速度的Vec3向量
     */
    LLNDAPI Vec3 getVelocity() const;

    /**
     * @brief 获取Actor每秒位置增量的长度 (即速度大小)
     * @return 速度大小
     */
    LLNDAPI float getPosDeltaPerSecLength() const;

    /**
     * @brief 通过指定原因使Actor受伤
     * @param damage 伤害值
     * @param cause (可选) 伤害原因。默认为 ActorDamageCause::Override
     * @param attacker (可选) 攻击者
     * @return 操作是否成功
     */
    LLAPI bool hurtByCause(
        float                                   damage,
        ::SharedTypes::Legacy::ActorDamageCause cause    = ::SharedTypes::Legacy::ActorDamageCause::Override,
        optional_ref<Actor>                     attacker = std::nullopt
    );

    /**
     * @brief 从Actor的视角进行射线追踪
     * @param tMax (可选) 射线的最大距离。默认为5.5格
     * @param includeActor (可选) 是否将其他Actor作为目标。默认为true
     * @param includeBlock (可选) 是否将方块作为目标。默认为true
     * @param blockCheckFunction (可选) 一个自定义函数，用于过滤哪些方块可以被追踪到。
     * @return 射线追踪的结果 (HitResult)
     */
    LLNDAPI class HitResult traceRay(
        float                                                                          tMax         = 5.5f,
        bool                                                                           includeActor = true,
        bool                                                                           includeBlock = true,
        std::function<bool(class BlockSource const&, class Block const&, bool)> const& blockCheckFunction =
            [](auto&&...) -> bool { return true; }
    ) const;

    /**
     * @brief 将Actor传送到指定位置和维度，并设置旋转
     * @param pos 目标位置
     * @param dimId 目标维度ID
     * @param rotation 目标朝向 (x-pitch, y-yaw)
     */
    LLAPI void teleport(class Vec3 const& pos, DimensionType dimId, class Vec2 const& rotation);

    /**
     * @brief 将Actor传送到指定位置和维度
     * @param pos 目标位置
     * @param dimId 目标维度ID
     */
    LLAPI void teleport(class Vec3 const& pos, DimensionType dimId);

    /**
     * @brief 设置Actor的自定义名称 (NameTag)
     * @param name 新的名称
     */
    LLAPI void setName(std::string const& name);

    /**
     * @brief 在此Actor的上下文中解析并评估一个Molang表达式
     * @param expression Molang表达式字符串
     * @return 表达式的浮点数结果
     */
    LLNDAPI float evalMolang(std::string const& expression);


    /**
     * @brief 获取Actor的碰撞箱 (Axis-Aligned Bounding Box)
     * @return 碰撞箱的常量引用
     */
    LLNDAPI const AABB& getAABB() const;

    /**
     * @brief 尝试从实体上下文获取Actor指针
     * @param entity 实体上下文
     * @param includeRemoved 是否包括已移除的Actor
     * @return 指向Actor的指针，如果获取失败则为nullptr
     */
    LLAPI static ::Actor* tryGetFromEntity(::EntityContext& entity, bool includeRemoved);

    /**
     * @brief 获取Actor所在的世界 (Level)
     * @return Level的引用
     * @remarks 这是一个内联函数，直接从成员变量 mLevel 获取
     */
    [[nodiscard]] Level& getLevel() const { return *reinterpret_cast<Level*>(mLevel); }


public:
    // member variables
    // NOLINTBEGIN
public:
    // member variables
    // 成员变量
    // NOLINTBEGIN (忽略特定代码风格检查的宏)

    // 实体上下文，管理实体的ECS（实体组件系统）相关数据
    ::ll::TypedStorage<8, 24, ::EntityContext> mEntityContext;

    // 变体参数列表，用于Actor初始化
    ::ll::TypedStorage<8, 72, ::VariantParameterList> mInitParams;

    // 自定义初始化事件名称
    ::ll::TypedStorage<8, 32, ::std::string> mCustomInitEventName;

    // Actor的初始化方法
    ::ll::TypedStorage<1, 1, ::ActorInitializationMethod> mInitMethod;

    // 是否在重载时强制使用生成（Spawn）的初始化方法
    ::ll::TypedStorage<1, 1, bool> mForceInitMethodToSpawnOnReload;

    // Actor是否已添加到世界中
    ::ll::TypedStorage<1, 1, bool> mAdded;

    // Actor的定义组，包含其行为、组件等定义
    ::ll::TypedStorage<8, 8, ::ActorDefinitionGroup*> mDefinitions;

    // 当前Actor的描述符，指向一个描述其属性的唯一指针
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ActorDefinitionDescriptor>> mCurrentDescription;

    // 拴绳的绳索系统，管理拴绳的视觉效果和物理行为
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::RopeSystem>> mLeashRopeSystem;

    // Actor的别名
    ::ll::TypedStorage<8, 32, ::std::string> mAlias;

    // 上一帧的渲染变换矩阵
    ::ll::TypedStorage<4, 68, ::std::optional<::glm::mat4x4>> mPreviousRenderTransform;

    // 上次被玩家伤害的时间
    ::ll::TypedStorage<4, 4, int> mLastHurtByPlayerTime;

    // 上一帧的骨骼矩阵，用于动画插值
    ::ll::TypedStorage<8, 16, ::std::map<::HashedString, ::std::vector<::std::vector<::glm::mat4x4>>>>
        mPreviousBoneMatrices;

    // 同步的Actor数据实体包装器，管理需要网络同步的数据
    ::ll::TypedStorage<8, 48, ::SynchedActorDataEntityWrapper> mEntityData;

    // 空间网络数据，用于优化网络传输
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::SpatialActorNetworkData>> mNetworkData;

    // 已发送的位置增量
    ::ll::TypedStorage<4, 12, ::Vec3> mSentDelta;

    // 当前缩放比例
    ::ll::TypedStorage<4, 4, float> mScale;

    // 上一帧的缩放比例
    ::ll::TypedStorage<4, 4, float> mScalePrev;

    // 是否忽略光照
    ::ll::TypedStorage<1, 1, bool> mIgnoreLighting;

    // 是否过滤光照
    ::ll::TypedStorage<1, 1, bool> mFilterLighting;

    // 脚步声音量
    ::ll::TypedStorage<4, 4, float> mStepSoundVolume;

    // 脚步声音调
    ::ll::TypedStorage<4, 4, float> mStepSoundPitch;

    // 上次被击中的碰撞箱
    ::ll::TypedStorage<8, 8, ::AABB*> mLastHitBB;

    // 名字标签的哈希值
    ::ll::TypedStorage<8, 8, uint64> mNameTagHash;

    // 阴影偏移
    ::ll::TypedStorage<4, 4, float> mShadowOffset;

    // 推挤穿透值
    ::ll::TypedStorage<4, 4, float> mPushthrough;

    // 存活的游戏刻数
    ::ll::TypedStorage<4, 4, int> mTickCount;

    // 无敌时间
    ::ll::TypedStorage<4, 4, int> mInvulnerableTime;

    // 上次的生命值
    ::ll::TypedStorage<4, 4, int> mLastHealth;

    // 是否被标记为受伤（用于视觉效果）
    ::ll::TypedStorage<1, 1, bool> mHurtMarked;

    // 上一帧是否受伤
    ::ll::TypedStorage<1, 1, bool> mWasHurtLastFrame;

    // 是否无敌
    ::ll::TypedStorage<1, 1, bool> mInvulnerable;

    // 火焰纹理的帧索引
    ::ll::TypedStorage<4, 4, int> mFlameTexFrameIndex;

    // 火焰帧增量时间
    ::ll::TypedStorage<4, 4, float> mFlameFrameIncrementTime;

    // 是否始终免疫火焰伤害
    ::ll::TypedStorage<1, 1, bool> mAlwaysFireImmune;

    // 骑乘时是否继承旋转
    ::ll::TypedStorage<1, 1, bool> mInheritRotationWhenRiding;

    // 是否强制加载区块
    ::ll::TypedStorage<1, 1, bool> mForcedLoading;

    // 是否强制发送移动数据包
    ::ll::TypedStorage<1, 1, bool> mForceSendMotionPacket;

    // 在这一帧是否被高亮显示
    ::ll::TypedStorage<1, 1, bool> mHighlightedThisFrame;

    // 是否已初始化
    ::ll::TypedStorage<1, 1, bool> mInitialized;

    // 是否在区块丢弃时被处理过
    ::ll::TypedStorage<1, 1, bool> mProcessedOnChunkDiscard;

    // 声音音量
    ::ll::TypedStorage<4, 4, float> mSoundVolume;

    // 晃动时间（例如，被攻击时）
    ::ll::TypedStorage<4, 4, int> mShakeTime;

    // 旧版的唯一ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mLegacyUniqueID;

    // 所在的维度（弱引用）
    ::ll::TypedStorage<8, 16, ::WeakRef<::Dimension>> mDimension;

    // 所在的世界/关卡
    ::ll::TypedStorage<8, 8, ::ILevel*> mLevel;

    // Actor渲染器的ID
    ::ll::TypedStorage<8, 48, ::HashedString> mActorRendererId;

    // Actor的类别
    ::ll::TypedStorage<4, 4, ::ActorCategory> mCategories;

    // 内置的Actor组件
    ::ll::TypedStorage<8, 32, ::BuiltInActorComponents> mBuiltInComponents;

    // 初始化动画组件时使用的Actor渲染器ID
    ::ll::TypedStorage<8, 48, ::HashedString> mActorRendererIdThatAnimationComponentWasInitializedWith;

    // 状态是否已改变
    ::ll::TypedStorage<1, 1, bool> mChanged;

    // 是否已被移除
    ::ll::TypedStorage<1, 1, bool> mRemoved;

    // 是否被移动到“灵bo”状态（一种临时的、不活跃的状态）
    ::ll::TypedStorage<1, 1, bool> mMovedToLimbo;

    // 是否被移动到未加载的区块
    ::ll::TypedStorage<1, 1, bool> mMovedToUnloadedChunk;

    // 是否阻挡建筑
    ::ll::TypedStorage<1, 1, bool> mBlocksBuilding;

    // 动画组件
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::AnimationComponent>> mAnimationComponent;

    // UI动画组件
    ::ll::TypedStorage<8, 16, ::std::shared_ptr<::AnimationComponent>> mUIAnimationComponent;

    // 目标实体的ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mTargetId;

    // 恋爱中的伴侣实体的ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mInLovePartner;

    // 持久的交易数据（例如村民）
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::CompoundTag>> mPersistingTradeOffers;

    // 持久的交易财富值
    ::ll::TypedStorage<4, 4, int> mPersistingTradeRiches;

    // 是否在进行持久的交易
    ::ll::TypedStorage<1, 1, bool> mPersistingTrade;

    // 效果（药水等）是否需要更新
    ::ll::TypedStorage<1, 1, bool> mEffectsDirty;

    // 战利品是否已掉落
    ::ll::TypedStorage<1, 1, bool> mLootDropped;

    // 在这一帧是否从NBT加载
    ::ll::TypedStorage<1, 1, bool> mLoadedFromNBTThisFrame;

    // 受伤时显示的颜色
    ::ll::TypedStorage<4, 16, ::mce::Color> mHurtColor;

    // Actor定义差异列表，用于动态修改Actor属性
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ActorDefinitionDiffList>> mDefinitionList;

    // 从NBT加载的Actor属性标签
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::CompoundTag>> mLoadedActorPropertyTag;

    // 指向Actor定义的指针
    ::ll::TypedStorage<8, 16, ::ActorDefinitionPtr> mActorDefinitionPtr;

    // 过滤后的名字标签（例如，处理了颜色代码）
    ::ll::TypedStorage<8, 32, ::std::string> mFilteredNameTag;

    // Actor与地形的交互数据
    ::ll::TypedStorage<8, 24, ::ActorTerrainInterlockData> mTerrainInterlockData;

    // 上次伤害此Actor的生物ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mLastHurtMobId;

    // 上次被哪个生物伤害的ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mLastHurtByMobId;

    // 上次被哪个玩家伤害的ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mLastHurtByPlayerId;

    // 上次受伤的时间戳
    ::ll::TypedStorage<8, 8, uint64> mLastHurtTimestamp;

    // 上次的伤害原因
    ::ll::TypedStorage<4, 4, ::SharedTypes::Legacy::ActorDamageCause> mLastHurtCause;

    // 上次的伤害值
    ::ll::TypedStorage<4, 4, float> mLastHurt;

    // 上次伤害此Actor的生物的时间戳
    ::ll::TypedStorage<4, 4, int> mLastHurtMobTimestamp;

    // 上次被生物伤害的时间
    ::ll::TypedStorage<4, 4, int> mLastHurtByMobTime;

    // 上次被生物伤害的时间戳
    ::ll::TypedStorage<4, 4, int> mLastHurtByMobTimestamp;

    // 是否是可预测的弹射物
    ::ll::TypedStorage<1, 1, bool> mIsPredictableProjectile;

    // 是否在UI中渲染
    ::ll::TypedStorage<1, 1, bool> mIsRenderingInUI;

    // 是否更新效果
    ::ll::TypedStorage<1, 1, bool> mUpdateEffects;

    // 是否可以拾取物品
    ::ll::TypedStorage<1, 1, bool> mCanPickupItems;

    // 是否已经设置过 `mCanPickupItems`
    ::ll::TypedStorage<1, 1, bool> mHasSetCanPickupItems;

    // 是否具有连锁伤害效果
    ::ll::TypedStorage<1, 1, bool> mChainedDamageEffects;

    // 被水瓶影响后效果生效的剩余刻数
    ::ll::TypedStorage<4, 4, int> mAffectedByWaterBottleTicksToEffect;

    // 生成规则枚举
    ::ll::TypedStorage<4, 4, ::SpawnRuleEnum> mSpawnRulesEnum;

    // 行为队列，用于存储和执行Actor的行为
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ActionQueue>> mActionQueue;

    // Molang变量映射表，用于动画和行为
    ::ll::TypedStorage<8, 56, ::MolangVariableMap> mMolangVariables;

    // 鱼钩的ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mFishingHookID;
    // NOLINTEND

public:
    // prevent constructor by default
    // 默认禁止构造函数
    Actor();

public:
    // virtual functions
    // 虚函数
    // NOLINTBEGIN

    // vIndex: 0
    /**
     * @brief 检查Actor是否拥有指定名称的组件
     * @param name 组件的哈希字符串名称
     * @return 如果拥有该组件则返回true
     */
    virtual bool hasComponent(::HashedString const& name) const;

    // vIndex: 1
    /**
     * @brief 当Actor掉出世界时调用
     */
    virtual void outOfWorld();

    // vIndex: 2
    /**
     * @brief 重新加载硬编码的数据（服务器端）
     * @param method 初始化方法
     * @param params 变体参数列表
     */
    virtual void reloadHardcoded(::ActorInitializationMethod, ::VariantParameterList const&);

    // vIndex: 3
    /**
     * @brief 重新加载硬编码的数据（客户端）
     * @param method 初始化方法
     */
    virtual void reloadHardcodedClient(::ActorInitializationMethod);

    // vIndex: 4
    /**
     * @brief 初始化组件
     * @param method 初始化方法
     * @param params 变体参数列表
     */
    virtual void initializeComponents(::ActorInitializationMethod method, ::VariantParameterList const&);

    // vIndex: 5
    /**
     * @brief 重新加载组件
     * @param method 初始化方法
     * @param params 变体参数列表
     */
    virtual void reloadComponents(::ActorInitializationMethod, ::VariantParameterList const&);

    // vIndex: 6
    /**
     * @brief 在服务器端初始化物品堆栈的ID
     */
    virtual void _serverInitItemStackIds();

    // vIndex: 7
    /**
     * @brief 执行初始移动
     */
    virtual void _doInitialMove();

    // vIndex: 8
    /**
     * @brief 析构函数
     */
    virtual ~Actor();

    // vIndex: 9
    /**
     * @brief 根据规则重置用户位置
     * @param rule 重置规则
     */
    virtual void resetUserPos(::ActorResetRule);

    // vIndex: 10
    /**
     * @brief 获取所有者的实体类型
     * @return 所有者的实体类型
     */
    virtual ::ActorType getOwnerEntityType();

    // vIndex: 11
    /**
     * @brief 移除此Actor
     */
    virtual void remove();

    // vIndex: 12
    /**
     * @brief 获取开火位置（例如，箭矢射出的位置）
     * @return 开火位置的Vec3向量
     */
    virtual ::Vec3 getFiringPos() const;

    // vIndex: 13
    /**
     * @brief 获取插值计算后的身体旋转角度
     * @param a 插值因子 (通常是tick的百分比)
     * @return 身体旋转角度
     */
    virtual float getInterpolatedBodyRot(float a = 0.0f) const;

    // vIndex: 14
    /**
     * @brief 获取插值计算后的头部旋转角度
     * @param a 插值因子
     * @return 头部旋转角度
     */
    virtual float getInterpolatedHeadRot(float = 0.0f) const;

    // vIndex: 15
    /**
     * @brief 获取插值计算后的身体偏航角
     * @param a 插值因子
     * @return 身体偏航角
     */
    virtual float getInterpolatedBodyYaw(float = 0.0f) const;

    // vIndex: 16
    /**
     * @brief 获取每秒偏航角速度（单位：度）
     * @return 偏航角速度
     */
    virtual float getYawSpeedInDegreesPerSecond() const;

    // vIndex: 17
    /**
     * @brief 获取插值计算后的骑乘偏移量
     * @param a 插值因子
     * @param b 未知参数
     * @return 骑乘偏移量的Vec3向量
     */
    virtual ::Vec3 getInterpolatedRidingOffset(float, int const) const;

    // vIndex: 18
    /**
     * @brief 判断Actor是否免疫火焰伤害
     * @return 如果免疫则返回true
     */
    virtual bool isFireImmune() const;

    // vIndex: 19
    /**
     * @brief 当攻击被盾牌格挡时调用
     * @param source 伤害源
     * @param blocker 格挡此伤害的Actor
     */
    virtual void blockedByShield(::ActorDamageSource const& source, ::Actor& blocker);

    // vIndex: 20
    /**
     * @brief 判断是否可以禁用盾牌
     * @return 如果可以则返回true
     */
    virtual bool canDisableShield();

    // vIndex: 21
    /**
     * @brief 传送至指定位置
     * @param pos 目标位置
     * @param shouldStopRiding 是否应停止骑乘
     * @param param3 未知参数
     * @param param4 未知参数
     * @param keepVelocity 是否保持传送前的速度
     */
    virtual void teleportTo(::Vec3 const& pos, bool shouldStopRiding, int, int, bool keepVelocity);

    // vIndex: 22
    /**
     * @brief 对移动进行线性插值
     * @param delta 位置变化量
     */
    virtual void lerpMotion(::Vec3 const& delta);

    // vIndex: 23
    /**
     * @brief 尝试创建一个用于添加此Actor的网络数据包
     * @return 一个指向 AddActorBasePacket 的唯一指针，如果失败则为空
     */
    virtual ::std::unique_ptr<::AddActorBasePacket> tryCreateAddActorPacket();

    // vIndex: 24
    /**
     * @brief 普通的游戏刻更新 (Normal Tick)
     */
    virtual void normalTick();

    // vIndex: 25
    /**
     * @brief 基础的游戏刻更新 (Base Tick)
     */
    virtual void baseTick();

    // vIndex: 26
    /**
     * @brief 作为乘客时的游戏刻更新
     */
    virtual void passengerTick();

    // vIndex: 27
    /**
     * @brief 开始骑乘另一个Actor
     * @param vehicle 要骑乘的载具Actor
     * @param forceRiding 是否强制骑乘
     * @return 如果成功骑乘则返回true
     */
    virtual bool startRiding(::Actor& vehicle, bool forceRiding);

    // vIndex: 28
    /**
     * @brief 添加一个乘客
     * @param passenger 要添加的乘客Actor
     */
    virtual void addPassenger(::Actor& passenger);

    // vIndex: 29
    /**
     * @brief 获取离开载具的提示信息
     * @param kind 提示类型
     * @param mode 输入模式
     * @param scheme 新的交互模型
     * @return 提示字符串
     */
    virtual ::std::string getExitTip(::std::string const& kind, ::InputMode mode, ::NewInteractionModel scheme) const;

    // vIndex: 30
    /**
     * @brief 获取实体的本地化名称字符串
     * @return 本地化名称
     */
    virtual ::std::string getEntityLocNameString() const;

    // vIndex: 31
    /**
     * @brief 判断Actor是否隐身
     * @return 如果隐身则返回true
     */
    virtual bool isInvisible() const;

    // vIndex: 32
    /**
     * @brief 判断是否可以显示名字标签
     * @return 如果可以则返回true
     */
    virtual bool canShowNameTag() const;

    // vIndex: 33
    /**
     * @brief 获取格式化后的名字标签
     * @return 格式化后的名字标签字符串
     */
    virtual ::std::string getFormattedNameTag() const;

    // vIndex: 34
    /**
     * @brief 获取名字标签的文本颜色
     * @return 名字标签的颜色
     */
    virtual ::mce::Color getNameTagTextColor() const;

    // vIndex: 35
    /**
     * @brief 获取阴影的半径
     * @return 阴影半径
     */
    virtual float getShadowRadius() const;

    // vIndex: 36
    /**
     * @brief 获取头部朝向的向量
     * @param a 插值因子
     * @return 头部朝向的单位向量
     */
    virtual ::Vec3 getHeadLookVector(float a = 0.0f) const;

    // vIndex: 37
    /**
     * @brief 判断在游戏中是否能与其他实体交互
     * @return 如果可以则返回true
     */
    virtual bool canInteractWithOtherEntitiesInGame() const;

    // vIndex: 38
    /**
     * @brief 获取亮度
     * @param a 插值因子
     * @param region 所在的方块源
     * @return 亮度值
     */
    virtual float getBrightness(float a, ::IConstBlockSource const& region) const;

    // vIndex: 39
    /**
     * @brief 当被玩家触摸时调用
     * @param player 触摸的玩家
     */
    virtual void playerTouch(::Player&);

    // vIndex: 40
    /**
     * @brief 判断Actor是否无法移动
     * @return 如果无法移动则返回true
     */
    virtual bool isImmobile() const;

    // vIndex: 41
    /**
     * @brief 判断是否为沉默的观察者
     * @return 如果是则返回true
     */
    virtual bool isSilentObserver() const;

    // vIndex: 42
    /**
     * @brief 判断Actor是否在睡觉
     * @return 如果在睡觉则返回true
     */
    virtual bool isSleeping() const;

    // vIndex: 43
    /**
     * @brief 设置Actor的睡眠状态
     * @param value 是否睡觉
     */
    virtual void setSleeping(bool);

    // vIndex: 44
    /**
     * @brief 设置Actor的潜行状态
     * @param value 是否潜行
     */
    virtual void setSneaking(bool value);

    // vIndex: 45
    /**
     * @brief 判断Actor是否在格挡
     * @return 如果在格挡则返回true
     */
    virtual bool isBlocking() const;

    // vIndex: 46
    /**
     * @brief 判断伤害是否被格挡
     * @param source 伤害源
     * @return 如果伤害被格挡则返回true
     */
    virtual bool isDamageBlocked(::ActorDamageSource const&) const;

    // vIndex: 47
    /**
     * @brief 判断Actor是否存活
     * @return 如果存活则返回true
     */
    virtual bool isAlive() const;

    // vIndex: 48
    /**
     * @brief 判断Actor是否着火
     * @return 如果着火则返回true
     */
    virtual bool isOnFire() const;

    // vIndex: 49
    /**
     * @brief 判断是否为地表生物
     * @return 如果是则返回true
     */
    virtual bool isSurfaceMob() const;

    // vIndex: 50
    /**
     * @brief 判断Actor是否可作为目标
     * @return 如果可作为目标则返回true
     */
    virtual bool isTargetable() const;

    // vIndex: 51
    /**
     * @brief 设置目标
     * @param entity 目标Actor
     */
    virtual void setTarget(::Actor* entity);

    // vIndex: 52
    /**
     * @brief 判断一个Actor是否为有效目标
     * @param actor 待判断的Actor
     * @return 如果是有效目标则返回true
     */
    virtual bool isValidTarget(::Actor*) const;

    // vIndex: 53
    /**
     * @brief 攻击另一个Actor
     * @param target 被攻击的Actor
     * @param cause 伤害原因
     * @return 如果攻击成功则返回true
     */
    virtual bool attack(::Actor&, ::SharedTypes::Legacy::ActorDamageCause const&);

    // vIndex: 54
    /**
     * @brief 执行远程攻击
     * @param target 目标Actor
     * @param damage 伤害值
     */
    virtual void performRangedAttack(::Actor& target, float);

    // vIndex: 55
    /**
     * @brief 设置所有者
     * @param ownerId 所有者的唯一ID
     */
    virtual void setOwner(::ActorUniqueID const ownerId);

    // vIndex: 56
    /**
     * @brief 设置坐下状态
     * @param value 是否坐下
     */
    virtual void setSitting(bool value);

    // vIndex: 57
    /**
     * @brief 当被驯服时调用
     */
    virtual void onTame();

    // vIndex: 58
    /**
     * @brief 当驯服失败时调用
     */
    virtual void onFailedTame();

    // vIndex: 59
    /**
     * @brief 设置站立状态
     * @param value 是否站立
     */
    virtual void setStanding(bool value);

    // vIndex: 60
    /**
     * @brief 判断是否可以进行强力跳跃
     * @return 如果可以则返回true
     */
    virtual bool canPowerJump() const;

    // vIndex: 61
    /**
     * @brief 判断是否被附魔（例如，附魔光效）
     * @return 如果被附魔则返回true
     */
    virtual bool isEnchanted() const;

    // vIndex: 62
    /**
     * @brief 播放环境音效
     */
    virtual void playAmbientSound();

    // vIndex: 63
    /**
     * @brief 获取环境音效的事件类型
     * @return 环境音效事件
     */
    virtual ::SharedTypes::Legacy::LevelSoundEvent getAmbientSound() const;

    // vIndex: 64
    /**
     * @brief 判断是否对某个伤害源无敌
     * @param source 伤害源
     * @return 如果无敌则返回true
     */
    virtual bool isInvulnerableTo(::ActorDamageSource const& source) const;

    // vIndex: 65
    /**
     * @brief 获取由方块造成的伤害原因
     * @param block 造成伤害的方块
     * @return 伤害原因
     */
    virtual ::SharedTypes::Legacy::ActorDamageCause getBlockDamageCause(::Block const&) const;

    // vIndex: 66
    /**
     * @brief 执行火焰伤害
     * @param amount 伤害量
     * @return 如果成功造成伤害则返回true
     */
    virtual bool doFireHurt(int amount);

    // vIndex: 67
    /**
     * @brief 当被闪电击中时调用
     */
    virtual void onLightningHit();

    // vIndex: 68
    /**
     * @brief 喂食
     * @param itemId 喂食的物品ID
     */
    virtual void feed(int itemId);

    // vIndex: 69
    /**
     * @brief 处理实体事件
     * @param eventId 事件ID
     * @param data 事件相关数据
     */
    virtual void handleEntityEvent(::ActorEvent eventId, int data);

    // vIndex: 70
    /**
     * @brief 获取Actor渲染器的ID
     * @return 渲染器ID的哈希字符串
     */
    virtual ::HashedString const& getActorRendererId() const;

    // vIndex: 71
    /**
     * @brief 使Actor消失（通常在远离玩家时）
     */
    virtual void despawn();

    // vIndex: 72
    /**
     * @brief 设置盔甲
     * @param slot 盔甲槽位
     * @param item 盔甲物品
     */
    virtual void setArmor(::SharedTypes::Legacy::ArmorSlot slot, ::ItemStack const& item);

    // vIndex: 73
    /**
     * @brief 获取指定槽位盔甲的材质类型
     * @param slot 盔甲槽位
     * @return 盔甲材质类型
     */
    virtual ::ArmorMaterialType getArmorMaterialTypeInSlot(::SharedTypes::Legacy::ArmorSlot) const;

    // vIndex: 74
    /**
     * @brief 获取指定槽位盔甲的纹理索引
     * @param slot 盔甲槽位
     * @return 纹理索引
     */
    virtual int getArmorTextureIndexInSlot(::SharedTypes::Legacy::ArmorSlot) const;

    // vIndex: 75
    /**
     * @brief 获取指定槽位盔甲的颜色
     * @param slot 盔甲槽位
     * @param layer 颜色层（用于皮革甲）
     * @return 颜色值
     */
    virtual float getArmorColorInSlot(::SharedTypes::Legacy::ArmorSlot, int) const;

    // vIndex: 76
    /**
     * @brief 设置装备槽中的物品
     * @param slot 装备槽位
     * @param item 物品
     */
    virtual void setEquippedSlot(::SharedTypes::Legacy::EquipmentSlot, ::ItemStack const&);

    // vIndex: 77
    /**
     * @brief 设置主手持有的物品
     * @param item 物品
     */
    virtual void setCarriedItem(::ItemStack const& item);

    // vIndex: 78
    /**
     * @brief 获取主手持有的物品
     * @return 主手物品的常量引用
     */
    virtual ::ItemStack const& getCarriedItem() const;

    // vIndex: 79
    /**
     * @brief 设置副手持有的物品
     * @param item 物品
     */
    virtual void setOffhandSlot(::ItemStack const& item);

    // vIndex: 80
    /**
     * @brief 获取装备的图腾
     * @return 图腾物品的常量引用
     */
    virtual ::ItemStack const& getEquippedTotem() const;

    // vIndex: 81
    /**
     * @brief 消耗图腾
     * @return 如果成功消耗则返回true
     */
    virtual bool consumeTotem();

    // vIndex: 82
    /**
     * @brief 从NBT标签加载数据
     * @param tag NBT数据
     * @param dataLoadHelper 数据加载辅助器
     * @return 如果加载成功则返回true
     */
    virtual bool load(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper);

    // vIndex: 83
    /**
     * @brief 查询实体渲染器
     * @return 渲染器ID的哈希字符串
     */
    virtual ::HashedString const& queryEntityRenderer() const;

    // vIndex: 84
    /**
     * @brief 获取来源的唯一ID（例如，弹射物的所有者）
     * @return 来源的唯一ID
     */
    virtual ::ActorUniqueID getSourceUniqueID() const;

    // vIndex: 85
    /**
     * @brief 判断是否能被冻结
     * @return 如果可以则返回true
     */
    virtual bool canFreeze() const;

    // vIndex: 86
    /**
     * @brief 获取在指定液体中的碰撞箱
     * @param type 液体材质类型
     * @return 碰撞箱
     */
    virtual ::AABB getLiquidAABB(::MaterialType const) const;

    // vIndex: 87
    /**
     * @brief 处理在传送门内部的逻辑
     * @param portalPos 传送门方块的位置
     */
    virtual void handleInsidePortal(::BlockPos const& portalPos);

    // vIndex: 88
    /**
     * @brief 判断是否能使用传送门改变维度
     * @return 如果可以则返回true
     */
    virtual bool canChangeDimensionsUsingPortal() const;

    // vIndex: 90 (注意：索引不连续)
    /**
     * @brief 改变维度
     * @param toId 目标维度ID
     */
    virtual void changeDimension(::DimensionType toId);

    // vIndex: 89
    /**
     * @brief 改变维度（通过数据包）
     * @param packet 改变维度的数据包
     */
    virtual void changeDimension(::ChangeDimensionPacket const&);

    // vIndex: 91
    /**
     * @brief 获取控制此Actor的玩家的唯一ID
     * @return 玩家的唯一ID
     */
    virtual ::ActorUniqueID getControllingPlayer() const;

    // vIndex: 92
    /**
     * @brief 对Actor造成摔落伤害
     * @param damage 伤害值
     * @param multiplier 伤害乘数
     * @param source 伤害源
     * @return 实际造成的伤害
     */
    virtual float causeFallDamageToActor(float, float, ::ActorDamageSource);

    // vIndex: 93
    /**
     * @brief 当同步数据更新时调用
     * @param dataId 更新的数据ID
     */
    virtual void onSynchedDataUpdate(int dataId);

    // vIndex: 94
    /**
     * @brief 判断是否可以添加乘客
     * @param passenger 待添加的乘客
     * @return 如果可以则返回true
     */
    virtual bool canAddPassenger(::Actor& passenger) const;

    // vIndex: 95
    /**
     * @brief 判断是否可以拾取某个物品
     * @param item 待拾取的物品
     * @return 如果可以则返回true
     */
    virtual bool canPickupItem(::ItemStack const&) const;

    // vIndex: 96
    /**
     * @brief 判断是否能被拉入载具
     * @return 如果可以则返回true
     */
    virtual bool canBePulledIntoVehicle() const;

    // vIndex: 97
    /**
     * @brief 判断是否在商队中
     * @return 如果在商队中则返回true
     */
    virtual bool inCaravan() const;

    // vIndex: 98
    /**
     * @brief 如果需要，发送移动数据包
     */
    virtual void sendMotionPacketIfNeeded();

    // vIndex: 99
    /**
     * @brief 判断是否可以同步新实体
     * @return 如果可以则返回true
     */
    virtual bool canSynchronizeNewEntity() const;

    // vIndex: 100
    /**
     * @brief 开始游泳
     */
    virtual void startSwimming();

    // vIndex: 101
    /**
     * @brief 停止游泳
     */
    virtual void stopSwimming();

    // vIndex: 102
    /**
     * @brief 构建调试信息字符串
     * @param out 输出字符串
     */
    virtual void buildDebugInfo(::std::string&) const;

    // vIndex: 103
    /**
     * @brief 获取命令权限等级
     * @return 命令权限等级
     */
    virtual ::CommandPermissionLevel getCommandPermissionLevel() const;

    // vIndex: 104
    /**
     * @brief 获取死亡时间
     * @return 死亡时间（单位：tick）
     */
    virtual int getDeathTime() const;

    // vIndex: 105
    /**
     * @brief 判断是否能被指定效果影响
     * @param id 效果ID
     * @return 如果能被影响则返回true
     */
    virtual bool canBeAffected(uint id) const;

    // vIndex: 106
    /**
     * @brief 判断是否能被箭矢施加的效果影响
     * @param effect 效果实例
     * @return 如果能被影响则返回true
     */
    virtual bool canBeAffectedByArrow(::MobEffectInstance const& effect) const;

    // vIndex: 107
    /**
     * @brief 当效果被移除时调用
     * @param effect 被移除的效果实例
     */
    virtual void onEffectRemoved(::MobEffectInstance& effect);

    // vIndex: 108
    /**
     * @brief 判断是否能阻碍生成和方块放置
     * @return 如果能阻碍则返回true
     */
    virtual bool canObstructSpawningAndBlockPlacement() const;

    // vIndex: 109
    /**
     * @brief 获取动画组件
     * @return 动画组件的引用
     */
    virtual ::AnimationComponent& getAnimationComponent();

    // vIndex: 110
    /**
     * @brief 为玩家打开容器组件
     * @param player 玩家
     */
    virtual void openContainerComponent(::Player& player);

    // vIndex: 111
    /**
     * @brief 挥动手臂
     */
    virtual void swing();

    // vIndex: 112
    /**
     * @brief 使用物品
     * @param item 使用的物品
     * @param itemUseMethod 使用方法
     * @param consumeItem 是否消耗物品
     */
    virtual void useItem(::ItemStackBase& item, ::ItemUseMethod itemUseMethod, bool consumeItem);

    // vIndex: 113
    /**
     * @brief 获取调试文本
     * @param outputInfo 输出的字符串向量
     */
    virtual void getDebugText(::std::vector<::std::string>& outputInfo);

    // vIndex: 114
    /**
     * @brief 获取在地图上的装饰物旋转角度
     * @return 旋转角度
     */
    virtual float getMapDecorationRotation() const;

    // vIndex: 115
    /**
     * @brief 获取乘客的Y轴旋转角度
     * @param passenger 乘客
     * @return 旋转角度
     */
    virtual float getPassengerYRotation(::Actor const& passenger) const;

    // vIndex: 116
    /**
     * @brief 添加物品到Actor的物品栏
     * @param item 要添加的物品
     * @return 如果成功添加则返回true
     */
    virtual bool add(::ItemStack& item);

    // vIndex: 117
    /**
     * @brief 掉落物品
     * @param item 要掉落的物品
     * @param randomly 是否随机方向掉落
     * @return 如果成功掉落则返回true
     */
    virtual bool drop(::ItemStack const& item, bool const randomly);

    // vIndex: 118
    /**
     * @brief 获取与玩家的交互信息
     * @param player 交互的玩家
     * @param interaction 交互信息输出参数
     * @param pos 交互位置
     * @return 如果存在交互则返回true
     */
    virtual bool getInteraction(::Player& player, ::ActorInteraction& interaction, ::Vec3 const&);

    // vIndex: 119
    /**
     * @brief 判断是否能破坏指定方块
     * @param block 待判断的方块
     * @return 如果能破坏则返回true
     */
    virtual bool canDestroyBlock(::Block const&) const;

    // vIndex: 120
    /**
     * @brief 设置辅助值（通常用于渲染）
     * @param value 辅助值
     */
    virtual void setAuxValue(int);

    // vIndex: 121
    /**
     * @brief 渲染服务器端的调试状态
     * @param options 游戏选项
     */
    virtual void renderDebugServerState(::Options const&);

    // vIndex: 122
    /**
     * @brief 杀死此Actor（不触发死亡事件，直接移除）
     */
    virtual void kill();

    // vIndex: 123
    /**
     * @brief 使此Actor死亡（触发死亡事件、掉落物等）
     * @param source 伤害源
     */
    virtual void die(::ActorDamageSource const& source);

    // vIndex: 124
    /**
     * @brief 判断死亡时是否应掉落战利品
     * @return 如果应掉落则返回true
     */
    virtual bool shouldDropDeathLoot() const;

    // vIndex: 125
    /**
     * @brief 应用实体快照（用于同步）
     * @param snapshotEntity 快照实体上下文
     * @param originalSnapshotEntity 原始快照实体访问器
     */
    virtual void applySnapshot(
        ::EntityContext const&                                   snapshotEntity,
        ::MovementDataExtractionUtility::SnapshotAccessor const& originalSnapshotEntity
    );

    // vIndex: 126
    /**
     * @brief 当被其他Actor推动时调用
     * @param pusher 推动者
     */
    virtual void onPush(::Actor&);

    // vIndex: 127
    /**
     * @brief 获取上次死亡的位置
     * @return 可选的死亡位置
     */
    virtual ::std::optional<::BlockPos> getLastDeathPos() const;

    // vIndex: 128
    /**
     * @brief 获取上次死亡的维度
     * @return 可选的死亡维度ID
     */
    virtual ::std::optional<::DimensionType> getLastDeathDimension() const;

    // vIndex: 129
    /**
     * @brief 判断之前是否死亡过
     * @return 如果死亡过则返回true
     */
    virtual bool hasDiedBefore() const;

    // vIndex: 130
    /**
     * @brief 执行进入水中的溅水效果
     */
    virtual void doEnterWaterSplashEffect();

    // vIndex: 131
    /**
     * @brief 执行离开水中的溅水效果
     */
    virtual void doExitWaterSplashEffect();

    // vIndex: 132
    /**
     * @brief 执行溅水效果
     */
    virtual void doWaterSplashEffect();

    // vIndex: 133
    /**
     * @brief 判断在手部容器物品设置时是否应提供反馈
     * @param handSlot 手部槽位
     * @param item 设置的物品
     * @return 如果应提供反馈则返回true
     */
    virtual bool _shouldProvideFeedbackOnHandContainerItemSet(::HandSlot handSlot, ::ItemStack const& item) const;

    // vIndex: 134
    /**
     * @brief 判断在盔甲设置时是否应提供反馈
     * @param slot 盔甲槽位
     * @param item 设置的物品
     * @return 如果应提供反馈则返回true
     */
    virtual bool _shouldProvideFeedbackOnArmorSet(::SharedTypes::Legacy::ArmorSlot slot, ::ItemStack const& item) const;

    // vIndex: 135
    /**
     * @brief 内部受伤处理函数
     * @param source 伤害源
     * @param damage 伤害值
     * @param param3 未知布尔值
     * @param param4 未知布尔值
     * @return 如果成功受伤则返回true
     */
    virtual bool _hurt(::ActorDamageSource const& source, float damage, bool, bool);

    // vIndex: 136
    /**
     * @brief 读取额外的存档数据
     * @param tag NBT数据
     * @param dataLoadHelper 数据加载辅助器
     */
    virtual void readAdditionalSaveData(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper);

    // vIndex: 137
    /**
     * @brief 添加额外的存档数据
     * @param tag NBT数据
     */
    virtual void addAdditionalSaveData(::CompoundTag& tag) const;
    // NOLINTEND

public:
    // member functions
    // 成员函数
    // NOLINTBEGIN

    /**
     * @brief 构造函数
     * @param level 所在的关卡/世界
     * @param entityContext 实体上下文
     */
    MCAPI Actor(::ILevel& level, ::EntityContext& entityContext);

    /**
     * @brief 构造函数
     * @param definitions Actor定义组
     * @param definitionName Actor定义标识符
     * @param entityContext 实体上下文
     */
    MCAPI Actor(
        ::ActorDefinitionGroup*            definitions,
        ::ActorDefinitionIdentifier const& definitionName,
        ::EntityContext&                   entityContext
    );

    /**
     * @brief 添加Actor的内置组件
     * @return 内置组件的集合
     */
    MCAPI ::BuiltInActorComponents _addActorBuiltInComponents();

    /**
     * @brief 添加Actor的非内置组件
     */
    MCAPI void _addActorNonBuiltInComponents();

    /**
     * @brief 掉落一个物品，返回生成的ItemActor
     * @param item 要掉落的物品堆栈
     * @param randomly 是否随机方向掉落
     * @return 指向掉落物实体(ItemActor)的常量指针
     */
    MCAPI ::ItemActor const* _drop(::ItemStack const& item, bool randomly);

    /**
     * @brief 获取所有效果的非const引用
     * @return 效果实例向量的引用
     */
    MCAPI ::std::vector<::MobEffectInstance>& _getAllEffectsNonConst();

    /**
     * @brief 获取指定组的动画组件
     * @param animationComponent 用于存储结果的共享指针
     * @param group 动画组件组类型 (例如，普通动画或UI动画)
     * @return 动画组件的引用
     */
    MCAPI ::AnimationComponent& _getAnimationComponent(
        ::std::shared_ptr<::AnimationComponent>& animationComponent,
        ::AnimationComponentGroupType            group
    );

    /**
     * @brief 初始化别名属性
     */
    MCAPI void _initAliasProperties();

    /**
     * @brief 初始化拴绳系统
     * @param holder 拴住此Actor的实体
     */
    MCAPI void _initializeLeashRopeSystem(::Actor* holder);

    /**
     * @brief 判断头部是否在水中
     * @return 如果头部在水中则返回true
     */
    MCAPI bool _isHeadInWater() const;

    /**
     * @brief 判断ItemStack网络管理器是否启用
     * @return 如果启用则返回true
     */
    MCAPI bool _isItemStackNetManagerEnabled() const;

    /**
     * @brief 发送需要同步的Actor数据
     */
    MCAPI void _sendDirtyActorData();

    /**
     * @brief 序列化组件到NBT标签
     * @param tag 输出的NBT标签
     */
    MCAPI void _serializeComponents(::CompoundTag& tag) const;

    /**
     * @brief 设置Actor的类型ID
     * @param type Actor类型
     */
    MCAPI void _setActorTypeId(::ActorType type);

    /**
     * @brief 设置维度转换组件
     * @param fromId 起始维度ID
     * @param toId 目标维度ID
     * @param portalCooldown 传送门冷却时间
     */
    MCAPI void _setDimensionTransitionComponent(::DimensionType fromId, ::DimensionType toId, int portalCooldown);

    /**
     * @brief 设置手部容器中的物品
     * @param item 物品堆栈
     * @param handSlot 手部槽位 (主手/副手)
     */
    MCAPI void _setHandContainerItem(::ItemStack const& item, ::HandSlot handSlot);

    /**
     * @brief 设置高度偏移
     * @param heightOffset 高度偏移值
     */
    MCAPI void _setHeightOffset(float heightOffset);

    /**
     * @brief 设置上一帧的位置
     * @param posPrev 上一帧的位置
     */
    MCAPI void _setPosPrev(::Vec3 const& posPrev);

    /**
     * @brief 设置服务器端的动画组件
     */
    MCAPI void _setupServerAnimationComponent();

    /**
     * @brief 如果动画组件是共享的，则同步游戏刻计数
     */
    MCAPI void _syncTickCountIfAnimationComponentShared();

    /**
     * @brief 尝试用染料对Actor染色
     * @param player 使用染料的玩家
     * @param dyeItem 染料物品
     * @param interaction 交互信息
     * @return 如果染色成功则返回true
     */
    MCAPI bool _tryApplyDye(::Player& player, ::ItemStack const& dyeItem, ::ActorInteraction& interaction);

    /**
     * @brief 尝试在脚下种植凋零玫瑰 (当被凋零杀死时)
     */
    MCAPI void _tryPlantWitherRose();

    /**
     * @brief 更新组合(composition)，通常指更新组件
     * @param reload 是否重载
     */
    MCAPI void _updateComposition(bool reload);

    /**
     * @brief 为Actor添加一个效果实例
     * @param effect 要添加的效果
     */
    MCAPI void addEffect(::MobEffectInstance const& effect);


    /**
     * @brief 为Actor添加一个标签 (Tag)
     * @param tag 要添加的标签字符串
     * @return 如果成功添加(或已存在)则返回true
     */
    MCAPI bool addTag(::std::string const& tag);

    /**
     * @brief 构建调试信息组
     * @param out 输出字符串
     */
    MCAPI void buildDebugGroupInfo(::std::string& out) const;

    /**
     * @brief 构建Actor的前向向量
     * @return 前向向量 (Vec3)
     */
    MCAPI ::Vec3 buildForward() const;

    /**
     * @brief 使Actor燃烧
     * @param dmg 伤害值
     * @param bInFire 是否在火焰方块中
     */
    MCAPI void burn(int dmg, bool bInFire);

    /**
     * @brief 计算对另一个实体的攻击伤害
     * @param entity 目标实体
     * @return 伤害值
     */
    MCAPI float calculateAttackDamage(::Actor& entity);

    /**
     * @brief 判断是否可以攻击另一个实体
     * @param entity 目标实体
     * @return 如果可以攻击则返回true
     */
    MCAPI bool canAttack(::Actor const& entity) const;

    /**
     * @brief 判断是否可以开始或继续爬梯子
     * @return 如果可以则返回true
     */
    MCAPI bool canBeginOrContinueClimbingLadder() const;

    /**
     * @brief 判断当前是否可以游泳
     * @return 如果可以则返回true
     */
    MCAPI bool canCurrentlySwim() const;

    /**
     * @brief 判断是否可以飞行
     * @return 如果可以则返回true
     */
    MCAPI bool canFly() const;

    /**
     * @brief 判断是否可以与另一个Actor交配
     * @param partner 伴侣
     * @return 如果可以则返回true
     */
    MCAPI bool canMate(::Actor const& partner) const;

    /**
     * @brief 判断是否能从游戏玩法中接收生物效果
     * @return 如果可以则返回true
     */
    MCAPI bool canReceiveMobEffectsFromGameplay() const;

    /**
     * @brief 判断是否能看见另一个Actor（无视障碍物）
     * @param target 目标Actor
     * @param obstructionType 障碍物形状类型
     * @return 如果能看见则返回true
     */
    MCAPI bool canSee(::Actor const& target, ::ShapeType obstructionType) const;

    /**
     * @brief 判断是否能看见某个位置
     * @param targetPos 目标位置
     * @param obstructionType 障碍物形状类型
     * @return 如果能看见则返回true
     */
    MCAPI bool canSee(::Vec3 const& targetPos, ::ShapeType obstructionType) const;

    /**
     * @brief 判断是否能看见日光
     * @return 如果能则返回true
     */
    MCAPI bool canSeeDaylight() const;

    /**
     * @brief 检查并应用摔落伤害
     * @param ya Y轴速度
     * @param onGround 是否在地面上
     * @param recheckLiquid 是否重新检查液体
     */
    MCAPI void checkFallDamage(float ya, bool onGround, bool recheckLiquid);

    /**
     * @brief 使用紫颂果进行传送
     * @param range 传送范围
     */
    MCAPI void chorusFruitTeleport(::Vec3 const& range);

    /**
     * @brief 判断是否比另一个实体更近
     * @param e 另一个实体
     * @param distance 距离阈值
     * @return 如果更近则返回true
     */
    MCAPI bool closerThan(::Actor const& e, float distance) const;

    /**
     * @brief 判断是否比另一个实体更近（区分水平和垂直距离）
     * @param e 另一个实体
     * @param distanceXZ 水平距离阈值
     * @param distanceY 垂直距离阈值
     * @return 如果更近则返回true
     */
    MCAPI bool closerThan(::Actor const& e, float distanceXZ, float distanceY) const;

    /**
     * @brief 消耗一个掉落物实体
     * @param itemActor 掉落物实体
     * @param count 消耗数量
     */
    MCAPI void consumeItem(::ItemActor& itemActor, int count);

    /**
     * @brief 创建一个更新装备的数据包
     * @param containerID 容器ID
     * @return 更新装备数据包
     */
    MCAPI ::UpdateEquipPacket createUpdateEquipPacket(int containerID);

    /**
     * @brief 从关卡缓存中注销标签
     */
    MCAPI void deregisterTagsFromLevelCache();

    /**
     * @brief 计算到另一个实体的距离
     * @param e 另一个实体
     * @return 距离
     */
    MCAPI float distanceTo(::Actor const& e) const;

    /**
     * @brief 计算到某个位置的距离
     * @param pos 目标位置
     * @return 距离
     */
    MCAPI float distanceTo(::Vec3 const& pos) const;

    /**
     * @brief 计算到另一个实体的距离的平方
     * @param e 另一个实体
     * @return 距离的平方
     */
    MCAPI float distanceToSqr(::Actor const& e) const;

    /**
     * @brief 计算到某个位置的距离的平方
     * @param pos 目标位置
     * @return 距离的平方
     */
    MCAPI float distanceToSqr(::Vec3 const& pos) const;

    /**
     * @brief 朝一个方向掉落物品
     * @param item 要掉落的物品
     * @param towards 目标方向
     */
    MCAPI void dropTowards(::ItemStack const& item, ::Vec3 towards);

    /**
     * @brief 根据装备表来装备物品
     * @param equipmentTable 装备表
     */
    MCAPI void equip(::EquipmentTable const& equipmentTable);

    /**
     * @brief 根据战利品表文件路径来装备物品
     * @param lootTableFilePath 战利品表文件路径
     */
    MCAPI void equip(::std::string const& lootTableFilePath);

    /**
     * @brief 根据装备定义来装备物品
     */
    MCAPI void equipFromEquipmentDefinition();

    /**
     * @brief 评估座位旋转
     * @param rideable 骑乘组件
     * @param useVehicleRenderParams 是否使用载具的渲染参数
     * @return 旋转角度
     */
    MCAPI float evaluateSeatRotation(::RideableComponent const& rideable, bool useVehicleRenderParams);

    /**
     * @brief 离开载具
     * @param exitFromPassenger 是否由乘客主动离开
     * @param actorIsBeingDestroyed Actor是否正在被销毁
     * @param wasEjectedByActivatorRail 是否被动力铁轨弹出
     */
    MCAPI void exitVehicle(bool exitFromPassenger, bool actorIsBeingDestroyed, bool wasEjectedByActivatorRail);

    /**
     * @brief 获取附近已排序的Actor列表
     * @param distance 搜索范围
     * @param actorTypeId 目标Actor类型ID
     * @return 按距离排序的Actor列表
     */
    MCAPI ::std::vector<::DistanceSortedActor> fetchNearbyActorsSorted(::Vec3 const& distance, ::ActorType actorTypeId);

    /**
     * @brief 获取碰撞箱的尺寸
     * @return 碰撞箱尺寸 (Vec2: 宽, 高)
     */
    MCAPI ::Vec2 const& getAABBDim() const;

    /**
     * @brief 获取Actor的定义标识符
     * @return Actor定义标识符
     */
    MCAPI ::ActorDefinitionIdentifier const& getActorIdentifier() const;

    /**
     * @brief 获取指定槽位的盔甲
     * @param slot 盔甲槽位
     * @return 盔甲物品的常量引用
     */
    MCAPI ::ItemStack const& getArmor(::SharedTypes::Legacy::ArmorSlot slot) const;

    /**
     * @brief 获取附着点的位置
     * @param location 附着点位置类型
     * @return 附着点位置
     */
    MCAPI ::Vec3 getAttachPos(::SharedTypes::Legacy::ActorLocation location) const;

    /**
     * @brief 获取插值计算后的附着点位置
     * @param location 附着点位置类型
     * @param alpha 插值因子
     * @return 附着点位置
     */
    MCAPI ::Vec3 getAttachPos(::SharedTypes::Legacy::ActorLocation location, float alpha) const;

    /**
     * @brief 获取属性实例
     * @param attribute 目标属性
     * @return 属性实例的常量引用
     */
    MCAPI ::AttributeInstance const& getAttribute(::Attribute const& attribute) const;

    /**
     * @brief 获取属性表 (常量版本)
     * @return 指向属性表的非空指针
     */
    MCAPI ::gsl::not_null<::BaseAttributeMap const*> getAttributes() const;

    /**
     * @brief 获取属性表
     * @return 指向属性表的非空指针
     */
    MCAPI ::gsl::not_null<::BaseAttributeMap*> getAttributes();

    /**
     * @brief 获取当前站立的方块位置
     * @param actor 目标Actor (通常是自己)
     * @return 脚下方块的位置
     */
    MCAPI ::BlockPos getBlockPosCurrentlyStandingOn(::Actor const* actor) const;

    /**
     * @brief 获取亮度
     * @param a 插值因子
     * @return 亮度值
     */
    MCAPI float getBrightness(float a = 0.0f) const;

    /**
     * @brief 获取最适合存放指定物品的主手槽位物品
     * @param item 目标物品
     * @return 槽位物品的常量引用
     */
    MCAPI ::ItemStack const& getCarriedItemInSlotPreferredBy(::ItemStack const& item) const;

    /**
     * @brief 获取箱子槽位数 (例如驴、羊驼)
     * @return 槽位数
     */
    MCAPI int getChestSlots() const;

    /**
     * @brief 获取当前的游泳量（用于动画）
     * @return 游泳量
     */
    MCAPI float getCurrentSwimAmount() const;

    /**
     * @brief 获取是否伤害附近生物的属性
     * @return 如果为true，则会伤害附近生物
     */
    MCAPI bool getDamageNearbyMobs() const;

    /**
     * @brief 获取所在的维度
     * @return 维度的引用
     */
    MCFOLD ::Dimension& getDimension() const;

    /**
     * @brief 获取所在维度的方块源
     * @return 方块源的引用
     */
    MCFOLD ::BlockSource& getDimensionBlockSource() const;

    /**
     * @brief 获取所在维度的方块源 (常量版本)
     * @return 方块源的常量引用
     */
    MCFOLD ::BlockSource const& getDimensionBlockSourceConst() const;

    /**
     * @brief 获取所在的维度 (常量版本)
     * @return 维度的常量引用
     */
    MCFOLD ::Dimension const& getDimensionConst() const;

    /**
     * @brief 获取维度ID
     * @return 维度ID
     */
    MCAPI ::DimensionType getDimensionId() const;

    /**
     * @brief 获取指定效果的实例
     * @param effect 效果类型
     * @return 指向效果实例的常量指针，如果不存在则为nullptr
     */
    MCAPI ::MobEffectInstance const* getEffect(::MobEffect const& effect) const;

    /**
     * @brief 获取实体注册表
     * @return 实体注册表的堆栈引用结果
     */
    MCAPI ::StackRefResult<::EntityRegistry> getEntityRegistry();

    /**
     * @brief 获取实体类型ID
     * @return 实体类型ID
     */
    MCAPI ::ActorType getEntityTypeId() const;

    /**
     * @brief 获取装备槽位数
     * @return 槽位数
     */
    MCAPI int getEquipSlots() const;

    /**
     * @brief 获取最适合指定物品的装备槽位
     * @param item 物品
     * @return 装备槽位
     */
    MCAPI ::SharedTypes::Legacy::EquipmentSlot getEquipmentSlotForItem(::ItemStack const& item) const;

    /**
     * @brief 获取指定装备槽位的物品
     * @param slot 装备槽位
     * @return 物品的常量引用
     */
    MCAPI ::ItemStack const& getEquippedSlot(::SharedTypes::Legacy::EquipmentSlot slot) const;

    /**
     * @brief 获取眼睛位置
     * @return 眼睛位置的Vec3向量
     */
    MCAPI ::Vec3 getEyePos() const;

    /**
     * @brief 获取摔落距离
     * @return 摔落距离
     */
    MCAPI float getFallDistance() const;

    /**
     * @brief 获取第一个乘客
     * @return 指向第一个乘客的指针，如果没有则为nullptr
     */
    MCAPI ::Actor* getFirstPassenger() const;

    /**
     * @brief 获取插值计算后的位置
     * @param a 插值因子
     * @return 插值位置
     */
    MCAPI ::Vec3 getInterpolatedPosition(float a = 0.0f) const;

    /**
     * @brief 获取插值计算后的骑乘位置
     * @param a 插值因子
     * @return 插值位置
     */
    MCAPI ::Vec3 getInterpolatedRidingPosition(float a = 0.0f) const;

    /**
     * @brief 获取插值计算后的旋转
     * @param a 插值因子
     * @return 插值旋转 (Vec2: pitch, yaw)
     */
    MCAPI ::Vec2 getInterpolatedRotation(float a = 0.0f) const;

    /**
     * @brief 获取上一个伤害此Actor的生物
     * @return 指向生物的指针，如果不是生物或不存在则为nullptr
     */
    MCAPI ::Mob* getLastHurtByMob();

    /**
     * @brief 获取上一个伤害此Actor的玩家
     * @return 指向玩家的指针，如果不是玩家或不存在则为nullptr
     */
    MCAPI ::Player* getLastHurtByPlayer();

    /**
     * @brief 获取拴绳持有者的唯一ID
     * @return 拴绳持有者的ID
     */
    MCAPI ::ActorUniqueID getLeashHolder() const;

    /**
     * @brief 获取所有链接 (例如，骑乘关系)
     * @return ActorLink的向量
     */
    MCAPI ::std::vector<::ActorLink> getLinks() const;

    /**
     * @brief 获取战利品表
     * @return 指向战利品表的指针
     */
    MCAPI ::LootTable* getLootTable();

    /**
     * @brief 获取标记变种 (例如，猫的颜色)
     * @return 变种值
     */
    MCAPI int getMarkVariant() const;

    /**
     * @brief 获取最大生命值
     * @return 最大生命值
     */
    MCAPI int getMaxHealth() const;

    /**
     * @brief 获取可修改的属性
     * @param attribute 目标属性
     * @return 带上下文的可修改属性
     */
    MCAPI ::MutableAttributeWithContext getMutableAttribute(::Attribute const& attribute);

    /**
     * @brief 获取名字标签
     * @return 名字标签字符串的常量引用
     */
    MCAPI ::std::string const& getNameTag() const;

    /**
     * @brief 获取副手槽位的物品
     * @return 副手物品的常量引用
     */
    MCAPI ::ItemStack const& getOffhandSlot() const;

    /**
     * @brief 获取死亡时掉落的经验值
     * @return 经验值
     */
    MCAPI int getOnDeathExperience();

    /**
     * @brief 获取或添加动态属性
     * @return 动态属性的引用
     */
    MCAPI ::DynamicProperties& getOrAddDynamicProperties();

    /**
     * @brief 获取或创建唯一ID
     * @return 唯一ID的常量引用
     */
    MCAPI ::ActorUniqueID const& getOrCreateUniqueID() const;

    /**
     * @brief 获取所有者生物
     * @return 指向所有者生物的指针
     */
    MCAPI ::Mob* getOwner() const;

    /**
     * @brief 获取所有者ID
     * @return 所有者唯一ID
     */
    MCFOLD ::ActorUniqueID const getOwnerId() const;

    /**
     * @brief 获取指定乘客的索引
     * @param passenger 乘客
     * @return 索引值，如果不是乘客则返回-1
     */
    MCAPI int getPassengerIndex(::Actor const& passenger) const;

    /**
     * @brief 获取持久化的交易信息
     * @return 指向交易信息NBT的唯一指针
     */
    MCAPI ::std::unique_ptr<::CompoundTag> getPersistingTradeOffers();

    /**
     * @brief 获取玩家所有者
     * @return 指向玩家所有者的指针
     */
    MCAPI ::Player* getPlayerOwner() const;

    /**
     * @brief 获取位置增量
     * @return 位置增量向量的常量引用
     */
    MCAPI ::Vec3 const& getPosDelta() const;

    /**
     * @brief 获取当前位置
     * @return 位置向量的常量引用
     */
    MCAPI ::Vec3 const& getPosition() const;

    /**
     * @brief 获取随机数生成器
     * @return 随机数生成器的引用
     */
    MCAPI ::Random& getRandom() const;

    /**
     * @brief 获取可编辑的名字标签（用于审查）
     * @return 可编辑的字符串对象
     */
    MCAPI ::Bedrock::Safety::RedactableString getRedactableNameTag() const;

    /**
     * @brief 获取骑乘高度
     * @return 高度值
     */
    MCAPI float getRidingHeight() const;

    /**
     * @brief 获取旋转
     * @return 旋转向量的常量引用 (Vec2: pitch, yaw)
     */
    MCAPI ::Vec2 const& getRotation() const;

    /**
     * @brief 获取运行时ID
     * @return 运行时ID
     */
    MCAPI ::ActorRuntimeID getRuntimeID() const;

    /**
     * @brief 获取状态标志
     * @param flag 目标标志
     * @return 如果标志被设置则返回true
     */
    MCAPI bool getStatusFlag(::ActorFlags flag) const;

    /**
     * @brief 获取力量属性值
     * @return 力量值
     */
    MCAPI int getStrength() const;

    /**
     * @brief 获取结构完整性
     * @return 结构完整性值
     */
    MCAPI int getStructuralIntegrity() const;

    /**
     * @brief 获取游泳量（用于动画，带插值）
     * @param a 插值因子
     * @return 游泳量
     */
    MCAPI float getSwimAmount(float a = 0.0f) const;

    /**
     * @brief 获取目标Actor
     * @return 指向目标Actor的指针
     */
    MCAPI ::Actor* getTarget() const;

    /**
     * @brief 获取交易列表
     * @return 指向商人配方列表的指针
     */
    MCAPI ::MerchantRecipeList* getTradeOffers();

    /**
     * @brief 获取正在交易的玩家
     * @return 指向玩家的指针
     */
    MCAPI ::Player* getTradingPlayer() const;

    /**
     * @brief 获取变种 (例如，马的颜色)
     * @return 变种值
     */
    MCFOLD int getVariant() const;

    /**
     * @brief 获取乘坐的载具
     * @return 指向载具的指针
     */
    MCAPI ::Actor* getVehicle() const;

    /**
     * @brief 获取乘坐的载具链的根载具
     * @return 指向根载具的指针
     */
    MCAPI ::Actor* getVehicleRoot() const;

    /**
     * @brief 获取视线向量（带插值）
     * @param a 插值因子
     * @return 视线单位向量
     */
    MCFOLD ::Vec3 getViewVector(float a = 0.0f) const;

    /**
     * @brief 获取实体的弱引用
     * @return 实体上下文的弱引用
     */
    MCAPI ::WeakRef<::EntityContext> const getWeakEntity() const;

    /**
     * @brief 处理摔落伤害
     * @param fallDistance 摔落距离
     * @param multiplier 伤害乘数
     * @param source 伤害源
     */
    MCAPI void handleFallDamage(float fallDistance, float multiplier, ::ActorDamageSource source);

    /**
     * @brief 处理剩余的摔落伤害
     * @param damage 伤害值
     * @param source 伤害源
     */
    MCAPI void handleLeftoverFallDamage(float damage, ::ActorDamageSource source);

    /**
     * @brief 判断是否拥有指定类别
     * @param categories 类别掩码
     * @return 如果拥有任一指定类别则返回true
     */
    MCAPI bool hasCategory(::ActorCategory categories) const;

    /**
     * @brief 判断是否在维度中
     * @return 如果在则返回true
     */
    MCAPI bool hasDimension() const;

    /**
     * @brief 判断是否拥有指定效果
     * @param effect 效果类型
     * @return 如果拥有则返回true
     */
    MCAPI bool hasEffect(::MobEffect const& effect) const;

    /**
     * @brief 判断是否属于指定家族
     * @param family 家族的哈希字符串
     * @return 如果属于则返回true
     */
    MCAPI bool hasFamily(::HashedString const& family) const;

    /**
     * @brief 判断是否有玩家乘客
     * @return 如果有则返回true
     */
    MCAPI bool hasPlayerPassenger() const;

    /**
     * @brief 判断是否有运行时ID
     * @return 如果有则返回true
     */
    MCAPI bool hasRuntimeID() const;

    /**
     * @brief 判断是否装备了鞍
     * @return 如果有则返回true
     */
    MCAPI bool hasSaddle() const;

    /**
     * @brief 判断是否拥有指定标签
     * @param tag 标签字符串
     * @return 如果拥有则返回true
     */
    MCAPI bool hasTag(::std::string const& tag) const;

    /**
     * @brief 判断是否拥有任何标签
     * @return 如果拥有则返回true
     */
    MCAPI bool hasTags() const;

    /**
     * @brief 判断是否属于指定类型
     * @param types 类型掩码
     * @return 如果属于任一指定类型则返回true
     */
    MCAPI bool hasType(::ActorType types) const;

    /**
     * @brief 判断是否拥有唯一ID
     * @return 如果拥有则返回true
     */
    MCAPI bool hasUniqueID() const;

    /**
     * @brief 治疗Actor
     * @param heal 治疗量
     */
    MCAPI void heal(int heal);

    /**
     * @brief 使Actor受伤
     * @param source 伤害源
     * @param damage 伤害值
     * @param knock 是否击退
     * @param ignite 是否点燃
     * @return 如果成功受伤则返回true
     */
    MCAPI bool hurt(::ActorDamageSource const& source, float damage, bool knock, bool ignite);

    /**
     * @brief 判断是否在向下流动的液体中
     * @return 如果在则返回true
     */
    MCAPI bool inDownwardFlowingLiquid() const;

    /**
     * @brief 初始化Actor属性
     */
    MCAPI void initActorProperties();

    /**
     * @brief 初始化渲染参数
     * @param params 渲染参数
     */
    MCAPI void initParams(::RenderParams& params);

    /**
     * @brief 判断是否处于冒险模式
     * @return 如果是则返回true
     */
    MCAPI bool isAdventure() const;

    /**
     * @brief 判断是否处于可攻击的游戏模式
     * @return 如果是则返回true
     */
    MCAPI bool isAttackableGamemode() const;

    /**
     * @brief 判断是否是自主的（由服务器控制）
     * @return 如果是则返回true
     */
    MCAPI bool isAutonomous() const;

    /**
     * @brief 判断是否是幼年体
     * @return 如果是则返回true
     */
    MCAPI bool isBaby() const;

    /**
     * @brief 判断是否带有箱子
     * @return 如果是则返回true
     */
    MCAPI bool isChested() const;

    /**
     * @brief 判断是否是客户端实体
     * @return 如果是则返回true
     */
    MCAPI bool isClientSide() const;

    /**
     * @brief 判断是否处于创造模式
     * @return 如果是则返回true
     */
    MCAPI bool isCreative() const;

    /**
     * @brief 判断是否在跳舞（鹦鹉）
     * @return 如果是则返回true
     */
    MCAPI bool isDancing() const;

    /**
     * @brief 判断是否已死亡
     * @return 如果是则返回true
     */
    MCAPI bool isDead() const;

    /**
     * @brief 判断是否能开门
     * @return 如果是则返回true
     */
    MCAPI bool isDoorOpener() const;


    /**
     * @brief 判断是否是全局的（不受距离影响）
     * @return 如果是则返回true
     */
    MCAPI bool isGlobal() const;

    /**
     * @brief 判断是否在云中
     * @return 如果是则返回true
     */
    MCAPI bool isInClouds() const;

    /**
     * @brief 判断是否在岩浆中
     * @return 如果是则返回true
     */
    MCAPI bool isInLava() const;

    /**
     * @brief 判断是否处于恋爱模式
     * @return 如果是则返回true
     */
    MCAPI bool isInLove() const;

    /**
     * @brief 判断是否在降水区域（雨或雪）
     * @return 如果是则返回true
     */
    MCAPI bool isInPrecipitation() const;

    /**
     * @brief 判断是否在雨中
     * @return 如果是则返回true
     */
    MCAPI bool isInRain() const;

    /**
     * @brief 判断是否在雪中
     * @return 如果是则返回true
     */
    MCAPI bool isInSnow() const;

    /**
     * @brief 判断是否在雷暴中
     * @return 如果是则返回true
     */
    MCAPI bool isInThunderstorm() const;

    /**
     * @brief 判断是否在水中
     * @return 如果是则返回true
     */
    MCAPI bool isInWater() const;

    /**
     * @brief 判断是否在水或雨中
     * @return 如果是则返回true
     */
    MCAPI bool isInWaterOrRain() const;

    /**
     * @brief 判断是否在世界中
     * @return 如果是则返回true
     */
    MCAPI bool isInWorld() const;

    /**
     * @brief 判断是否在跳跃
     * @return 如果是则返回true
     */
    MCAPI bool isJumping() const;

    /**
     * @brief 判断是否被拴住了
     * @return 如果是则返回true
     */
    MCAPI bool isLeashed() const;

    /**
     * @brief 判断是否是本地玩家
     * @return 如果是则返回true
     */
    MCFOLD bool isLocalPlayer() const;

    /**
     * @brief 判断是否在水面上方
     * @return 如果是则返回true
     */
    MCAPI bool isOverWater() const;

    /**
     * @brief 判断一个Actor是否是自己的乘客
     * @param passenger 待判断的Actor
     * @return 如果是乘客则返回true
     */
    MCAPI bool isPassenger(::Actor const& passenger) const;

    /**
     * @brief 判断是否是持久化的（不会被自然清除）
     * @return 如果是则返回true
     */
    MCAPI bool isPersistent() const;

    /**
     * @brief 判断是否是玩家
     * @return 如果是则返回true
     */
    MCFOLD bool isPlayer() const;

    /**
     * @brief 判断是否是远程玩家
     * @return 如果是则返回true
     */
    MCAPI bool isRemotePlayer() const;

    /**
     * @brief 判断是否在骑乘
     * @return 如果是则返回true
     */
    MCAPI bool isRiding() const;

    /**
     * @brief 判断是否在骑乘指定的载具
     * @param targetVehicle 目标载具
     * @return 如果是则返回true
     */
    MCAPI bool isRiding(::Actor* targetVehicle) const;

    /**
     * @brief 判断是否是静音的
     * @return 如果是则返回true
     */
    MCAPI bool isSilent() const;

    /**
     * @brief 判断是否在坐下
     * @return 如果是则返回true
     */
    MCAPI bool isSitting() const;

    /**
     * @brief 判断是否在潜行
     * @return 如果是则返回true
     */
    MCAPI bool isSneaking() const;

    /**
     * @brief 判断是否是旁观者模式
     * @return 如果是则返回true
     */
    MCAPI bool isSpectator() const;

    /**
     * @brief 判断是否是生存模式
     * @return 如果是则返回true
     */
    MCAPI bool isSurvival() const;

    /**
     * @brief 判断是否在游泳
     * @return 如果是则返回true
     */
    MCAPI bool isSwimming() const;

    /**
     * @brief 判断是否被驯服
     * @return 如果是则返回true
     */
    MCAPI bool isTame() const;

    /**
     * @brief 判断是否接触到伤害性方块（例如仙人掌）
     * @return 如果是则返回true
     */
    MCAPI bool isTouchingDamageBlock() const;

    /**
     * @brief 判断是否在交易
     * @return 如果是则返回true
     */
    MCAPI bool isTrading() const;

    /**
     * @brief 判断是否是指定类型
     * @param type 类型
     * @return 如果是则返回true
     */
    MCAPI bool isType(::ActorType type) const;

    /**
     * @brief 判断是否在指定类型的液体下方
     * @param type 液体材质类型
     * @return 如果是则返回true
     */
    MCAPI bool isUnderLiquid(::MaterialType type) const;

    /**
     * @brief 判断是否穿着皮革甲
     * @return 如果是则返回true
     */
    MCAPI bool isWearingLeatherArmor() const;

    /**
     * @brief 判断是否是世界构建者
     * @return 如果是则返回true
     */
    MCAPI bool isWorldBuilder() const;

    /**
     * @brief 当杀死另一个实体时调用
     * @param entity 被杀死的实体
     */
    MCAPI void killed(::Actor& entity);

    /**
     * @brief 从NBT加载实体标志
     * @param tag NBT数据
     * @param dataLoadHelper 数据加载辅助器
     */
    MCAPI void loadEntityFlags(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper);

    /**
     * @brief 从NBT加载链接
     * @param entityTag 实体NBT数据
     * @param links 输出的链接向量
     * @param dataLoadHelper 数据加载辅助器
     */
    MCAPI void
    loadLinks(::CompoundTag const& entityTag, ::std::vector<::ActorLink>& links, ::DataLoadHelper& dataLoadHelper);

    /**
     * @brief 移动Actor
     * @param posDelta 位置增量
     */
    MCAPI void move(::Vec3 const& posDelta);

    /**
     * @brief 移动到指定位置和旋转
     * @param pos 目标位置
     * @param rot 目标旋转
     */
    MCAPI void moveTo(::Vec3 const& pos, ::Vec2 const& rot);

    /**
     * @brief 判断是否在可攀爬的方块上
     * @return 如果是则返回true
     */
    MCAPI bool onClimbableBlock() const;

    /**
     * @brief 当效果被添加时调用
     * @param effect 被添加的效果实例
     */
    MCAPI void onEffectAdded(::MobEffectInstance& effect);

    /**
     * @brief 当效果被更新时调用
     * @param effect 被更新的效果实例
     */
    MCAPI void onEffectUpdated(::MobEffectInstance& effect);

    /**
     * @brief 拾取掉落物实体
     * @param itemActor 掉落物实体
     * @param count 拾取数量
     */
    MCAPI void pickUpItem(::ItemActor& itemActor, int count);

    /**
     * @brief 播放音效
     * @param type 音效事件类型
     * @param pos 音效位置
     * @param data 音效数据
     */
    MCAPI void playSound(::SharedTypes::Legacy::LevelSoundEvent type, ::Vec3 const& pos, int data);

    /**
     * @brief 在指定区域播放音效
     * @param region 方块源
     * @param type 音效事件类型
     * @param pos 音效位置
     * @param data 音效数据
     */
    MCAPI void playSound(
        ::IConstBlockSource const&             region,
        ::SharedTypes::Legacy::LevelSoundEvent type,
        ::Vec3 const&                          pos,
        int                                    data
    );

    /**
     * @brief 播放同步的音效
     * @param type 音效事件类型
     * @param pos 音效位置
     * @param data 音效数据
     * @param isGlobal 是否是全局音效
     */
    MCAPI void
    playSynchronizedSound(::SharedTypes::Legacy::LevelSoundEvent type, ::Vec3 const& pos, int data, bool isGlobal);

    /**
     * @brief 定位乘客的位置
     * @param passenger 乘客
     */
    MCAPI void positionPassenger(::Actor& passenger);

    /**
     * @brief 发送一个游戏事件
     * @param gameEvent 游戏事件
     * @param originPos 事件起源位置
     * @param affectedBlock 受影响的方块
     */
    MCAPI void postGameEvent(::GameEvent const& gameEvent, ::Vec3 const& originPos, ::Block const* affectedBlock);

    /**
     * @brief 发送溅水游戏事件
     */
    MCAPI void postSplashGameEvent();

    /**
     * @brief 将一个行为事件推入行为队列的后端
     * @param actionEvent 行为事件
     */
    MCAPI void pushBackActionEventToActionQueue(::ActionEvent actionEvent);

    /**
     * @brief 将Actor推出方块
     * @param vec 推出的方向和力度
     */
    MCAPI void pushOutOfBlocks(::Vec3 const& vec);

    /**
     * @brief 从定义中请求更新碰撞箱
     */
    MCAPI void queueBBUpdateFromDefinition();

    /**
     * @brief 刷新组件
     */
    MCAPI void refreshComponents();

    /**
     * @brief 重新加载Actor（定义、组件等）
     */
    MCAPI void reload();

    /**
     * @brief 移除所有效果
     */
    MCAPI void removeAllEffects();

    /**
     * @brief 移除所有乘客
     * @param beingDestroyed Actor是否正在被销毁
     */
    MCAPI void removeAllPassengers(bool beingDestroyed);

    /**
     * @brief 移除指定ID的效果
     * @param effectId 效果ID
     */
    MCAPI void removeEffect(int effectId);

    /**
     * @brief 移除一个标签
     * @param tag 要移除的标签
     * @return 如果成功移除则返回true
     */
    MCAPI bool removeTag(::std::string const& tag);

    /**
     * @brief 保存到NBT（包含ID）
     * @param entityTag 输出的NBT标签
     * @return 如果成功保存则返回true
     */
    MCAPI bool save(::CompoundTag& entityTag) const;

    /**
     * @brief 保存实体标志到NBT
     * @param entityTag 输出的NBT标签
     */
    MCAPI void saveEntityFlags(::CompoundTag& entityTag) const;

    /**
     * @brief 保存链接为ListTag
     * @return 包含链接数据的ListTag的唯一指针
     */
    MCAPI ::std::unique_ptr<::ListTag> saveLinks() const;

    /**
     * @brief 保存持久化的交易信息
     * @param offersTag 交易信息的NBT
     * @param riches 财富值
     */
    MCAPI void savePersistingTrade(::std::unique_ptr<::CompoundTag> offersTag, int riches);

    /**
     * @brief 保存到NBT（不包含ID）
     * @param entityTag 输出的NBT标签
     */
    MCAPI void saveWithoutId(::CompoundTag& entityTag) const;

    /**
     * @brief 发送一个Actor定义事件触发器
     * @param event 事件名称
     */
    MCAPI void sendActorDefinitionEventTriggered(::std::string const& event);

    /**
     * @brief 通过序列化设置生命值
     * @param newHealth 新的生命值
     */
    MCAPI void serializationSetHealth(int newHealth);

    /**
     * @brief 设置Actor渲染器ID
     * @param actorRendererId 渲染器ID
     */
    MCAPI void setActorRendererId(::HashedString actorRendererId);

    /**
     * @brief 设置是否为自主的
     * @param g 是否自主
     */
    MCAPI void setAutonomous(bool g);

    /**
     * @brief 设置基础定义
     * @param sourceId 源定义标识符
     * @param clearDefs 是否清除现有定义
     * @param update 是否立即更新
     */
    MCAPI void setBaseDefinition(::ActorDefinitionIdentifier const& sourceId, bool clearDefs, bool update);

    /**
     * @brief 设置方块目标
     * @param target 目标方块位置
     */
    MCAPI void setBlockTarget(::BlockPos const& target);

    /**
     * @brief 设置所在的维度
     * @param weakDimension 维度的弱引用
     */
    MCAPI void setDimension(::WeakRef<::Dimension> weakDimension);

    /**
     * @brief 设置是否隐身
     * @param value 是否隐身
     */
    MCAPI void setInvisible(bool value);

    /**
     * @brief 设置是否在跳跃
     * @param jump 是否跳跃
     */
    MCAPI void setJumping(bool jump);

    /**
     * @brief 设置上次被击中的碰撞箱
     * @param pos 位置
     * @param radius 半径
     */
    MCAPI void setLastHitBB(::Vec3 const& pos, ::Vec3 const& radius);

    /**
     * @brief 设置上一个伤害此Actor的生物
     * @param mob 生物
     */
    MCAPI void setLastHurtByMob(::Mob* mob);

    /**
     * @brief 设置上一个伤害此Actor的玩家
     * @param player 玩家
     */
    MCAPI void setLastHurtByPlayer(::Player* player);

    /**
     * @brief 设置上一个被此Actor伤害的实体
     * @param target 目标实体
     */
    MCAPI void setLastHurtMob(::Actor* target);

    /**
     * @brief 设置拴绳持有者
     * @param leashHolder 拴绳持有者的唯一ID
     */
    MCAPI void setLeashHolder(::ActorUniqueID leashHolder);

    /**
     * @brief 设置有限的生命周期
     * @param lifetimeTicks 生命周期（单位：tick）
     */
    MCAPI void setLimitedLifetimeTicks(int lifetimeTicks);

    /**
     * @brief 设置标记变种
     * @param value 变种值
     */
    MCAPI void setMarkVariant(int value);

    /**
     * @brief 设置移动声音距离偏移
     * @param movementSoundDistanceOffset 偏移值
     */
    MCAPI void setMovementSoundDistanceOffset(float movementSoundDistanceOffset);

    /**
     * @brief 设置名字标签
     * @param name 名字
     */
    MCAPI void setNameTag(::std::string const& name);

    /**
     * @brief 设置为持久化的
     */
    MCAPI void setPersistent();

    /**
     * @brief 设置上一帧的位置和旋转
     */
    MCAPI void setPreviousPosRot();

    /**
     * @brief 设置可编辑的名字标签
     * @param name 可编辑的字符串
     */
    MCAPI void setRedactableNameTag(::Bedrock::Safety::RedactableString const& name);

    /**
     * @brief 设置上一帧的旋转
     * @param rotation 上一帧的旋转
     */
    MCAPI void setRotationPrev(::Vec2 const& rotation);

    /**
     * @brief 设置旋转（带角度环绕处理）
     * @param rot 旋转值
     */
    MCAPI void setRotationWrapped(::Vec2 const& rot);

    /**
     * @brief 设置皮肤ID
     * @param value 皮肤ID
     */
    MCAPI void setSkinID(int value);

    /**
     * @brief 设置状态标志
     * @param flag 目标标志
     * @param value 是否设置
     */
    MCAPI void setStatusFlag(::ActorFlags flag, bool value);

    /**
     * @brief 设置力量属性值
     * @param strength 力量值
     */
    MCAPI void setStrength(int strength);

    /**
     * @brief 设置最大力量属性值
     * @param strength 最大力量值
     */
    MCAPI void setStrengthMax(int strength);

    /**
     * @brief 设置变种
     * @param value 变种值
     */
    MCFOLD void setVariant(int value);

    /**
     * @brief 判断是否应该被孤立（从世界中移除）
     * @param source 方块源
     * @return 如果应该被孤立则返回true
     */
    MCAPI bool shouldOrphan(::BlockSource& source);

    /**
     * @brief 判断是否应该进行游戏刻更新
     * @return 如果应该则返回true
     */
    MCAPI bool shouldTick() const;

    /**
     * @brief 在指定位置生成一个掉落物实体
     * @param item 物品
     * @param yOffs Y轴偏移
     * @return 指向生成的掉落物实体的指针
     */
    MCAPI ::ItemActor* spawnAtLocation(::ItemStack const& item, float yOffs);

    /**
     * @brief 生成进食粒子效果
     * @param itemInUse 正在使用的物品
     * @param count 粒子数量
     */
    MCAPI void spawnEatParticles(::ItemStack const& itemInUse, int count);

    /**
     * @brief 生成轨迹气泡（例如，在水下）
     */
    MCAPI void spawnTrailBubbles();

    /**
     * @brief 停止骑乘
     * @param exitFromPassenger 是否由乘客主动离开
     * @param actorIsBeingDestroyed Actor是否正在被销毁
     * @param switchingVehicles 是否正在切换载具
     * @param isBeingTeleported 是否正在被传送
     */
    MCAPI void
    stopRiding(bool exitFromPassenger, bool actorIsBeingDestroyed, bool switchingVehicles, bool isBeingTeleported);

    /**
     * @brief 同步地设置尺寸
     * @param w 宽度
     * @param h 高度
     */
    MCAPI void synchronousSetSize(float w, float h);

    /**
     * @brief 将乘客传送到指定位置
     * @param pos 目标位置
     * @param cause 原因
     * @param entityType 实体类型
     */
    MCAPI void teleportPassengersTo(::Vec3 const& pos, int cause, int entityType);

    /**
     * @brief 对Actor进行游戏刻更新
     * @param region 所在的方块源
     * @return 操作是否成功
     */
    MCAPI bool tick(::BlockSource& region);

    /**
     * @brief 更新方块伤害（例如，站在岩浆块上）
     */
    MCAPI void tickBlockDamage();

    /**
     * @brief 更新拴绳逻辑
     */
    MCAPI void tickLeash();

    /**
     * @brief 触发Actor被移除事件
     */
    MCAPI void triggerActorRemovedEvent();

    /**
     * @brief 尝试获取最适合指定物品的装备槽位
     * @param item 物品描述符
     * @return 可选的槽位索引
     */
    MCAPI ::std::optional<int> tryGetEquippableSlotForItem(::ItemDescriptor item) const;


    /**
     * @brief 尝试传送到指定位置
     * @param pos 目标位置
     * @param landOnBlock 是否需要落在方块上
     * @param avoidLiquid 是否避免液体
     * @param cause 原因
     * @param entityType 实体类型
     * @return 如果传送成功则返回true
     */
    MCAPI bool tryTeleportTo(::Vec3 const& pos, bool landOnBlock, bool avoidLiquid, int cause, int entityType);

    /**
     * @brief 更新描述
     */
    MCAPI void updateDescription();

    /**
     * @brief 更新在方块内部的状态
     */
    MCAPI void updateInsideBlock();

    /**
     * @brief 更新隐身状态
     */
    MCAPI void updateInvisibilityStatus();

    /**
     * @brief 更新Molang变量
     * @param renderParams 渲染参数
     */
    MCAPI void updateMolangVariables(::RenderParams& renderParams);

    /**
     * @brief 更新Ticking数据
     */
    MCAPI void updateTickingData();

    /**
     * @brief 更新在水中的状态
     */
    MCAPI void updateWaterState();

    /**
     * @brief 使Actor摇晃（例如，被攻击时）
     */
    MCAPI void wobble();
    // NOLINTEND

public:
    // static functions
    // 静态函数
    // NOLINTBEGIN

    /**
     * @brief 相对移动
     * @param posDelta 位置增量 (输入输出)
     * @param yRotDegrees Y轴旋转角度
     * @param xa x轴输入
     * @param ya y轴输入
     * @param za z轴输入
     * @param speed 速度
     */
    MCAPI static void _moveRelative(::Vec3& posDelta, float yRotDegrees, float xa, float ya, float za, float speed);

    /**
     * @brief 获取指定位置下方的站立点
     * @param pos 位置
     * @param box 碰撞箱
     * @param region 方块源
     * @param other 其他碰撞形状接口
     * @return 脚下方块的位置
     */
    MCAPI static ::BlockPos getBlockPosCurrentlyStandingOn(
        ::Vec3 const&                                      pos,
        ::AABB                                             box,
        ::IConstBlockSource const&                         region,
        ::optional_ref<::GetCollisionShapeInterface const> other
    );

    /**
     * @brief 从效果列表中获取指定效果
     * @param effects 效果列表
     * @param effect 效果类型
     * @return 指向效果实例的常量指针
     */
    MCAPI static ::MobEffectInstance const*
    getEffect(::std::vector<::MobEffectInstance> const& effects, ::MobEffect const& effect);

    /**
     * @brief 获取插值计算后的旋转
     * @param prevRot 上一帧的旋转
     * @param rot 当前帧的旋转
     * @param a 插值因子
     * @return 插值旋转
     */
    MCAPI static ::Vec2 getInterpolatedRotation(::Vec2 const& prevRot, ::Vec2 const& rot, float a);

    /**
     * @brief 获取在指定液体中的碰撞箱
     * @param aabb 原始碰撞箱
     * @param liquidType 液体材质类型
     * @return 液体中的碰撞箱
     */
    MCAPI static ::AABB getLiquidAABB(::AABB const& aabb, ::MaterialType liquidType);

    /**
     * @brief 获取插值计算后的视线向量
     * @param prevRot 上一帧的旋转
     * @param rot 当前帧的旋转
     * @param a 插值因子
     * @return 视线单位向量
     */
    MCAPI static ::Vec3 getViewVector(::Vec2 const& prevRot, ::Vec2 const& rot, float a);

    /**
     * @brief 判断实体是否不可移动
     * @param entity 实体上下文
     * @return 如果不可移动则返回true
     */
    MCAPI static bool isImmobile(::EntityContext const& entity);

    /**
     * @brief 尝试从严格的实体上下文中获取Actor指针
     * @param entity 严格的实体上下文
     * @param registry 实体注册表
     * @param includeRemoved 是否包括已移除的Actor
     * @return 指向Actor的指针，如果获取失败则为nullptr
     */
    MCAPI static ::Actor*
    tryGetFromEntity(::StrictEntityContext const& entity, ::EntityRegistry& registry, bool includeRemoved);
    // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(::ILevel& level, ::EntityContext& entityContext);

    MCAPI void* $ctor(
        ::ActorDefinitionGroup*            definitions,
        ::ActorDefinitionIdentifier const& definitionName,
        ::EntityContext&                   entityContext
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
    MCAPI bool $hasComponent(::HashedString const& name) const;

    MCAPI void $outOfWorld();

    MCFOLD void $reloadHardcoded(::ActorInitializationMethod, ::VariantParameterList const&);

    MCFOLD void $reloadHardcodedClient(::ActorInitializationMethod);

    MCAPI void $initializeComponents(::ActorInitializationMethod method, ::VariantParameterList const&);

    MCAPI void $reloadComponents(::ActorInitializationMethod, ::VariantParameterList const&);

    MCAPI void $_serverInitItemStackIds();

    MCAPI void $_doInitialMove();

    MCFOLD void $resetUserPos(::ActorResetRule);

    MCAPI ::ActorType $getOwnerEntityType();

    MCAPI void $remove();

    MCAPI ::Vec3 $getFiringPos() const;

    MCAPI float $getInterpolatedBodyRot(float a) const;

    MCFOLD float $getInterpolatedHeadRot(float) const;

    MCFOLD float $getInterpolatedBodyYaw(float) const;

    MCAPI float $getYawSpeedInDegreesPerSecond() const;

    MCFOLD ::Vec3 $getInterpolatedRidingOffset(float, int const) const;

    MCAPI bool $isFireImmune() const;

    MCAPI void $blockedByShield(::ActorDamageSource const& source, ::Actor& blocker);

    MCAPI bool $canDisableShield();

    MCAPI void $teleportTo(::Vec3 const& pos, bool shouldStopRiding, int, int, bool keepVelocity);

    MCAPI void $lerpMotion(::Vec3 const& delta);

    MCAPI ::std::unique_ptr<::AddActorBasePacket> $tryCreateAddActorPacket();

    MCAPI void $normalTick();

    MCAPI void $baseTick();

    MCAPI void $passengerTick();

    MCAPI bool $startRiding(::Actor& vehicle, bool forceRiding);

    MCAPI void $addPassenger(::Actor& passenger);

    MCAPI ::std::string $getExitTip(::std::string const& kind, ::InputMode mode, ::NewInteractionModel scheme) const;

    MCAPI ::std::string $getEntityLocNameString() const;

    MCAPI bool $isInvisible() const;

    MCAPI bool $canShowNameTag() const;

    MCAPI ::std::string $getFormattedNameTag() const;

    MCFOLD ::mce::Color $getNameTagTextColor() const;

    MCAPI float $getShadowRadius() const;

    MCFOLD ::Vec3 $getHeadLookVector(float a) const;

    MCFOLD bool $canInteractWithOtherEntitiesInGame() const;

    MCAPI float $getBrightness(float a, ::IConstBlockSource const& region) const;

    MCFOLD void $playerTouch(::Player&);

    MCFOLD bool $isImmobile() const;

    MCAPI bool $isSilentObserver() const;

    MCFOLD bool $isSleeping() const;

    MCFOLD void $setSleeping(bool);

    MCAPI void $setSneaking(bool value);

    MCFOLD bool $isBlocking() const;

    MCFOLD bool $isDamageBlocked(::ActorDamageSource const&) const;

    MCFOLD bool $isAlive() const;

    MCFOLD bool $isOnFire() const;

    MCFOLD bool $isSurfaceMob() const;

    MCFOLD bool $isTargetable() const;

    MCAPI void $setTarget(::Actor* entity);

    MCFOLD bool $isValidTarget(::Actor*) const;

    MCAPI void $performRangedAttack(::Actor& target, float);

    MCAPI void $setOwner(::ActorUniqueID const ownerId);

    MCFOLD void $setSitting(bool value);

    MCFOLD void $onTame();

    MCFOLD void $onFailedTame();

    MCAPI void $setStanding(bool value);

    MCAPI bool $canPowerJump() const;

    MCAPI bool $isEnchanted() const;

    MCAPI void $playAmbientSound();

    MCAPI ::SharedTypes::Legacy::LevelSoundEvent $getAmbientSound() const;

    MCAPI bool $isInvulnerableTo(::ActorDamageSource const& source) const;

    MCAPI bool $doFireHurt(int amount);

    MCAPI void $onLightningHit();

    MCAPI void $feed(int itemId);

    MCAPI void $handleEntityEvent(::ActorEvent eventId, int data);

    MCFOLD ::HashedString const& $getActorRendererId() const;

    MCAPI void $despawn();

    MCAPI void $setArmor(::SharedTypes::Legacy::ArmorSlot slot, ::ItemStack const& item);

    MCFOLD ::ArmorMaterialType $getArmorMaterialTypeInSlot(::SharedTypes::Legacy::ArmorSlot) const;

    MCFOLD int $getArmorTextureIndexInSlot(::SharedTypes::Legacy::ArmorSlot) const;

    MCFOLD float $getArmorColorInSlot(::SharedTypes::Legacy::ArmorSlot, int) const;

    MCFOLD void $setEquippedSlot(::SharedTypes::Legacy::EquipmentSlot, ::ItemStack const&);

    MCAPI void $setCarriedItem(::ItemStack const& item);

    MCAPI ::ItemStack const& $getCarriedItem() const;

    MCAPI void $setOffhandSlot(::ItemStack const& item);

    MCAPI ::ItemStack const& $getEquippedTotem() const;

    MCAPI bool $consumeTotem();

    MCAPI bool $load(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper);

    MCFOLD ::HashedString const& $queryEntityRenderer() const;

    MCFOLD ::ActorUniqueID $getSourceUniqueID() const;

    MCFOLD bool $canFreeze() const;

    MCAPI void $handleInsidePortal(::BlockPos const& portalPos);

    MCAPI bool $canChangeDimensionsUsingPortal() const;

    MCAPI void $changeDimension(::DimensionType toId);

    MCFOLD void $changeDimension(::ChangeDimensionPacket const&);

    MCFOLD ::ActorUniqueID $getControllingPlayer() const;

    MCFOLD float $causeFallDamageToActor(float, float, ::ActorDamageSource);

    MCAPI void $onSynchedDataUpdate(int dataId);

    MCAPI bool $canAddPassenger(::Actor& passenger) const;

    MCFOLD bool $canPickupItem(::ItemStack const&) const;

    MCFOLD bool $canBePulledIntoVehicle() const;

    MCFOLD bool $inCaravan() const;

    MCAPI void $sendMotionPacketIfNeeded();

    MCFOLD bool $canSynchronizeNewEntity() const;

    MCAPI void $startSwimming();

    MCAPI void $stopSwimming();

    MCFOLD void $buildDebugInfo(::std::string&) const;

    MCFOLD int $getDeathTime() const;

    MCAPI bool $canBeAffected(uint id) const;

    MCAPI bool $canBeAffectedByArrow(::MobEffectInstance const& effect) const;

    MCAPI void $onEffectRemoved(::MobEffectInstance& effect);

    MCAPI bool $canObstructSpawningAndBlockPlacement() const;

    MCAPI ::AnimationComponent& $getAnimationComponent();

    MCAPI void $openContainerComponent(::Player& player);

    MCFOLD void $swing();

    MCAPI void $useItem(::ItemStackBase& item, ::ItemUseMethod itemUseMethod, bool consumeItem);

    MCAPI void $getDebugText(::std::vector<::std::string>& outputInfo);

    MCAPI float $getMapDecorationRotation() const;

    MCAPI float $getPassengerYRotation(::Actor const& passenger) const;

    MCAPI bool $add(::ItemStack& item);

    MCAPI bool $drop(::ItemStack const& item, bool const randomly);

    MCAPI bool $getInteraction(::Player& player, ::ActorInteraction& interaction, ::Vec3 const&);

    MCFOLD bool $canDestroyBlock(::Block const&) const;

    MCFOLD void $setAuxValue(int);

    MCFOLD void $renderDebugServerState(::Options const&);

    MCAPI void $kill();

    MCAPI void $die(::ActorDamageSource const& source);

    MCAPI bool $shouldDropDeathLoot() const;

    MCAPI void $applySnapshot(
        ::EntityContext const&                                   snapshotEntity,
        ::MovementDataExtractionUtility::SnapshotAccessor const& originalSnapshotEntity
    );

    MCFOLD void $onPush(::Actor&);

    MCFOLD ::std::optional<::BlockPos> $getLastDeathPos() const;

    MCFOLD ::std::optional<::DimensionType> $getLastDeathDimension() const;

    MCFOLD bool $hasDiedBefore() const;

    MCFOLD void $doEnterWaterSplashEffect();

    MCFOLD void $doExitWaterSplashEffect();

    MCAPI void $doWaterSplashEffect();

    MCAPI bool $_shouldProvideFeedbackOnHandContainerItemSet(::HandSlot handSlot, ::ItemStack const& item) const;

    MCAPI bool $_shouldProvideFeedbackOnArmorSet(::SharedTypes::Legacy::ArmorSlot slot, ::ItemStack const& item) const;

    MCAPI bool $_hurt(::ActorDamageSource const& source, float damage, bool, bool);

    MCAPI void $readAdditionalSaveData(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper);

    MCAPI void $addAdditionalSaveData(::CompoundTag& tag) const;
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
