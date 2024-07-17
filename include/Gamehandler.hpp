//
// Created by VZWK5HR on 11.07.2024.
//
#include "menu.hpp"
#include "highscore.hpp"
#include "Gamemode_1.h"
#include "Gamemode_2.h"

#ifndef KLASSENDIAGRAMM_DRAWIO_GAMEHANDLER_H
#define KLASSENDIAGRAMM_DRAWIO_GAMEHANDLER_H


class Gamehandler {
public:
    Gamehandler() {}

    void start();
private:
    double showResults(std::vector<double> scores, Menu *menu);
};


#endif //KLASSENDIAGRAMM_DRAWIO_GAMEHANDLER_H
