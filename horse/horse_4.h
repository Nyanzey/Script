#ifndef HORSE_4_H
#define HORSE_4_H

#include <iostream>
#include <fstream>

double horse_4(int n, int x, int y);

double horse_4(int n, int x, int y)
{
    std::ofstream nfile;
    nfile.open("horse_4.txt");
    nfile << n << x << y;
    nfile.close();
    return 5.9;
}

#endif