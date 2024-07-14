//
// Created by VZWK5HR on 04.07.2024.
//

#ifndef REACTION_GAME_MOUSECLICK_CLICKHANDLER_H
#define REACTION_GAME_MOUSECLICK_CLICKHANDLER_H
#include <opencv2/opencv.hpp>
#include <iostream>


class clickHandler {
public:

    clickHandler(): clickx(-1), clicky(-1), clickBool(false) {}     //Constructor, set clickx & clicky to an error state

    static void CallBackFunc(int event, int x, int y, int flags, void* userdata);           //Bridge function to call "CallBackFunc(event,x,y)"

    void primeMouseClick(std::string windowName);       //Set up the mouse callback function

    std::vector<int> getPosition();         //Return the x and y position from last mouse click

    bool checkClick();      //Return if the left mouse button has been clicked

private:
    void CallBackFunc(int event, int x, int y);     //React to left mouse click

    int clickx, clicky;         //X and Y position of last mouse click

    bool clickBool;             //Boolean for whether the left mouse button has been clicked

};


#endif //REACTION_GAME_MOUSECLICK_CLICKHANDLER_H
