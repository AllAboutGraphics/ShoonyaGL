#pragma once
#include "sglpch.h"
#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace SGL
{
	class SGL_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();

		private:
			std::unique_ptr<Window> m_Window;
			bool m_Running = true;

			void OnEvent(Event& e);
			bool OnWindowCloseEvent(WindowCloseEvent& e);
	};

	//To be defined in client
	Application* CreateApplication();
}