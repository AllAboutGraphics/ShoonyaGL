#pragma once
#include "sglpch.h"
#include "Core.h"

namespace SGL
{
	class SGL_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}