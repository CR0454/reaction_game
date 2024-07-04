//
// Created by VZWK5HR on 04.07.2024.
//

#include "../include/timer.hpp"

void timer::setTimer() {
    m_start = std::chrono::high_resolution_clock::now();
}

double timer::getTimer() {
    return 0.000001 * std::chrono::duration_cast<std::chrono::microseconds >(std::chrono::high_resolution_clock::now() - m_start).count();
}

bool timer::timeGreater(double limit) {
    if(getTimer() >= limit) {
        return true;
    }
    else {
        false;
    }
}
