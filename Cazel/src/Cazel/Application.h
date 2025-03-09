#pragma once // 防止头文件重复包含

#include "Core.h" // 引入核心头文件，可能包含 CAZEL_API 宏定义

namespace Cazel { // 使用命名空间避免命名冲突

    // Application 类，提供应用程序的基本生命周期管理
    class CAZEL_API Application
    {
    public:
        Application(); // 构造函数，用于初始化应用程序实例
        // 优化建议：可以在构造函数中初始化资源，例如窗口、日志系统等。

        virtual ~Application(); // 虚析构函数，确保派生类可以正确释放资源
        // 优化建议：在析构函数中释放资源，例如关闭文件、释放内存等。

        void run(); // 主循环函数，运行应用程序
        // 优化建议：实现事件处理、逻辑更新和渲染等功能。
    };

    // 全局函数声明，供框架调用以创建用户自定义的应用程序实例
    // 说明：用户需要在客户端代码中定义此函数，返回一个自定义的 Application 实例。
    // 优化建议：将返回值改为 std::unique_ptr<Application>，以避免手动管理内存。
    Application* CreateApplication();
} // namespace Cazel