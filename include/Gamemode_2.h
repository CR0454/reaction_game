//
// Created by matti on 05.07.2024.
//

#ifndef KLASSENDIAGRAMM_DRAWIO_GAMEMODE_2_H
#define KLASSENDIAGRAMM_DRAWIO_GAMEMODE_2_H

#include "Gamemode.h"

class Gamemode_2 : public Gamemode {
public:
    Gamemode_2(int count, string sequenz) : Gamemode(count, sequenz) {}

    double run() override;

private:
    void waitRandomTime(int minimumMiliseconds, int maximumMiliseconds);
};

#endif //KLASSENDIAGRAMM_DRAWIO_GAMEMODE_2_H
