//
// Created by VZWK5HR on 02.07.2024.
//

#ifndef REACTION_GAME_GUI_H
#define REACTION_GAME_GUI_H

#include "label.hpp"

class Gui {

public:
    Gui(std::string sequence):
        m_imageN(0),
        m_sequence(sequence)
        {}

    void createWindow(std::string winName);

    void refreshWindow(std::string winName, cv::Mat image);

    cv::Mat nextImage();                //Load the next image in the sequence

    void drawBox(Label, cv::Mat, int, int, int);        //Draws the specified label on the currently shown image

    int getImageN();                    //Return the current frame number

private:
    std::string getPath();      //Private function to generate the complete path and filename for the current image

    int m_imageN;               //Image number in sequence
    std::string m_sequence;     //Used image sequence


};


#endif //REACTION_GAME_GUI_H
