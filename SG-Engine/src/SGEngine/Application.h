#pragma once
#include "Core.h"
#include "Window.h"

namespace SGEngine
{
	class SGE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run() const;
	private:
		std::unique_ptr<Window> mWindow;
	};

	Application* CreateApplication();
}
