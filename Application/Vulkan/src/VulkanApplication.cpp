#include "Headers/VulkanApplication.h"

void sandbox::application::VulkanApplication::Initialize()
{
	window.Initialize();
	graphics.Initialize();
}

bool sandbox::application::VulkanApplication::Continue()
{
	return !window.ShouldClose();
}

void sandbox::application::VulkanApplication::Loop()
{
	window.Update();
	graphics.Draw();
}

void sandbox::application::VulkanApplication::CleanUp()
{
	graphics.CleanUp();
	window.CleanUp();
}
