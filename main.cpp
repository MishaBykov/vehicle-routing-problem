#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "broot-force/Solve.h"
#include "k-means/K_cluster.h"
#include "k-means/Cluster.h"

int main() {
    setlocale(LC_ALL, "rus");
//    Solve solve("../test_full.txt");
//    solve.solve(0, 0, 0);
//    auto path = solve.getBestWay();
//    auto cost = solve.getBestCost();
//    std::cout << cost << std::endl;
//    for (int i : path) {
//        std::cout << i + 1 << ' ';
//    }

    std::vector<Point> points = Point::read_points("/home/misha/CLionProjects/vehicle-routing-problem/broot-force/test.txt");

    Solve solve(points);

    return 0;
}