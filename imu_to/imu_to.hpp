/**
 * @file imu_to.hpp
 * @author qingyu
 * @brief
 * @version 0.3
 * @date 2026-11-25
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#pragma once

#include <zephyr/zbus/zbus.h>

namespace topic::imu_to {

struct Message
{
    uint32_t version = 0;       // 帧序号，每解算一帧自增，订阅方据此判断数据是否仍在更新
    uint32_t sample_us = 0;     // 采样时刻，MCU 本地 µs（32 位，比较用模差）

    float quaternion[4] = {1.0f, 0.0f, 0.0f, 0.0f};
    float gyro[3]       = {0.0f, 0.0f, 0.0f};
    float accel[3]      = {0.0f, 0.0f, 0.0f};

    float temperature = 0.0f;
    float roll        = 0.0f;
    float pitch       = 0.0f;
    float yaw         = 0.0f;
    float yaw_total   = 0.0f;
};

} // namespace topic::imu_to

ZBUS_CHAN_DECLARE(pub_imu_to);
ZBUS_OBS_DECLARE(sub_imu_to);
