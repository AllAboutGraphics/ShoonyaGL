#pragma once

#include "ShoonyaGL/Window.h"

#include <GLFW/glfw3.h>

namespace SGL
{
	class WindowsWindow : public Window
	{
		public:
			WindowsWindow(const WindowsProp& props);
			virtual ~WindowsWindow();

			void OnUpdate() override;

			inline unsigned int GetWidth() const override { return m_Data.Width; }
			inline unsigned int GetHeight() const override { return m_Data.Height; }

			// Window attributes
			inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
			void SetVSync(bool enabled) override;
			bool IsVSync() const override;

		private:
			virtual void Init(const WindowsProp& props);
			virtual void Shutdown();

		private:
			GLFWwindow* m_Window;

			struct WindowData
			{
				std::string Title;
				unsigned int Width;
				unsigned int Height;
				bool VSync;

				EventCallbackFn EventCallback;
			};

			WindowData m_Data;

			//Setup GLFW Callbacks
			void SetupGLFWEventsCallbacks();
			void SetupWindowSizeCallback();
			void SetupWindowCloseCallback();
			void SetupWindowKeyCallback();
			void SetupWindowMouseButtonCallback();
			void SetupWindowMouseScrollCallback();
			void SetupWindowCursorPositionCallback();
			void SetupErrorCallback();
	};
}