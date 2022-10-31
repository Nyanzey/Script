#ifndef HORSE_3_H
#define HORSE_3_H

#include <iostream>
#include <vector>
#include <utility>
#include <ctime>
#include <fstream>
#include <math.h>

double horse_3(int n, int x, int y);
std::vector<std::vector<int>> genBoard(int n);
std::vector<std::pair<int, int>> validmoves(std::vector<std::vector<int>> &marked, int x, int y);
void horseutil(std::vector<std::vector<int>> &marked, int x, int y, int &count, bool &found);
void printout(std::vector<std::vector<int>> &marked);
std::pair<int, int> choice(std::vector<std::pair<int, int>> &options, std::vector<std::vector<int>> &marked);
std::pair<int, int> tiebreak(std::vector<std::vector<int>> &marked, std::vector<std::pair<int, int>> &options, std::vector<int> idx);
double euclid(int x0, int y0, int x1, int y1);

double horse_3(int n, int x, int y)
{
    std::vector<std::vector<int>> marked = genBoard(n);
    int count = 1;
    bool found = false;
    auto t0 = std::clock();
    horseutil(marked, x, y, count, found);
    auto t1 = std::clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    return time;
}

std::vector<std::vector<int>> genBoard(int n)
{
    std::vector<std::vector<int>> res;
    std::vector<int> sup;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sup.push_back(0);
        }
        res.push_back(sup);
    }
    return res;
}

std::vector<std::pair<int, int>> validmoves(std::vector<std::vector<int>> &marked, int x, int y)
{
    std::vector<int> sup = {1, 2, 2, 1};
    std::vector<std::pair<int, int>> res;
    int idx = 0;
    for (int i = -2; i <= 2; i++)
    {
        if (i == 0)
        {
            continue;
        }
        if (x+i >= 0 && x+i < marked.size())
        {
            if(y+sup[idx] >= 0 && y+sup[idx] < marked.size())
            {
                if (marked[x+i][y+sup[idx]] == 0)
                {
                    std::pair<int, int> ins(x+i, y+sup[idx]);
                    res.push_back(ins);
                }
            }
            if (y-sup[idx] >= 0 && y-sup[idx] < marked.size())
            {
                if (marked[x+i][y-sup[idx]] == 0)
                {
                    std::pair<int, int> ins(x+i, y-sup[idx]);
                    res.push_back(ins);
                }
            }
        }
        idx++;
    }
    return res;
}

void horseutil(std::vector<std::vector<int>> &marked, int x, int y, int &count, bool &found)
{
    if (found) {return;}
    marked[x][y] = count;
    if (count == marked.size()*marked.size())
    {
        printout(marked);
        found = true;
        return;
    }
    std::vector<std::pair<int, int>> valid = validmoves(marked, x, y);
    count++;
    while (valid.size() > 0)
    {
        std::pair<int, int> nxt = choice(valid, marked);
        horseutil(marked, nxt.first, nxt.second, count, found);
    }
    marked[x][y] = 0;
    count--;
    return;
}

void printout(std::vector<std::vector<int>> &marked)
{
    std::ofstream output;
    output.open("horse_3.txt");
    for (int i = 0; i < marked.size(); i++)
    {
        for (int j = 0; j < marked.size(); j++)
        {
            output << marked[i][j] << "\t";
        }
        output << "\n";
    }
    output.close();
}

std::pair<int, int> choice(std::vector<std::pair<int, int>> &options, std::vector<std::vector<int>> &marked)
{
    int min = 8;
    int count = 0;
    std::vector<int> idx;
    std::pair<int, int> res;
    for (int i = 0; i < options.size(); i++)
    {
        if (validmoves(marked, options[i].first, options[i].second).size() <= min)
        {
            count++;
            idx.push_back(i);
            min = validmoves(marked, options[i].first, options[i].second).size();
        }
    }
    if (count == 1)
    {
        res = options[idx[0]];
        options.erase(options.begin()+idx[0]);
    }
    else
    {
        res = tiebreak(marked, options, idx);
    }
    return res;
}

std::pair<int, int> tiebreak(std::vector<std::vector<int>> &marked, std::vector<std::pair<int, int>> &options, std::vector<int> idx)
{
    int indx = idx[0];
    int x0 = marked.size()/2;
    int y0 = x0;
    int x1 = options[indx].first;
    int y1 = options[indx].second;
    std::pair<int, int> res = options[indx];

    double max = euclid(x0, y0, x1, y1);
    for (int i = 1; i < idx.size(); i++)
    {
        x1 = options[idx[i]].first;
        y1 = options[idx[i]].second;
        if (euclid(x0, y0, x1, y1) > max)
        {
            max = euclid(x0, y0, x1, y1);
            res = options[idx[i]];
            indx = idx[i];
        }
    }
    options.erase(options.begin()+indx);
    return res;
}

double euclid(int x0, int y0, int x1, int y1)
{
    double r = (x1-x0)*(x1-x0);
    double s = (y1-y0)*(y1-y0);
    return std::sqrt(r+s);
}


#endif