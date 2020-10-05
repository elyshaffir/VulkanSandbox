#ifndef SANDBOX_VULKANGRAPHICS_H
#define SANDBOX_VULKANGRAPHICS_H

#include <vector>
#include "Instance.h"
#include "../Surface.h"

namespace sandbox::vulkan
{
	class VulkanGraphics
	{
	public:
		void Initialize(glfw::GLFWWindow window);

		void Draw();

		void CleanUp();

	private:
		Instance instance;
		Surface surface;
	};
}

#endif //SANDBOX_VULKANGRAPHICS_H
