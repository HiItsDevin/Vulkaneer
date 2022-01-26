#include "vulkanite_app.hpp"

namespace vulkanite {
	void VulkaniteApp::run() {
		while(!vulkaniteWindow.shouldClose()) {
			glfwPollEvents();
		}
	}
}