//
// Created by Devin Louis on 19/01/2022.
//

#include "vulkanite_app.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main() {
    vulkanite::App app{};

    try {
        app.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}