#ifndef SANDBOX_QUEUEFAMILYINDICES_H
#define SANDBOX_QUEUEFAMILYINDICES_H

#include <optional>
#include "QueueFamilyRequirements.h"

namespace sandbox::vulkan
{
	struct QueueFamilyIndices
	{
	public:
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool IsComplete(QueueFamilyRequirements requirements)
		{
			return (!requirements.graphicsFamily || graphicsFamily.has_value()) &&
				   (!requirements.presentFamily || presentFamily.has_value());
		}
	};
}

#endif //SANDBOX_QUEUEFAMILYINDICES_H
