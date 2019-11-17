#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/Event.h"


namespace SGEngine
{
	class SGE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run() const;
		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> mWindow;
		bool mRunning;
		bool OnWindowClose(Event& e);
	};

	Application* CreateApplication();
}
