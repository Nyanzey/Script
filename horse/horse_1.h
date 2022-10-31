#ifndef HORSE_1_H
#define HORSE_1_H

#include <iostream>
#include <fstream>

double horse_1(int n, int x, int y);

double horse_1(int n, int x, int y)
{
    std::ofstream nfile;
    nfile.open("horse_1.txt");
    nfile << n << x << y;
    nfile.close();
    return 3.5;
}

#endif