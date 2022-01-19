cmake_minimum_required(VERSION 3.16)
project(vulkanite LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(Vulkan REQUIRED)
find_package(GLFW REQUIRED)
find_package(glm REQUIRED)

add_executable(vulkanite
        Vulkanite/src/vulkanite_app.cpp
        Vulkanite/src/vulkanite_app.hpp

        Vulkanite/src/vulkanite_window.cpp
        Vulkanite/src/vulkanite_window.hpp

        Vulkanite/src/vulkanite_main.cpp)

target_link_libraries(vulkanite PRIVATE
Vulkan::Vulkan
GLFW::GLFW
glm::glm
)