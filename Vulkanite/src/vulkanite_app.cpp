//
// Created by Devin Louis on 19/01/2022.
//

#include "vulkanite_app.hpp"
#include <iostream>

namespace vulkanite {
    void App::run() {
        std::cout << "Running Vulkanite...";
        while (!vulkaniteWindow.shouldClose()) {
            glfwPollEvents();
        }
    }
}