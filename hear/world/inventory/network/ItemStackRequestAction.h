#pragma once // 防止头文件被重复包含

#include "mc/_HeaderOutputPredefine.h" // Minecraft 基岩版特有的预定义头文件

// auto generated inclusion list - 自动生成的包含列表
#include "mc/platform/Result.h" // 包含 Bedrock::Result，用于表示可能失败的操作结果
#include "mc/util/BidirectionalUnorderedMap.h" // 包含双向无序映射，用于枚举和字符串之间的转换
#include "mc/world/inventory/network/ItemStackRequestActionType.h" // 包含物品请求操作类型的定义

// auto generated forward declare list - 自动生成的前向声明列表
// clang-format off
class BinaryStream;
class BlockPalette;
class ItemStackRequestActionCraftBase;
class ReadOnlyBinaryStream;
// clang-format on

/**
 * @brief 物品堆栈请求操作的基类
 *
 * 代表一个单一、具体的物品操作，例如“移动一个物品”、“丢弃一个物品”或“合成一个物品”。
 * 一个完整的 ItemStackRequest (物品堆栈请求) 可能包含一个或多个这样的操作。
 * 这是一个多态基类，具体的行为由其派生类实现。
 */
class ItemStackRequestAction {
public:
  // member variables - 成员变量
  // NOLINTBEGIN
  // 存储此操作的具体类型，如移动、丢弃、合成等。
  ::ll::TypedStorage<1, 1, ::ItemStackRequestActionType> mActionType;
  // NOLINTEND

public:
  // virtual functions - 虚函数
  // NOLINTBEGIN
  // vIndex: 0
  /**
   * @brief 虚析构函数。
   * 确保通过基类指针删除派生类对象时，能够正确调用派生类的析构函数。
   */
  virtual ~ItemStackRequestAction();

  // vIndex: 1
  /**
   * @brief 如果此操作是合成相关的，则返回合成操作的指针。
   * @return 如果是合成操作，则为指向 ItemStackRequestActionCraftBase
   * 的常量指针；否则为 nullptr。
   */
  virtual ::ItemStackRequestActionCraftBase const *getCraftAction() const;

  // vIndex: 2
  /**
   * @brief 获取此操作关联的过滤后字符串的索引。
   * 用于需要文本输入的操作，如在铁砧上重命名物品。该索引指向请求中字符串列表里的特定字符串。
   * @return 字符串索引；如果无关联字符串，则通常返回-1。
   */
  virtual int getFilteredStringIndex() const;

  // vIndex: 3
  /**
   * @brief [已废弃] 在物品加载后进行某些处理。
   * @warning 函数名中的 DEPRECATEDASKTYLAING 表明此函数已废弃，不应使用。
   * 可能是用于在旧版本中处理物品ID升级等。
   */
  virtual void postLoadItems_DEPRECATEDASKTYLAING(::BlockPalette &blockPalette,
                                                  bool isClientSide);

  // vIndex: 4
  /**
   * @brief 将此操作的数据写入二进制流（序列化）。
   * @param stream 要写入的目标二进制流。
   * @note 这是一个纯虚函数，必须由派生类实现。
   */
  virtual void _write(::BinaryStream &) const = 0;

  // vIndex: 5
  /**
   * @brief 从只读二进制流中读取数据来填充此操作（反序列化）。
   * @param stream 包含操作数据的源二进制流。
   * @return 如果读取成功，则返回一个成功的 Result；否则返回一个包含错误的
   * Result。
   * @note 这是一个纯虚函数，必须由派生类实现。
   */
  virtual ::Bedrock::Result<void> _read(::ReadOnlyBinaryStream &) = 0;
  // NOLINTEND

public:
  // static functions - 静态函数
  // NOLINTBEGIN
  /**
   * @brief 从二进制流中读取数据，并创建一个具体的 ItemStackRequestAction
   * 派生类实例。
   * 这是一个工厂函数，它首先读取操作类型，然后根据类型构造相应的对象。
   * @param stream 包含操作数据的源二进制流。
   * @return 如果成功，返回一个包含新创建操作对象的
   * unique_ptr；否则返回一个错误。
   */
  MCAPI static ::Bedrock::Result<::std::unique_ptr<::ItemStackRequestAction>>
  read(::ReadOnlyBinaryStream &stream);
  // NOLINTEND

public:
  // static variables - 静态变量
  // NOLINTBEGIN
  /**
   * @brief
   * 返回一个将操作类型枚举（ItemStackRequestActionType）映射到其字符串名称的双向映射。
   * 主要用于调试和日志记录。
   */
  MCAPI static ::BidirectionalUnorderedMap<::ItemStackRequestActionType,
                                           ::std::string> const &
  actionTypeMap();
  // NOLINTEND

public:
  // destructor thunk - 析构函数调用跳板
  // (内部实现，用于虚函数表)
  // NOLINTBEGIN
  MCFOLD void $dtor();
  // NOLINTEND

public:
  // virtual function thunks - 虚函数调用跳板
  // (内部实现，用于跨模块调用虚函数)
  // NOLINTBEGIN
  MCFOLD ::ItemStackRequestActionCraftBase const *$getCraftAction() const;
  MCFOLD int $getFilteredStringIndex() const;
  MCFOLD void $postLoadItems_DEPRECATEDASKTYLAING(::BlockPalette &blockPalette,
                                                  bool isClientSide);
  // NOLINTEND

public:
  // vftables - 虚函数表
  // (内部实现)
  // NOLINTBEGIN
  MCAPI static void **$vftable();
  // NOLINTEND
};