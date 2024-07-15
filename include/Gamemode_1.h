//
// Created by matti on 05.07.2024.
//

#ifndef KLASSENDIAGRAMM_DRAWIO_GAMEMODE_1_H
#define KLASSENDIAGRAMM_DRAWIO_GAMEMODE_1_H

#include "Gamemode.h"

class Gamemode_1 : public Gamemode {
public:
    Gamemode_1(int count, string sequence) : Gamemode(count, sequence) {}  // constructor

    double run() override; // run will start the game and return the score

};

#endif //KLASSENDIAGRAMM_DRAWIO_GAMEMODE_1_H