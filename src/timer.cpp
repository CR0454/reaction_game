//
// Created by VZWK5HR on 04.07.2024.
//

#include "../include/timer.hpp"

void Timer::setTimer() {
    m_start = std::chrono::high_resolution_clock::now();
}

//get time from function in microseconds to increase accuracy -> convert to seconds
double Timer::getTimer() {
    return 0.000001 * std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_start).count();
}

bool Timer::timeGreater(double limit) {
    if(getTimer() >= limit) {
        return true;
    }
    else {
        return false;
    }
}
