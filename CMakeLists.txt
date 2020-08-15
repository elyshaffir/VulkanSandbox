cmake_minimum_required(VERSION 3.17)
project(Sandbox)
add_executable(Sandbox main.cpp)

set(CMAKE_CXX_STANDARD 17)

set(glm_DIR ${CMAKE_MODULE_PATH} "D:/DATA/Documents/Visual Studio 2019/Libraries/glm/cmake/glm")
find_package(glm REQUIRED)
target_link_libraries(${PROJECT_NAME} glm)
include_directories("D:/DATA/Documents/Visual Studio 2019/Libraries/glm")

include_directories(${Vulkan_INCLUDE_DIR})
target_link_libraries(Sandbox "D:/DATA/Documents/Vulkan/1.2.141.2/Lib/*.dll")

include_directories("D:/DATA/Documents/Visual Studio 2019/Libraries/stb")
include_directories("D:/DATA/Documents/Visual Studio 2019/Libraries/tinyobjloader")

include_directories("D:/DATA/Documents/Visual Studio 2019/Libraries/glfw-3.3.2.bin.WIN64/include")
target_link_libraries(Sandbox "D:/DATA/Documents/Visual Studio 2019/Libraries/glfw-3.3.2.bin.WIN64/lib-vc2019/glfw3.dll")