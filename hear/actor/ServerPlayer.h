#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/common/SubClientId.h"
#include "mc/deps/core/platform/PlatformType.h"
#include "mc/deps/core/string/HashedString.h"
#include "mc/deps/core/utility/AutomaticID.h"
#include "mc/deps/core/utility/CrashDumpLogStringID.h"
#include "mc/deps/core/utility/NonOwnerPointer.h"
#include "mc/deps/input/InputMode.h"
#include "mc/deps/shared_types/legacy/actor/ArmorSlot.h"
#include "mc/legacy/ActorUniqueID.h"
#include "mc/util/CallbackToken.h"
#include "mc/util/HudElement.h"
#include "mc/util/HudVisibility.h"
#include "mc/world/ContainerID.h"
#include "mc/world/actor/ActorEvent.h"
#include "mc/world/actor/ActorInitializationMethod.h"
#include "mc/world/actor/player/Player.h"
#include "mc/world/inventory/InventoryMenu.h"
#include "mc/world/level/GameType.h"
#include "mc/world/level/Tick.h"

// auto generated forward declare list
// clang-format off
class Actor;
class ActorDamageSource;
class BlockActor;
class BlockPos;
class ChunkSource;
class ComplexInventoryTransaction;
class CompoundTag;
class Container;
class ContainerManagerModel;
class DataLoadHelper;
class Dimension;
class EntityContext;
class FrameUpdateContextBase;
class GameServerToken;
class IContainerManager;
class InventoryTransaction;
class ItemStack;
class Level;
class NetworkIdentifier;
class Packet;
class PacketSender;
class PlayerEventCoordinator;
class ResolvedTextObject;
class ServerNetworkSystem;
class TextObjectRoot;
class Vec3;
struct INpcDialogueData;
struct PlayerMovementSettings;
struct SyncedClientOptionsComponent;
struct VariantParameterList;
namespace ClientBlobCache::Server { class ActiveTransfersManager; }
namespace Editor { class IEditorManager; }
namespace Editor { class IEditorPlayer; }
namespace mce { class UUID; }
// clang-format on

class ServerPlayer : public ::Player { // ServerPlayer类，继承自Player类
public:
    // ServerPlayer inner types declare
    // ServerPlayer 内部类型声明
    // clang-format off
        struct NearbyActor; // 附近Actor的结构
    // clang-format on

    // ServerPlayer inner types define
    // ServerPlayer 内部类型定义
    using OnPlayerLoadedCallback = ::std::function<void(::ServerPlayer&)>; // 玩家加载完成时的回调函数类型

    // 附近的Actor结构，用于追踪玩家周围的实体状态
    struct NearbyActor {
    public:
        // NearbyActor inner types define
        // NearbyActor 内部类型定义
        enum class State : int {
            Unknown  = 0, // 未知状态
            New      = 1, // 新出现的
            Exist    = 2, // 已存在
            DidExist = 3, // 曾经存在过
        };

    public:
        // member variables
        // 成员变量
        // NOLINTBEGIN
        // 是否是自主的 (由服务器控制)
        ::ll::TypedStorage<1, 1, bool> isAutonomous;
        // 状态
        ::ll::TypedStorage<4, 4, ::ServerPlayer::NearbyActor::State> state;
        // 临时Actor指针
        ::ll::TypedStorage<8, 8, ::Actor*> tempActor;
        // NOLINTEND
    };

public:
    // member variables
    // 成员变量
    // NOLINTBEGIN

    // 客户端平台类型 (如 Win10, Android)
    ::ll::TypedStorage<4, 4, ::PlatformType> mPlatformType;
    // 服务器网络系统引用
    ::ll::TypedStorage<8, 8, ::ServerNetworkSystem&> mNetwork;
    // 玩家加载完成时的回调函数
    ::ll::TypedStorage<8, 64, ::std::function<void(::ServerPlayer&)>> mOnPlayerLoadedCallback;
    // 物品栏菜单
    ::ll::TypedStorage<8, 112, ::InventoryMenu> mInventoryMenu;
    // 容器ID计数器
    ::ll::TypedStorage<1, 1, ::ContainerID> mContainerCounter;
    // 最大区块加载半径
    ::ll::TypedStorage<4, 4, uint> mMaxChunkRadius;
    // 初始玩家加载是否正在进行
    ::ll::TypedStorage<1, 1, bool> mIsInitialPlayerLoadHappening;
    // 是否是教师 (教育版功能)
    ::ll::TypedStorage<1, 1, bool> mIsTeacher;
    // 本地玩家是否已初始化
    ::ll::TypedStorage<1, 1, bool> mLocalPlayerInitialized;
    // 是否正在等待常加载区域(Ticking Area)预加载
    ::ll::TypedStorage<1, 1, bool> mWaitingForTickingAreasPreload;
    // 上一个使用盾牌格挡的游戏刻
    ::ll::TypedStorage<8, 8, ::Tick> mPrevShieldBlockingTick;
    // 客户端的视野半径
    ::ll::TypedStorage<4, 4, uint> mClientViewRadius;
    // 客户端请求的视野半径
    ::ll::TypedStorage<4, 4, uint> mClientRequestedRadius;
    // 是否与客户端侧区块生成兼容
    ::ll::TypedStorage<1, 1, bool> mIsCompatibleWithClientSideChunkGen;
    // 剩余的结构刷新刻数
    ::ll::TypedStorage<4, 4, int> mRemainingStructureRefreshTicks;
    // 当前所在的结构特征
    ::ll::TypedStorage<8, 48, ::HashedString> mCurrentStructureFeature;
    // 上一个已知的同步游戏刻
    ::ll::TypedStorage<4, 4, int> mLastKnownSyncTick;
    // 附近的Actor列表
    ::ll::TypedStorage<8, 64, ::std::unordered_map<::ActorUniqueID, ::ServerPlayer::NearbyActor>> mNearbyActors;
    // 关闭容器的回调令牌
    ::ll::TypedStorage<8, 16, ::CallbackToken> mCloseContainerToken;
    // 编辑器模式下的服务器玩家对象
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::Editor::IEditorPlayer>> mEditorServerPlayer;
    // 是否有排队的视角移动请求
    ::ll::TypedStorage<1, 1, bool> mHasQueuedViewMove;
    // 是否正在等待断开连接
    ::ll::TypedStorage<1, 1, bool> mIsPendingDisconnect;
    // HUD元素的可见性状态数组
    ::ll::TypedStorage<4, 52, ::std::array<::HudVisibility, 13>> mHudElementsVisibilityState;
    // NOLINTEND

public:
    // prevent constructor by default
    // 默认禁止构造
    ServerPlayer& operator=(ServerPlayer const&);
    ServerPlayer(ServerPlayer const&);
    ServerPlayer();

public:
    // virtual functions
    // 虚函数
    // NOLINTBEGIN

    // vIndex: 0
    /**
     * @brief 析构函数 (重写 Player)
     */
    virtual ~ServerPlayer() /*override*/;

    // vIndex: 4
    /**
     * @brief 初始化组件 (重写 Player)
     */
    virtual void
    initializeComponents(::ActorInitializationMethod method, ::VariantParameterList const& params) /*override*/;

    // vIndex: 145
    /**
     * @brief AI逻辑步进 (重写 Player)
     */
    virtual void aiStep() /*override*/;

    // vIndex: 24
    /**
     * @brief 普通的游戏刻更新 (重写 Player)
     */
    virtual void normalTick() /*override*/;

    // vIndex: 138
    /**
     * @brief 击退 (重写 Player)
     */
    virtual void knockback(
        ::Actor* source,
        int      dmg,
        float    xd,
        float    zd,
        float    horizontalPower,
        float    verticalPower,
        float    heightCap
    ) /*override*/;

    // vIndex: 123
    /**
     * @brief 死亡处理 (重写 Player)
     */
    virtual void die(::ActorDamageSource const& source) /*override*/;

    // vIndex: 185
    /**
     * @brief 移动视角 (重写 Player)
     */
    virtual void moveView() /*override*/;

    // vIndex: 186
    /**
     * @brief 移动生成点视角 (重写 Player)
     */
    virtual void moveSpawnView(::Vec3 const& spawnPosition, ::DimensionType dimension) /*override*/;

    // vIndex: 183
    /**
     * @brief 帧更新 (重写 Player)
     */
    virtual void frameUpdate(::FrameUpdateContextBase&) /*override*/;

    // vIndex: 52
    /**
     * @brief 判断是否为有效目标 (重写 Player)
     */
    virtual bool isValidTarget(::Actor* attacker) const /*override*/;

    // vIndex: 156
    /**
     * @brief 对指定盔甲槽位造成伤害 (重写 Mob)
     */
    virtual void
    hurtArmorSlots(::ActorDamageSource const& source, int dmg, ::std::bitset<5> const hurtSlots) /*override*/;

    // vIndex: 158
    /**
     * @brief 发送盔甲伤害数据 (重写 Mob)
     */
    virtual void sendArmorDamage(::std::bitset<5> const damagedSlots) /*override*/;

    // vIndex: 159
    /**
     * @brief 发送盔甲数据 (重写 Mob)
     */
    virtual void sendArmor(::std::bitset<5> const armorSlots) /*override*/;

    // vIndex: 157
    /**
     * @brief 设置受损的盔甲 (重写 Mob)
     */
    virtual void setDamagedArmor(::SharedTypes::Legacy::ArmorSlot, ::ItemStack const&) /*override*/;

    // vIndex: 165
    /**
     * @brief 发送物品栏 (重写 Player)
     */
    virtual void sendInventory(bool shouldSelectSlot) /*override*/;

    // vIndex: 228
    /**
     * @brief 发送物品栏交易 (重写 Player)
     */
    virtual void sendInventoryTransaction(::InventoryTransaction const& transaction) const /*override*/;

    // vIndex: 229
    /**
     * @brief 发送复杂的物品栏交易 (重写 Player)
     */
    virtual void sendComplexInventoryTransaction(::std::unique_ptr<::ComplexInventoryTransaction> transaction) const
        /*override*/;

    // vIndex: 230
    /**
     * @brief 发送网络数据包 (重写 Player)
     */
    virtual void sendNetworkPacket(::Packet& packet) const /*override*/;

    // vIndex: 201
    /**
     * @brief 显示文本对象消息 (重写 Player)
     */
    virtual void displayTextObjectMessage(
        ::TextObjectRoot const& textObject,
        ::std::string const&    fromXuid,
        ::std::string const&    fromPlatformId
    ) /*override*/;

    // vIndex: 203
    /**
     * @brief 显示文本对象私聊消息 (重写 Player)
     */
    virtual void displayTextObjectWhisperMessage(
        ::ResolvedTextObject const& resolvedTextObject,
        ::std::string const&        xuid,
        ::std::string const&        platformId
    ) /*override*/;

    // vIndex: 202
    /**
     * @brief 显示文本对象私聊消息 (重写 Player)
     */
    virtual void displayTextObjectWhisperMessage(
        ::std::string const& message,
        ::std::string const& xuid,
        ::std::string const& platformId
    ) /*override*/;

    // vIndex: 204
    /**
     * @brief 显示私聊消息 (重写 Player)
     */
    virtual void displayWhisperMessage(
        ::std::string const&                 author,
        ::std::string const&                 message,
        ::std::optional<::std::string> const filteredMessage,
        ::std::string const&                 xuid,
        ::std::string const&                 platformId
    ) /*override*/;

    // vIndex: 195
    /**
     * @brief 打开交易界面 (重写 Player)
     */
    virtual void openTrading(::ActorUniqueID const& uniqueID, bool useNewScreen) /*override*/;

    // vIndex: 193
    /**
     * @brief 打开作品集 (重写 Player)
     */
    virtual void openPortfolio() /*override*/;

    // vIndex: 197
    /**
     * @brief 打开NPC交互界面 (重写 Player)
     */
    virtual void openNpcInteractScreen(::std::shared_ptr<::INpcDialogueData> npc) /*override*/;

    // vIndex: 198
    /**
     * @brief 打开物品栏 (重写 Player)
     */
    virtual void openInventory() /*override*/;

    // vIndex: 194
    /**
     * @brief 打开书 (重写 Player)
     */
    virtual void openBook(int, bool, int, ::BlockActor* lectern) /*override*/;

    // vIndex: 208
    /**
     * @brief 打开告示牌编辑界面 (重写 Player)
     */
    virtual void openSign(::BlockPos const& position, bool isFrontSide) /*override*/;

    // vIndex: 187
    /**
     * @brief 检查移动统计数据 (重写 Player)
     */
    virtual void checkMovementStats(::Vec3 const& d) /*override*/;

    // vIndex: 188
    /**
     * @brief 获取当前所在的结构特征 (重写 Player)
     */
    virtual ::HashedString getCurrentStructureFeature() const /*override*/;

    // vIndex: 69
    /**
     * @brief 处理实体事件 (重写 Player)
     */
    virtual void handleEntityEvent(::ActorEvent id, int data) /*override*/;

    // vIndex: 220
    /**
     * @brief 设置容器数据 (重写 Player)
     */
    virtual void setContainerData(::IContainerManager& menu, int id, int value) /*override*/;

    // vIndex: 221
    /**
     * @brief 容器中槽位发生变化时调用 (重写 Player)
     */
    virtual void slotChanged(
        ::IContainerManager& menu,
        ::Container&         container,
        int                  slot,
        ::ItemStack const&   oldItem,
        ::ItemStack const&   newItem,
        bool                 isResultSlot
    ) /*override*/;

    // vIndex: 222
    /**
     * @brief 刷新容器 (重写 Player)
     */
    virtual void refreshContainer(::IContainerManager& menu) /*override*/;

    // vIndex: 206
    /**
     * @brief 停止在床上睡觉 (重写 Player)
     */
    virtual void stopSleepInBed(bool forcefulWakeUp, bool updateLevelList) /*override*/;

    // vIndex: 72
    /**
     * @brief 设置盔甲 (重写 Player)
     */
    virtual void setArmor(::SharedTypes::Legacy::ArmorSlot const slot, ::ItemStack const& item) /*override*/;

    // vIndex: 79
    /**
     * @brief 设置副手物品 (重写 Player)
     */
    virtual void setOffhandSlot(::ItemStack const& item) /*override*/;

    // vIndex: 164
    /**
     * @brief 死亡时清除带有消失诅咒的物品 (重写 Player)
     */
    virtual void clearVanishEnchantedItemsOnDeath() /*override*/;

    // vIndex: 88
    /**
     * @brief 判断是否能使用传送门改变维度 (重写 Player)
     */
    virtual bool canChangeDimensionsUsingPortal() const /*override*/;

    // vIndex: 90
    /**
     * @brief 改变维度 (重写 Player)
     */
    virtual void changeDimension(::DimensionType toId) /*override*/;

    // vIndex: 181
    /**
     * @brief 带着终末之诗改变维度 (重写 Player)
     */
    virtual void changeDimensionWithCredits(::DimensionType dimension) /*override*/;

    // vIndex: 213
    /**
     * @brief 设置玩家游戏模式 (重写 Player)
     */
    virtual void setPlayerGameType(::GameType gameType) /*override*/;

    // vIndex: 177
    /**
     * @brief 准备区域 (重写 Player)
     */
    virtual void prepareRegion(::ChunkSource& mainChunkSource) /*override*/;

    // vIndex: 224
    /**
     * @brief 判断一个Actor是否与此玩家相关 (重写 Player)
     */
    virtual bool isActorRelevant(::Actor const& actor) /*override*/;

    // vIndex: 91
    /**
     * @brief 获取控制此Actor的玩家ID (重写 Player)
     */
    virtual ::ActorUniqueID getControllingPlayer() const /*override*/;

    // vIndex: 178
    /**
     * @brief 销毁区域 (重写 Player)
     */
    virtual void destroyRegion() /*override*/;

    // vIndex: 226
    /**
     * @brief 当被挂起时调用 (重写 Player)
     */
    virtual void onSuspension() /*override*/;

    // vIndex: 227
    /**
     * @brief 当链接的槽位改变时调用 (重写 Player)
     */
    virtual void onLinkedSlotsChanged() /*override*/;

    // vIndex: 225
    /**
     * @brief 判断是否是教师 (重写 Player)
     */
    virtual bool isTeacher() const /*override*/;

    // vIndex: 210
    /**
     * @brief 判断是否正在加载中 (重写 Player)
     */
    virtual bool isLoading() const /*override*/;

    // vIndex: 82
    /**
     * @brief 从NBT加载数据 (重写 Player)
     */
    virtual bool load(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper) /*override*/;

    // vIndex: 211
    /**
     * @brief 判断玩家是否已初始化完成 (重写 Player)
     */
    virtual bool isPlayerInitialized() const /*override*/;

    // vIndex: 190
    /**
     * @brief 重生 (重写 Player)
     */
    virtual void respawn() /*override*/;

    // vIndex: 231
    /**
     * @brief 获取玩家事件协调器 (重写 Player)
     */
    virtual ::PlayerEventCoordinator& getPlayerEventCoordinator() /*override*/;

    // vIndex: 241
    /**
     * @brief 销毁编辑器玩家 (重写 Player)
     */
    virtual void destroyEditorPlayer() /*override*/;

    // vIndex: 240
    /**
     * @brief 获取编辑器玩家接口 (重写 Player)
     */
    virtual ::Bedrock::NonOwnerPointer<::Editor::IEditorPlayer> getEditorPlayer() const /*override*/;

    // vIndex: 236
    /**
     * @brief 获取最大区块构建半径 (重写 Player)
     */
    virtual uchar getMaxChunkBuildRadius() const /*override*/;

    // vIndex: 242
    /**
     * @brief 获取生成区块的限制
     */
    virtual int _getSpawnChunkLimit() const;

    // vIndex: 243
    /**
     * @brief 更新区块发布者视图
     */
    virtual void _updateChunkPublisherView(::Vec3 const& position, float minDistance);

    // vIndex: 6
    /**
     * @brief 服务器端初始化ItemStack ID (重写 Player)
     */
    virtual void _serverInitItemStackIds() /*override*/;
    // NOLINTEND

public:
    // member functions
    // 成员函数
    // NOLINTBEGIN

    /**
     * @brief ServerPlayer 构造函数
     */
    MCAPI ServerPlayer(
        ::Level&                                           level,
        ::PacketSender&                                    packetSender,
        ::ServerNetworkSystem&                             network,
        ::ClientBlobCache::Server::ActiveTransfersManager& clientCacheMirror,
        ::GameType                                         playerGameType,
        bool                                               isHostingPlayer,
        ::NetworkIdentifier const&                         owner,
        ::SubClientId                                      subid,
        ::std::function<void(::ServerPlayer&)>             onPlayerLoadedCallback,
        ::mce::UUID                                        uuid,
        ::std::string const&                               playFabId,
        ::std::string const&                               deviceId,
        ::GameServerToken const&                           gameServerToken,
        int                                                maxChunkRadius,
        bool                                               enableItemStackNetManager,
        ::EntityContext&                                   entityContext,
        ::PlatformType                                     platformType,
        ::InputMode                                        inputMode,
        ::SyncedClientOptionsComponent                     clientOptions
    );

    /**
     * @brief 内部方法：检查已加载的常加载区域(Ticking Areas)
     */
    MCAPI bool _checkForLoadedTickingAreas() const;

    /**
     * @brief 内部方法：记录崩溃转储(Crash Dump)事件
     */
    MCAPI void _logCDEvent(
        ::CrashDumpLogStringID option1,
        ::CrashDumpLogStringID option2,
        ::CrashDumpLogStringID option3,
        ::CrashDumpLogStringID option4
    );

    /**
     * @brief 内部方法：移除附近的实体
     */
    MCAPI void _removeNearbyEntities();

    /**
     * @brief 内部方法：设置容器管理器模型
     */
    MCAPI void _setContainerManagerModel(::std::shared_ptr<::ContainerManagerModel> menu);

    /**
     * @brief 内部方法：更新附近的Actor
     */
    MCAPI void _updateNearbyActors();

    /**
     * @brief 接受客户端报告的位置
     */
    MCAPI void acceptClientPosition(::Vec3 const& clientPos, ::Vec3 const& clientPosDelta);

    /**
     * @brief 将一个Actor添加到复制列表
     */
    MCAPI void addActorToReplicationList(::gsl::not_null<::Actor*> actor, bool autonomous);

    /**
     * @brief 检查作弊行为
     */
    MCAPI void checkCheating(::Vec3 const& clientPos, ::Vec3 const& clientPosDelta);

    /**
     * @brief 创建编辑器玩家 (编辑器功能)
     */
    MCAPI void createEditorPlayer(::Bedrock::NonOwnerPointer<::Editor::IEditorManager> editorManager);

    /**
     * @brief 断开此玩家的连接
     */
    MCAPI void disconnect();

    /**
     * @brief 执行删除容器管理器的操作
     */
    MCAPI void doDeleteContainerManager(bool forceDisconnect);

    /**
     * @brief 执行初始生成
     */
    MCAPI void doInitialSpawn();

    /**
     * @brief 在服务器上处理实体拾取请求 (鼠标中键)
     */
    MCAPI void handleActorPickRequestOnServer(::Actor& target, bool withData, bool isActorAgentAndEduMode);

    /**
     * @brief 在服务器上处理方块拾取请求 (鼠标中键)
     */
    MCAPI void handleBlockPickRequestOnServer(::BlockPos const& position, bool withData);

    /**
     * @brief 隐藏所有HUD元素，除了指定的那些
     */
    MCAPI void hideAllExcept(::std::optional<::std::vector<::HudElement>> const& hudElements);

    /**
     * @brief 判断是否在指定方块的拾取范围内
     */
    MCAPI bool isInPickRangeOf(::BlockPos const& pos) const;

    /**
     * @brief 打开一个非托管的容器
     * @return 容器ID
     */
    MCAPI ::ContainerID openUnmanagedContainer();

    /**
     * @brief 复制后的游戏刻更新
     */
    MCAPI void postReplicationTick(::Tick const& currentTick);

    /**
     * @brief 复制前的游戏刻更新
     */
    MCAPI void preReplicationTick(::Tick const& currentTick);

    /**
     * @brief 选择一个物品 (同步到客户端快捷栏)
     */
    MCAPI bool selectItem(::ItemStack const& item);

    /**
     * @brief 设置客户端的区块加载半径
     */
    MCAPI void setClientChunkRadius(uint requestedRadius, uchar clientMaxChunkRadius);

    /**
     * @brief 设置HUD元素的可见性状态
     */
    MCAPI void setHudVisibilityState(
        ::HudVisibility                                     hudVisibility,
        ::std::optional<::std::vector<::HudElement>> const& hudElements
    );
    // NOLINTEND

public:
    // static functions
    // 静态函数
    // NOLINTBEGIN

    /**
     * @brief 初始化玩家的游戏刻更新相关组件
     */
    MCAPI static void initializePlayerTickComponents(::EntityContext& entity, ::PlayerMovementSettings const& settings);

    /**
     * @brief 尝试从实体上下文获取ServerPlayer指针
     */
    MCAPI static ::ServerPlayer* tryGetFromEntity(::EntityContext& entity, bool includeRemoved);

    // NOLINTEND

public:
    // constructor thunks
    // NOLINTBEGIN
    MCAPI void* $ctor(
        ::Level&                                           level,
        ::PacketSender&                                    packetSender,
        ::ServerNetworkSystem&                             network,
        ::ClientBlobCache::Server::ActiveTransfersManager& clientCacheMirror,
        ::GameType                                         playerGameType,
        bool                                               isHostingPlayer,
        ::NetworkIdentifier const&                         owner,
        ::SubClientId                                      subid,
        ::std::function<void(::ServerPlayer&)>             onPlayerLoadedCallback,
        ::mce::UUID                                        uuid,
        ::std::string const&                               playFabId,
        ::std::string const&                               deviceId,
        ::GameServerToken const&                           gameServerToken,
        int                                                maxChunkRadius,
        bool                                               enableItemStackNetManager,
        ::EntityContext&                                   entityContext,
        ::PlatformType                                     platformType,
        ::InputMode                                        inputMode,
        ::SyncedClientOptionsComponent                     clientOptions
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

    MCAPI void $aiStep();

    MCAPI void $normalTick();

    MCAPI void $knockback(
        ::Actor* source,
        int      dmg,
        float    xd,
        float    zd,
        float    horizontalPower,
        float    verticalPower,
        float    heightCap
    );

    MCAPI void $die(::ActorDamageSource const& source);

    MCAPI void $moveView();

    MCAPI void $moveSpawnView(::Vec3 const& spawnPosition, ::DimensionType dimension);

    MCFOLD void $frameUpdate(::FrameUpdateContextBase&);

    MCAPI bool $isValidTarget(::Actor* attacker) const;

    MCAPI void $hurtArmorSlots(::ActorDamageSource const& source, int dmg, ::std::bitset<5> const hurtSlots);

    MCAPI void $sendArmorDamage(::std::bitset<5> const damagedSlots);

    MCAPI void $sendArmor(::std::bitset<5> const armorSlots);

    MCAPI void $sendInventory(bool shouldSelectSlot);

    MCAPI void $sendInventoryTransaction(::InventoryTransaction const& transaction) const;

    MCAPI void $sendComplexInventoryTransaction(::std::unique_ptr<::ComplexInventoryTransaction> transaction) const;

    MCAPI void $sendNetworkPacket(::Packet& packet) const;

    MCAPI void $displayTextObjectMessage(
        ::TextObjectRoot const& textObject,
        ::std::string const&    fromXuid,
        ::std::string const&    fromPlatformId
    );

    MCAPI void $displayTextObjectWhisperMessage(
        ::ResolvedTextObject const& resolvedTextObject,
        ::std::string const&        xuid,
        ::std::string const&        platformId
    );

    MCAPI void $displayTextObjectWhisperMessage(
        ::std::string const& message,
        ::std::string const& xuid,
        ::std::string const& platformId
    );

    MCAPI void $displayWhisperMessage(
        ::std::string const&                 author,
        ::std::string const&                 message,
        ::std::optional<::std::string> const filteredMessage,
        ::std::string const&                 xuid,
        ::std::string const&                 platformId
    );

    MCAPI void $openTrading(::ActorUniqueID const& uniqueID, bool useNewScreen);

    MCFOLD void $openPortfolio();

    MCFOLD void $openNpcInteractScreen(::std::shared_ptr<::INpcDialogueData> npc);

    MCAPI void $openInventory();

    MCAPI void $openBook(int, bool, int, ::BlockActor* lectern);

    MCAPI void $openSign(::BlockPos const& position, bool isFrontSide);

    MCAPI void $checkMovementStats(::Vec3 const& d);

    MCAPI ::HashedString $getCurrentStructureFeature() const;

    MCAPI void $handleEntityEvent(::ActorEvent id, int data);

    MCAPI void $setContainerData(::IContainerManager& menu, int id, int value);

    MCAPI void $slotChanged(
        ::IContainerManager& menu,
        ::Container&         container,
        int                  slot,
        ::ItemStack const&   oldItem,
        ::ItemStack const&   newItem,
        bool                 isResultSlot
    );

    MCAPI void $refreshContainer(::IContainerManager& menu);

    MCAPI void $stopSleepInBed(bool forcefulWakeUp, bool updateLevelList);

    MCAPI void $setOffhandSlot(::ItemStack const& item);

    MCAPI void $clearVanishEnchantedItemsOnDeath();

    MCAPI bool $canChangeDimensionsUsingPortal() const;

    MCAPI void $changeDimension(::DimensionType toId);

    MCAPI void $changeDimensionWithCredits(::DimensionType dimension);

    MCAPI void $setPlayerGameType(::GameType gameType);

    MCAPI void $prepareRegion(::ChunkSource& mainChunkSource);

    MCAPI bool $isActorRelevant(::Actor const& actor);

    MCAPI ::ActorUniqueID $getControllingPlayer() const;

    MCAPI void $destroyRegion();

    MCAPI void $onSuspension();

    MCAPI void $onLinkedSlotsChanged();

    MCAPI bool $isTeacher() const;

    MCAPI bool $isLoading() const;

    MCAPI bool $load(::CompoundTag const& tag, ::DataLoadHelper& dataLoadHelper);

    MCAPI bool $isPlayerInitialized() const;

    MCAPI void $respawn();

    MCAPI ::PlayerEventCoordinator& $getPlayerEventCoordinator();

    MCAPI void $destroyEditorPlayer();

    MCAPI ::Bedrock::NonOwnerPointer<::Editor::IEditorPlayer> $getEditorPlayer() const;

    MCAPI uchar $getMaxChunkBuildRadius() const;

    MCAPI int $_getSpawnChunkLimit() const;

    MCAPI void $_updateChunkPublisherView(::Vec3 const& position, float minDistance);

    MCAPI void $_serverInitItemStackIds();
    // NOLINTEND

public:
    // vftables
    // NOLINTBEGIN
    MCNAPI static void** $vftable();
    // NOLINTEND
};
