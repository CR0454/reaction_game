#include <iostream>
#include "menu.hpp"

void Menu::setN() //keine Parameter, da die Werte direkt eingelesen werden in der Funktion
{
    std::cout<<"Wie viele Runden moechten Sie spielen? \n";
    int x;
    std::cin>>x; //wird direkt von der Konsole eingelesen
    n = x;
}

int Menu::getN()
{
    return n;
}

void Menu::setSequence()
{
    std::cout<<"Welche Sequenz moechten Sie spielen?\n";
    int y;
    std::cin>>y;
    sequence = y;
}
std::string Menu::getSequence()
{
    return sequence;
}
void Menu::setName()
{
    std::cout<<"Bitte geben Sie Ihren Spielernamen an: \n";
    std::string m_name;
    std::cin>>m_name;
    name = m_name;
}
std::string Menu::getName()
{
    return name;
}