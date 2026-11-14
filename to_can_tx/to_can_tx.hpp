/**
 * @file to_can_tx.hpp
 * @author qingyu
 * @brief
 * @version 0.1
 * @date 2026-05-14
 *
 * @copyright Copyright (c) 2026
 *
 */

#pragma once

#include <stdint.h>
#include <zephyr/kernel.h>

extern struct k_msgq user_can0_msgq;
extern struct k_msgq user_can1_msgq;

namespace topic::to_can_tx {

struct Message {
    uint16_t tx_id;
    uint32_t version;		// 发送序号，用于核对发布/订阅链路
    uint8_t  data[8];
};

} // namespace topic::to_can_tx
