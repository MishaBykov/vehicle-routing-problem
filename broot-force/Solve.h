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
#include "../core/Point.h"

class Solve {

    std::vector<std::vector<double> > a;
    std::vector<std::vector<int> > b;
    std::vector<double> way, best_way;
    std::vector<bool> n_new;
    double best_cost;
    unsigned long n;

    std::vector<std::vector<int> > getBFromA();
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
        std::getline(f_in, buf);
        std::stringstream ss(buf);
        while (!ss.eof()) {
            a.back().emplace_back();
            ss >> a.back().back();
        }
    }
    getBFromA();
    n = a.size();
    way.resize(n);
    best_way.resize(n);
    n_new.resize(n, true);
    best_cost = 10000000;
    f_in.close();
}

Solve::Solve(const std::vector<Point> &points) {
    double max_cost = 0;
    a.resize(points.size());
    for( auto &i : a ) {
        i.resize(points.size(), 0);
    }
    for( int i = 0; i < points.size(); i++ ) {
        for( int j = i - 1; j > -1; j-- ) {
            a[i][j] = Point::distance(points[i], points[j]);
            a[j][i] = Point::distance(points[i], points[j]);
            max_cost += a[i][j];
        }
    }
    for(int i = 0; i < a.size(); i++) {
        a[i][i] = max_cost + 1;
    }
    getBFromA();
    n = a.size();
    way.resize(n);
    best_way.resize(n);
    n_new.resize(n, true);
    best_cost = 10000000;
}

double Solve::getBestCost() {
    return best_cost;
}

std::vector<std::vector<int> > Solve::getBFromA() {
    std::vector< std::pair<int, double> > ind_cost(a.size());
    for (auto &i : a) {
        for(int j = 0; j < a.size(); j++) {
            ind_cost[j].first = j;
            ind_cost[j].second = i[j];
        }
        std::sort(ind_cost.begin(), ind_cost.end(), compare );
        b.emplace_back();
        for (auto &j : ind_cost) {
            b.back().emplace_back(j.first);
        }
    }
    return std::vector<std::vector<int>>();
}

#endif //VEHICLE_ROUTING_PROBLEM_SOLVE_H
