#ifndef SANDBOX_QUEUEFAMILYINDICES_H
#define SANDBOX_QUEUEFAMILYINDICES_H

#include <optional>
#include <vector>
#include <vulkan/vulkan.h>
#include "QueueFamilySupport.h"

namespace sandbox::vulkan
{
	class QueueFamilyIndices
	{
	public:
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool IsComplete(QueueFamilySupport queueFamilySupport);

		std::vector<VkDeviceQueueCreateInfo> CreateQueueCreateInfos();
	};
}

#endif //SANDBOX_QUEUEFAMILYINDICES_H
