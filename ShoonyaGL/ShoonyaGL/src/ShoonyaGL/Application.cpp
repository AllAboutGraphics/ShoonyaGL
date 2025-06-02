#include "sglpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace SGL
{
	Application::Application()
	{
		
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

		while (true);
	}
}