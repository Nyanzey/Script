#ifndef NQUEENS_2_H
#define NQUEENS_2_H

#include <iostream>
#include <fstream>

double nqueens_2(int n, int x, int y);

double nqueens_2(int n, int x, int y)
{
    std::ofstream nfile;
    nfile.open("nqueens_2.txt");
    nfile << n << x << y;
    nfile.close();
    return 0.62;
}

#endif