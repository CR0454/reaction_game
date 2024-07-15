#include <iostream>
#include <fstream>
#ifndef HIGHSCORE_HPP_INCLUDED
#define HIGHSCORE_HPP_INCLUDED

class Highscore
{
    public:
    double getHighscore();
    void setHighscore(double value);

    private:
    double highscore;

};

#endif //HIGHSCORE_HPP_INCLUDED