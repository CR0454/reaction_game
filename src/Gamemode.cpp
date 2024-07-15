//
// Created by matti on 05.07.2024.
//

#include "../include/Gamemode.h"

double Gamemode::run() {
    return 0;
}

double Gamemode::getScore() {
    return score / count;
}

Label Gamemode::randomLabel(vector <Label> labels) {
    labelHandler labelhandler;

    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<int> distribution(0, labels.size() - 1);

    int randomIndex = distribution(rng);

    Label randomLabel = labels[randomIndex];
    return randomLabel;
}

bool Gamemode::compareClick(Label labelToClick, clickHandler *clickH) {
    labelHandler labelhandler;

    vector<int> clickPosition = clickH->getPosition();
    if (clickPosition[0] == -1 || clickPosition[1] == -1) {
        printf("No click found\n");
        return false;
    }
    int click_x = clickPosition[0];
    int click_y = clickPosition[1];

    vector<int> boxPosition = labelhandler.getBoxPosition(labelToClick);
    if (boxPosition[0] == -1 || boxPosition[1] == -1 || boxPosition[2] == -1 || boxPosition[3] == -1) {
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

void Gamemode::clickResult(Label labelToClick, cv::Mat image, Gui *gui) {

    clickHandler clickhandler;
    Timer timer;

    bool personAfk = 1; // set player as afk until proven otherwise

    clickhandler.primeMouseClick(windowName);

    gui.refreshWindow(windowName, image);

    timer.setTimer();

    while (!timer.timeGreater(afkTime)) {
        gui.refreshWindow(windowName, image);
        if (clickhandler.checkClick()) {
            if (compareClick(labelToClick, &clickhandler)) {
                score += timer.getTimer();
                printf("Correct click, time: %f\nCurrent avg. time: %f\n", timer.getTimer(), getScore());
            } else {
                score += (timer.getTimer() + penalty);
                printf("Incorrect click, time: %f plus %d sek punishment\nCurrent avg. time: %f\n"
                       , timer.getTimer(), penalty, getScore());
            }
            personAfk = 0;
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(16)); // limit to 60 fps for performance reasons
    }

    if personAfk{
                score += (2 * penalty);
                printf("You´re too slow or AFK, %d sek punishment\nCurrent avg. time: %f\n", (2*penalty), getScore());
        }
}
