#ifndef SANDBOX_QUEUEFAMILYREQUIREMENTS_H
#define SANDBOX_QUEUEFAMILYREQUIREMENTS_H

namespace sandbox::vulkan
{
	struct QueueFamilyRequirements
	{
	public:
		bool graphicsFamily;
		bool presentFamily;
	};
}

#endif //SANDBOX_QUEUEFAMILYREQUIREMENTS_H
