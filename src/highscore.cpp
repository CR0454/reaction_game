#include "../include/highscore.hpp"
#include <fstream>
#include <string>
#include <vector>
double Highscore::getHighscore()
{
    double highscore;
    std::ifstream fread1("../highscore.txt"); //reads file
    std::string output1;
    while (std::getline(fread1, output1)) {
        highscore = std::stod(output1); //converts the output string to a double
    }
    fread1.close();
    return highscore;
}

void Highscore::setHighscore(double x) {
    std::ifstream fread("../highscore.txt");
    std::string output;
    double score;
    while (std::getline(fread, output)) {
        score = std::stod(output); // Zeile wird als string eingelesen und dann zu double konvertiert mit stod
    }
    fread.close();
        if (x < score) {
            std::ofstream highscorefile; //Ausgabestreamobjekt definieren

            highscorefile.open("../highscore.txt", std::ofstream::ate);
            highscorefile << x;
            highscorefile.close();
        } else {
            std::cout << "Did not reach a new Highscore";
        }
    }
