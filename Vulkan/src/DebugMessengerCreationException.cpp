#include "../include/DebugMessengerCreationException.h"

using namespace sandbox::vulkan;

std::string DebugMessengerCreationException::DescribeSpecific()
{
	return "Failed to create debug messenger.";
}
