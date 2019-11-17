#include "sgepch.h"
#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace SGEngine
{
	std::shared_ptr<spdlog::logger> Logger::m_ClientLogger;
	std::shared_ptr<spdlog::logger> Logger::m_CoreLogger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] [%n]: %v%$");

		m_ClientLogger = spdlog::stdout_color_mt("CLIENT");
		m_ClientLogger->set_level(spdlog::level::trace);

		m_CoreLogger = spdlog::stdout_color_mt("SGENGINE");
		m_CoreLogger->set_level(spdlog::level::trace);
		//%^[%T] % n: %v%$
	}
}