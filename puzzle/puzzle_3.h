#ifndef PUZZLE_3_H
#define PUZZLE_3_H

#include <iostream>
#include <fstream>

double puzzle_3();

double puzzle_3()
{
    std::ofstream nfile;
    nfile.open("puzzle_3.txt");
    nfile.close();
    return 13;
}

#endif