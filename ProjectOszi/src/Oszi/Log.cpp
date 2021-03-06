#include <ozpch.h>
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/pattern_formatter.h"

namespace Oszi {

	std::shared_ptr<spdlog::logger> Log::s_Logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %l: %v%$");
		s_Logger = spdlog::stdout_color_mt("Oszi");
		s_Logger->set_level(spdlog::level::trace);
	}
}