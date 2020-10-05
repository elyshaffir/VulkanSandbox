#ifndef SANDBOX_NOPHYSICALDEVICECOMBINATIONEXCEPTION_H
#define SANDBOX_NOPHYSICALDEVICECOMBINATIONEXCEPTION_H

#include "PhysicalInterfaceCreationException.h"

namespace sandbox::vulkan
{
	class NoPhysicalDeviceCombinationException : public PhysicalInterfaceCreationException
	{
	protected:
		std::string DescribeSpecific() override;
	};
}

#endif //SANDBOX_NOPHYSICALDEVICECOMBINATIONEXCEPTION_H
