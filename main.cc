#include <fstream>
#include "puzzle/puzzle_5.h"
int main() {
    std::ofstream out("out");
    auto time = puzzle_5();
    out << time;
}