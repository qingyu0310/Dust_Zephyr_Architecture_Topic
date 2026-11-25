/**
 * @file remote_to.hpp
 * @author qingyu
 * @brief
 * @version 0.2
 * @date 2026-11-25
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#pragma once

#include <cstdint>
#include <zephyr/zbus/zbus.h>

namespace topic::remote_to {

enum class ChassisMode : uint8_t
{
    Normal = 0,
    Spin,
};

enum class StartMode : uint8_t
{
    Off = 0,
    On,
};

struct Channel
{
    float chassisx = 0.0f, chassisy = 0.0f;
    float pitch    = 0.0f, yaw      = 0.0f;
};

struct Message
{
    uint32_t version   = 0;
    uint32_t sample_us = 0;     // 采样时刻，MCU 本地 µs（32 位，比较用模差）

    // 语义字段（归一化 [-1, 1]）
    float chassisx = 0.0f;
    float chassisy = 0.0f;
    float yaw      = 0.0f;
    float pitch    = 0.0f;

    // 模式标志
    ChassisMode chassis_mode    = ChassisMode::Normal;

    StartMode   shoot_ctrl      = StartMode::Off;
    StartMode   reload_ctrl     = StartMode::Off;
    StartMode   autoaim_ctrl    = StartMode::Off;
    StartMode   supercap_ctrl   = StartMode::Off;
    StartMode   robot_ctrl      = StartMode::On;	// 整车总开关

    // 自定义字段
    StartMode   custom1         = StartMode::Off;
    StartMode   custom2         = StartMode::Off;
    StartMode   custom3         = StartMode::Off;
    StartMode   custom4         = StartMode::Off;
    StartMode   custom5         = StartMode::Off;
};

}

ZBUS_CHAN_DECLARE(pub_remote_to);

ZBUS_OBS_DECLARE(sub_remote_to);
