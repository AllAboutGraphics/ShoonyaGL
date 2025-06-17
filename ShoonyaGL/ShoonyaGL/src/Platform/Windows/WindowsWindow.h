#pragma once

#include "ShoonyaGL/Window.h"

#include "Platform/Windows/WindowEventListener.h"

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
			WindowData m_Data;
			WindowEventListener m_WindowEventListener;
	};
}