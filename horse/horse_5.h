#ifndef HORSE_5_H
#define HORSE_5_H

#include <iostream>
#include <fstream>

double horse_5(int n, int x, int y);

double horse_5(int n, int x, int y)
{
    std::ofstream nfile;
    nfile.open("horse_5.txt");
    nfile << n << x << y;
    nfile.close();
    return 6.5;
}

#endif