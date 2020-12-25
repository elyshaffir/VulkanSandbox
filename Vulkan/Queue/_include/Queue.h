#ifndef SANDBOX_QUEUE_H
#define SANDBOX_QUEUE_H

#include <vulkan/vulkan.h>

namespace sandbox::vulkan
{
	class Queue
	{
	public:
		Queue(uint32_t index);

		VkDeviceQueueCreateInfo CreateQueueCreateInfo();
	private:
		uint32_t index;
	};
}

#endif //SANDBOX_QUEUE_H
