//
// Created by misha on 05.11.18.
//
#include <utility>
#include <memory>
#include "K_cluster.h"

KCluster::KCluster(std::vector< Point > points, const unsigned &k) : vector_points(std::move(points)) {
    vector_clusters.resize(k);
}

Cluster &KCluster::getCluster(unsigned i) { return vector_clusters.at(i); }

void KCluster::initialCenters() {
    unsigned long k = vector_clusters.size();
    int step = static_cast<int>(vector_points.size() / k);

    int i = 0;
    for (auto &cluster : vector_clusters) {
        cluster.Add(vector_points[i]);
        cluster.UpdateCenter();
        i += step;
    }
}

void KCluster::pointsInClusters(){
    for(auto &cluster : vector_clusters )
        cluster.Clear();
    for(auto point : vector_points) { // Запускаем цикл по всем пикселям множества
        Cluster* cluster_min = &vector_clusters[0];
        for (auto &cluster : vector_clusters) {
            if(Point::distance(cluster_min->GetCenter(), point) > Point::distance(cluster.GetCenter(), point))
                cluster_min = &cluster;
        }
        cluster_min->Add(point);
    }
}

void KCluster::main(){
    KCluster::initialCenters();
    unsigned long count_cluster = vector_clusters.size(), count_constant_mass = 0;
    while(count_cluster != count_constant_mass) {//Запускаем основной цикл
        count_constant_mass = 0;
        pointsInClusters();//Связываем точки с кластерами
        for(auto &cluster : vector_clusters)//Высчитываем новые координаты центроидов
            cluster.UpdateCenter();
        for (auto &cluster : vector_clusters) {//Проверяем не совпадают ли они с предыдущими цент-ми
            if (!cluster.IsUpdateCenter())
                count_constant_mass++;
        }
    }
}

unsigned long KCluster::size() {
    return vector_clusters.size();
}
