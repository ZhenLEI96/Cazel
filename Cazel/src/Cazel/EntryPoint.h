#pragma once // 防止头文件重复包含

// 声明全局函数 CreateApplication，供框架调用以创建用户自定义的应用程序实例
// 优化建议：将返回值改为 std::unique_ptr<Application>，以避免手动管理内存。
extern Cazel::Application* Cazel::CreateApplication();

// main 函数，程序的入口点
int main(int argc, char** argv)
{
    Cazel::Log::Init(); // 初始化日志系统
    CZ_CORE_WARN("Initialized Log!"); // 输出核心模块的警告信息

    int a = 5; // 定义一个整数变量
    CZ_CLIENT_INFO("Hello! Var = {0}", a); // 输出客户端模块的信息日志

    // 创建用户自定义的应用程序实例
    // 优化建议：使用智能指针（如 std::unique_ptr）代替裸指针，避免手动管理内存。
    auto app = Cazel::CreateApplication();

    app->run(); // 启动应用程序的主循环

    delete app; // 释放动态分配的内存
    // 优化建议：如果使用智能指针，这里不需要手动调用 delete。
}

