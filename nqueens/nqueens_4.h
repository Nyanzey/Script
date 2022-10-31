#ifndef NQUEENS_4_H
#define NQUEENS_4_H

#include <iostream>
#include <fstream>

double nqueens_4(int n, int x, int y);

double nqueens_4(int n, int x, int y)
{
    std::ofstream nfile;
    nfile.open("nqueens_4.txt");
    nfile << n << x << y;
    nfile.close();
    return 24;
}

#endif