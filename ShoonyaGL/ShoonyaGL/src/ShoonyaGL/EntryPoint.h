#pragma once

#ifdef SGL_PLATFORM_WINDOWS

extern SGL::Application* SGL::CreateApplication();

int main(int argc, char** argv)
{
	auto app = SGL::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif