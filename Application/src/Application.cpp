#include "Headers/Application.h"

#include <utility>

using namespace sandbox::application;

Application::Application(std::string name, const metadata::ApplicationVersion & version)
		: name(std::move(name)), version(version)
{
}

void Application::Run()
{
	Initialize();
	while (Continue())
	{
		Loop();
	}
	CleanUp();
}
