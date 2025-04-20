#pragma once

#ifdef SGL_PLATFORM_WINDOWS

extern SGL::Application* SGL::CreateApplication();

int main(int argc, char** argv)
{
	SGL::Log::Init();
	SGL_CORE_WARN("Initialized Log!");
	int var = 5;
	SGL_INFO("Hello! Var = {0}", var);

	auto app = SGL::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif