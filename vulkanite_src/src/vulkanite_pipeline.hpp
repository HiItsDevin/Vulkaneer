//
// Created by Devin Louis on 19/01/2022.
//

#pragma once

#include "vulkanite_device.hpp"

#include <string>
#include <vector>

namespace vulkanite {
    struct PipelineConfigInfo {};
    class VulkanitePipeline {
    public:
        VulkanitePipeline(
                Vulkanite::VulkaniteDevice &device,
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo);
        ~VulkanitePipeline() {}

        VulkanitePipeline(const VulkanitePipeline&) = delete;
        void operator=(const VulkanitePipeline&) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(
                const std::string& vertFilepath,
                const std::string& fragFilepath,
                const PipelineConfigInfo& configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        Vulkanite::VulkaniteDevice& vulkaniteDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}