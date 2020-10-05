#include "../include/ExtensionUnavailableException.h"

#include <utility>

using namespace sandbox::vulkan;

ExtensionUnavailableException::ExtensionUnavailableException(std::string extension) : extension(std::move(extension))
{
}

std::string ExtensionUnavailableException::DescribeSpecific()
{
	return "Extension " + extension + " is unavailable."
}
