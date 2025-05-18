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
		SGL_TRACE(e.ToString());

		while (true);
	}
}