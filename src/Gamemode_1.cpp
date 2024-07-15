//
// Created by matti on 05.07.2024.
//

#include "../include/Gamemode_1.h"

double Gamemode_1::run() {
    labelHandler labelhandler;
    Gui gui(sequenz);

    labelhandler.loadLabels(sequenz);
    gui.createWindow(windowName);

    gui.pushToTop(windowName);

    for (int i = 0; i < count; ++i) {

        cv::Mat image = gui.nextImage();

        Label random_label = randomLabel(labelhandler.getFrameLabels(gui.getImageN()));

        gui.drawBox(random_label, image, 255, 0, 0);

        clickResult(random_label, image, &gui);
    }
    return getScore();
}