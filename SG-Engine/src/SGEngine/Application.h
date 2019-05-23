#pragma once
#include "Core.hpp"

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
