//
// Created by matti on 05.07.2024.
//

#ifndef KLASSENDIAGRAMM_DRAWIO_GAMEMODE_2_H
#define KLASSENDIAGRAMM_DRAWIO_GAMEMODE_2_H

#include "Gamemode.h"
#include <string>

class Gamemode_2 : public Gamemode {
public:
    Gamemode_2(int count, std::string sequenz);
    virtual ~Gamemode_2();
    double run() override;
};

#endif //KLASSENDIAGRAMM_DRAWIO_GAMEMODE_2_H
