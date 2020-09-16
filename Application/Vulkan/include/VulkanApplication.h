#ifndef SANDBOX_VULKANAPPLICATION_H
#define SANDBOX_VULKANAPPLICATION_H

#include "../../Headers/Application.h"
#include "../Components/GLFW/Headers/GLFWWindow.h"
#include "../Components/Vulkan/Headers/VulkanGraphics.h"

namespace sandbox::application
{
	class VulkanApplication : public Application
	{
	protected:
		virtual void Initialize() override;

		virtual bool Continue() override;

		virtual void Loop() override;

		virtual void CleanUp() override;
	private:
		components::GLFWWindow window;
		components::VulkanGraphics graphics;
	};
}

#endif //SANDBOX_VULKANAPPLICATION_H
