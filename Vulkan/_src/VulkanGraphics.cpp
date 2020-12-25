#include "../_include/VulkanGraphics.h"

#include <utility>

using namespace sandbox::vulkan;

void VulkanGraphics::Initialize(glfw::GLFWWindow window)
{
	instance = Instance();
	surface.Initialize(std::move(window), instance);
}

void VulkanGraphics::Draw()
{

}

void VulkanGraphics::CleanUp()
{

}
