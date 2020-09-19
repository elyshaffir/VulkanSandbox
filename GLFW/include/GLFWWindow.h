#ifndef SANDBOX_GLFWWINDOW_H
#define SANDBOX_GLFWWINDOW_H

#include <string>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "../../include/Window.h"

namespace sandbox::application::components
{
	class GLFWWindow : public Window
	{
	public:
		GLFWWindow(std::string title, int32_t width, int32_t height);

		virtual void Initialize() override;

		virtual bool ShouldClose() override;

		virtual void Update() override;

		virtual void CleanUp() override;
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
