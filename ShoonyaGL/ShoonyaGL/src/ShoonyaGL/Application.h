#pragma once
#include "Core.h"

namespace SGL
{
	class SGL_API Application
	{
		public:
			Application();
			~Application();

			void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}