#include "sgepch.h"
#include "Application.h"
#include <glad/glad.h>
#include "Events/ApplicationEvents.h"
#include "Layering/Layer.h"

namespace SGEngine
{
#define BIND_EVENT_FN(FN) std::bind(&Application::FN, this, std::placeholders::_1)

	Application::Application() : mRunning(true)
	{
		mWindow = std::unique_ptr<Window>(Window::Create());
		mWindow->SetEventCallbackFunction(BIND_EVENT_FN(OnEvent));

		mLayerStack = std::make_unique<LayerStack>();
	}

	Application::~Application()
	{
		//mLayerStack.reset(nullptr);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for(auto i = mLayerStack->end(); i != mLayerStack->begin();)
		{
			(*--i)->OnEvent(e);
			if (e.IsHandled())
			{
				break;
			}
		}
		SGE_CORE_TRACE("{0}", e);
	}

	void Application::PushLayer(Layer* layer)
	{
		mLayerStack->PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		mLayerStack->PushOverlay(layer);
	}


	void Application::Run() const
	{
		while (mRunning)
		{
			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for(Layer* layer : *mLayerStack)
			{
				layer->OnUpdate();
			}
			mWindow->OnUpdate();
		}
	}

	bool Application::OnWindowClose(Event& e)
	{
		mRunning = false;
		return true;
	}
}
