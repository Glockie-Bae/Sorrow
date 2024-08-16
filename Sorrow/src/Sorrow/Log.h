#pragma once
#include"Core.h"
#include"spdlog\spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include<memory>

#include"spdlog/fmt/ostr.h"


namespace Sorrow {
	class SORROW_API Log {
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		
	
	};

}


// Core Log Macros
#define SW_CORE_TRACE(...)			::Sorrow::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SW_CORE_INFO(...)			::Sorrow::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SW_CORE_WARN(...)			::Sorrow::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SW_CORE_ERROR(...)			::Sorrow::Log::GetCoreLogger()->error(__VA_ARGS__)
//#define SW_CORE_FATAL(...)			::Sorrow::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client Log Macros
#define SW_Client_TRACE(...)		::Sorrow::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SW_Client_INFO(...)			::Sorrow::Log::GetClientLogger()->info(__VA_ARGS__)
#define SW_Client_WARN(...)			::Sorrow::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SW_Client_ERROR(...)		::Sorrow::Log::GetClientLogger()->error(__VA_ARGS__)
//#define SW_Client_FATAL(...)		::Sorrow::Log::GetClientLogger()->fatal(__VA_ARGS__)
