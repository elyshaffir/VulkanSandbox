#ifndef SANDBOX_VULKANAPPLICATION_H
#define SANDBOX_VULKANAPPLICATION_H

#include "../../Application/_include/Application.h"
#include "VulkanGraphics.h"

namespace sandbox::vulkan
{
	class VulkanApplication : public application::Application
	{
	protected:
		virtual void Initialize() override;

		virtual bool Continue() override;

		virtual void Loop() override;

		virtual void CleanUp() override;
	private:
		glfw::GLFWWindow window;
		VulkanGraphics graphics;
	};
}

#endif //SANDBOX_VULKANAPPLICATION_H
