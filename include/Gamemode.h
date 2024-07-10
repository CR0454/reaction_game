//
// Created by matti on 05.07.2024.
//

#ifndef KLASSENDIAGRAMM_DRAWIO_GAMEMODE_H
#define KLASSENDIAGRAMM_DRAWIO_GAMEMODE_H
#include <iostream>
using namespace std;

class Gamemode {
public:
    Gamemode(int count, string sequenz) : count(count), sequenz(sequenz); // construktor
    ~Gamemode(); // destruktor

virtual:
    double run(); // strat game and return avg. time

protected:
    label randomLabel(vector<label> labels); // return random label
    bool compareClick(label labelToClick); // checks if click is in box
    int score; // average time to click
    int count; // count of rounds to play
    string sequenz; // sequenz of images
};


#endif //KLASSENDIAGRAMM_DRAWIO_GAMEMODE_H
