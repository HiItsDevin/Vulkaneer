#include "vulkanite_app.hpp"

namespace vulkanite {
	VulkaniteApp::VulkaniteApp() {
        createPipelineLayout();
        createPipeline();
        createCommandBuffers();
    }

    VulkaniteApp::~VulkaniteApp() {
        vkDestroyPipelineLayout(vulkaniteDevice.device(), pipelineLayout, nullptr);
    }

    void VulkaniteApp::run() {
		while(!vulkaniteWindow.shouldClose()) {
			glfwPollEvents();
		}
	}

    void VulkaniteApp::createPipelineLayout() {
        VkPipelineLayoutCreateInfo pipelineLayoutInfo {};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        pipelineLayoutInfo.pSetLayouts = nullptr;
        pipelineLayoutInfo.pushConstantRangeCount = 0;
        pipelineLayoutInfo.pPushConstantRanges = nullptr;
        if (vkCreatePipelineLayout(vulkaniteDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create pipeline layout!");
        }
    }

    void VulkaniteApp::createPipeline() {
        auto pipelineConfig = VulkanitePipeline::defaultPipelineConfigInfo(vulkaniteSwapChain.width(), vulkaniteSwapChain.height());
        pipelineConfig.renderPass = vulkaniteSwapChain.getRenderPass();
        pipelineConfig.pipelineLayout = pipelineLayout;
        vulkanitePipeline = std::make_unique<VulkanitePipeline>(
                vulkaniteDevice,
                "shaders/simple_shader.frag.spv",
                "shaders/simple_shader.vert.spv",
                pipelineConfig);
    }

    void VulkaniteApp::createCommandBuffers() {}
    void VulkaniteApp::drawFrame() {}
}