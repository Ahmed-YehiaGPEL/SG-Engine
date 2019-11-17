#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Layering/LayerStack.h"


namespace SGEngine
{
	class SGE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run() const;
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		std::unique_ptr<Window> mWindow;
		bool mRunning;
		bool OnWindowClose(Event& e);

		std::unique_ptr<LayerStack> mLayerStack;
	};

	Application* CreateApplication();
}
