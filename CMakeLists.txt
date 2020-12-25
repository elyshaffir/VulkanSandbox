# This CMakeLists.txt file is not optimized and is probably full of bad practices.
# But it works.
# - Need to make sure no unnecessary binaries are linked
# - Need to make sure local variables like ${PROJECT_NAME} are used wherever they can
cmake_minimum_required(VERSION 3.17)
project(Sandbox)
add_executable(Sandbox main.cpp Application/_src/Application.cpp Application/_include/Application.h Data/_include/Version.h Vulkan/_src/VulkanApplication.cpp Vulkan/_include/VulkanApplication.h GLFW/_src/GLFWWindow.cpp GLFW/_include/GLFWWindow.h Vulkan/_src/VulkanGraphics.cpp Vulkan/_include/VulkanGraphics.h Vulkan/Instance/_src/Instance.cpp Vulkan/Instance/_include/Instance.h Data/_include/Engine.h Exceptions/_include/Exception.h Vulkan/_include/VulkanException.h Vulkan/_src/VulkanException.cpp Vulkan/Instance/_src/InstanceCreationException.cpp Vulkan/Instance/_include/InstanceCreationException.h Exceptions/_src/Exception.cpp Vulkan/Instance/_src/ValidationLayersUnavailableException.cpp Vulkan/Instance/_include/ValidationLayersUnavailableException.h IO/_include/OutputChannel.h IO/_src/ConsoleOutputChannel.cpp IO/_include/ConsoleOutputChannel.h Vulkan/Instance/_src/ExtensionUnavailableException.cpp Vulkan/Instance/_include/ExtensionUnavailableException.h Vulkan/Instance/_src/DebugMessengerCreationException.cpp Vulkan/Instance/_include/DebugMessengerCreationException.h GLFW/_src/WindowSurfaceCreationException.cpp GLFW/_include/WindowSurfaceCreationException.h Vulkan/Surface/_src/Surface.cpp Vulkan/Surface/_include/Surface.h Vulkan/PhysicalInterface/Device/_src/Device.cpp Vulkan/PhysicalInterface/Device/_include/Device.h Vulkan/PhysicalInterface/_src/PhysicalInterface.cpp Vulkan/PhysicalInterface/_include/PhysicalInterface.h Vulkan/Queue/_include/QueueFamilyIndices.h Vulkan/PhysicalInterface/DeviceSupport/_src/DeviceSupport.cpp Vulkan/PhysicalInterface/DeviceSupport/_include/DeviceSupport.h Vulkan/Surface/SwapChain/_include/SwapChainSupportDetails.h Vulkan/PhysicalInterface/_src/PhysicalInterfaceCreationException.cpp Vulkan/PhysicalInterface/_include/PhysicalInterfaceCreationException.h Vulkan/PhysicalInterface/_src/NotEnoughPhysicalDevicesException.cpp Vulkan/PhysicalInterface/_include/NotEnoughPhysicalDevicesException.h Vulkan/PhysicalInterface/Device/_src/NoSupportingDeviceException.cpp Vulkan/PhysicalInterface/Device/_include/NoSupportingDeviceException.h Vulkan/PhysicalInterface/DeviceSupport/_src/ArbitraryDeviceSupport.cpp Vulkan/PhysicalInterface/DeviceSupport/_include/ArbitraryDeviceSupport.h Vulkan/Queue/_include/QueueFamilySupport.h Vulkan/Queue/_src/QueueFamilyIndices.cpp Vulkan/Queue/Queue.cpp Vulkan/Queue/Queue.h)

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
