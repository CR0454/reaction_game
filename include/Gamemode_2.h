//
// Created by matti on 05.07.2024.
//

#ifndef KLASSENDIAGRAMM_DRAWIO_GAMEMODE_2_H
#define KLASSENDIAGRAMM_DRAWIO_GAMEMODE_2_H

#include "Gamemode.h"

class Gamemode_2 : public Gamemode {
public:
    Gamemode_2(int count, string sequence) : Gamemode(count, sequence) {} // constructor

    double run() override; // run will start the game and return the score

private:
    void waitRandomTime(int minimumMilliseconds, int maximumMilliseconds); // wait random time between minimum and maximum milliseconds
};

#endif //KLASSENDIAGRAMM_DRAWIO_GAMEMODE_2_H
