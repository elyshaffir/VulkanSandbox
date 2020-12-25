#ifndef SANDBOX_GLFWWINDOW_H
#define SANDBOX_GLFWWINDOW_H

#include <string>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace sandbox::glfw
{
	class GLFWWindow
	{
	public:
		GLFWWindow(std::string title, int32_t width, int32_t height);

		virtual void Initialize();

		virtual bool ShouldClose();

		virtual void Update();

		virtual void CleanUp();

		void CreateVulkanSurface(VkInstance instance, VkSurfaceKHR * surface);

	private:
		const std::string title;
		const int32_t width;
		const int32_t height;

		GLFWwindow * window;

		bool resized;

		static void OnResize(GLFWwindow * window, int32_t width, int32_t height);
	};
}

#endif //SANDBOX_GLFWWINDOW_H
