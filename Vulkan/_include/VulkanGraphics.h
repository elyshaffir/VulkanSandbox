#ifndef SANDBOX_VULKANGRAPHICS_H
#define SANDBOX_VULKANGRAPHICS_H

#include <vector>
#include "../Instance/_include/Instance.h"
#include "../Surface/_include/Surface.h"
#include "../Queue/_include/Queue.h"

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
		Queue graphicsQueue;
		Queue presentationQueue;
	};
}

#endif //SANDBOX_VULKANGRAPHICS_H
