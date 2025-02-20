#pragma once
#include "Core.h"
namespace Cazel {
	class CAZEL_API Application
	{
	public:
		Application(); // 构造函数，用于初始化应用程序实例
		virtual ~Application(); // 虚析构函数，确保派生类可以正确释放资源
		void run(); // 主循环函数，运行应用程序
	};
	// to be defined in CLIENT
	Application* CreateApplication();
}


