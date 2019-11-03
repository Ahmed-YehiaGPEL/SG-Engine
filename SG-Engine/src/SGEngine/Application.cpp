#include "Application.h"
#include "Events/ApplicationEvents.h"
#include "Logger.h"

namespace SGEngine 
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	void Application::Run() const
	{
		WindowResizeEvent windowEvent(200, 600);
		SGE_CLIENT_INFO(windowEvent);
		while (true);
	}
}
