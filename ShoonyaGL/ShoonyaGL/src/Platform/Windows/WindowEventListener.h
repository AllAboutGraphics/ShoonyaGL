#pragma once

#include <GLFW/glfw3.h>

#include "ShoonyaGL/Events/ApplicationEvent.h"
#include "ShoonyaGL/Events/KeyEvent.h"
#include "ShoonyaGL/Events/MouseEvent.h"

namespace SGL
{
	struct WindowData
	{
		using EventCallbackFn = std::function<void(Event&)>;

		std::string Title;
		unsigned int Width;
		unsigned int Height;
		bool VSync;

		EventCallbackFn EventCallback;
	};

	class WindowEventListener
	{
		public:
			void SetupGLFWEventsCallbacks(GLFWwindow* pWindow);

		private:
			void SetupWindowSizeCallback(GLFWwindow* pWindow);
			void SetupWindowCloseCallback(GLFWwindow* pWindow);
			void SetupWindowKeyCallback(GLFWwindow* pWindow);
			void SetupWindowMouseButtonCallback(GLFWwindow* pWindow);
			void SetupWindowMouseScrollCallback(GLFWwindow* pWindow);
			void SetupWindowCursorPositionCallback(GLFWwindow* pWindow);
			void SetupErrorCallback();
	};
}