#include "Log.h" // 引入日志系统的声明

namespace Cazel { // 使用命名空间避免命名冲突

    // 定义静态成员变量 s_CoreLogger 和 s_ClientLogger
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    // 初始化日志系统
    void Log::Init()
    {
        // 设置全局日志格式
        // 优化建议：可以允许用户通过配置文件或参数自定义日志格式。
        spdlog::set_pattern("%^[%T] %n: %v%$");

        // 创建核心模块日志器，命名为 "HAZEL"
        s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
        s_CoreLogger->set_level(spdlog::level::trace); // 设置日志级别为 trace

        // 创建客户端模块日志器，命名为 "APP"
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace); // 设置日志级别为 trace

        // 优化建议：
        // 1. 添加对文件日志的支持，例如将日志输出到文件中。
        // 示例：
        // auto file_logger = spdlog::basic_logger_mt("file_logger", "logs/log.txt");
        // s_CoreLogger->sinks().push_back(file_logger->sinks().front());

        // 2. 在发布版本中动态调整日志级别，例如禁用 TRACE 和 INFO。
        // 示例：
        // #ifdef NDEBUG
        // s_CoreLogger->set_level(spdlog::level::warn);
        // s_ClientLogger->set_level(spdlog::level::warn);
        // #endif
    }

} // namespace Cazel