#include <iostream>
#include "../include/menu.hpp"

void Menu::setN() //keine Parameter, da die Werte direkt eingelesen werden in der Funktion
{
    int x;
    while(true) {
        std::cout << "How many rounds would you like to play? \n";
        std::cin >> x; //directly read in from the console
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout<<"Invalid expression, please enter a number\n";
        }
        else {
            std::cin.ignore(1000,'\n');
            Menu::n = x;
            break;
        }
    }
}

int Menu::getN()
{
    return n;
}

void Menu::setSequence()
{
    std::cout<<"Which sequence would you like to play?\n";
    std::string y;
    std::cin>>y;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout<<"Invalid expression, please enter a number\n";
    }
    else {
        std::cin.ignore(1000, '\n');

        sequence = y;
    }
}
std::string Menu::getSequence()
{
    return sequence;
}

void Menu::setName()
{
    std::cout<<"Please enter your name: \n";
    std::string m_name;
    std::cin>>m_name;
    name = m_name;
}

std::string Menu::getName()
{
    return name;
}