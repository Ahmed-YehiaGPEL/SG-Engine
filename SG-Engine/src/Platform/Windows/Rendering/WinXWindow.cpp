#include "sgepch.h"
#include "WinXWindow.h"
#include "Events/ApplicationEvents.h"
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"

namespace SGEngine
{
	Window* Window::Create(const WindowProperties& properties)
	{
		return new PlatformImpl::Windows::WinXWindow(properties);
	}

	namespace PlatformImpl::Windows
	{
#define GET_WINDOW_DATA(WINDOW) *static_cast<WindowData*>(glfwGetWindowUserPointer(WINDOW))

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
					glfwSetErrorCallback([](int errorCode, const char* description) {SGE_CORE_ERROR("[{0}] : {1}", errorCode, description); });
				}
				else
				{
					SGE_CORE_FATAL("Failed to initialize GLFW!");
				}
			}

			mInstance = glfwCreateWindow(mWindowData.Width, mWindowData.Height, mWindowData.Title.c_str(), nullptr,
			                             nullptr);
			glfwMakeContextCurrent(mInstance);
			glfwSetWindowUserPointer(mInstance, &mWindowData);
			SetVSync(true);

			SetupEventCallbacks();
		}

		void WinXWindow::Close() const
		{
			glfwDestroyWindow(mInstance);
		}

		void WinXWindow::SetupEventCallbacks()
		{
			glfwSetWindowCloseCallback(mInstance, [](GLFWwindow* window)
			{
				const WindowData data = GET_WINDOW_DATA(window);
				WindowCloseEvent event;
				data.CallbackFunction(event);
			});

			glfwSetWindowSizeCallback(mInstance, [](GLFWwindow* window, int width, int height)
			{
				WindowData data = GET_WINDOW_DATA(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.CallbackFunction(event);
			});

			glfwSetCursorPosCallback(mInstance, [](GLFWwindow* window, double posX, double posY)
			{
				const WindowData data = GET_WINDOW_DATA(window);
				MouseMovedEvent event(posX, posY);
				data.CallbackFunction(event);
			});

			glfwSetMouseButtonCallback(mInstance, [](GLFWwindow* window, int button, int action, int mods)
			{
				const WindowData data = GET_WINDOW_DATA(window);

				switch (action)
				{
				case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						data.CallbackFunction(event);
						break;
					}
				case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(button);
						data.CallbackFunction(event);
						break;
					}
				}
			});

			glfwSetKeyCallback(mInstance, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				const WindowData data = GET_WINDOW_DATA(window);

				switch (action)
				{
				case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 1);
						data.CallbackFunction(event);
						break;
					}
				case GLFW_RELEASE:
					{
						KeyReleaseEvent event(key);
						data.CallbackFunction(event);
						break;
					}
				case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						data.CallbackFunction(event);
						break;
					}
				}
			});

			glfwSetScrollCallback(mInstance, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				const WindowData data = GET_WINDOW_DATA(window);
				MouseScrolledEvent event(xOffset, yOffset);
				data.CallbackFunction(event);
			});
		}
	}
}
