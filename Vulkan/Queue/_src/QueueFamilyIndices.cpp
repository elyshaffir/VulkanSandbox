#include "../_include/QueueFamilyIndices.h"

using namespace sandbox::vulkan;

VkDeviceQueueCreateInfo CreateQueueCreateInfo(uint32_t queueFamilyIndex)
{
	float queuePriority = 1.0f;
	VkDeviceQueueCreateInfo queueCreateInfo { };
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.queueFamilyIndex = queueFamilyIndex;
	queueCreateInfo.queueCount = 1;
	queueCreateInfo.pQueuePriorities = &queuePriority;
	return queueCreateInfo;
}

bool QueueFamilyIndices::IsComplete(QueueFamilySupport queueFamilySupport)
{
	return (!queueFamilySupport.graphicsFamily || graphicsFamily.has_value()) &&
		   (!queueFamilySupport.presentFamily || presentFamily.has_value());
}

std::vector<VkDeviceQueueCreateInfo> QueueFamilyIndices::CreateQueueCreateInfos()
{
	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
	if (graphicsFamily.has_value())
	{
		queueCreateInfos.push_back(CreateQueueCreateInfo(graphicsFamily.value()));
	}

	if (presentFamily.has_value())
	{
		queueCreateInfos.push_back(CreateQueueCreateInfo(presentFamily.value()));
	}
	return queueCreateInfos;
}
