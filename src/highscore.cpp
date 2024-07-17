#include "../include/highscore.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <limits>

Highscore::Highscore(){
};
Highscore::~Highscore(){
};

bool Highscore::deleteContent(){
    std::cout<<"The content of the file is invalid. \n If you want the content to be deleted enter 'yes' and if not 'no'.\n ";
    while(true) {
        std::string decision;
        std::cin>>decision;
        if (decision == "yes") {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::ofstream fdeleteContent("../highscore.txt", std::ios::trunc);
            return 1;

        } else {
            std::cin.clear(); //deletes error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //ignores unnecessary inputs
            std::cout << "Invalid expression. Please enter 'yes' or 'no'.\n";

        }
    }

}



double Highscore::getHighscore() {
    double highscore;
    std::ifstream fread("../highscore.txt"); //reads file
    std::string output;
    if (fread) {
        while (std::getline(fread, output)) {
            try {
                highscore = std::stod(output);
            }
            catch (const std::invalid_argument) {
                deleteContent();
                if (deleteContent() == 1) {
                    highscore = 0; // line is read in as a string and afterwards converted to a double with stod
                    break;
                }else {
                    break;
                }
            }
        }

    fread.close();
    return highscore;
    }
    else{
        std::ofstream fread("../highscore.txt"); //creates a file if it does not exist yet
        return 0;
    }
}

void Highscore::setHighscore(double value) {
    std::ifstream fread("../highscore.txt");
    std::string output;
    double score;
    if (fread) {
        while (std::getline(fread, output)) {
            score = std::stod(output);
        }
        fread.close();
        if (value < score || value == 0) {
            std::ofstream highscorefile; //defines output stream object
            highscorefile.open("../highscore.txt", std::ofstream::ate);
            highscorefile << value;
            highscorefile.close();
        }
        else {
            std::cout << "Did not reach a new Highscore";
        }
    }
    else {
        std::ofstream fread;
        fread.open("../highscore.txt", std::ofstream::ate);
        fread << value;
        fread.close();
        std::cout << "There are no highscores stored yet, you are the first person to play this game";
    }
}