//
// Created by matti on 05.07.2024.
//

#ifndef KLASSENDIAGRAMM_DRAWIO_GAMEMODE_H
#define KLASSENDIAGRAMM_DRAWIO_GAMEMODE_H

//Include all necessary class files for all game modes
#include "labelHandler.hpp"
#include "gui.hpp"
#include "timer.hpp"
#include "clickHandler.hpp"

//Include all necessary libraries for all game modes
#include <iostream>
#include <random>
#include <chrono>
#include <thread>

//define namespace std, so we don't have to write std:: before every function in all game modes
using namespace std;

class Gamemode {
public:
    Gamemode(int count, string sequence) : count(count), sequenz(sequence), score(0) {} // constructor

    virtual double run(); // start game and return double score

protected:
    // protected functions
    void clickResult(Label labelToClick, cv::Mat image, Gui *gui); // print result of click and add time to score
    double getScore(int currentFrame); // return score at current frame
    Label randomLabel(vector <Label> labels); // return random label from given vector
    bool compareClick(Label labelToClick, clickHandler *clickHandler); // checks if click is in box

    // protected input variables
    double score; // average time to click
    int count; // count of rounds to play
    string sequence; // which sequence of images to play

    // protected const variables for game settings
    const string windowName = "Reaction Game"; // name of the window
    const int penalty = 5; // penalty for wrong click and afk(2*penalty)
    const int afkTime = 3; // after this time the player is afk
};


#endif //KLASSENDIAGRAMM_DRAWIO_GAMEMODE_H
