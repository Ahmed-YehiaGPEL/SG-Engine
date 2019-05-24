#pragma once

#ifdef SGE_PLATFORM_WINDOWS
extern SGEngine::Application* SGEngine::CreateApplication();

int main(int argc, char** argv)
{
	SGEngine::Logger::Init();
	
	SGE_CORE_INFO("Core Initialized");
	SGE_CLIENT_WARN("Empty Client started  {0:n}", 3);
	const auto app = SGEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif
