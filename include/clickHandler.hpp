//
// Created by VZWK5HR on 04.07.2024.
//

#ifndef REACTION_GAME_MOUSECLICK_CLICKHANDLER_H
#define REACTION_GAME_MOUSECLICK_CLICKHANDLER_H
#include <opencv2/opencv.hpp>
#include <iostream>


class clickHandler {
public:

    clickHandler(): clickx(-1), clicky(-1) {}

    static void CallBackFunc(int event, int x, int y, int flags, void* userdata);           //Bridge function to call "CallBackFunc(event,x,y)"

    void primeMouseClick(std::string windowName);       //Set up the mouse callback function

    std::vector<int> getPosition();         //Return the x and y position from last mouse click

private:
    void CallBackFunc(int event, int x, int y);     //React to left mouse click

    int clickx, clicky;

};


#endif //REACTION_GAME_MOUSECLICK_CLICKHANDLER_H
