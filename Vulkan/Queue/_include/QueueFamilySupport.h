#ifndef SANDBOX_QUEUEFAMILYSUPPORT_H
#define SANDBOX_QUEUEFAMILYSUPPORT_H

namespace sandbox::vulkan
{
	struct QueueFamilySupport
	{
	public:
		bool graphicsFamily;
		bool presentFamily;
	};
}

#endif //SANDBOX_QUEUEFAMILYSUPPORT_H
