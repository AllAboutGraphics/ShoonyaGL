#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace SGL
{
	class SGL_API Log
	{
		public:
			static void  Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//For SDK
#define SGL_CORE_TRACE(...) ::SGL::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SGL_CORE_INFO(...)	::SGL::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SGL_CORE_WARN(...)	::SGL::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SGL_CORE_ERROR(...) ::SGL::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SGL_CORE_FATAL(...) ::SGL::Log::GetCoreLogger()->fatal(__VA_ARGS__)
//For Client APP
#define SGL_TRACE(...)		::SGL::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SGL_INFO(...)		::SGL::Log::GetClientLogger()->info(__VA_ARGS__)
#define SGL_WARN(...)		::SGL::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SGL_ERROR(...)		::SGL::Log::GetClientLogger()->error(__VA_ARGS__)
#define SGL_FATAL(...)		::SGL::Log::GetClientLogger()->fatal(__VA_ARGS__)