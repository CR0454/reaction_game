//
// Created by matti on 05.07.2024.
//

#include "../include/Gamemode_1.h"

vector<double> Gamemode_1::run() {
    labelHandler labelHandler;
    Gui gui(sequence);

    labelHandler.loadLabels(sequence); //load labels

    gui.createWindow(windowName); // create window
    gui.pushToTop(windowName); // will focus the window to the front

    for (int i = 0; i < count; ++i) {

        cv::Mat image = gui.nextImage(); //load next image of sequence

        vector <Label> labels_of_image = labelHandler.getFrameLabels(gui.getImageN()); //get labels of image

        //check if there are labels in the image
        if (labels_of_image.empty()) {
            i--;
        }
        else{

            Label random_label = randomLabel(labels_of_image); // choose random label

            gui.drawBox(random_label, image, 255, 0, 0); //draw red box around random label

            clickResult(random_label, image, &gui);
        }

    }
    return score; //return final score vector
}