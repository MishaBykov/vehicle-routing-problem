//
// Created by misha on 05.11.18.
//

#ifndef VEHICLE_ROUTING_PROBLEM_K_CLUSTER_H
#define VEHICLE_ROUTING_PROBLEM_K_CLUSTER_H

#include <vector>
#include <cstdio>
#include <cstdlib>
#include "Cluster.h"

class KCluster {
    std::vector< Cluster > vector_clusters;
    std::vector< Point > vector_points;

public:
    explicit KCluster(std::vector< Point > points, const unsigned &k);

    void initialCenters();
    void pointsInClusters();
    unsigned long size();
    void main();
    Cluster& getCluster(unsigned i);//Доступ  к элементам вектора

};


#endif //VEHICLE_ROUTING_PROBLEM_K_CLUSTER_H
