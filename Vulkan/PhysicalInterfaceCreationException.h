#ifndef SANDBOX_PHYSICALINTERFACECREATIONEXCEPTION_H
#define SANDBOX_PHYSICALINTERFACECREATIONEXCEPTION_H

#include "include/VulkanException.h"

namespace sandbox::vulkan
{
	class PhysicalInterfaceCreationException : public VulkanException
	{
	protected:
		std::string DescribeReason() override;
	};
}

#endif //SANDBOX_PHYSICALINTERFACECREATIONEXCEPTION_H
