//
// Created by matti on 05.07.2024.
//

#include "../include/Gamemode.h"

vector<double> Gamemode::run() {
    score.push_back(-1); // add -1 to score vector for exception handling
    return score;
}

Label Gamemode::randomLabel(vector <Label> labels) {
    labelHandler labelHandler;


    unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); //set seed for random number generator to current time
    mt19937 rng(seed); //initialize random number generator
    uniform_int_distribution<int> distribution(0, labels.size() - 1); //initialize distribution for random number generator

    int randomIndex = distribution(rng); //get random number

    return labels[randomIndex];
}

bool Gamemode::compareClick(Label labelToClick, clickHandler *clickH) {
    labelHandler labelHandler;

    // get click position
    vector<int> clickPosition = clickH->getPosition();

    // exception handling if no click is found
    if (clickPosition[0] == -1 || clickPosition[1] == -1) {
        printf("No click found\n");
        return false;
    }
    // convert click position to variables, so it is easier to read
    int click_x = clickPosition[0];
    int click_y = clickPosition[1];

    // get box position of label to click
    vector<int> boxPosition = labelHandler.getBoxPosition(labelToClick);

    // exception handling if no box is found
    if (boxPosition[0] == -1 || boxPosition[1] == -1 || boxPosition[2] == -1 || boxPosition[3] == -1) {
        printf("No box found\n");
        return false;
    }
    // convert box position to variables, so it is easier to read
    int box_start_x = boxPosition[0];
    int box_start_y = boxPosition[1];
    int box_end_x = boxPosition[2];
    int box_end_y = boxPosition[3];

    // check if click is in box
    if (click_x >= box_start_x && click_x <= box_end_x && click_y >= box_start_y && click_y <= box_end_y) {
        return true;
    } else {
        return false;
    }
}

void Gamemode::clickResult(Label labelToClick, cv::Mat image, Gui *gui) {

    clickHandler clickHandler;
    Timer timer;

    bool personAfk = 1; // set player as afk until proven otherwise

    clickHandler.primeMouseClick(windowName); // prime click so it can be detected

    gui->refreshWindow(windowName, image); // refresh image for new frame and boxes

    timer.setTimer();

    while (!timer.timeGreater(afkTime)) {

        gui->refreshWindow(windowName, image); // refresh window so window doesn't freeze

        if (clickHandler.checkClick()) { //enter if player clicked
            if (compareClick(labelToClick, &clickHandler)) { //enter if player clicked correct

                // if player clicked correct, print and add the time it took to click to the score
                score.push_back(timer.getTimer());
                printf("Correct click, time: %f\n", timer.getTimer());
            }
            else { // enter if player clicked wrong

                // if player clicked wrong, print and add penalty + the time it took to click to the score
                score.push_back(timer.getTimer() + penalty);
                printf("Incorrect click, time: %f plus %d sek punishment\n", timer.getTimer(), penalty);
            }
            //set player as not afk (so if won´t be true) and break loop
            personAfk = 0;
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(16)); // limit to 60 fps for performance reasons
    }

    if (personAfk){
        // if player is afk or too slow, print and add penalty to the score
        score.push_back(2*penalty);
        printf("You´re too slow or AFK, %d sek punishment\n", (2*penalty));
    }
}
