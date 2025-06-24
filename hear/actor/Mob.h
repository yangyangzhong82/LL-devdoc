#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/shared_types/legacy/LevelSoundEvent.h"
#include "mc/deps/shared_types/legacy/actor/ActorDamageCause.h"
#include "mc/deps/shared_types/legacy/actor/ArmorSlot.h"
#include "mc/deps/shared_types/legacy/item/EquipmentSlot.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/world/actor/Actor.h"
#include "mc/world/actor/ActorEvent.h"
#include "mc/world/actor/ActorInitializationMethod.h"
#include "mc/world/actor/ArmorMaterialType.h"
#include "mc/world/actor/BuiltInMobComponents.h"
#include "mc/world/actor/MobSpawnMethod.h"
#include "mc/world/actor/TravelType.h"
#include "mc/world/item/ClockSpriteCalculator.h"
#include "mc/world/item/CompassSpriteCalculator.h"
#include "mc/world/level/BlockPos.h"

// auto generated forward declare list
// clang-format off
class AABB;
class ActorDamageSource;
class ActorDefinitionGroup;
class BaseAttributeMap;
class Block;
class BodyControl;
class CompoundTag;
class DataLoadHelper;
class EntityContext;
class HashedString;
class ItemStack;
class ListTag;
class Options;
class SaveContext;
class SynchedActorDataWriter;
class Vec3;
struct ActorDefinitionIdentifier;
struct JumpPreventionResult;
struct LegacyGoalDefinition;
struct VariantParameterList;
namespace mce { class UUID; }
// clang-format on

class Mob : public ::Actor { // Mob类，继承自Actor类
public:
    /**
     * @brief 刷新生物的物品栏
     * @remarks 通常用于在装备或手持物品改变后通知客户端
     */
    LLAPI void refreshInventory();

    /**
     * @brief 尝试从实体上下文获取Mob指针
     * @param entity 实体上下文
     * @param includeRemoved 是否包括已移除的生物
     * @return 指向Mob的指针，如果获取失败则为nullptr
     */
    LLAPI static ::Mob* tryGetFromEntity(::EntityContext& entity, bool includeRemoved);

public:
    // member variables
    // 成员变量
    // NOLINTBEGIN

    // 受伤方向
    ::ll::TypedStorage<4, 4, float> mHurtDir;
    // 上一帧的身体倾斜度 (用于动画插值)
    ::ll::TypedStorage<4, 4, float> mOTilt;
    // 当前身体倾斜度
    ::ll::TypedStorage<4, 4, float> mTilt;
    // 指南针精灵图计算器
    ::ll::TypedStorage<8, 32, ::CompassSpriteCalculator> mCompassSpriteCalc;
    // 回响指南针精灵图计算器
    ::ll::TypedStorage<8, 32, ::CompassSpriteCalculator> mRecoveryCompassSpriteCalc;
    // 时钟精灵图计算器
    ::ll::TypedStorage<4, 12, ::ClockSpriteCalculator> mClockSpriteCalc;
    // 攻击动画进度
    ::ll::TypedStorage<4, 4, float> mAttackAnim;
    // 挥动动画的剩余时间
    ::ll::TypedStorage<4, 4, int> mSwingTime;
    // 内置的Mob组件
    ::ll::TypedStorage<8, 24, ::BuiltInMobComponents> mBuiltInMobComponents;
    // 移动组件的当前速度
    ::ll::TypedStorage<4, 4, float> mMovementComponentCurrentSpeed;
    // 是否正在挥动手臂
    ::ll::TypedStorage<1, 1, bool> mSwinging;
    // 是否是地表生物
    ::ll::TypedStorage<1, 1, bool> mSurfaceMob;
    // 是否是自然生成的
    ::ll::TypedStorage<1, 1, bool> mNaturallySpawned;
    // 是否想要成为骑士 (如蜘蛛骑士)
    ::ll::TypedStorage<1, 1, bool> mWantsToBeJockey;
    // 是否有绑定的原点 (用于限制活动范围)
    ::ll::TypedStorage<1, 1, bool> mHasBoundOrigin;
    // 一个非常糟糕的hack，用于决定是否应用击退
    ::ll::TypedStorage<1, 2, ::std::optional<bool>> mActuallyDoKnockbackOrNotReallyBadHackDoNotUse;
    // 生成方式 (如自然生成、刷怪蛋)
    ::ll::TypedStorage<1, 1, ::MobSpawnMethod> mSpawnMethod;
    // 是否在重载时创建AI
    ::ll::TypedStorage<1, 1, bool> mCreateAiOnReload;
    // 商队的头实体ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mCaravanHead;
    // 商队的尾实体ID
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mCaravanTail;
    // 上一帧的攻击动画进度
    ::ll::TypedStorage<4, 4, float> mOAttackAnim;
    // 绑定的原点位置
    ::ll::TypedStorage<4, 12, ::BlockPos> mBoundOrigin;
    // 目标队长ID (用于袭击)
    ::ll::TypedStorage<8, 8, ::ActorUniqueID> mTargetCaptainId;
    // NOLINTEND

public:
    // prevent constructor by default
    // 默认禁止构造
    Mob();

public:
    // virtual functions
    // 虚函数
    // NOLINTBEGIN

    // vIndex: 4
    /**
     * @brief 初始化组件 (重写 Actor)
     */
    virtual void
    initializeComponents(::ActorInitializationMethod method, ::VariantParameterList const& params) /*override*/;

    // vIndex: 3
    /**
     * @brief 重新加载硬编码数据 (客户端) (重写 Actor)
     */
    virtual void reloadHardcodedClient(::ActorInitializationMethod method) /*override*/;

    // vIndex: 2
    /**
     * @brief 重新加载硬编码数据 (服务器端) (重写 Actor)
     */
    virtual void reloadHardcoded(::ActorInitializationMethod method, ::VariantParameterList const& params) /*override*/;

    // vIndex: 8
    /**
     * @brief 析构函数 (重写 Actor)
     */
    virtual ~Mob() /*override*/;

    // vIndex: 138
    /**
     * @brief 使生物被击退
     * @param source 击退来源
     * @param dmg 伤害值
     * @param xd X方向分量
     * @param zd Z方向分量
     * @param horizontalPower 水平击退强度
     * @param verticalPower 垂直击退强度
     * @param heightCap 垂直击退高度上限
     */
    virtual void
    knockback(::Actor*, int, float xd, float zd, float horizontalPower, float verticalPower, float heightCap);

    // vIndex: 122
    /**
     * @brief 杀死生物 (重写 Actor)
     */
    virtual void kill() /*override*/;

    // vIndex: 123
    /**
     * @brief 生物死亡 (重写 Actor)
     */
    virtual void die(::ActorDamageSource const& source) /*override*/;

    // vIndex: 124
    /**
     * @brief 判断死亡时是否应掉落战利品 (重写 Actor)
     */
    virtual bool shouldDropDeathLoot() const /*override*/;

    // vIndex: 139
    /**
     * @brief 播放生成动画
     */
    virtual void spawnAnim();

    // vIndex: 47
    /**
     * @brief 判断是否存活 (重写 Actor)
     */
    virtual bool isAlive() const /*override*/;

    // vIndex: 42
    /**
     * @brief 判断是否在睡觉 (重写 Actor)
     */
    virtual bool isSleeping() const /*override*/;

    // vIndex: 43
    /**
     * @brief 设置睡眠状态 (重写 Actor)
     */
    virtual void setSleeping(bool val) /*override*/;

    // vIndex: 45
    /**
     * @brief 判断是否在格挡 (重写 Actor)
     */
    virtual bool isBlocking() const /*override*/;

    // vIndex: 140
    /**
     * @brief 设置疾跑状态
     */
    virtual void setSprinting(bool shouldSprint);

    // vIndex: 96
    /**
     * @brief 判断是否能被拉入载具 (重写 Actor)
     */
    virtual bool canBePulledIntoVehicle() const /*override*/;

    // vIndex: 141
    /**
     * @brief 获取死亡音效
     */
    virtual ::SharedTypes::Legacy::LevelSoundEvent getDeathSound();

    // vIndex: 142
    /**
     * @brief 获取速度
     */
    virtual float getSpeed() const;

    // vIndex: 143
    /**
     * @brief 设置速度
     */
    virtual void setSpeed(float speed);

    // vIndex: 16
    /**
     * @brief 获取每秒偏航角速度 (重写 Actor)
     */
    virtual float getYawSpeedInDegreesPerSecond() const /*override*/;

    // vIndex: 24
    /**
     * @brief 普通的游戏刻更新 (重写 Actor)
     */
    virtual void normalTick() /*override*/;

    // vIndex: 25
    /**
     * @brief 基础的游戏刻更新 (重写 Actor)
     */
    virtual void baseTick() /*override*/;

    // vIndex: 144
    /**
     * @brief 应用受伤效果 (如播放音效、显示红光)
     */
    virtual void hurtEffects(::ActorDamageSource const& source, float damage, bool knock, bool ignite);

    // vIndex: 66
    /**
     * @brief 执行火焰伤害 (重写 Actor)
     */
    virtual bool doFireHurt(int amount) /*override*/;

    // vIndex: 145
    /**
     * @brief AI逻辑步进
     */
    virtual void aiStep();

    // vIndex: 146
    /**
     * @brief 推开其他Actor
     */
    virtual void pushActors();

    // vIndex: 147
    /**
     * @brief 检查生成规则
     */
    virtual bool checkSpawnRules(bool);

    // vIndex: 148
    /**
     * @brief 检查生成时是否有障碍物
     */
    virtual bool checkSpawnObstruction() const;

    // vIndex: 28
    /**
     * @brief 添加乘客 (重写 Actor)
     */
    virtual void addPassenger(::Actor& passenger) /*override*/;

    // vIndex: 27
    /**
     * @brief 开始骑乘 (重写 Actor)
     */
    virtual bool startRiding(::Actor& vehicle, bool forceRiding) /*override*/;

    // vIndex: 69
    /**
     * @brief 处理实体事件 (重写 Actor)
     */
    virtual void handleEntityEvent(::ActorEvent eventId, int data) /*override*/;

    // vIndex: 149
    /**
     * @brief 获取物品使用时长
     */
    virtual int getItemUseDuration() const;

    // vIndex: 150
    /**
     * @brief 获取物品使用开始进度
     */
    virtual float getItemUseStartupProgress() const;

    // vIndex: 151
    /**
     * @brief 获取物品使用间隔进度
     */
    virtual float getItemUseIntervalProgress() const;

    // vIndex: 111
    /**
     * @brief 挥动手臂 (重写 Actor)
     */
    virtual void swing() /*override*/;

    // vIndex: 152
    /**
     * @brief 获取头部的最大X轴旋转角度
     */
    virtual float getMaxHeadXRot();

    // vIndex: 40
    /**
     * @brief 判断是否无法移动 (重写 Actor)
     */
    virtual bool isImmobile() const /*override*/;

    // vIndex: 19
    /**
     * @brief 当攻击被盾牌格挡时调用 (重写 Actor)
     */
    virtual void blockedByShield(::ActorDamageSource const& source, ::Actor& blocker) /*override*/;

    // vIndex: 51
    /**
     * @brief 设置目标 (重写 Actor)
     */
    virtual void setTarget(::Actor* entity) /*override*/;

    // vIndex: 53
    /**
     * @brief 攻击 (重写 Actor)
     */
    virtual bool attack(::Actor&, ::SharedTypes::Legacy::ActorDamageCause const&) /*override*/;

    // vIndex: 153
    /**
     * @brief 判断是否与另一个Mob结盟
     */
    virtual bool isAlliedTo(::Mob*);

    // vIndex: 154
    /**
     * @brief 对目标造成伤害
     */
    virtual bool doHurtTarget(::Actor*, ::SharedTypes::Legacy::ActorDamageCause const&);

    // vIndex: 65
    /**
     * @brief 获取由方块造成的伤害原因 (重写 Actor)
     */
    virtual ::SharedTypes::Legacy::ActorDamageCause getBlockDamageCause(::Block const&) const /*override*/;

    // vIndex: 97
    /**
     * @brief 判断是否在商队中 (重写 Actor)
     */
    virtual bool inCaravan() const /*override*/;

    // vIndex: 155
    /**
     * @brief 获取盔甲值
     */
    virtual int getArmorValue() const;

    // vIndex: 156
    /**
     * @brief 对指定盔甲槽位造成伤害
     */
    virtual void hurtArmorSlots(::ActorDamageSource const& source, int dmg, ::std::bitset<5> const hurtSlots);

    // vIndex: 157
    /**
     * @brief 设置受损的盔甲
     */
    virtual void setDamagedArmor(::SharedTypes::Legacy::ArmorSlot, ::ItemStack const&);

    // vIndex: 158
    /**
     * @brief 发送盔甲伤害数据
     */
    virtual void sendArmorDamage(::std::bitset<5> const);

    // vIndex: 159
    /**
     * @brief 发送盔甲数据
     */
    virtual void sendArmor(::std::bitset<5> const armorSlots);

    // vIndex: 73
    /**
     * @brief 获取指定槽位盔甲的材质类型 (重写 Actor)
     */
    virtual ::ArmorMaterialType getArmorMaterialTypeInSlot(::SharedTypes::Legacy::ArmorSlot) const /*override*/;

    // vIndex: 74
    /**
     * @brief 获取指定槽位盔甲的纹理索引 (重写 Actor)
     */
    virtual int getArmorTextureIndexInSlot(::SharedTypes::Legacy::ArmorSlot) const /*override*/;

    // vIndex: 75
    /**
     * @brief 获取指定槽位盔甲的颜色 (重写 Actor)
     */
    virtual float getArmorColorInSlot(::SharedTypes::Legacy::ArmorSlot, int) const /*override*/;

    // vIndex: 160
    /**
     * @brief 获取所有手部物品 (主手和副手)
     */
    virtual ::std::vector<::ItemStack const*> getAllHand() const;

    // vIndex: 161
    /**
     * @brief 获取所有装备 (盔甲和手部)
     */
    virtual ::std::vector<::ItemStack const*> getAllEquipment() const;

    // vIndex: 104
    /**
     * @brief 获取死亡时间 (重写 Actor)
     */
    virtual int getDeathTime() const /*override*/;


    // vIndex: 163
    /**
     * @brief 死亡时掉落装备
     */
    virtual void dropEquipmentOnDeath(::ActorDamageSource const& source);

    // vIndex: 162
    /**
     * @brief 死亡时掉落装备
     */
    virtual void dropEquipmentOnDeath();

    // vIndex: 164
    /**
     * @brief 死亡时清除带有消失诅咒的物品
     */
    virtual void clearVanishEnchantedItemsOnDeath();

    // vIndex: 165
    /**
     * @brief 发送物品栏
     */
    virtual void sendInventory(bool);

    // vIndex: 102
    /**
     * @brief 构建调试信息字符串 (重写 Actor)
     */
    virtual void buildDebugInfo(::std::string& out) const /*override*/;

    // vIndex: 13
    /**
     * @brief 获取插值计算后的身体旋转角度 (重写 Actor)
     */
    virtual float getInterpolatedBodyRot(float a) const /*override*/;

    // vIndex: 14
    /**
     * @brief 获取插值计算后的头部旋转角度 (重写 Actor)
     */
    virtual float getInterpolatedHeadRot(float a) const /*override*/;

    // vIndex: 15
    /**
     * @brief 获取插值计算后的身体偏航角 (重写 Actor)
     */
    virtual float getInterpolatedBodyYaw(float a) const /*override*/;

    // vIndex: 49
    /**
     * @brief 判断是否为地表生物 (重写 Actor)
     */
    virtual bool isSurfaceMob() const /*override*/;

    // vIndex: 166
    /**
     * @brief 获取经过附魔减伤后的伤害值
     */
    virtual float getDamageAfterEnchantReduction(::ActorDamageSource const& source, float damage) const;

    // vIndex: 167
    /**
     * @brief 创建AI目标
     */
    virtual bool createAIGoals();

    // vIndex: 168
    /**
     * @brief 当生物出生时调用 (例如，繁殖)
     */
    virtual void onBorn(::Actor& parent1, ::Actor& parent2);

    // vIndex: 169
    /**
     * @brief 设置物品槽
     */
    virtual bool setItemSlot(::SharedTypes::Legacy::EquipmentSlot slot, ::ItemStack const& item);

    // vIndex: 170
    /**
     * @brief 设置是否正在过渡到坐下状态
     */
    virtual void setTransitioningSitting(bool value);

    // vIndex: 0
    /**
     * @brief 判断是否拥有组件 (重写 Actor)
     */
    virtual bool hasComponent(::HashedString const& name) const /*override*/;

    // vIndex: 88
    /**
     * @brief 判断是否能使用传送门改变维度 (重写 Actor)
     */
    virtual bool canChangeDimensionsUsingPortal() const /*override*/;

    // vIndex: 21
    /**
     * @brief 传送到指定位置 (重写 Actor)
     */
    virtual void teleportTo(
        ::Vec3 const& pos,
        bool          shouldStopRiding,
        int           cause,
        int           sourceEntityType,
        bool          keepVelocity
    ) /*override*/;

    // vIndex: 171
    /**
     * @brief 获取走向目标的价值
     */
    virtual float _getWalkTargetValue(::BlockPos const&);

    // vIndex: 172
    /**
     * @brief 判断在禁止生物生成时是否可以存在
     */
    virtual bool canExistWhenDisallowMob() const;

    // vIndex: 60
    /**
     * @brief 判断是否可以进行强力跳跃 (重写 Actor)
     */
    virtual bool canPowerJump() const /*override*/;

    // vIndex: 76
    /**
     * @brief 设置装备槽中的物品 (重写 Actor)
     */
    virtual void setEquippedSlot(::SharedTypes::Legacy::EquipmentSlot slot, ::ItemStack const& item) /*override*/;


    // vIndex: 121
    /**
     * @brief 渲染服务器端的调试状态 (重写 Actor)
     */
    virtual void renderDebugServerState(::Options const& options) /*override*/;

    // vIndex: 85
    /**
     * @brief 判断是否能被冻结 (重写 Actor)
     */
    virtual bool canFreeze() const /*override*/;

    // vIndex: 173
    /**
     * @brief 更新死亡逻辑
     */
    virtual void tickDeath();

    // vIndex: 137
    /**
     * @brief 添加额外的存档数据 (重写 Actor)
     */
    virtual void addAdditionalSaveData(::CompoundTag& tag) const /*override*/;

    // vIndex: 136
    /**
     * @brief 读取额外的存档数据 (重写 Actor)
     */
    virtual void readAdditionalSaveData(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper) /*override*/;

    // vIndex: 174
    /**
     * @brief 初始化身体控制器
     */
    virtual ::std::unique_ptr<::BodyControl> initBodyControl();

    // vIndex: 92
    /**
     * @brief 对Actor造成摔落伤害 (重写 Actor)
     */
    virtual float causeFallDamageToActor(float distance, float multiplier, ::ActorDamageSource source) /*override*/;

    // vIndex: 1
    /**
     * @brief 当掉出世界时调用 (重写 Actor)
     */
    virtual void outOfWorld() /*override*/;

    // vIndex: 135
    /**
     * @brief 内部受伤处理 (重写 Actor)
     */
    virtual bool _hurt(::ActorDamageSource const& source, float damage, bool knock, bool) /*override*/;

    // vIndex: 175
    /**
     * @brief 新的服务端AI步进
     */
    virtual void newServerAiStep();

    // vIndex: 7
    /**
     * @brief 执行初始移动 (重写 Actor)
     */
    virtual void _doInitialMove() /*override*/;

    // vIndex: 176
    /**
     * @brief 获取用于生成检查的调整后碰撞箱
     */
    virtual ::AABB _getAdjustedAABBForSpawnCheck(::AABB const& aabb, ::Vec3 const&) const;
    // NOLINTEND

public:
    // member functions
    // 成员函数
    // NOLINTBEGIN

    /**
     * @brief Mob构造函数
     */
    MCAPI
    Mob(::ActorDefinitionGroup*            definitions,
        ::ActorDefinitionIdentifier const& definitionName,
        ::EntityContext&                   entityContext);

    /**
     * @brief 内部方法：添加内置Mob组件
     */
    MCAPI ::BuiltInMobComponents _addBuiltInMobComponents();

    /**
     * @brief 内部方法：执行灵魂疾行粒子效果
     */
    MCAPI void _doSoulSpeedParticleEffect();

    /**
     * @brief 内部方法：初始化硬编码的组件
     */
    MCAPI bool _initHardCodedComponents(bool isClientSide);

    /**
     * @brief 内部方法：初始化
     */
    MCAPI void _initialize(::EntityContext& entityContext, bool isClientSide);

    /**
     * @brief 内部方法：记录Mob组件初始化错误
     */
    MCAPI void _logMobComponentInitializationError(
        ::std::string const& typeName,
        ::std::string const& existingName,
        char const*          descriptionJsonName
    );

    /**
     * @brief 内部方法：处理灵魂疾行
     */
    MCAPI void _processSoulSpeed();

    /**
     * @brief 内部方法：注册Mob属性
     */
    MCAPI void _registerMobAttributes();

    /**
     * @brief 内部方法：保存盔甲到NBT
     */
    MCAPI ::std::unique_ptr<::ListTag> _saveArmor(::SaveContext const& saveContext) const;

    /**
     * @brief 内部方法：验证属性
     */
    MCAPI void _verifyAttributes();

    /**
     * @brief 计算相对移动速度
     * @param travelType 移动类型 (如行走、游泳)
     * @return 相对速度
     */
    MCAPI float calcMoveRelativeSpeed(::TravelType travelType);

    /**
     * @brief 检查受击后是否免疫伤害
     * @return 如果免疫则返回true
     */
    MCAPI bool checkForPostHitDamageImmunity(float damageDifference, ::ActorDamageSource const& source);

    /**
     * @brief 检查不死图腾的死亡保护
     * @return 如果图腾生效则返回true
     */
    MCAPI bool checkTotemDeathProtection(::ActorDamageSource const& killingDamage);

    /**
     * @brief 清空主手槽位
     */
    MCAPI void clearMainHandSlot();

    /**
     * @brief 当容器发生变化时调用
     */
    MCAPI void containerChanged(int iSlot);

    /**
     * @brief 创建AI
     * @param goals AI目标定义列表
     */
    MCAPI void createAI(::std::vector<::LegacyGoalDefinition> goals);

    /**
     * @brief 掉落"背包" (例如，被杀死的劫掠兽)
     */
    MCAPI void dropBags();

    /**
     * @brief 掉落容器内物品
     */
    MCAPI void dropContainer();

    /**
     * @brief 发出跳跃被阻止的事件
     */
    MCAPI void emitJumpPreventedEvent(::BlockPos const& pos);

    /**
     * @brief 执行冰霜行者效果
     */
    MCAPI void frostWalk();

    /**
     * @brief 获取盔甲覆盖百分比
     */
    MCAPI float getArmorCoverPercentage() const;

    /**
     * @brief 获取盔甲类型的哈希值
     */
    MCAPI int getArmorTypeHash();

    /**
     * @brief 获取商队大小
     */
    MCAPI int getCaravanSize() const;

    /**
     * @brief 获取当前挥动动画的时长
     */
    MCAPI int getCurrentSwingDuration();

    /**
     * @brief 获取经过盔甲减伤后的伤害值
     */
    MCAPI float getDamageAfterArmorReduction(::ActorDamageSource const& source, float damage) const;

    /**
     * @brief 获取经过伤害感知组件调整后的伤害值
     */
    MCAPI float getDamageAfterDamageSensorComponentAdjustments(::ActorDamageSource const& source, float damage);

    /**
     * @brief 获取经过抗性效果减伤后的伤害值
     */
    MCAPI float getDamageAfterResistanceEffect(::ActorDamageSource const& source, float damage) const;


    /**
     * @brief 获取伤害原因
     */
    MCAPI ::SharedTypes::Legacy::ActorDamageCause getDamageCause() const;

    /**
     * @brief 获取进食计数器
     */
    MCAPI int getEatCounter() const;

    /**
     * @brief 获取预期的摔落伤害
     */
    MCAPI float getExpectedFallDamage(float distance, float multiplier) const;

    /**
     * @brief 获取商队的第一个头实体
     */
    MCAPI ::Mob* getFirstCaravanHead();

    /**
     * @brief 获取受伤音效
     */
    MCAPI ::SharedTypes::Legacy::LevelSoundEvent getHurtSound(::SharedTypes::Legacy::ActorDamageCause cause);

    /**
     * @brief 获取指定装备槽的物品
     */
    MCAPI ::ItemStack const& getItemSlot(::SharedTypes::Legacy::EquipmentSlot slot) const;

    /**
     * @brief 获取跳跃提升效果的放大器值
     */
    MCAPI float getJumpEffectAmplifierValue();

    /**
     * @brief 获取跳跃阻止结果
     */
    MCAPI ::JumpPreventionResult getJumpPrevention();


    /**
     * @brief 获取近战击退加成
     */
    MCAPI int getMeleeKnockbackBonus();

    /**
     * @brief 获取移动类型
     */
    MCAPI ::TravelType getTravelType();

    /**
     * @brief 获取身体的Y轴旋转
     */
    MCAPI float getYBodyRotation() const;

    /**
     * @brief 伤害盔甲
     */
    MCAPI void hurtArmor(::ActorDamageSource const& source, int dmg);

    /**
     * @brief 判断是否在疾跑
     */
    MCAPI bool isSprinting() const;

    /**
     * @brief 从地面跳跃
     */
    MCAPI void jumpFromGround();

    /**
     * @brief 击退 (非虚函数版本)
     */
    MCAPI void knockback(::Actor* source, int dmg, float xd, float zd, float horizontalPower, float verticalPower);

    /**
     * @brief 看向一个实体
     * @param lookAt 目标实体
     * @param yMax Y轴最大转动角度
     * @param xMax X轴最大转动角度
     */
    MCAPI void lookAt(::Actor* lookAt, float yMax, float xMax);

    /**
     * @brief 移除速度修饰符
     */
    MCAPI void removeSpeedModifier(::mce::UUID const& attributeID);

    /**
     * @brief 重置属性
     */
    MCAPI void resetAttributes();

    /**
     * @brief 保存副手物品到NBT
     */
    MCAPI ::std::unique_ptr<::ListTag> saveOffhand(::SaveContext const& saveContext) const;

    /**
     * @brief 发送指定盔甲槽的数据
     */
    MCAPI void sendArmorSlot(::SharedTypes::Legacy::ArmorSlot slot);

    /**
     * @brief 设置进食计数器
     */
    MCAPI void setEatCounter(int value);

    /**
     * @brief 设置跳跃的剩余刻数
     */
    MCAPI void setJumpTicks(int ticks);

    /**
     * @brief 设置身体的Y轴旋转
     */
    MCAPI void setYBodyRotation(float rotation);

    /**
     * @brief 设置身体的Y轴旋转 (带旧值)
     */
    MCAPI void setYBodyRotations(float rotation, float oldRotation);

    /**
     * @brief 判断是否应应用水中重力
     */
    MCAPI bool shouldApplyWaterGravity();

    /**
     * @brief 立即设置身体的Y轴旋转
     */
    MCAPI void snapToYBodyRot(float yBodyRot);

    /**
     * @brief 立即设置头部的Y轴旋转
     */
    MCAPI void snapToYHeadRot(float yHeadRot);

    /**
     * @brief 更新生物效果的视觉效果
     */
    MCAPI void tickMobEffectsVisuals();

    /**
     * @brief 更新装备
     */
    MCAPI void updateEquipment();

    /**
     * @brief 更新鞘翅的耐久度
     */
    MCAPI void updateGlidingDurability();
    // NOLINTEND

public:
    // static functions
    // 静态函数
    // NOLINTBEGIN

    /**
     * @brief 静态方法：设置疾跑状态
     */
    MCAPI static void setSprinting(::BaseAttributeMap& attributes, ::SynchedActorDataWriter data, bool shouldSprint);
    // NOLINTEND

public:
    // static variables
    // 静态变量
    // NOLINTBEGIN
    MCAPI static float const& ASCEND_BLOCK_BY_JUMPING_SPEED(); // 跳跃爬上方块的速度
    MCAPI static float const& DEFAULT_GRAVITY();               // 默认重力
    MCAPI static float const& FRICTION_CONSTANT();             // 摩擦系数
    MCAPI static float const& FRICTION_CONSTANT_MODIFIED();    // 修改后的摩擦系数
    MCAPI static float const& FRICTION_MODIFIER();             // 摩擦修正值
    MCAPI static float const& GLIDING_FALL_RESET_DELTA();      // 滑翔时重置摔落距离的增量
    MCAPI static float const& LADDER_CLIMB_SPEED();            // 爬梯子速度
    MCAPI static float const& SLOW_FALL_GRAVITY();             // 缓降效果的重力

public:
    // constructor thunks
    // NOLINTBEGIN
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
    MCAPI void $initializeComponents(::ActorInitializationMethod method, ::VariantParameterList const& params);

    MCAPI void $reloadHardcodedClient(::ActorInitializationMethod method);

    MCAPI void $reloadHardcoded(::ActorInitializationMethod method, ::VariantParameterList const& params);

    MCAPI void
    $knockback(::Actor*, int, float xd, float zd, float horizontalPower, float verticalPower, float heightCap);

    MCAPI void $kill();

    MCAPI void $die(::ActorDamageSource const& source);

    MCAPI bool $shouldDropDeathLoot() const;

    MCFOLD void $spawnAnim();

    MCAPI bool $isAlive() const;

    MCAPI bool $isSleeping() const;

    MCAPI void $setSleeping(bool val);

    MCAPI bool $isBlocking() const;

    MCAPI void $setSprinting(bool shouldSprint);

    MCFOLD bool $canBePulledIntoVehicle() const;

    MCAPI ::SharedTypes::Legacy::LevelSoundEvent $getDeathSound();

    MCAPI float $getSpeed() const;

    MCAPI void $setSpeed(float speed);

    MCAPI float $getYawSpeedInDegreesPerSecond() const;

    MCAPI void $normalTick();

    MCAPI void $baseTick();

    MCAPI void $hurtEffects(::ActorDamageSource const& source, float damage, bool knock, bool ignite);

    MCAPI bool $doFireHurt(int amount);

    MCAPI void $aiStep();

    MCAPI void $pushActors();

    MCAPI bool $checkSpawnRules(bool);

    MCAPI bool $checkSpawnObstruction() const;

    MCAPI void $addPassenger(::Actor& passenger);

    MCAPI bool $startRiding(::Actor& vehicle, bool forceRiding);

    MCAPI void $handleEntityEvent(::ActorEvent eventId, int data);

    MCFOLD int $getItemUseDuration() const;

    MCFOLD float $getItemUseStartupProgress() const;

    MCFOLD float $getItemUseIntervalProgress() const;

    MCAPI void $swing();

    MCAPI float $getMaxHeadXRot();

    MCAPI bool $isImmobile() const;

    MCAPI void $blockedByShield(::ActorDamageSource const& source, ::Actor& blocker);

    MCFOLD void $setTarget(::Actor* entity);

    MCFOLD bool $isAlliedTo(::Mob*);

    MCAPI bool $inCaravan() const;

    MCAPI int $getArmorValue() const;

    MCAPI void $hurtArmorSlots(::ActorDamageSource const& source, int dmg, ::std::bitset<5> const hurtSlots);

    MCFOLD void $sendArmorDamage(::std::bitset<5> const);

    MCAPI void $sendArmor(::std::bitset<5> const armorSlots);

    MCAPI ::std::vector<::ItemStack const*> $getAllHand() const;

    MCAPI ::std::vector<::ItemStack const*> $getAllEquipment() const;

    MCAPI int $getDeathTime() const;

    MCAPI void $dropEquipmentOnDeath(::ActorDamageSource const& source);

    MCAPI void $dropEquipmentOnDeath();

    MCAPI void $clearVanishEnchantedItemsOnDeath();

    MCAPI void $sendInventory(bool);

    MCAPI void $buildDebugInfo(::std::string& out) const;

    MCAPI float $getInterpolatedBodyRot(float a) const;

    MCAPI float $getInterpolatedHeadRot(float a) const;

    MCAPI float $getInterpolatedBodyYaw(float a) const;

    MCAPI bool $isSurfaceMob() const;

    MCAPI float $getDamageAfterEnchantReduction(::ActorDamageSource const& source, float damage) const;

    MCAPI bool $createAIGoals();

    MCFOLD void $onBorn(::Actor&, ::Actor&);

    MCAPI bool $setItemSlot(::SharedTypes::Legacy::EquipmentSlot slot, ::ItemStack const& item);

    MCAPI void $setTransitioningSitting(bool value);

    MCAPI bool $hasComponent(::HashedString const& name) const;

    MCAPI bool $canChangeDimensionsUsingPortal() const;

    MCAPI void
    $teleportTo(::Vec3 const& pos, bool shouldStopRiding, int cause, int sourceEntityType, bool keepVelocity);

    MCFOLD float $_getWalkTargetValue(::BlockPos const&);

    MCAPI bool $canExistWhenDisallowMob() const;

    MCAPI bool $canPowerJump() const;

    MCAPI void $setEquippedSlot(::SharedTypes::Legacy::EquipmentSlot slot, ::ItemStack const& item);

    MCFOLD void $renderDebugServerState(::Options const& options);

    MCAPI bool $canFreeze() const;

    MCAPI void $tickDeath();

    MCAPI void $addAdditionalSaveData(::CompoundTag& tag) const;

    MCAPI void $readAdditionalSaveData(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper);

    MCAPI ::std::unique_ptr<::BodyControl> $initBodyControl();

    MCAPI float $causeFallDamageToActor(float distance, float multiplier, ::ActorDamageSource source);

    MCAPI void $outOfWorld();

    MCAPI bool $_hurt(::ActorDamageSource const& source, float damage, bool knock, bool);

    MCFOLD void $newServerAiStep();

    MCAPI void $_doInitialMove();

    MCAPI ::AABB $_getAdjustedAABBForSpawnCheck(::AABB const& aabb, ::Vec3 const&) const;
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
