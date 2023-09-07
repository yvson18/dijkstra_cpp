#include <iostream>
#include <vector>

#include "Dijkstra.h"
#include "Graph.h"

int main() {

    // inicialização do grafo    
    // Graph graph(5);

    // graph.addEdge(0, 1, 5);
    // graph.addEdge(0, 2, 2);
    // graph.addEdge(0, 3, 1);

    // graph.addEdge(1, 0, 5);
    // graph.addEdge(1, 4, 3);
    // graph.addEdge(2, 0, 2);
    // graph.addEdge(2, 4, 8);
    // graph.addEdge(3, 0, 1);
    // graph.addEdge(3, 4, 9);

    // graph.addEdge(4, 1, 3);
    // graph.addEdge(4, 2, 8);
    // graph.addEdge(4, 3, 9);

    Graph graph(4);

    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 3, 3);

    graph.addEdge(3, 2, 3);
    graph.addEdge(2, 1, 2);
    graph.addEdge(1, 0, 5);

    //solver Dijkstra
    Dijkstra solver(graph);

    std::vector<int> path = solver.solve(1,3);

    // printar caminho
    std::cout << "\nCaminho: " << std::endl;
    for(int i = 0; i < path.size() - 1; i++){
        std::cout << path[i] << " -> ";
    }
    std::cout << path[path.size() - 1] << std::endl;

    return 0;
}