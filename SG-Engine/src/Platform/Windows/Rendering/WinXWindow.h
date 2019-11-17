#pragma once
#include "Core.h"
#include "Window.h"
#include "GLFW/glfw3.h"

namespace SGEngine
{
	namespace PlatformImpl
	{
		namespace Windows
		{
			class SGE_API WinXWindow : public Window
			{
			public:
				explicit WinXWindow(const WindowProperties& properties);
				~WinXWindow() override;
				void OnUpdate() override;
				unsigned GetWidth() const override;
				unsigned GetHeight() const override;
				void SetEventCallbackFunction(const std::function<void(SGEngine::Event&)>& callback) override;
				void SetVSync(bool enabled) override;
				bool IsVSyncEnabled() override;

				void Init();
				void Close() const;

			private:
				GLFWwindow* mInstance;
				struct WindowData
				{
					unsigned int Width;
					unsigned int Height;
					std::string Title;
					bool IsVSyncEnabled;
					std::function<void(SGEngine::Event&)> CallbackFunction;
					WindowData(const WindowProperties& prop)
					{
						Width = prop.Width;
						Height = prop.Height;
						Title = prop.Title;
						IsVSyncEnabled = false;
						CallbackFunction = nullptr;
					}
				};
				WindowData mWindowData;

				static bool mGLFWInitialized;
			};
		}
	}
}
