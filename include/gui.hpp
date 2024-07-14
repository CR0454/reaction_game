//
// Created by VZWK5HR on 02.07.2024.
//

#ifndef REACTION_GAME_GUI_H
#define REACTION_GAME_GUI_H

#include "label.hpp"

class Gui {

public:
    Gui(std::string sequence):      //Constructor, set the current image frame to 0 and the sequence to the given value
        m_imageN(0),
        m_sequence(sequence)
        {}

    void createWindow(std::string winName);     //Create a window for all other GUI elements to take part in

    void pushToTop(std::string winName);        //Used to push window atop all other windows at the start of game

    void refreshWindow(std::string winName, cv::Mat image);     //

    cv::Mat nextImage();                //Load the next image in the sequence

    void drawBox(Label label, cv::Mat image, int r, int g, int b);        //Draws the specified label on the currently shown image

    int getImageN();                    //Return the current frame number

private:
    const std::string getPath();      //Private function to generate the complete path and filename for the current image

    int m_imageN;               //Image number in sequence
    const std::string m_sequence;     //Used image sequence


};


#endif //REACTION_GAME_GUI_H
