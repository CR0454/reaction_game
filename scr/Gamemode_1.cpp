//
// Created by matti on 05.07.2024.
//

#include "Gamemode_1.h"

Gamemode_1::Gamemode_1(int count, string sequenz) : count(count), sequenz(sequenz) {
}

Gamemode_1::~Gamemode_1() {

}

double Gamemode_1::run() {
    labelHandler labelhandler();
    Gui gui(sequenz);

    for (int i = 0; i < count; ++i) {

        cv::Mat image = gui.nextImage();

        label random_label = randomLabel(labelhandler.getFrameLabels(gui.getImageN()));

        drawBox(random_label, image, 0);

        gui.refreshImage(image);

        Timer timer();
        timer.setTimer();

        while (!timerGreaterThan(10)) {
            if (compareClick(random_label)) {
                score += timer.getTimer();
                printf("Correct click\n, time: %d\n", timer.getTimer());
            } else {
                score += (timer.getTimer() + 5);
                printf("Incorrect click\n, time: %d \nplus 5sek punishment\n", timer.getTimer());
            }
        }
    }
    return score / count;
}