//
// Created by matti on 05.07.2024.
//

#include "../include/Gamemode_1.h"
#include <thread>

Gamemode_1::~Gamemode_1() {

}

double Gamemode_1::run() {
    labelHandler labelhandler;
    Gui gui(sequenz);
    Timer timer;

    labelhandler.loadLabels(sequenz);
    cv::namedWindow("Reaction Game", 1);

    for (int i = 0; i < count; ++i) {

        cv::Mat image = gui.nextImage();

        Label random_label = randomLabel(labelhandler.getFrameLabels(gui.getImageN()));

        gui.drawBox(random_label, image, 255, 0, 0);

        gui.refreshWindow("Reaction Game", image);

        timer.setTimer();

        clickHandler clickhandler;
        clickhandler.primeMouseClick("Reaction Game");

        while (!timer.timeGreater(3)) {
            gui.refreshWindow("Reaction Game", image);
            if(clickhandler.checkClick()) {
                if (compareClick(random_label, &clickhandler)) {
                    score += timer.getTimer();
                    printf("Correct click\n, time: %f\n", timer.getTimer());
                } else {
                    score += (timer.getTimer() + 5);
                    printf("Incorrect click\n, time: %f \nplus 5sek punishment\n", timer.getTimer());
                }
                break;
            }
            this_thread::sleep_for(chrono::milliseconds(10));

        }
    }
    return score / count;
}