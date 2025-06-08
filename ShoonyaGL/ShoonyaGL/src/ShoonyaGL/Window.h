#pragma once
#include "sglpch.h"

#include "Core.h"
#include "Events/Event.h"

namespace SGL
{
	struct WindowsProp
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowsProp(const std::string& title = "ShoonyaGL Engine", unsigned int width = 1280, unsigned int height = 720) : Title(title), Width(width), Height(height) {}
	};

	class SGL_API Window
	{
		public:
			using EventCallbackFn = std::function<void(Event&)>;

			virtual ~Window() {}

			virtual void OnUpdate() = 0;

			virtual inline unsigned int GetWidth() const = 0;
			virtual inline unsigned int GetHeight() const = 0;

			// Windows attibutes
			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			static Window* Create(const WindowsProp& prop = WindowsProp());
	};
}