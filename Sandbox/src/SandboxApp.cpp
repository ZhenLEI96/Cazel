#include <Cazel.h> // 引入 Cazel 框架的核心头文件，包含 Application 类等基础功能

// 定义 Sandbox 类，继承自 Cazel::Application
// 说明：Sandbox 是用户自定义的应用程序类，继承自框架提供的基类 Application。
// 优化建议：可以在构造函数和析构函数中添加资源初始化和释放的逻辑。
class Sandbox : public Cazel::Application
{
public:
    Sandbox() // 构造函数，用于初始化 Sandbox 实例
    {
        // 优化建议：在这里可以初始化应用程序所需的资源，例如窗口、渲染器等。
    }
    ~Sandbox() // 析构函数，用于释放 Sandbox 实例占用的资源
    {
        // 优化建议：在这里可以释放资源，例如关闭文件、释放内存等。
    }
};

// 全局函数 CreateApplication，供框架调用以创建用户自定义的应用程序实例
// 说明：这是框架的入口点，框架会调用此函数来创建并运行应用程序。
// 优化建议：使用智能指针（如 std::unique_ptr）代替裸指针，避免潜在的内存泄漏问题。
Cazel::Application* Cazel::CreateApplication()
{
    return new Sandbox(); // 创建并返回一个 Sandbox 实例
}