//
// Created by VZWK5HR on 03.07.2024.
//

#ifndef REACTION_GAME_LABEL_H
#define REACTION_GAME_LABEL_H

#include <iostream>
#include <opencv2/opencv.hpp>


class Label {
public:
    Label() : m_frame(-1), m_type(""), m_bbox(cv::Rect()) {}        //Default constructor defining m_frame as exception state '-1'
    Label(int frame, const std::string &type, const cv::Rect &bbox)
            : m_frame(frame), m_type(type), m_bbox(bbox) {}


    const int m_frame;            //Frame number, where the bounding box corresponds to
    const std::string m_type;     //Class of the bounding box (e.g. Pedestrian, Car, Cyclist)
    const cv::Rect m_bbox;
};


#endif //REACTION_GAME_LABEL_H
