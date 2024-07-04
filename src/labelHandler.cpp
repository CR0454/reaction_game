//
// Created by VZWK5HR on 04.07.2024.
//

#include "../include/labelHandler.hpp"
#include <string>
#include <fstream>
#include <iostream>

int labelHandler::loadLabels(std::string sequence) {

    std::string path = "../label_02/" + sequence + ".txt";        //path to sequence label file
    std::ifstream file(path);
    if(!file.is_open()) {
        std::cerr << "Could not open label file: " << path << std::endl;
        return -1;
    }
    std::string line;
    while(std::getline(file, line)) {
        std::istringstream ss(line);
        int frame, track_id, truncated, occluded;
        float alpha, bbox_left, bbox_top, bbox_right, bbox_bottom;
        float height, width, length;
        float loc_x, loc_y, loc_z, rot_y;
        std::string type;

        ss >> frame >> track_id >> type >> truncated >> occluded >> alpha
           >> bbox_left >> bbox_top >> bbox_right >> bbox_bottom
           >> height >> width >> length
           >> loc_x >> loc_y >> loc_z >> rot_y;

        if(!ss.fail()) {
            if(type != "DontCare") {            //"DontCare" m_labels are ignored while loading
                cv::Rect bbox(static_cast<int>(bbox_left), static_cast<int>(bbox_top),
                              static_cast<int>(bbox_right - bbox_left), static_cast<int>(bbox_bottom - bbox_top));
                m_labels.emplace_back(frame, type, bbox);
            }

        }
        else {
            std::cerr << "Error reading line: " << line << std::endl;
        }
    }
    std::cout << "Read " << m_labels.size() << " labels from file \"" << path << "\"\n";

    return 0;

}

std::vector<Label> labelHandler::getFrameLabels(int frame) {
    std::vector<Label> frameLabels;
    for(Label label: m_labels) {
        if(label.m_frame == frame) {         //Check if label is tagged for frame -> add to list
            frameLabels.emplace_back(label);
        }
        else if(label.m_frame > frame) {     //labels sorted by frame -> avoid unnecessary checks
            break;
        }
    }
    return frameLabels;
}