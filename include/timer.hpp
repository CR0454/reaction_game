//
// Created by VZWK5HR on 04.07.2024.
//

#ifndef REACTION_GAME_TIMER_TIMER_H
#define REACTION_GAME_TIMER_TIMER_H

#include <chrono>


class timer {
public:
    timer() {}

    void setTimer();        //Set start for timer

    double getTimer();      //Return time since start in seconds

    bool timeGreater(double);       //Check if the time since start is greater than input seconds

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
};


#endif //REACTION_GAME_TIMER_TIMER_H
