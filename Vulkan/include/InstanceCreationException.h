#ifndef SANDBOX_INSTANCECREATIONEXCEPTION_H
#define SANDBOX_INSTANCECREATIONEXCEPTION_H

#include "VulkanException.h"

namespace sandbox::vulkan
{
	class InstanceCreationException : public VulkanException
	{
	public:
		InstanceCreationException();

	protected:
		virtual std::string DescribeReason() override;

		virtual std::string DescribeSpecific() override;
	};
}

#endif //SANDBOX_INSTANCECREATIONEXCEPTION_H
