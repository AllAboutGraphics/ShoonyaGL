#include "sglpch.h"
#include "WindowsWindow.h"
#include "ShoonyaGL/Events/ApplicationEvent.h"
#include "ShoonyaGL/Events/KeyEvent.h"
#include "ShoonyaGL/Events/MouseEvent.h"

namespace SGL
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowsProp& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowsProp& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled) glfwSwapInterval(1);
		else glfwSwapBuffers(0);
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::Init(const WindowsProp& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		SGL_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			SGL_CORE_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		//Set GLFW callbacks
		SetupGLFWEventsCallbacks();
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

#pragma region SetupGLFWCallbacks
	void WindowsWindow::SetupGLFWEventsCallbacks()
	{
		SetupErrorCallback();
		SetupWindowSizeCallback();
		SetupWindowCloseCallback();
		SetupWindowKeyCallback();
		SetupWindowMouseButtonCallback();
		SetupWindowMouseScrollCallback();
		SetupWindowCursorPositionCallback();
	}

	void WindowsWindow::SetupWindowSizeCallback()
	{
		glfwSetWindowSizeCallback(m_Window,
			[](GLFWwindow* window, int width, int height) {
				WindowData& windowData = *(WindowData *)glfwGetWindowUserPointer(window);
				windowData.Width = width;
				windowData.Height = height;
				WindowResizeEvent event(width, height);
				windowData.EventCallback(event);
			});
	}

	void WindowsWindow::SetupWindowCloseCallback()
	{
		glfwSetWindowCloseCallback(m_Window,
			[](GLFWwindow* window) {
				WindowData& windowData = *(WindowData *)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				windowData.EventCallback(event);
			});
	}

	void WindowsWindow::SetupWindowKeyCallback()
	{
		glfwSetKeyCallback(m_Window,
			[](GLFWwindow* window, int key, int scancode, int action, int mods) {
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						windowData.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleaseEvent event(key);
						windowData.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, 1);
						windowData.EventCallback(event);
						break;
					}
				}
			});
	}

	void WindowsWindow::SetupWindowMouseButtonCallback()
	{
		glfwSetMouseButtonCallback(m_Window,
			[](GLFWwindow* window, int button, int action, int mods) {
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(button);
						windowData.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleaseEvent event(button);
						windowData.EventCallback(event);
						break;
					}
				}
			});
	}

	void WindowsWindow::SetupWindowMouseScrollCallback()
	{
		glfwSetScrollCallback(m_Window,
			[](GLFWwindow* window, double xoffset, double yoffset) {
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event(xoffset, yoffset);
				windowData.EventCallback(event);
			});
	}

	void WindowsWindow::SetupWindowCursorPositionCallback()
	{
		glfwSetCursorPosCallback(m_Window,
			[](GLFWwindow* window, double xpos, double ypos) {
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xpos, (float)ypos);
				windowData.EventCallback(event);
			});
	}

	void WindowsWindow::SetupErrorCallback()
	{
		glfwSetErrorCallback([](int error_code,
			const char* description) {
				SGL_CORE_ERROR("GLFW Error ({0}) : {1}", error_code, description);
			});
	}
#pragma endregion
}