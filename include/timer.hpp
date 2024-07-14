//
// Created by VZWK5HR on 04.07.2024.
//

#ifndef REACTION_GAME_TIMER_TIMER_H
#define REACTION_GAME_TIMER_TIMER_H

#include <chrono>


class Timer {
public:
    Timer() {}

    void setTimer();        //Set start for Timer

    double getTimer();      //Return time since start in seconds

    bool timeGreater(double limit);       //Check if the time since start is greater than input seconds

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;        //Start point for the timer
};


#endif //REACTION_GAME_TIMER_TIMER_H
