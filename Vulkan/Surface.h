#ifndef SANDBOX_SURFACE_H
#define SANDBOX_SURFACE_H

#include <vulkan/vulkan.h>
#include "include/Instance.h"
#include "../GLFW/include/GLFWWindow.h"
#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"

namespace sandbox::vulkan
{
	class Surface
	{
	public:
		void Initialize(glfw::GLFWWindow window, Instance instance);

		QueueFamilyIndices GetQueueFamilyIndices(VkPhysicalDevice physicalDevice) const;

		SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice physicalDevice) const;

	private:
		VkSurfaceKHR surface;
	};
}

#endif //SANDBOX_SURFACE_H
