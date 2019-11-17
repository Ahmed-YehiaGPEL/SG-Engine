#include "sgepch.h"
#include "Application.h"
#include <GLFW/glfw3.h>

namespace SGEngine
{
	Application::Application()
	{
		mWindow = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}
	void Application::Run() const
	{
		while (true)
		{
			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			mWindow->OnUpdate();
		}
	}
}
