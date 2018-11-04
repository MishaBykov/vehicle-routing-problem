#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Solve.h"


int main() {
    setlocale(LC_ALL, "rus");
    Solve solve("test_full.txt");
    solve.solve(0, 0, 0);
    auto path = solve.getBestWay();
    auto cost = solve.getBestCost();
    std::cout << cost << std::endl;
    for (int i : path) {
        std::cout << i + 1 << ' ';
    }

    return 0;
}