#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace SGEngine
{
	class SGE_API Logger
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;
	};


}
#define SGE_CORE_TRACE(...) ::SGEngine::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define SGE_CORE_ERROR(...) ::SGEngine::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define SGE_CORE_WARN(...)  ::SGEngine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define SGE_CORE_INFO(...)  ::SGEngine::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define SGE_CORE_FATAL(...) ::SGEngine::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#define SGE_CLIENT_TRACE(...) ::SGEngine::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define SGE_CLIENT_ERROR(...) ::SGEngine::Logger::GetClientLogger()->error(__VA_ARGS__)
#define SGE_CLIENT_WARN(...)  ::SGEngine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define SGE_CLIENT_INFO(...)  ::SGEngine::Logger::GetClientLogger()->info(__VA_ARGS__)
#define SGE_CLIENT_FATAL(...) ::SGEngine::Logger::GetClientLogger()->critical(__VA_ARGS__)
