#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>

namespace vulkanite
{
	class VulkaniteWindow
	{
	public:
		VulkaniteWindow(int w, int h, std::string name);
		~VulkaniteWindow();
	private:
		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}