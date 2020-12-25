#ifndef SANDBOX_WINDOWSURFACECREATIONEXCEPTION_H
#define SANDBOX_WINDOWSURFACECREATIONEXCEPTION_H

#include "../../Vulkan/include/VulkanException.h"

namespace sandbox::glfw
{
	class WindowSurfaceCreationException : public vulkan::VulkanException
	{
	protected:
		std::string DescribeReason() override;

		std::string DescribeSpecific() override;
	};
}

#endif //SANDBOX_WINDOWSURFACECREATIONEXCEPTION_H
