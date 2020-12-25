#ifndef SANDBOX_SURFACE_H
#define SANDBOX_SURFACE_H

#include <vulkan/vulkan.h>
#include "../../Instance/_include/Instance.h"
#include "../../../GLFW/_include/GLFWWindow.h"
#include "../../Queue/_include/QueueFamilyIndices.h"
#include "../SwapChain/_include/SwapChainSupportDetails.h"

namespace sandbox::vulkan
{
	class Surface
	{
	public:
		void Initialize(glfw::GLFWWindow window, Instance instance);

		QueueFamilyIndices GetQueueFamilyIndices(VkPhysicalDevice physicalDevice,
												 QueueFamilySupport queueFamilySupport) const;

		SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice physicalDevice) const;

	private:
		VkSurfaceKHR surface;
	};
}

#endif //SANDBOX_SURFACE_H
