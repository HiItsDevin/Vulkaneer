cmake_minimum_required(VERSION 3.16)
project(vulkanite LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(Vulkan REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(vulkanite
        "src/vulkanite_main.cpp"

        "src/vulkanite_app.cpp"
        "src/vulkanite_app.hpp"

        "src/vulkanite_window.cpp"
        "src/vulkanite_window.hpp"

        "src/vulkanite_pipeline.cpp"
        "src/vulkanite_pipeline.hpp"

        "src/vulkanite_device.cpp"
        "src/vulkanite_device.hpp")

target_link_libraries(vulkanite PRIVATE
        Vulkan::Vulkan
        glfw
        glm::glm)