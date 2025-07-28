#pragma once

#include "mc/_HeaderOutputPredefine.h"

/**
 * @brief 定义了库存交易过程中可能发生的各种错误类型。
 */
enum class InventoryTransactionError : int {
  /**
   * @brief 未知错误。
   */
  Unknown = 0,
  /**
   * @brief 没有错误，表示交易成功。
   */
  NoError = 1,
  /**
   * @brief 物品数量不平衡。
   *        例如，交易前后物品总数发生意外变化，可能表示物品被复制或丢失。
   */
  BalanceMismatch = 2,
  /**
   * @brief 源物品不匹配。
   *        客户端声称要移动的物品与服务器上源位置的实际物品不一致。
   */
  SourceItemMismatch = 3,
  /**
   * @brief 库存（容器）不匹配。
   *        交易涉及的库存与服务器预期的不符。
   */
  InventoryMismatch = 4,
  /**
   * @brief 大小不匹配。
   *        通常指物品堆叠大小或库存大小不正确。
   */
  SizeMismatch = 5,
  /**
   * @brief 权限不匹配。
   *        执行操作的玩家没有权限访问或修改相关库存。
   */
  AuthorityMismatch = 6,
  /**
   * @brief 状态不匹配。
   *        物品或库存的当前状态与执行交易所需的状态不符。
   */
  StateMismatch = 7,
  /**
   * @brief 被 API 拒绝。
   *        交易被脚本、插件或其他外部 API 明确拒绝。
   */
  ApiDenied = 8,
};
