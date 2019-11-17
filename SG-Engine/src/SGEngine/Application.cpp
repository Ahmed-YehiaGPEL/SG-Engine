#include "sgepch.h"
#include "Application.h"
#include <GLFW/glfw3.h>
#include "Events/ApplicationEvents.h"

namespace SGEngine
{
#define BIND_EVENT_FN(FN) std::bind(&Application::FN, this, std::placeholders::_1)

	Application::Application() : mRunning(true)
	{
		mWindow = std::unique_ptr<Window>(Window::Create());
		mWindow->SetEventCallbackFunction(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		SGE_CORE_TRACE("{0}", e);
	}


	void Application::Run() const
	{
		while (mRunning)
		{
			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			mWindow->OnUpdate();
		}
	}

	bool Application::OnWindowClose(Event& e)
	{
		mRunning = false;
		return true;
	}
}
