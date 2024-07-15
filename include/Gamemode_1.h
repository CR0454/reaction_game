//
// Created by matti on 05.07.2024.
//

#ifndef KLASSENDIAGRAMM_DRAWIO_GAMEMODE_1_H
#define KLASSENDIAGRAMM_DRAWIO_GAMEMODE_1_H

#include "Gamemode.h"

class Gamemode_1 : public Gamemode {
public:
    Gamemode_1(int count, string sequenz) : Gamemode(count, sequenz) {}

    double run() override;

};

#endif //KLASSENDIAGRAMM_DRAWIO_GAMEMODE_1_H