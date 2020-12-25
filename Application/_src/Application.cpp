#include <utility>
#include "../include/Application.h"

using namespace sandbox::application;

Application::Application(std::string name, const Version & version)
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
