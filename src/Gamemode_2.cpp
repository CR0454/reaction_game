//
// Created by matti on 05.07.2024.
//

#include "../include/Gamemode_2.h"

void Gamemode_2::waitRandomTime(int minimumMiliseconds, int maximumMiliseconds) {

    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(seed);
    uniform_int_distribution<int> distribution(minimumMiliseconds, maximumMiliseconds);
    int randomMilliseconds = distribution(rng);
    this_thread::sleep_for(chrono::milliseconds(randomMilliseconds));
}

double Gamemode_2::run() {
    labelHandler labelhandler;
    Gui gui(sequenz);
    Timer timer;

    labelhandler.loadLabels(sequenz);

    gui.createWindow(windowName);
    gui.pushToTop(windowName);

    for (int i = 0; i < count; ++i) {

        cv::Mat image = gui.nextImage();

        vector <Label> labels_of_image = labelhandler.getFrameLabels(gui.getImageN());

        Label random_label = randomLabel(labels_of_image);

        gui.refreshWindow(windowName, image);

        for (int i = 0; i < labels_of_image.size(); i++) {
            gui.drawBox(labels_of_image[i], image, 0, 0, 255);
        }

        gui.refreshWindow(windowName, image);

        gui.drawBox(random_label, image, 255, 0, 0);

        waitRandomTime(1000, 2000);

        clickResult(random_label, image, &gui);
    }
    return getScore();
}