//
// Created by misha on 04.11.18.
//

#ifndef VEHICLE_ROUTING_PROBLEM_SOLVE_H
#define VEHICLE_ROUTING_PROBLEM_SOLVE_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../core/point.h"

class Solve {

    std::vector<std::vector<double> > a;
    std::vector<std::vector<int> > b;
    std::vector<double> way, best_way;
    std::vector<bool> n_new;
    double best_cost;
    unsigned long n;

    static bool compare(std::pair<double, double> a, std::pair<double, double> b) {
        return a.second < b.second;
    }

public:

    explicit Solve(const std::string &file_a);
    explicit Solve(const std::vector<Point> &points);

    void solve(int v, int count, double cost);

    std::vector<double> getBestWay();
    double getBestCost();
};

void Solve::solve(int v, int count, double cost) {
    if (cost > best_cost)
        return;
    if (count == n - 1) {
        cost = cost + a[v][0];
        way[n - 1] = v;

        if (cost < best_cost) {
            best_cost = cost;
            best_way = way;
        }
        return;
    }
    n_new[v] = false;
    way[count] = v;
    for (int i = 0; i < n; i++) {
        if (n_new[b[v][i]])
            solve(b[v][i], count + 1, cost + a[v][b[v][i]]);
    }
    n_new[v] = true;
}

std::vector<double> Solve::getBestWay() {
    return best_way;
}

Solve::Solve(const std::string &file_a) {
    std::ifstream f_in;
    f_in.open(file_a);
    std::string buf;
    while (!f_in.eof()) {
        a.emplace_back();
        b.emplace_back();
        std::getline(f_in, buf);
        std::stringstream ss(buf);
        std::vector< std::pair<int, int> > ind_cost;
        int i = 0;
        while (!ss.eof()) {
            ind_cost.emplace_back();
            ind_cost.back().first = i;
            ss >> ind_cost.back().second;
            i++;
        }
        std::sort(ind_cost.begin(), ind_cost.end(), compare );
        a.back().resize(ind_cost.size());
        for (auto &cost : ind_cost) {
            a.back()[cost.first] = cost.second;
            b.back().push_back(cost.first);
        }

    }
    n = a.size();
    way.resize(n);
    best_way.resize(n);
    n_new.resize(n, true);
    best_cost = 10000000;
    f_in.close();
}

Solve::Solve(const std::vector<Point> &points) {
    int max_cost = 0;
    a.resize(points.size());
    for( auto &i : a ) {
        i.resize(points.size(), 0);
    }
    for( int i = 1; i < points.size(); i++ ) {
        for( int j = i - 1; j > 0; j-- ) {
            a[i][j] = Point::distance(points[i], points[j]);
        }
    }
}

double Solve::getBestCost() {
    return best_cost;
}

#endif //VEHICLE_ROUTING_PROBLEM_SOLVE_H
