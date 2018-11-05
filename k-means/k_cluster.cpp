//
// Created by misha on 05.11.18.
//
#include <utility>
#include <memory>
#include "k_cluster.h"

KCluster::KCluster(std::vector< Point > points, const unsigned &k) : vector_points(std::move(points)) {
    vector_clusters.resize(k);
}

Cluster &KCluster::getCluster(unsigned i) { return vector_clusters.at(i); }

void KCluster::initialCenters() {
    unsigned long k = vector_clusters.size();
    int step = static_cast<int>(vector_points.size() / k);
    int i = 0;

    for (auto cluster : vector_clusters) {
        cluster.Add(vector_points[k]);
        cluster.updateCenter();
        i += step;
    }
}

void KCluster::pointsInClusters(){
    for(Cluster cluster : vector_clusters )
        cluster.Clear();
    for(auto point : vector_points) { // Запускаем цикл по всем пикселям множества
        Cluster* cluster_min = &vector_clusters[0];
        for (auto cluster : vector_clusters) {
            if(Point::distance(cluster_min->getCenter(), point) > Point::distance(cluster.getCenter(), point))
                cluster_min = &cluster;
        }
        cluster_min->Add(point);
    }
}

void KCluster::updateClustersCenter() {
    for(auto cluster : vector_clusters)//Высчитываем новые координаты центроидов
        cluster.updateCenter();
}

void KCluster::main(){
    KCluster::initialCenters();
    unsigned long count_cluster = vector_clusters.size(), count_constant_mass = 0;
    while(count_cluster != count_constant_mass) {//Запускаем основной цикл
        count_constant_mass = 0;
        pointsInClusters();//Связываем точки с кластерами
        updateClustersCenter();
        for (auto cluster : vector_clusters) {//Проверяем не совпадают ли они с предыдущими цент-ми
            if (cluster.isUpadteCenter())
                count_constant_mass++;
        }
    }
}
