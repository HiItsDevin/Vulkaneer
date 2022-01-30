#include "vulkanite_pipeline.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace vulkanite {
	VulkanitePipeline::VulkanitePipeline(VulkaniteDevice& device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo) : vulkaniteDevice{device} {
		createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
	}

	std::vector<char> VulkanitePipeline::readFile(const std::string& filepath) {

		std::ifstream file{ filepath, std::ios::ate | std::ios::binary };

		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file: " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}

	void VulkanitePipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo) {
		auto vertCode = readFile(vertFilepath);
		auto fragCode = readFile(fragFilepath);

		std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
		std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
	}

	void VulkanitePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(vulkaniteDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create shader module");
		}
	}

	PipelineConfigInfo VulkanitePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
		PipelineConfigInfo configInfo{};

		configInfo.inputAssemblyInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		configInfo.inputAssemblyInfo.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		configInfo.inputAssemblyInfo.primitiveRestartEnable = VK_FALSE;

		return configInfo;
	}
}