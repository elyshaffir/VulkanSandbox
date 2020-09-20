#include "../include/InstanceCreationException.h"

using namespace sandbox::vulkan;

InstanceCreationException::InstanceCreationException() : VulkanException(exceptions::ExceptionSeverity::Fatal)
{
}

std::string InstanceCreationException::DescribeReason()
{
	return "instance creation process";
}

std::string InstanceCreationException::DescribeSpecific()
{
	return "Failed to create instance.";
}
