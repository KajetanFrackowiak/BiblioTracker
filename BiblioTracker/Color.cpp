//
// Created by frackowiak on 01.01.24.
//

#include "Color.h"

#include <iostream>

void setColor(const Color color) {
    switch (color) {
        // ANSI escape codes
        case Color::RESET:
            std::cout << "\033[0m";
            break;
        case Color::RED:
            std::cout << "\033[1;31m";
            break;
        case Color::GREEN:
            std::cout << "\033[1;32m";
            break;
        case Color::YELLOW:
            std::cout << "\033[1;33m";
            break;
        case Color::BLUE:
            std::cout << "\033[1;34m";
            break;
        case Color::PURPLE:
            std::cout <<"\033[1;35m";
    }
}
