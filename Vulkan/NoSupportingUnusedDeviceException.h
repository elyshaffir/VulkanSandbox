#ifndef SANDBOX_NOSUPPORTINGUNUSEDDEVICEEXCEPTION_H
#define SANDBOX_NOSUPPORTINGUNUSEDDEVICEEXCEPTION_H

#include "NoSupportingDeviceException.h"

namespace sandbox::vulkan
{
	class NoSupportingUnusedDeviceException : public NoSupportingDeviceException
	{
	protected:
		std::string DescribeSpecific() override;
	};
}

#endif //SANDBOX_NOSUPPORTINGUNUSEDDEVICEEXCEPTION_H
