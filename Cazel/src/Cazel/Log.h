#pragma once

#include <memory>

#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\sinks\stdout_color_sinks.h"


namespace Cazel
{
	class CAZEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define CZ_CORE_TRACE(...)   ::Cazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CZ_CORE_WARN(...)    ::Cazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CZ_CORE_INFO(...)    ::Cazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CZ_CORE_ERROR(...)   ::Cazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CZ_CORE_FATAL(...)   ::Cazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CZ_CLIENT_TRACE(...) ::Cazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CZ_CLIENT_WARN(...)  ::Cazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CZ_CLIENT_INFO(...)  ::Cazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define CZ_CLIENT_ERROR(...) ::Cazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define CZ_CLIENT_FATAL(...) ::Cazel::Log::GetClientLogger()->fatal(__VA_ARGS__)
