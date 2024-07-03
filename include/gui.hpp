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
        {loadLabels();}    //Labels are automatically loaded when an object is created

    int refreshImage();         //Takes the next image in the sequence and displays it

    int loadLabels();           //Load all Labels for the selected sequence without "DontCare"

    std::vector<Label> getFrameLabels();        //Return all Labels associated with the currently shown image

    void drawBox(Label, int, int, int);        //Draws the specified label on the currently shown image

private:
    std::string getPath();      //Private function to generate the complete path and filename for the current image

    cv::Mat image;              //Current image loaded into OpenCV
    int m_imageN;               //Image number in sequence
    std::string m_sequence;     //Used image sequence
    std::vector<Label> m_labels;        //All labels for the sequence as loaded by loadLabels()


};


#endif //REACTION_GAME_GUI_H
