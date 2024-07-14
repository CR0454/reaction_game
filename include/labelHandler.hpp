//
// Created by VZWK5HR on 04.07.2024.
//

#ifndef REACTION_GAME_LABELHANDLER_H
#define REACTION_GAME_LABELHANDLER_H

#include "label.hpp"

class labelHandler {
public:
    labelHandler() {}

    int loadLabels(std::string sequence);           //Load all Labels for the selected sequence, ignoring "DontCare"

    std::vector<Label> getFrameLabels(int frame);        //Return all Labels associated with the input frame

    std::vector<int> getBoxPosition(Label label);     //Return position of label

private:
    std::vector<Label> m_labels;                    //Vector for all labels in the sequence
};


#endif //REACTION_GAME_LABELHANDLER_H
