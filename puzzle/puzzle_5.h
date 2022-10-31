#ifndef PUZZLE_5_H
#define PUZZLE_5_H

#include <iostream>
#include <fstream>

double puzzle_5();

double puzzle_5()
{
    std::ofstream nfile;
    nfile.open("puzzle_5.txt");
    nfile.close();
    return 15;
}

#endif