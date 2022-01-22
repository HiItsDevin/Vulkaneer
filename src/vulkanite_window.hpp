//
// Created by Devin Louis on 19/01/2022.
//

#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace vulkanite {
    class VulkaniteWindow {
    public:
        VulkaniteWindow(int w, int h, std::string name);
        ~VulkaniteWindow();

        VulkaniteWindow(const VulkaniteWindow &) = delete;
        VulkaniteWindow &operator=(const VulkaniteWindow &) = delete;

        bool shouldClose() { return glfwWindowShouldClose(window);}

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    private:
        void initWindow();
        const int width;
        const int height;
        std::string windowName;
        GLFWwindow* window;
    };
}