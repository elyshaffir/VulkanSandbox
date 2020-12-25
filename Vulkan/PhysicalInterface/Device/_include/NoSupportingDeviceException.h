#ifndef SANDBOX_NOSUPPORTINGDEVICEEXCEPTION_H
#define SANDBOX_NOSUPPORTINGDEVICEEXCEPTION_H

#include "../../_include/PhysicalInterfaceCreationException.h"

namespace sandbox::vulkan
{
	class NoSupportingDeviceException : public PhysicalInterfaceCreationException
	{
	protected:
		std::string DescribeSpecific() override;
	};
}

#endif //SANDBOX_NOSUPPORTINGDEVICEEXCEPTION_H
