//
// Created by VZWK5HR on 02.07.2024.
//

#include <opencv2/opencv.hpp>
#include "../include/gui.hpp"
#include <fstream>

/*void Gui::refreshImage(cv::Mat image) {

    cv::imshow("Reaction Game", image);
    cv::waitKey(0);
}*/

void Gui::createWindow(std::string winName) {
    cv::namedWindow(winName, 1);
}

void Gui::refreshWindow(std::string winName, cv::Mat img) {
    cv::imshow(winName, img);
    cv::waitKey(10);
}

cv::Mat Gui::nextImage() {
    cv::Mat image = cv::imread(getPath());

    if (image.empty()) {                                    //Check if image was loaded correctly
        std::cerr << "Error: Could not open or find the image!" << std::endl;
    }
    m_imageN++;                     //"Current" image in sequence increased by 1 in preparation for next function call
    return image;
}

std::string Gui::getPath() {
    std::string path = "../training/image_02/";     //Default folder layout for every image sequence
    path += m_sequence + "/";                       //Sequence specific folder name

    std::string filename = "";                      //Filename conversion int to string with necessary zeroes
    if(m_imageN >= 10000 && m_imageN < 100000 ) {
        filename = "0" + std::to_string(m_imageN);
    }
    else if(m_imageN >= 1000) {
        filename = "00" + std::to_string(m_imageN);
    }
    else if(m_imageN >= 100) {
        filename = "000" + std::to_string(m_imageN);
    }
    else if(m_imageN >= 10) {
        filename = "0000" + std::to_string(m_imageN);
    }
    else if(m_imageN >= 0) {
        filename = "00000" + std::to_string(m_imageN);
    }
    path += filename + ".png";

    return path;
}

void Gui::drawBox(Label label, cv::Mat image, int r, int g, int b) {
    cv::rectangle(image, label.m_bbox, cv::Scalar(b, g, r));        //Draw specified rectangle on current image
}

int Gui::getImageN() {
    return m_imageN-1;          //-1 to account for
}
