#ifndef PUZZLE_4_H
#define PUZZLE_4_H

#include <iostream>
#include <fstream>

double puzzle_4();

double puzzle_4()
{
    std::ofstream nfile;
    nfile.open("puzzle_4.txt");
    nfile.close();
    return 14;
}

#endif