cmake_minimum_required(VERSION 3.12)
project(vehicle-routing-problem)

set(CMAKE_CXX_STANDARD 14)


add_executable(
        vehicle-routing-problem
        main.cpp
        broot-force/Solve.h k-means/Cluster.cpp k-means/Cluster.h k-means/K_cluster.cpp k-means/K_cluster.h core/Point.cpp core/Point.h)