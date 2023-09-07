#include "Graph.h"
#include <iostream>

#define INF int(1e9)

Graph::Graph(int numVertices) {
    
    this->numVertices = numVertices;
    this->weights.assign(numVertices, std::vector<int>(numVertices, INF));
    this->adj.resize(numVertices);

}

void Graph::addEdge(int source, int destination, int weight) {
    adj[source].push_back(destination);
    weights[source][destination] = weight;
}

void Graph::printWeights() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << weights[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void Graph::printAdjacencyList() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Adjacência do vértice " << i << ": ";
        for (int j : adj[i]) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}