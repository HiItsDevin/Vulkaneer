#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

namespace vulkanite
{
	class VulkaniteWindow
	{
	public:
		VulkaniteWindow(int w, int h, std::string name);
		~VulkaniteWindow();

		bool shouldClose() {
			return glfwWindowShouldClose(window);
		}
	private:
		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}