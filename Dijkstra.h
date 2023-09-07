#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include "Graph.h"

class Dijkstra {
    public:
        Graph graph;
        
        Dijkstra(Graph graph);
        std::vector<int> solve(int source, int destiny);

};

#endif