#include "../_include/Queue.h"

sandbox::vulkan::Queue::Queue(uint32_t index) : index(index)
{
}

VkDeviceQueueCreateInfo sandbox::vulkan::Queue::CreateQueueCreateInfo()
{
	float queuePriority = 1.0f;
	VkDeviceQueueCreateInfo queueCreateInfo { };
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.queueFamilyIndex = index;
	queueCreateInfo.queueCount = 1;
	queueCreateInfo.pQueuePriorities = &queuePriority;
	return queueCreateInfo;
}
