#pragma once

#include <string>
#include <vector>

namespace vulkanite {
	class VulkanitePipeline {
	public:
		VulkanitePipeline(const std::string& vertFilepath, const std::string& fragFilepath);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
	};
}