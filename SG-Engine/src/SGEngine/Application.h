#pragma once
#include "Core.h"

namespace SGEngine
{
	class SGE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run() const;
	};

	Application* CreateApplication();
}
