//
// Created by matti on 05.07.2024.
//

#include "../include/Gamemode_2.h"

void Gamemode_2::waitRandomTime(int minimumMilliseconds, int maximumMilliseconds) {

    unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); //set seed for random number generator to current time
    mt19937 rng(seed); //initialize random number generator
    uniform_int_distribution<int> distribution(minimumMilliseconds, maximumMilliseconds); //initialize distribution for random number generator
    int randomMilliseconds = distribution(rng); //get random number
    this_thread::sleep_for(chrono::milliseconds(randomMilliseconds)); //wait random time
}

double Gamemode_2::run() {
    labelHandler labelHandler;
    Gui gui(sequence);
    Timer timer;

    labelHandler.loadLabels(sequence); //load labels

    gui.createWindow(windowName); // create window
    gui.pushToTop(windowName); // will focus the window to the front

    for (int i = 0; i < count; ++i) {

        cv::Mat image = gui.nextImage(); //load next image of sequence

        vector <Label> labels_of_image = labelHandler.getFrameLabels(gui.getImageN()); //get labels of image

        Label random_label = randomLabel(labels_of_image); // choose random label

        //draw blue boxes around all labels
        for (int i = 0; i < labels_of_image.size(); i++) {
            gui.drawBox(labels_of_image[i], image, 0, 0, 255);
        }

        gui.refreshWindow(windowName, image); // display image with blue boxes

        waitRandomTime(1000, 2000); // wait random time between 1 and 2 seconds

        gui.drawBox(random_label, image, 255, 0, 0); //draw red box around random label

        clickResult(random_label, image, &gui);
    }
    return score; //return final score vector
}