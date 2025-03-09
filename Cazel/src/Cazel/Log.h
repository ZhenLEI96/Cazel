#pragma once // 防止头文件重复包含

#include <memory> // 引入智能指针
#include "Core.h" // 引入框架核心头文件
#include "spdlog/spdlog.h" // 引入 spdlog 日志库
#include "spdlog/sinks/stdout_color_sinks.h" // 引入带颜色输出的日志功能

namespace Cazel { // 使用命名空间避免命名冲突

    // Log 类，封装日志系统的功能
    class CAZEL_API Log
    {
    public:
        static void Init(); // 初始化日志系统
        // 优化建议：可以在 Init 中设置日志格式、输出目标等。

        // 获取核心模块的日志器
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

        // 获取客户端模块的日志器
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger; // 核心模块的日志器
        static std::shared_ptr<spdlog::logger> s_ClientLogger; // 客户端模块的日志器
    };

}

// 核心模块日志宏
#define CZ_CORE_TRACE(...)   ::Cazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CZ_CORE_WARN(...)    ::Cazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CZ_CORE_INFO(...)    ::Cazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CZ_CORE_ERROR(...)   ::Cazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CZ_CORE_FATAL(...)   ::Cazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// 客户端模块日志宏
#define CZ_CLIENT_TRACE(...) ::Cazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CZ_CLIENT_WARN(...)  ::Cazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CZ_CLIENT_INFO(...)  ::Cazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define CZ_CLIENT_ERROR(...) ::Cazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define CZ_CLIENT_FATAL(...) ::Cazel::Log::GetClientLogger()->fatal(__VA_ARGS__)

// 优化建议：
// 1. 添加条件编译选项，允许在发布版本中禁用低优先级日志（如 TRACE 和 INFO）。
// 示例：
// #ifdef _DEBUG
// #define CZ_CORE_TRACE(...) ::Cazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
// #else
// #define CZ_CORE_TRACE(...)
// #endif