cmake_minimum_required(VERSION 3.12)
project(vehicle-routing-problem)

set(CMAKE_CXX_STANDARD 14)


add_executable(
        vehicle-routing-problem
        main.cpp
        broot-force/Solve.h k-means/cluster.cpp k-means/cluster.h k-means/k-means.cpp k-means/k-means.h)