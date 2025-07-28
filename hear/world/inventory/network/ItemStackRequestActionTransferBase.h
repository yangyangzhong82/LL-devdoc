#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/platform/Result.h"
#include "mc/world/inventory/network/ItemStackRequestAction.h"
#include "mc/world/inventory/network/ItemStackRequestSlotInfo.h"

// auto generated forward declare list
// clang-format off
class BinaryStream;
class ReadOnlyBinaryStream;
// clang-format on

/**
 * @brief 代表涉及物品转移的操作的基类。
 *
 * 这类操作通常需要一个源（Source）和一个可选的目标（Destination）。
 * 这个类提供了所有转移类操作（如拿取、放置、交换）共享的数据成员和序列化逻辑。
 * 它是 ItemStackRequestAction 的一个派生类。
 */
class ItemStackRequestActionTransferBase : public ::ItemStackRequestAction {
public:
  // member variables - 成员变量
  // NOLINTBEGIN
  // 一个标志，指示目标槽位信息（mDst）是否在网络流中被序列化。
  // 对于像“丢弃”这样没有明确目标槽位的操作，此项可能为false。
  ::ll::TypedStorage<1, 1, bool> mIsDstSerialized;
  // 一个标志，指示数量信息（mAmount）是否在网络流中被序列化。
  // 用于优化，当转移整个堆栈时可能不需要单独发送数量。
  ::ll::TypedStorage<1, 1, bool> mIsAmountSerialized;
  ::ll::TypedStorage<1, 1, uchar> mAmount; // 要转移的物品数量。
  ::ll::TypedStorage<4, 40, ::ItemStackRequestSlotInfo>
      mSrc; // 转移操作的源槽位信息。
  ::ll::TypedStorage<4, 40, ::ItemStackRequestSlotInfo>
      mDst; // 转移操作的目标槽位信息。
            // NOLINTEND

public:
  // virtual functions - 虚函数
  // NOLINTBEGIN
  // vIndex: 4
  /**
   * @brief 将此操作的数据（源、目标、数量等）写入二进制流（序列化）。
   * @override
   */
  virtual void _write(::BinaryStream &stream) const /*override*/;

  // vIndex: 5
  /**
   * @brief 从只读二进制流中读取数据来填充此操作（反序列化）。
   * @override
   */
  virtual ::Bedrock::Result<void>
  _read(::ReadOnlyBinaryStream &stream) /*override*/;

  // vIndex: 0
  /**
   * @brief 虚析构函数。
   * @override
   */
  virtual ~ItemStackRequestActionTransferBase() /*override*/ = default;
  // NOLINTEND

public:
    // virtual function thunks
    // NOLINTBEGIN
    MCNAPI void $_write(::BinaryStream& stream) const;

    MCNAPI ::Bedrock::Result<void> $_read(::ReadOnlyBinaryStream& stream);
    // NOLINTEND
};
