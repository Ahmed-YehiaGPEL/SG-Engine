#pragma once
#include "sgepch.h"

#include "Core.h"
#include "Events/Event.h"

namespace SGEngine
{
	struct WindowProperties
	{
		unsigned int Width;
		unsigned int Height;
		std::string Title;

		WindowProperties(unsigned int width = 800, unsigned int height = 600, const std::string& title = "SGEngine Window")
			: Width(width)
			, Height(height)
			, Title(title) {

		}
	};

	class SGE_API Window
	{
	public:
		virtual ~Window(){};
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallbackFunction(const std::function<void(SGEngine::Event&)>& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSyncEnabled() = 0;

		static Window* Create(const WindowProperties& properties = WindowProperties());
	};
}