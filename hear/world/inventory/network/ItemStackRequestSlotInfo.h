#pragma once

#include "mc/_HeaderOutputPredefine.h"
#include "mc/world/containers/ContainerEnumName.h"
#include "mc/world/inventory/network/ItemStackNetIdVariant.h"

// auto generated inclusion list
#include "mc/world/containers/FullContainerName.h"
#include "mc/world/inventory/network/ItemStackNetIdVariant.h"

/**
 * @brief 描述一个物品请求操作中涉及到的单个槽位信息。
 *
 * 这个结构体用于精确地定位一个容器中的一个特定槽位，
 * 并且包含了客户端认为该槽位中物品的网络ID，用于服务器端验证。
 */
struct ItemStackRequestSlotInfo {
public:
  // member variables - 成员变量
  // NOLINTBEGIN
  // 完整的容器名称，用于唯一标识一个容器（例如，玩家背包、箱子等）。
  ::FullContainerName mFullContainerName;
  // 槽位索引，指明是容器中的第几个槽位。
  uchar mSlot;
  // 物品的网络ID变体。这是客户端发送的、它认为存在于该槽位中的物品的网络ID。
  // 服务器会用这个ID来验证客户端的状态是否与服务器同步，防止作弊。
  ::ItemStackNetIdVariant mNetIdVariant;
  // NOLINTEND

public:
  // prevent constructor by default - 默认禁止构造/拷贝
  ItemStackRequestSlotInfo &operator=(ItemStackRequestSlotInfo const &);
  ItemStackRequestSlotInfo(ItemStackRequestSlotInfo const &);
  ItemStackRequestSlotInfo();

public:
  // member functions - 成员函数
  // NOLINTBEGIN
  // 移动赋值运算符
  MCNAPI ::ItemStackRequestSlotInfo &operator=(::ItemStackRequestSlotInfo &&);

  // 析构函数
  MCNAPI ~ItemStackRequestSlotInfo();
  // NOLINTEND

public:
    // destructor thunk
    // NOLINTBEGIN
    MCNAPI void $dtor();
    // NOLINTEND
};
