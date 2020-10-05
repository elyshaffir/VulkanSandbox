#ifndef SANDBOX_INSTANCECREATIONEXCEPTION_H
#define SANDBOX_INSTANCECREATIONEXCEPTION_H

#include "VulkanException.h"

namespace sandbox::vulkan
{
	class InstanceCreationException : public VulkanException
	{
	protected:
		std::string DescribeReason() override;

		std::string DescribeSpecific() override;
	};
}

#endif //SANDBOX_INSTANCECREATIONEXCEPTION_H
