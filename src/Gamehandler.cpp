//
// Created by VZWK5HR on 11.07.2024.
//

#include "../include/Gamehandler.hpp"

void Gamehandler::start() {
    Menu menu;
    Highscore highscore;
    Gamemode* gamemode;

    menu.setName();
    menu.setRounds();
    menu.setSequence();
    menu.setMode();

    std::cout << "Current highscore is " << highscore.getHighscore() << std::endl;

    std::vector<double> scores;
    if(menu.getMode() == 1){
        gamemode = new Gamemode_1(menu.getRounds(), menu.getSequence());
        scores = gamemode -> run();
    }
    else{
        gamemode = new Gamemode_2(menu.getRounds(), menu.getSequence());
        scores = gamemode -> run();
    }

    double avgScore = showResults(scores, &menu);

    highscore.setHighscore(avgScore);
}

double Gamehandler::showResults(std::vector<double> scores, Menu *menu) {
    std::vector<double> sortScores = scores;
    std::sort(sortScores.begin(), sortScores.end());
    std::cout << "\nPlayer: " << menu -> getName() << std::endl;
    for(int i = 0; i < 3 && i < scores.size(); i++) {
        std::cout << i+1 << ". Frame " << std::find(scores.begin(), scores.end(), sortScores.at(i)) - scores.begin() <<
            ": " << sortScores.at(i) << " s\n";
    }
    double avg = std::accumulate(scores.begin(), scores.end(), 0.0);
    avg /= scores.size();
    std::cout << "Avg: " << avg << " s\n\n";

    return avg;
}