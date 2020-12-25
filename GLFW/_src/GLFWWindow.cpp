#include <utility>
#include "../include/GLFWWindow.h"
#include "../include/WindowSurfaceCreationException.h"

using namespace sandbox::glfw;

GLFWWindow::GLFWWindow(std::string title, int32_t width, int32_t height)
	: title(std::move(title)), width(width), height(height), window(nullptr), resized(false)
{
}

void GLFWWindow::Initialize()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	glfwSetWindowUserPointer(window, this);
	glfwSetFramebufferSizeCallback(window, OnResize);
}

bool GLFWWindow::ShouldClose()
{
	return glfwWindowShouldClose(window);
}

void GLFWWindow::Update()
{
	glfwPollEvents();
}

void GLFWWindow::CleanUp()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void GLFWWindow::OnResize(GLFWwindow * window, int32_t width, int32_t height)
{
	static_cast<GLFWWindow *>(glfwGetWindowUserPointer(window))->resized = true;
}

void GLFWWindow::CreateVulkanSurface(VkInstance instance, VkSurfaceKHR * surface)
{
	if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS)
	{
		throw WindowSurfaceCreationException();
	}
}
