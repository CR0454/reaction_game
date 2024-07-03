//
// Created by VZWK5HR on 02.07.2024.
//

#include <opencv2/opencv.hpp>
#include "../include/gui.hpp"
#include <fstream>

int Gui::refreshImage() {                                       //int only for exception handling
    image = cv::imread(getPath());

    if (image.empty()) {                                    //Check if image was loaded correctly
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return -1;
    }

    m_imageN++;                     //"Current" image in sequence increased by 1 in preparation for next function call
    cv::imshow("Reaction Game", image);
    cv::waitKey(0);

    return 0;
}

std::string Gui::getPath() {
    std::string path = "../training/image_02/";     //Default folder layout for every image sequence
    path += m_sequence + "/";                       //Sequence specific folder name

    std::string filename = "";                      //Filename conversion int to string with necessary zeros
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

int Gui::loadLabels() {

    std::string path = "../label_02/" + m_sequence + ".txt";        //path to sequence label file
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
    return 0;

}

std::vector<Label> Gui::getFrameLabels() {
    std::vector<Label> frameLabels;
    for(Label label: m_labels) {
        if(label.m_frame == m_imageN) {         //Check if label is tagged for current frame in sequence -> add to list
            frameLabels.emplace_back(label);
        }
        else if(label.m_frame > m_imageN) {     //labels sorted by frame -> avoid unnecessary checks
            break;
        }
    }
    return frameLabels;
}

void Gui::drawBox(Label label, int r, int g, int b) {
    cv::rectangle(image, label.m_bbox, cv::Scalar(b, g, r));        //Draw specified rectangle on current image
    cv::imshow("Reaction Game", image);         //Display image with new Label
    cv::waitKey(0);
}
