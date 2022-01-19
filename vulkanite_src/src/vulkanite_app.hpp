//
// Created by Devin Louis on 19/01/2022.
//

#pragma once

#include "vulkanite_window.hpp"

namespace vulkanite {
    class App {
    public:
        static constexpr int WIDTH = 1280;
        static constexpr int HEIGHT = 720;

        void run();
    private:
        VulkaniteWindow vulkaniteWindow{WIDTH, HEIGHT, "Vulkanite"};
    };
}