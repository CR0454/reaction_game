//
// Created by VZWK5HR on 03.07.2024.
//

#ifndef REACTION_GAME_LABEL_H
#define REACTION_GAME_LABEL_H

#include <iostream>
#include <opencv2/opencv.hpp>


class Label {
public:
    Label() : m_frame(0), m_type(""), m_bbox(cv::Rect()) {}
    Label(int frame, const std::string &type, const cv::Rect &bbox)
            : m_frame(frame), m_type(type), m_bbox(bbox) {}

    void drawLabel(cv::Mat);

    int m_frame;            //Frame number, where the bounding box corresponds to
    std::string m_type;     //Class of the bounding box (e.g. Pedestrian, Car, Cyclist) --> DontCare should be ignored
    cv::Rect m_bbox;
};


#endif //REACTION_GAME_LABEL_H
