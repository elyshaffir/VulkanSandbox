#ifndef SANDBOX_VULKANEXCEPTION_H
#define SANDBOX_VULKANEXCEPTION_H

#include "../../Exceptions/include/Exception.h"

namespace sandbox::vulkan
{
	class VulkanException : public exceptions::Exception
	{
	public:
		VulkanException(exceptions::ExceptionSeverity severity);

	protected:
		virtual std::string DescribeDomain() override;
	};
}

#endif //SANDBOX_VULKANEXCEPTION_H
