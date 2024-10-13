#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Makena
{
	class MAKENA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define MKN_CORE_TRACE(...)	::Makena::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MKN_CORE_INFO(...)	::Makena::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MKN_CORE_WARN(...)	::Makena::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MKN_CORE_ERROR(...) ::Makena::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MKN_CORE_FATAL(...) ::Makena::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MKN_TRACE(...)		::Makena::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MKN_INFO(...)		::Makena::Log::GetClientLogger()->info(__VA_ARGS__)
#define MKN_WARN(...)		::Makena::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MKN_ERROR(...)		::Makena::Log::GetClientLogger()->error(__VA_ARGS__)
#define MKN_FATAL(...)		::Makena::Log::GetClientLogger()->fatal(__VA_ARGS__)