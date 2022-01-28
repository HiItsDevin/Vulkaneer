#pragma once

#include "vulkanite_window.hpp"
#include "vulkanite_pipeline.hpp"

namespace vulkanite {
	class VulkaniteApp {
	public:
		static constexpr int WIDTH = 1280;
		static constexpr int HEIGHT = 720;

		void run();
	private:
		VulkaniteWindow vulkaniteWindow{ WIDTH, HEIGHT, "Vulkanite" };
		VulkanitePipeline vulkanitePipeline{ "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv" };
	};
}