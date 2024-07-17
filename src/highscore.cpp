#include "../include/highscore.hpp"
#include <fstream>
#include <string>
#include <vector>

Highscore::Highscore(){
};
Highscore::~Highscore(){
};

double Highscore::getHighscore()
{
    double highscore;
    std::ifstream fread("../highscore.txt"); //reads file
    std::string output;
    if(fread) {
        while (std::getline(fread, output)) {
            highscore = std::stod(output); // line is read in as a string and afterwards converted to a double with stod
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