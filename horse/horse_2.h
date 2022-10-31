#ifndef HORSE_2_H
#define HORSE_2_H

#include <iostream>
#include <fstream>

double horse_2(int n, int x, int y);

double horse_2(int n, int x, int y)
{
    std::ofstream nfile;
    nfile.open("horse_2.txt");
    nfile << n << x << y;
    nfile.close();
    return 2.8;
}

#endif