//
// Created by Devin Louis on 19/01/2022.
//

#include "vulkanite_window.hpp"

namespace vulkanite
{
    VulkaniteWindow::VulkaniteWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }

    VulkaniteWindow::~VulkaniteWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }


    void VulkaniteWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }
}
