//
// Created by VZWK5HR on 03.07.2024.
//

#include "../include/label.hpp"

void Label::drawLabel(cv::Mat img) {
    cv::rectangle(img, m_bbox, cv::Scalar(0, 255, 0));
}