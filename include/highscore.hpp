#include <iostream>
#include <fstream>
#ifndef HIGHSCORE_HPP_INCLUDED
#define HIGHSCORE_HPP_INCLUDED

class Highscore
{
    public:
    Highscore();
    ~Highscore();
    double getHighscore();
    void setHighscore(double value);

    private:
    double highscore;
    bool deleteContent();

};

#endif //HIGHSCORE_HPP_INCLUDED