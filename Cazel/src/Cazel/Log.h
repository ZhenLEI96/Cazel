#pragma once // ��ֹͷ�ļ��ظ�����

#include <memory> // ��������ָ��
#include "Core.h" // �����ܺ���ͷ�ļ�
#include "spdlog/spdlog.h" // ���� spdlog ��־��
#include "spdlog/sinks/stdout_color_sinks.h" // �������ɫ�������־����

namespace Cazel { // ʹ�������ռ����������ͻ

    // Log �࣬��װ��־ϵͳ�Ĺ���
    class CAZEL_API Log
    {
    public:
        static void Init(); // ��ʼ����־ϵͳ
        // �Ż����飺������ Init ��������־��ʽ�����Ŀ��ȡ�

        // ��ȡ����ģ�����־��
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

        // ��ȡ�ͻ���ģ�����־��
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger; // ����ģ�����־��
        static std::shared_ptr<spdlog::logger> s_ClientLogger; // �ͻ���ģ�����־��
    };

}

// ����ģ����־��
#define CZ_CORE_TRACE(...)   ::Cazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CZ_CORE_WARN(...)    ::Cazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CZ_CORE_INFO(...)    ::Cazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CZ_CORE_ERROR(...)   ::Cazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CZ_CORE_FATAL(...)   ::Cazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// �ͻ���ģ����־��
#define CZ_CLIENT_TRACE(...) ::Cazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CZ_CLIENT_WARN(...)  ::Cazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CZ_CLIENT_INFO(...)  ::Cazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define CZ_CLIENT_ERROR(...) ::Cazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define CZ_CLIENT_FATAL(...) ::Cazel::Log::GetClientLogger()->fatal(__VA_ARGS__)

// �Ż����飺
// 1. �����������ѡ������ڷ����汾�н��õ����ȼ���־���� TRACE �� INFO����
// ʾ����
// #ifdef _DEBUG
// #define CZ_CORE_TRACE(...) ::Cazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
// #else
// #define CZ_CORE_TRACE(...)
// #endif