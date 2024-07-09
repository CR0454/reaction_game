//
// Created by matti on 05.07.2024.
//

#include "Gamemode_2.h"
#include <random>
#include <chrono>
#include <thread>

Gamemode_2::Gamemode_2(int count, std::string sequenz) : Gamemode(count, sequenz) {
}

Gamemode_2::~Gamemode_2() {

}

double Gamemode_2::run() {
    labelHandler labelhandler();
    Gui gui(sequenz);
    Timer timer();

    for (int i = 0; i < count; ++i) {

        cv::Mat image = gui.nextImage();

        labes_of_image = labelhandler.getFrameLabels(gui.getImageN());

        label random_label = randomLabel(labels_of_image);

        drawBox(random_label, image, 0);

        for(int i = 0; i < labels_of_image.size(); i++) {
            drawBox(labels_of_image[i], image, 2);
        }


        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        std::mt19937 rng(seed);
        std::uniform_int_distribution<int> distribution(1000, 2000);
        int randomMilliseconds = distribution(rng);
        std::this_thread::sleep_for(std::chrono::milliseconds(randomMilliseconds));


        gui.refreshImage(image);

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