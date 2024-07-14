//
// Created by VZWK5HR on 02.07.2024.
//

#include <opencv2/opencv.hpp>
#include "../include/gui.hpp"
#include <fstream>

void Gui::createWindow(std::string winName) {
    cv::namedWindow(winName, 1);        //Create a window with the input name
}

void Gui::pushToTop(std::string winName) {
    cv::setWindowProperty(winName, cv::WND_PROP_TOPMOST, 1);        //Set window to "topmost" to appear above all other windows
    cv::setWindowProperty(winName, cv::WND_PROP_TOPMOST, 0);        //Deactivate "topmost" to be able to open other windows above game
}

void Gui::refreshWindow(std::string winName, cv::Mat img) {
    cv::imshow(winName, img);               //Display image with all additionally drawn boxes in window
    cv::waitKey(1);
}

cv::Mat Gui::nextImage() {
    m_imageN++;         //Current image in sequence increased by 1 to get the next image
    cv::Mat image = cv::imread(getPath());      //Load the image

    if (image.empty()) {                                    //Check if image was loaded correctly
        std::cerr << "Error: Could not open or find the image!" << std::endl;
    }

    return image;
}

std::string const Gui::getPath() {
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
    cv::rectangle(image, label.m_bbox, cv::Scalar(b, g, r), 2);        //Draw specified rectangle on current image
}

int Gui::getImageN() {
    return m_imageN;
}
