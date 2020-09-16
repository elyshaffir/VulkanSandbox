# This CMakeLists.txt file is not optimized and is probably full of bad practices.
# But it works.
# - Need to make sure no unnecessary binaries are linked
# - Need to make sure local variables like ${PROJECT_NAME} are used wherever they can
cmake_minimum_required(VERSION 3.17)
project(Sandbox)
add_executable(Sandbox main.cpp Application/src/Application.cpp Application/include/Application.h Metadata/include/Version.h Application/Vulkan/src/VulkanApplication.cpp Application/Vulkan/include/VulkanApplication.h Application/Vulkan/Components/include/Window.h Application/Vulkan/Components/GLFW/src/GLFWWindow.cpp Application/Vulkan/Components/GLFW/include/GLFWWindow.h Application/Vulkan/Components/Vulkan/src/VulkanGraphics.cpp Application/Vulkan/Components/Vulkan/include/VulkanGraphics.h Application/Vulkan/Components/include/Graphics.h Vulkan/src/Instance.cpp Vulkan/include/Instance.h Metadata/include/Engine.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")

set(glm_DIR "D:/DATA/Documents/Visual Studio 2019/Libraries/glm/cmake/glm")
find_package(glm REQUIRED)
target_link_libraries(Sandbox glm::glm)

find_package(Vulkan)  # Probably confirmed to be elegant
target_link_libraries(Sandbox Vulkan::Vulkan)

include_directories("D:/DATA/Documents/Visual Studio 2019/Libraries/stb")
include_directories("D:/DATA/Documents/Visual Studio 2019/Libraries/tinyobjloader")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
# This probably causes the glfw folder to appear in the project window
add_subdirectory("D:/DATA/Documents/Visual Studio 2019/Libraries/glfw-3.3.2" build)
target_link_libraries(Sandbox glfw)
