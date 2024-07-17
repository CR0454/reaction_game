#include <iostream>
#include "../include/menu.hpp"
#include <regex>
#include <limits>

Menu::Menu(){
};
Menu::~Menu(){
};

void Menu::setRounds() //no input parameters -> read in from the console
{
    int rounds;
    while(true) {
        std::cout << "How many rounds would you like to play? \n";
        std::cin >> rounds;
        if(std::cin.fail()){ //if the user does not enter an integer, he is reasked until the input is an integer
            std::cin.clear(); //deletes error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //ignores unnecessary inputs
            std::cout<<"Invalid expression, please enter a number\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            Menu::m_rounds = rounds;
            break; // stops reasking the user when input is correct
        }
    }
}

int Menu::getRounds()
{
    return m_rounds;
}

void Menu::setSequence()
{
    std::regex pattern("^00([0-1][0-9]|20)$"); // all numbers between 0000 and 0020 (only in this format)
    std::cout<<"Which sequence would you like to play? (Enter a number between 0000 and 0020)\n";
    std::string sequence;
    while(true){
        std::cin>>sequence;
        if(std::regex_match(sequence, pattern)){ //the user has to enter the number by following the pattern
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            m_sequence = sequence;
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Invalid expression, please enter a number between 0000 and 0020 (in the same format)\n";
        }
    }
}

std::string Menu::getSequence()
{
    return m_sequence;
}

void Menu::setName()
{
    std::cout<<"Please enter your name: \n";
    std::cin>>Menu::m_name;
}

std::string Menu::getName()
{
    return m_name;
}

void Menu::setMode()
{
    int gamemode;
    std::cout << "Select your Game Mode: \n";
    std::cout << "Mode 1 - Direct Click Reaction (click on the appearing box as fast as possible) \n";
    std::cout << "Mode 2 - Color Change Reaction (click on the box whose color changes as fast as possible) \n";
    while(true) {
        std::cin >> gamemode;
        if(std::cin.fail() || !(gamemode ==1 || gamemode == 2)){ //reasks user until the conditions are fullfilled
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"Invalid expression, please enter 1 or 2\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            m_gamemode = gamemode;
            break;
        }
    }
}

int Menu::getMode()
{
    return m_gamemode;
}