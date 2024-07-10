//
// Created by matti on 05.07.2024.
//

#include "Gamemode.h"
#include "gui.hpp"
#include "label.hpp"
#include "labelhandler.hpp"
#include "timer.hpp"
#include "clickhandler.hpp"
#include <iostream>
#include <random>
#include <chrono>


using namespace std;


Gamemode::Gamemode(int count, string sequenz) : count(count), sequenz(sequenz) {
}

Gamemode::~Gamemode() {

}

double Gamemode::run() {
    return 0;
}

label Gamemode::randomLabel(vector<label> labels) {
    labelHandler labelhandler();

    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<int> distribution(0, labels.size() - 1);

    int randomIndex = distribution(rng);

    label randomLabel = labels[randomIndex];
    return randomLabel;
}

bool Gamemode::compareClick(label labelToClick) {

    clickhandler clickhandler();
    labelHandler labelhandler();

    clickhandler.primeMouseClick("Reaction Game");

    vector<int> clickPosition = clickhandler.getPosition();
    if (clickPosition[0] == -1 && clickPosition[1] == -1) {
        printf("No click found\n");
        return false;
    }
    int click_x = position[0];
    int click_y = position[1];

    vector<int> boxPosition = labelhandler.getBoxPosition(labelToClick);
    if (boxPosition[0] == -1 && boxPosition[1] == -1 && boxPosition[2] == -1 && boxPosition[3] == -1) {
        printf("No box found\n");
        return false;
    }
    int box_start_x = boxPosition[0];
    int box_start_y = boxPosition[1];
    int box_end_x = boxPosition[2];
    int box_end_y = boxPosition[3];

    if (click_x >= box_start_x && click_x <= box_end_x && click_y >= box_start_y && click_y <= box_end_y) {
        return true;
    } else {
        return false;
    }
}