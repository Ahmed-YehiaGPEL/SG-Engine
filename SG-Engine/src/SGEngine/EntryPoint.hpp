#pragma once
#include "../SGEngine.hpp"
#ifdef SGE_PLATFORM_WINDOWS

extern SGEngine::Application* SGEngine::CreateApplication();

int main()
{
	printf("Engine Started\n");
	const auto app = SGEngine::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Undefined Platform
#endif
