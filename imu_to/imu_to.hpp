/**
 * @file imu_to.hpp
 * @author qingyu
 * @brief
 * @version 0.2
 * @date 2026-11-13
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

    float quaternion[4] = {1.0f, 0.0f, 0.0f, 0.0f};
    float gyro[3]       = {0.0f, 0.0f, 0.0f};
    float accel[3]      = {0.0f, 0.0f, 0.0f};

    float temperature = 0.0f;
    float roll        = 0.0f;
    float pitch       = 0.0f;
    float yaw         = 0.0f;
    float yaw_total   = 0.0f;

    /* 滤波器内部状态，供诊断 */
    float bg[1]       = {0.0f};			// 陀螺 yaw 零偏 (rad/s)
    float chi2        = 0.0f;			// 卡方检验值
    float k_scale     = 1.0f;			// 增益缩放
    float w_norm      = 0.0f;			// 角速度幅值 (rad/s)
    float a_norm      = 0.0f;			// 加速度幅值 (m/s^2)
    bool  stable      = false;			// 静止判定
};

} // namespace topic::imu_to

ZBUS_CHAN_DECLARE(pub_imu_to);
ZBUS_OBS_DECLARE(sub_imu_to);
