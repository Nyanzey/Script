#ifndef NQUEENS_5_H
#define NQUEENS_5_H

#include <iostream>
#include <fstream>

double nqueens_5(int n, int x, int y);

double nqueens_5(int n, int x, int y)
{
    std::ofstream nfile;
    nfile.open("nqueens_5.txt");
    nfile << n << x << y;
    nfile.close();
    return 25;
}

#endif