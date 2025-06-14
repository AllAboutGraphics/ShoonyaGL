#include "sglpch.h"
#include "Application.h"

#include "Log.h"

#include <GLFW/glfw3.h>


namespace SGL
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
		
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SGL_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SGL_TRACE(e.ToString());
		}

		while (m_Running)
		{
			glClearColor(1.0, 0.0, 1.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowCloseEvent));
		SGL_CORE_TRACE("{0}", e.ToString());
	}

	bool Application::OnWindowCloseEvent(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}