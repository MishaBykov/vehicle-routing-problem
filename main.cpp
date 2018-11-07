#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "broot-force/Solve.h"
#include "k-means/K_cluster.h"
#include "k-means/Cluster.h"

int main() {
    setlocale(LC_ALL, "rus");

//    Solve solve("/home/misha/CLionProjects/vehicle-routing-problem/broot-force/test_full.txt");
//    solve.solve(0, 0, 0);
//    auto path = solve.getBestWay();
//    auto cost = solve.getBestCost();
//    std::cout << cost << std::endl;
//    for (double & i : path) {
//        std::cout << i << ' ';
//    }

    std::vector<Point> points = Point::read_points(
            R"(C:\Users\Misha\CLionProjects\vehicle-routing-problem\Taxicab_100.txt)");

    KCluster kCluster(points, 5);
    kCluster.main();
    for(int i = 0; i < kCluster.size(); i++)
        std::cout << kCluster.getCluster(static_cast<unsigned int>(i)).Size() << ' ';
    std::cout << std::endl;
    std::vector<Solve> solves;
    solves.reserve(kCluster.size());
    std::cout << "end clusters" << std::endl;
    for ( int i = 0; i < kCluster.size(); i++ ){
        solves.emplace_back(kCluster.getCluster(static_cast<unsigned int>(i)).getPoints());
        solves.back().solve(0, 0, 0);
        std::cout << "end solve" << i << std::endl;
    }

    for (auto &solve : solves) {
        std::cout << solve.getBestCost() << std::endl;
        for( int j = 0; j < solve.getBestWay().size(); j++) {
            std::cout << solve.getBestWay()[j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}