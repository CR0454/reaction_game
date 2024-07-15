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

    if(menu.getMode() == 1){
        gamemode = new Gamemode_1(menu.getRounds(), menu.getSequence());
        highscore.setHighscore(gamemode -> run());
    }
    else{
        gamemode = new Gamemode_2(menu.getRounds(), menu.getSequence());
        highscore.setHighscore(gamemode -> run());
    }
}