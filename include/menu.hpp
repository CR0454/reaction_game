#include <iostream>
#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

class Menu
{
    public:
    Menu() {}
    ~Menu() {}
    void setRounds();
    int getRounds();
    void setSequence();
    std::string getSequence();
    void setName();
    std::string getName();
    void setMode();
    int getMode();

    private:
    std::string m_name;
    int m_rounds;
    std::string m_sequence;
    int m_gamemode;

};

#endif //MENU_HPP_INCLUDED