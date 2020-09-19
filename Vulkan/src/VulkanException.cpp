#include "../include/VulkanException.h"

using namespace sandbox::vulkan;

VulkanException::VulkanException(sandbox::exceptions::ExceptionSeverity severity) : Exception(severity)
{
}

std::string VulkanException::DescribeDomain()
{
	return "Vulkan";
}
