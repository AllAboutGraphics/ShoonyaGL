#include "SandboxApp.h"

SandboxApp::SandboxApp()
{
}

SandboxApp::~SandboxApp()
{
}

SGL::Application* SGL::CreateApplication()
{
	return new SandboxApp();
}