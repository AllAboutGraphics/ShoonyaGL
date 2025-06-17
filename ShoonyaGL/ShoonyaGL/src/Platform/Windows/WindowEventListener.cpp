#include "sglpch.h"
#include "WindowEventListener.h"

namespace SGL
{
	void WindowEventListener::SetupGLFWEventsCallbacks(GLFWwindow* pWindow)
	{
		SetupWindowSizeCallback(pWindow);
		SetupWindowCloseCallback(pWindow);
		SetupWindowKeyCallback(pWindow);
		SetupWindowMouseButtonCallback(pWindow);
		SetupWindowMouseScrollCallback(pWindow);
		SetupWindowCursorPositionCallback(pWindow);
		SetupErrorCallback();
	}

	void WindowEventListener::SetupWindowSizeCallback(GLFWwindow* pWindow)
	{
		glfwSetWindowSizeCallback(pWindow,
			[](GLFWwindow* window, int width, int height) {
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				windowData.Width = width;
				windowData.Height = height;
				WindowResizeEvent event(width, height);
				windowData.EventCallback(event);
			});
	}

	void WindowEventListener::SetupWindowCloseCallback(GLFWwindow* pWindow)
	{
		glfwSetWindowCloseCallback(pWindow,
			[](GLFWwindow* window) {
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				windowData.EventCallback(event);
			});
	}

	void WindowEventListener::SetupWindowKeyCallback(GLFWwindow* pWindow)
	{
		glfwSetKeyCallback(pWindow,
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

	void WindowEventListener::SetupWindowMouseButtonCallback(GLFWwindow* pWindow)
	{
		glfwSetMouseButtonCallback(pWindow,
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

	void WindowEventListener::SetupWindowMouseScrollCallback(GLFWwindow* pWindow)
	{
		glfwSetScrollCallback(pWindow,
			[](GLFWwindow* window, double xoffset, double yoffset) {
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event(xoffset, yoffset);
				windowData.EventCallback(event);
			});
	}

	void WindowEventListener::SetupWindowCursorPositionCallback(GLFWwindow* pWindow)
	{
		glfwSetCursorPosCallback(pWindow,
			[](GLFWwindow* window, double xpos, double ypos) {
				WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xpos, (float)ypos);
				windowData.EventCallback(event);
			});
	}

	void WindowEventListener::SetupErrorCallback()
	{
		glfwSetErrorCallback([](int error_code,
			const char* description) {
				SGL_CORE_ERROR("GLFW Error ({0}) : {1}", error_code, description);
			});
	}
}