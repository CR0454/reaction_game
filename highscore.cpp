#include "highscore.hpp"

double Highscore::getHighscore()
{
    return highscore;
}

void Highscore::setHighscore(double x)
{
    if(x < highscore) //Neuer Highscore sobald man weniger Zeit benötigt
    {
    highscore = x;
    }
}