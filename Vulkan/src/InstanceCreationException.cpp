#include "../include/InstanceCreationException.h"

using namespace sandbox::vulkan;

std::string InstanceCreationException::DescribeReason()
{
	return "instance creation process";
}

std::string InstanceCreationException::DescribeSpecific()
{
	return "Failed to create instance.";
}
