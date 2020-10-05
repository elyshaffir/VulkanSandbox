#include "../include/VulkanApplication.h"

using namespace sandbox::vulkan;

void VulkanApplication::Initialize()
{
	window.Initialize();
	graphics.Initialize(window);
}

bool VulkanApplication::Continue()
{
	return !window.ShouldClose();
}

void VulkanApplication::Loop()
{
	window.Update();
	graphics.Draw();
}

void VulkanApplication::CleanUp()
{
	graphics.CleanUp();
	window.CleanUp();
}
