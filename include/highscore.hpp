#include <iostream>
#include <fstream>
#ifndef HIGHSCORE_CPP_INCLUDED
#define HIGHSCORE_CPP_INCLUDED

class Highscore
{
    public:
    double getHighscore();
    void setHighscore(double x);

    private:
    double highscore;

};

#endif //HIGHSCORE_CPP_INCLUDED