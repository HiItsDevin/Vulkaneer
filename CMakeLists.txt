cmake_minimum_required(VERSION 3.16)
project(vulkanite LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(Vulkan REQUIRED)
find_package(GLFW REQUIRED)
find_package(glm REQUIRED)

add_executable(vulkanite
        vulkanite_src/src/vulkanite_app.cpp
        vulkanite_src/src/vulkanite_app.hpp

        vulkanite_src/src/vulkanite_window.cpp
        vulkanite_src/src/vulkanite_window.hpp

        vulkanite_src/src/vulkanite_pipeline.cpp
        vulkanite_src/src/vulkanite_pipeline.hpp

        vulkanite_src/src/vulkanite_device.cpp
        vulkanite_src/src/vulkanite_device.hpp

        vulkanite_src/src/vulkanite_main.cpp)

target_link_libraries(vulkanite PRIVATE
Vulkan::Vulkan
GLFW::GLFW
glm::glm)