#include "sgepch.h"
#include "WinXWindow.h"

namespace SGEngine
{
	Window* Window::Create(const WindowProperties& properties)
	{
		return new PlatformImpl::Windows::WinXWindow(properties);
	}

	namespace PlatformImpl::Windows
	{
		bool WinXWindow::mGLFWInitialized = false;

		WinXWindow::WinXWindow(const WindowProperties& properties) : mInstance(nullptr), mWindowData(properties)
		{
			Init();
		}

		WinXWindow::~WinXWindow()
		{
			Close();
		};

		void WinXWindow::OnUpdate()
		{
			glfwPollEvents();
			glfwSwapBuffers(mInstance);
		}

		unsigned int WinXWindow::GetWidth() const
		{
			return mWindowData.Width;
		}

		unsigned int WinXWindow::GetHeight() const
		{
			return mWindowData.Height;
		}

		void WinXWindow::SetEventCallbackFunction(const std::function<void(SGEngine::Event&)>& callback)
		{
			mWindowData.CallbackFunction = callback;
		}

		void WinXWindow::SetVSync(bool enabled)
		{
			if (enabled)
			{
				glfwSwapInterval(1);
			}
			else
			{
				glfwSwapInterval(0);
			}
			mWindowData.IsVSyncEnabled = enabled;
		}

		bool WinXWindow::IsVSyncEnabled()
		{
			return mWindowData.IsVSyncEnabled;
		}

		void WinXWindow::Init()
		{
			SGE_CORE_INFO("Creating window with name {0}", mWindowData.Title);
			if (!mGLFWInitialized)
			{
				const auto success = glfwInit();
				if (success)
				{
					mGLFWInitialized = true;
					SGE_CORE_INFO("GLFW Initialized Succesfully!");
				}
				else
				{
					SGE_CORE_FATAL("Failed to initialize GLFW!");
				}
			}

			mInstance = glfwCreateWindow(mWindowData.Width, mWindowData.Height, mWindowData.Title.c_str(), nullptr, nullptr);
			glfwMakeContextCurrent(mInstance);
			glfwSetWindowUserPointer(mInstance, &mWindowData);
			SetVSync(true);
		}

		void WinXWindow::Close() const
		{
			glfwDestroyWindow(mInstance);
		}

	}
}
