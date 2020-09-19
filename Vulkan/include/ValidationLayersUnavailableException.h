#ifndef SANDBOX_VALIDATIONLAYERSUNAVAILABLEEXCEPTION_H
#define SANDBOX_VALIDATIONLAYERSUNAVAILABLEEXCEPTION_H

#include "InstanceCreationException.h"

namespace sandbox::vulkan
{
	class ValidationLayersUnavailableException : public InstanceCreationException
	{
	protected:
		std::string DescribeSpecific() override;
	};
}

#endif //SANDBOX_VALIDATIONLAYERSUNAVAILABLEEXCEPTION_H
