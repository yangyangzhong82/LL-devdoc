#pragma once // 防止头文件被重复包含

#include "mc/_HeaderOutputPredefine.h" // Minecraft 基岩版特有的预定义头文件，用于构建系统
#include "mc/world/actor/player/Player.h"

// auto generated inclusion list - 自动生成的包含列表
#include "mc/deps/game_refs/WeakRef.h"
#include "mc/world/TypedRuntimeId.h"
#include "mc/world/containers/ContainerEnumName.h"
#include "mc/world/inventory/network/ItemStackNetResult.h"
#include "mc/world/inventory/network/TypedClientNetId.h"
#include "mc/world/inventory/network/TypedServerNetId.h"

// auto generated forward declare list - 自动生成的前向声明列表
// clang-format off
class Container;
class ContainerScreenContext;
class ContainerScreenValidation;
class EntityContext;
class ItemInstance;
class ItemStack;
class ItemStackNetManagerScreen;
class ItemStackNetManagerServer;
class ItemStackRequestAction;
class ItemStackRequestActionCraftHandler;
class ItemStackRequestActionTransferBase;
class Player;
class ScreenHandlerBase;
class SimpleSparseContainer;
struct ContainerRuntimeIdTag;
struct ContainerValidationCraftInputs;
struct FullContainerName;
struct ItemStackLegacyRequestIdTag;
struct ItemStackNetIdTag;
struct ItemStackRequestHandlerSlotInfo;
struct ItemStackRequestIdTag;
struct ItemStackRequestSlotInfo;
struct ItemStackResponseContainerInfo;
// clang-format on

/**
 * @brief 物品堆栈请求操作处理器
 *
 * 这个类在服务器端运行，负责处理从客户端发来的所有与物品相关的操作请求。
 * 例如，当玩家在背包或容器中移动、合成、丢弃或使用物品时，客户端会发送一个
 * ItemStackRequest， 这个类的实例会验证并执行这些请求。
 */
class ItemStackRequestActionHandler {
public:
  // ItemStackRequestActionHandler inner types declare - 内部类型声明
  // clang-format off
    struct PlayerLegacyRequestSlotIdAssignment;
    struct RequestIdAssignments;
    struct RequestSlotIdAssignment;
    struct ScreenData;
  // clang-format on

  // ItemStackRequestActionHandler inner types define - 内部类型定义

  /**
   * @brief 定义了移除物品的不同方式。
   */
  enum class RemoveType : int {
    Drop = 0,         // 丢弃物品（例如，从背包拖出）
    DropRandomly = 1, // 随机丢弃（例如，容器被破坏时）
    Destroy = 2,      // 销毁物品（例如，创造模式下的删除）
    Consume = 3,      // 消耗物品（例如，吃食物）
  };

  /**
   * @brief 记录了单个请求中，一个具体槽位的ID分配情况。
   * 用于将客户端感知的槽位与服务器端的物品网络ID进行匹配和验证。
   */
  struct RequestSlotIdAssignment {
  public:
    // member variables
    // NOLINTBEGIN
    ::ll::TypedStorage<1, 1, uchar> mSlot; // 槽位索引
    ::ll::TypedStorage<4, 4, ::ItemStackNetId>
        mServerNetId; // 该槽位上物品的服务器端网络ID
                      // NOLINTEND
  };

  /**
   * @brief 记录了单个请求ID所对应的所有槽位ID分配信息。
   * 一个请求可能涉及多个容器和多个槽位。
   */
  struct RequestIdAssignments {
  public:
    // member variables
    // NOLINTBEGIN
    ::ll::TypedStorage<8, 8, ::std::chrono::steady_clock::time_point>
        mExpireTime; // 请求的过期时间点，用于防止处理过时的请求
    // 一个映射，存储了本次请求中涉及到的所有容器及其槽位分配信息。
    // Key是容器的运行时ID，Value是另一个从槽位索引到`RequestSlotIdAssignment`的映射。
    ::ll::TypedStorage<
        8, 64,
        ::std::unordered_map<
            ::ContainerRuntimeId,
            ::std::unordered_map<uchar, ::ItemStackRequestActionHandler::
                                            RequestSlotIdAssignment>>>
        mContainers;
    // NOLINTEND
  };

  /**
   * @brief 用于处理旧版（Legacy）物品请求的槽位ID分配。
   * 兼容一些不使用现代网络ID系统的旧版容器交互。
   */
  struct PlayerLegacyRequestSlotIdAssignment {
  public:
    // member variables
    // NOLINTBEGIN
    ::ll::TypedStorage<1, 1, ::ContainerEnumName const>
        mContainerName; // 容器的枚举名称（旧版系统使用）
    ::ll::TypedStorage<4, 4, ::ContainerRuntimeId const>
        mContainerRuntimeId; // 容器的运行时ID
    // 一个向量，存储了旧版请求ID和服务器网络ID的配对。
    ::ll::TypedStorage<8, 24,
                       ::std::vector<::std::pair<::ItemStackLegacyRequestId,
                                                 ::ItemStackNetId>>>
        mSlots;
    // NOLINTEND

  public:
    // prevent constructor by default
    PlayerLegacyRequestSlotIdAssignment();

  public:
    // member functions
    // NOLINTBEGIN
    MCNAPI
    PlayerLegacyRequestSlotIdAssignment(::ContainerEnumName containerName,
                                        ::Container &container);
    MCNAPI ~PlayerLegacyRequestSlotIdAssignment();
    // NOLINTEND
  public:
    // constructor thunks
    // NOLINTBEGIN
    MCNAPI void *$ctor(::ContainerEnumName containerName,
                       ::Container &container);
    // NOLINTEND
  public:
    // destructor thunk
    // NOLINTBEGIN
    MCNAPI void $dtor();
    // NOLINTEND
  };

  /**
   * @brief 存储与当前玩家打开的屏幕（UI）相关的数据。
   * 每个屏幕（如工作台、熔炉、箱子）都有自己的一套状态和处理器。
   */
  struct ScreenData {
  public:
    // member variables
    // NOLINTBEGIN
    // 合成请求处理器，专门处理合成相关的操作。
    ::ll::TypedStorage<8, 8,
                       ::std::unique_ptr<::ItemStackRequestActionCraftHandler>>
        mCraftRequestHandler;
    // 屏幕处理器基类，处理当前屏幕的通用逻辑。
    ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ScreenHandlerBase>>
        mScreenHandler;
    // 运行时ID到稀疏容器的映射。用于在服务器端模拟客户端的容器状态，以进行验证。
    ::ll::TypedStorage<
        8, 64,
        ::std::unordered_map<::ContainerRuntimeId,
                             ::std::shared_ptr<::SimpleSparseContainer>>>
        mRuntimeIdSparseContainerMap;
    // 最近的请求记录，用于跟踪和验证，防止重放攻击或乱序处理。
    ::ll::TypedStorage<
        8, 64,
        ::std::unordered_map<
            ::ItemStackRequestId,
            ::ItemStackRequestActionHandler::RequestIdAssignments>>
        mRecentRequests;
    // NOLINTEND

  public:
    // prevent constructor by default
    ScreenData &operator=(ScreenData const &);
    ScreenData(ScreenData const &);
    ScreenData();

  public:
    // member functions
    // NOLINTBEGIN
    MCNAPI ScreenData(::ItemStackRequestActionHandler::ScreenData &&);
    MCNAPI ::ItemStackRequestActionHandler::ScreenData &
    operator=(::ItemStackRequestActionHandler::ScreenData &&);
    MCNAPI ~ScreenData();
    // NOLINTEND
  public:
    // constructor thunks
    // NOLINTBEGIN
    MCNAPI void *$ctor(::ItemStackRequestActionHandler::ScreenData &&);
    // NOLINTEND
  public:
    // destructor thunk
    // NOLINTBEGIN
    MCNAPI void $dtor();
    // NOLINTEND
  };

public:
  // member variables
  // NOLINTBEGIN
  ::ll::TypedStorage<8, 8, ::Player &>
      mPlayer; // 触发这些请求的玩家对象的引用。
  ::ll::TypedStorage<8, 8, ::ItemStackNetManagerServer &>
      mItemStackNetManager; // 物品堆栈网络管理器的引用，用于处理网络同步。
  ::ll::TypedStorage<4, 4, ::ContainerRuntimeId const>
      mPlayerArmorContainerRuntimeId; // 玩家盔甲容器的运行时ID。
  ::ll::TypedStorage<4, 4, ::ContainerRuntimeId const>
      mPlayerHandContainerRuntimeId; // 玩家主手/副手容器的运行时ID。
  ::ll::TypedStorage<4, 4, ::ContainerRuntimeId const>
      mPlayerUIContainerRuntimeId; // 玩家UI容器（背包）的运行时ID。
  // 存储玩家旧版请求的数组，用于盔甲、主手和UI容器。
  ::ll::TypedStorage<
      8, 96,
      ::std::array<
          ::ItemStackRequestActionHandler::PlayerLegacyRequestSlotIdAssignment,
          3>>
      mPlayerLegacyRequests;
  ::ll::TypedStorage<8, 8, ::std::chrono::steady_clock::time_point>
      mLastTime; // 上次处理请求的时间点，可能用于节流或超时。
  ::ll::TypedStorage<8, 24, ::WeakRef<::EntityContext>>
      mCurrentRequestScreen; // 当前请求关联的屏幕实体上下文的弱引用。
  ::ll::TypedStorage<4, 16, ::ItemStackRequestId>
      mClientRequestId; // 当前正在处理的客户端请求ID。
  // 用于构建发回给客户端的响应的容器信息。
  ::ll::TypedStorage<8, 24, ::std::vector<::ItemStackResponseContainerInfo>>
      mResponseContainerInfos;
  // 过滤后的字符串。通常与铁砧、书与笔等需要文本输入的UI相关。
  ::ll::TypedStorage<8, 16,
                     ::std::map<::std::string, ::std::vector<::std::string>>>
      mFilteredStrings;
  // 原始字符串。与`mFilteredStrings`类似，但存储的是未经处理的原始输入。
  ::ll::TypedStorage<8, 16,
                     ::std::map<::std::string, ::std::vector<::std::string>>>
      mStrings;
  // 屏幕验证器，用于验证操作是否在当前屏幕下合法。
  ::ll::TypedStorage<8, 8, ::std::unique_ptr<::ContainerScreenValidation>>
      mScreenValidation;
  // NOLINTEND

public:
  // prevent constructor by default
  ItemStackRequestActionHandler &
  operator=(ItemStackRequestActionHandler const &);
  ItemStackRequestActionHandler(ItemStackRequestActionHandler const &);
  ItemStackRequestActionHandler();

public:
  // member functions
  // NOLINTBEGIN
  /**
   * @brief 构造函数。
   * @param itemStackNetManager 物品网络管理器。
   * @param player 关联的玩家。
   */
  MCAPI ItemStackRequestActionHandler(
      ::ItemStackNetManagerServer &itemStackNetManager, ::Player &player);

  /**
   * @brief 向响应中添加一个槽位的信息。
   * 当一个槽位的内容发生变化时，调用此函数将变化记录下来，以便稍后通知客户端。
   */
  MCAPI void
  _addResponseSlotInfo(::ItemStackRequestHandlerSlotInfo const &slotInfo,
                       ::ItemStack const &item);

  /**
   * @brief 缓存一个旧版的槽位ID分配。
   */
  MCAPI void _cacheLegacySlotIdAssignment(
      ::ContainerEnumName containerName, uchar slot,
      ::ItemStackLegacyRequestId const &legacyClientRequestId,
      ::ItemStackNetId const &serverNetId);

  /**
   * @brief 缓存一个槽位ID分配。
   * 将请求中的槽位与服务器端的物品网络ID关联起来，存入缓存以备后续验证。
   */
  MCAPI void
  _cacheSlotIdAssigment(::ContainerRuntimeId const &containerRuntimeId,
                        uchar requestSlot, uchar slot,
                        ::ItemStackNetId const &serverNetId);

  /**
   * @brief 根据屏幕上下文创建一个屏幕处理器（ScreenHandler）。
   * 不同的屏幕（如工作台、熔炉）有不同的处理器实现。
   */
  MCAPI ::std::unique_ptr<::ScreenHandlerBase>
  _createScreenHandler(::ContainerScreenContext const &screenContext);

  /**
   * @brief 获取或初始化一个稀疏容器。
   * 稀疏容器用于在服务器端模拟客户端容器的状态，以进行操作验证。
   */
  MCAPI ::std::shared_ptr<::SimpleSparseContainer>
  _getOrInitSparseContainer(::FullContainerName const &openContainerId);

  /**
   * @brief 处理移除物品的请求（如丢弃、销毁）。
   * @return 操作结果（成功、失败等）。
   */
  MCAPI ::ItemStackNetResult
  _handleRemove(::ItemStackRequestActionTransferBase const &requestAction,
                ::ItemStack &removedItem,
                ::ItemStackRequestActionHandler::RemoveType removeType);

  /**
   * @brief 处理转移物品的请求（如从一个槽位移动到另一个槽位）。
   * @return 操作结果。
   */
  MCAPI ::ItemStackNetResult
  _handleTransfer(::ItemStackRequestActionTransferBase const &requestAction,
                  bool isSrcHintSlot, // 源槽位是否是提示槽位
                  bool isDstHintSlot, // 目标槽位是否是提示槽位
                  bool isSwap         // 是否是交换操作
  );

  /**
   * @brief 当玩家打开一个新屏幕时，初始化屏幕相关数据。
   */
  MCAPI void _initScreen(::ItemStackNetManagerScreen &screen);

  /**
   * @brief 解析请求中的槽位ID分配，从缓存中查找并返回。
   */
  MCAPI ::std::optional<
      ::ItemStackRequestActionHandler::RequestSlotIdAssignment>
  _resolveSlotIdAssignment(::ItemStackRequestSlotInfo const &requestSlotInfo,
                           ::ContainerRuntimeId const &containerRuntimeId);

  /**
   * @brief 尝试获取当前屏幕的数据。
   * @return 如果玩家当前打开了某个UI屏幕，则返回指向该屏幕数据的指针。
   */
  MCAPI ::ItemStackRequestActionHandler::ScreenData *
  _tryGetCurrentScreenData() const;

  /**
   * @brief 验证一个请求的槽位信息是否有效。
   * 检查容器是否存在，槽位是否有效，以及槽位中的物品是否符合预期。
   */
  MCAPI ::ItemStackRequestHandlerSlotInfo
  _validateRequestSlot(::ItemStackRequestSlotInfo const &requestSlotInfo,
                       bool isItemRequired, bool isHintSlot);

  /**
   * @brief 为特定请求ID添加字符串（例如，铁砧重命名时输入的文本）。
   */
  MCAPI void addStrings(::ItemStackRequestId requestId,
                        ::std::vector<::std::string> strings);

  /**
   * @brief 开始处理一个新的请求。
   * 设置当前请求的ID，并准备处理一系列操作。
   */
  MCAPI void beginRequest(::ItemStackRequestId const &clientRequestId,
                          ::ItemStackNetManagerScreen &screen);

  /**
   * @brief 结束当前请求，并返回最终结果和需要同步给客户端的容器信息。
   */
  MCAPI ::std::tuple<::ItemStackNetResult,
                     ::std::vector<::ItemStackResponseContainerInfo>>
  endRequest(::ItemStackNetResult currentResult);

  /**
   * @brief 获取与请求ID关联的过滤后字符串。
   */
  MCAPI ::std::vector<::std::string> const &
  getFilteredStrings(::ItemStackRequestId requestId) const;

  /**
   * @brief 获取当前的屏幕上下文。
   */
  MCAPI ::ContainerScreenContext const &getScreenContext() const;

  /**
   * @brief 获取与请求ID关联的原始字符串。
   */
  MCAPI ::std::vector<::std::string> const &
  getStrings(::ItemStackRequestId requestId) const;

  /**
   * @brief 处理单个物品请求操作。
   * 这是分发各种具体操作（如移动、合成、丢弃）的入口点。它会根据操作类型调用相应的处理函数。
   */
  MCAPI ::ItemStackNetResult
  handleRequestAction(::ItemStackRequestAction const &requestAction);

  /**
   * @brief 检查是否存在与请求ID关联的过滤后字符串。
   */
  MCAPI bool hasFilteredStrings(::ItemStackRequestId requestId) const;

  /**
   * @brief 每tick调用的常规更新函数。
   * 主要用于清理过期的请求缓存。
   */
  MCAPI void normalTick();

  /**
   * @brief 尝试执行合成操作。
   * @param craftInputs 合成所需的输入物品和配方信息。
   * @param numCrafts 尝试合成的次数。
   * @return 返回合成出的物品实例列表。
   */
  MCAPI ::std::vector<::ItemInstance>
  tryCraft(::std::unique_ptr<::ContainerValidationCraftInputs> craftInputs,
           uchar numCrafts);
  // NOLINTEND

public:
  // constructor thunks
  // NOLINTBEGIN
  MCAPI void *$ctor(::ItemStackNetManagerServer &itemStackNetManager,
                    ::Player &player);
  // NOLINTEND
};