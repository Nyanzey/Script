#ifndef NQUEENS_1_H
#define NQUEENS_1_H

#include <iostream>
#include <fstream>

double nqueens_1(int n, int x, int y);

double nqueens_1(int n, int x, int y)
{
    std::ofstream nfile;
    nfile.open("nqueens_1.txt");
    nfile << n << x << y;
    nfile.close();
    return 2.1;
}

#endif