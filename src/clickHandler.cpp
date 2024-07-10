//
// Created by VZWK5HR on 04.07.2024.
//

#include "../include/clickHandler.hpp"
void clickHandler::CallBackFunc(int event, int x, int y) {
    if(event == cv::EVENT_LBUTTONDOWN) {        //Nur bei linkem Mausklick
        clickx = x;
        clicky = y;
        clickBool = true;
    }
}

void clickHandler::CallBackFunc(int event, int x, int y, int flags, void *userdata) {
    clickHandler* clickH = reinterpret_cast<clickHandler*>(userdata);
    clickH -> CallBackFunc(event, x, y);

}

void clickHandler::primeMouseClick(std::string windowName) {
    cv::setMouseCallback(windowName, CallBackFunc, NULL);
}

std::vector<int> clickHandler::getPosition() {
    std::vector<int> pos = {clickx, clicky};
    return pos;
}

void clickHandler::primeClick() {
    clickBool = false;
}

bool clickHandler::checkClick() {
    return clickBool;
}