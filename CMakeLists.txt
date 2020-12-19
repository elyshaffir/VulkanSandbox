# This CMakeLists.txt file is not optimized and is probably full of bad practices.
# But it works.
# - Need to make sure no unnecessary binaries are linked
# - Need to make sure local variables like ${PROJECT_NAME} are used wherever they can
cmake_minimum_required(VERSION 3.17)
project(Sandbox)
add_executable(Sandbox main.cpp Application/src/Application.cpp Application/include/Application.h Data/include/Version.h Vulkan/src/VulkanApplication.cpp Vulkan/include/VulkanApplication.h Application/Components/include/Window.h GLFW/src/GLFWWindow.cpp GLFW/include/GLFWWindow.h Vulkan/src/VulkanGraphics.cpp Vulkan/include/VulkanGraphics.h Application/Components/include/Graphics.h Vulkan/src/Instance.cpp Vulkan/include/Instance.h Data/include/Engine.h Exceptions/include/Exception.h Vulkan/include/VulkanException.h Vulkan/src/VulkanException.cpp Vulkan/src/InstanceCreationException.cpp Vulkan/include/InstanceCreationException.h Exceptions/src/Exception.cpp Vulkan/src/ValidationLayersUnavailableException.cpp Vulkan/include/ValidationLayersUnavailableException.h IO/include/OutputChannel.h IO/ConsoleOutputChannel.cpp IO/ConsoleOutputChannel.h Vulkan/src/ExtensionUnavailableException.cpp Vulkan/include/ExtensionUnavailableException.h Vulkan/src/DebugMessengerCreationException.cpp Vulkan/include/DebugMessengerCreationException.h GLFW/WindowSurfaceCreationException.cpp GLFW/WindowSurfaceCreationException.h Vulkan/Surface.cpp Vulkan/Surface.h Vulkan/Device.cpp Vulkan/Device.h Vulkan/PhysicalInterface.cpp Vulkan/PhysicalInterface.h Vulkan/QueueFamilyIndices.h Vulkan/DeviceSupport.cpp Vulkan/DeviceSupport.h Vulkan/SwapChainSupportDetails.h Vulkan/PhysicalInterfaceCreationException.cpp Vulkan/PhysicalInterfaceCreationException.h Vulkan/NotEnoughPhysicalDevicesException.cpp Vulkan/NotEnoughPhysicalDevicesException.h Vulkan/NoPhysicalDeviceCombinationException.cpp Vulkan/NoPhysicalDeviceCombinationException.h Vulkan/NoSupportingUnusedDeviceException.cpp Vulkan/NoSupportingUnusedDeviceException.h Vulkan/NoSupportingDeviceException.cpp Vulkan/NoSupportingDeviceException.h Vulkan/ArbitraryDeviceSupport.cpp Vulkan/ArbitraryDeviceSupport.h Vulkan/QueueFamilyRequirements.h)

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
