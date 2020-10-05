#ifndef SANDBOX_QUEUEFAMILYINDICES_H
#define SANDBOX_QUEUEFAMILYINDICES_H

#include <optional>

namespace sandbox::vulkan
{
	struct QueueFamilyIndices
	{
	public:
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool IsComplete()
		{
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};
}

#endif //SANDBOX_QUEUEFAMILYINDICES_H
