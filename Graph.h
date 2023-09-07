#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
    public:
        Graph(){};
        Graph(int numVertices);

        void addEdge(int source, int destination, int weight);
        void printWeights();
        void printAdjacencyList();
        
        int numVertices;
        std::vector<std::vector<int>> weights;
        std::vector<std::vector<int>> adj;
};

#endif // GRAPH_H