#include "../include/WindowSurfaceCreationException.h"

using namespace sandbox::glfw;

std::string WindowSurfaceCreationException::DescribeReason()
{
	return "window surface creation process";
}

std::string WindowSurfaceCreationException::DescribeSpecific()
{
	return "Failed to create window surface.";
}
