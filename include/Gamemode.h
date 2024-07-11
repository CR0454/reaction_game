//
// Created by matti on 05.07.2024.
//

#ifndef KLASSENDIAGRAMM_DRAWIO_GAMEMODE_H
#define KLASSENDIAGRAMM_DRAWIO_GAMEMODE_H
#include <iostream>
#include "label.hpp"
#include "labelHandler.hpp"
#include "gui.hpp"
#include "timer.hpp"
#include "clickHandler.hpp"
using namespace std;

class Gamemode {
public:
    Gamemode(int count, string sequenz) : count(count), sequenz(sequenz), score(0) {} // construktor
    ~Gamemode(); // destruktor

    virtual double run(); // strat game and return avg. time

protected:
    Label randomLabel(vector<Label> labels); // return random label
    bool compareClick(Label labelToClick, clickHandler *clickhandler); // checks if click is in box
    double score; // average time to click
    int count; // count of rounds to play
    string sequenz; // sequenz of images
};


#endif //KLASSENDIAGRAMM_DRAWIO_GAMEMODE_H
