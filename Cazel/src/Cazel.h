#pragma once // 防止头文件重复包含

// 引入 Cazel 框架的核心功能
// Application.h 提供应用程序的基本生命周期管理
// Log.h 提供统一的日志记录接口
#include "Cazel/Application.h"
#include "Cazel/Log.h"

// 优化建议：可以为这些头文件添加简短的注释，说明每个头文件的具体作用。
// 例如：
// #include "Cazel/Application.h" // 应用程序基类，管理初始化、运行和销毁
// #include "Cazel/Log.h"         // 日志系统，支持核心模块和客户端模块的日志记录

//-------------entrypotin-----------
// 引入框架的入口点相关功能
// EntryPoint.h 包含 CreateApplication 函数的声明或其他启动逻辑
#include "Cazel/EntryPoint.h"
//----------------------------------

// 优化建议：
// 1. 确保 EntryPoint.h 中的内容足够精简，仅包含与入口点相关的逻辑。
// 2. 如果 EntryPoint.h 中有复杂的实现，可以考虑将其拆分为多个模块，进一步提高可维护性。