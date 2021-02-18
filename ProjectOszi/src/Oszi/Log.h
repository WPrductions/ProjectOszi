#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Oszi {
	
	class OSZI_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

//Console Log Macros
#define OZ_FATAL(...) ::Oszi::Log::GetLogger()->fatal(__VA_ARGS__)
#define OZ_ERROR(...) ::Oszi::Log::GetLogger()->error(__VA_ARGS__)
#define OZ_WARN(...) ::Oszi::Log::GetLogger()->warn(__VA_ARGS__)
#define OZ_INFO(...) ::Oszi::Log::GetLogger()->info(__VA_ARGS__)
#define OZ_TRACE(...) ::Oszi::Log::GetLogger()->trace(__VA_ARGS__)