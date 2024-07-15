#include <iostream>

enum class Sequence
{
spielhjdbhjev,
dbbdh
};

class Menu
{
    public:
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