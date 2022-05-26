#pragma once

#include "vulkanite_window.hpp"
#include "vulkanite_pipeline.hpp"
#include "vulkanite_device.hpp"
#include "vulkanite_swap_chain.hpp"

#include <memory>
#include <vector>

namespace vulkanite {
	class VulkaniteApp {
	public:
		static constexpr int WIDTH = 1280;
		static constexpr int HEIGHT = 720;

        VulkaniteApp();
        ~VulkaniteApp();

        VulkaniteApp(const VulkaniteApp &) = delete;
        VulkaniteApp &operator=(const VulkaniteApp &) = delete;
		void run();
	private:
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

		VulkaniteWindow vulkaniteWindow{ WIDTH, HEIGHT, "Vulkanite" };
		VulkaniteDevice vulkaniteDevice{vulkaniteWindow};
        VulkaniteSwapChain vulkaniteSwapChain{vulkaniteDevice, vulkaniteWindow.getExtent()};
		std::unique_ptr<VulkanitePipeline> vulkanitePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
	};
}