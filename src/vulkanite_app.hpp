#pragma once

#include "vulkanite_window.hpp"
#include "vulkanite_pipeline.hpp"
#include "vulkanite_device.hpp"

namespace vulkanite {
	class VulkaniteApp {
	public:
		static constexpr int WIDTH = 1280;
		static constexpr int HEIGHT = 720;

		void run();
	private:
		VulkaniteWindow vulkaniteWindow{ WIDTH, HEIGHT, "Vulkanite" };
		VulkaniteDevice vulkaniteDevice{vulkaniteWindow};
		VulkanitePipeline vulkanitePipeline{vulkaniteDevice, "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", VulkanitePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
	};
}