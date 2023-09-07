#include "Dijkstra.h"
#include "Graph.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>  // Para std::this_thread::sleep_for
#include <chrono>  // Para std::chrono::seconds

#define INF int(1e9)

struct Node {
    int idx;
    int chave;
    
    bool operator<(const Node& other) const {
        return chave < other.chave;
    }
};

Dijkstra::Dijkstra(Graph graph){
    this->graph = graph;

    // printar weights do grafo

    // std::cout << "\nGrafo: " << std::endl;
    // for(int i = 0; i < this->graph.numVertices; i++){
    //     for(int j = 0; j < this->graph.numVertices; j++){
    //         std::cout << this->graph.weights[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // // printar lista de adjacencia do grafo
    // std::cout << "\nLista de Adjacencia: " << std::endl;

    // for(int i = 0; i < this->graph.numVertices; i++){
    //     std::cout << i << " -> ";
    //     for(int j = 0; j < this->graph.adj[i].size(); j++){
    //         std::cout << this->graph.adj[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
}

std::vector<int> Dijkstra::solve(int source, int destiny){
    
    // guarda custos e indexs do pai
    int chaves[this->graph.numVertices];
    int pai[this->graph.numVertices];

    // Setup
    for(int u = 0; u < this->graph.numVertices; u++){
        chaves[u] = INF;
        pai[u] = -1; // assing like Null
    }

    chaves[source] = 0;

    bool visitado[this->graph.numVertices];
    
    for (int i = 0; i < this->graph.numVertices; i++){
        visitado[i] = false;
    }

    std::vector <Node> fila_de_prioridade;

    // inicializa a fila de prioridade
    for (int i = 0; i < this->graph.numVertices; i++){
        Node node;
        node.idx = i;
        node.chave = chaves[i];
        fila_de_prioridade.push_back(node);
    }
    
    //ordenar a fila de prioridade
    std::sort(fila_de_prioridade.begin(), fila_de_prioridade.end());

    while(!fila_de_prioridade.empty()){
        int u = fila_de_prioridade[0].idx; // pega idx de quem tá no topo
        
        for(int i = 0; i < this->graph.adj[u].size() ; i++){
            int v = this->graph.adj[u][i]; // v: idx do no filho
        
            if((!visitado[v]) && ((this->graph.weights[u][v] + chaves[u]) < chaves[v])){
                // update pai e custos
                pai[v] = u;
                chaves[v] = this->graph.weights[u][v] + chaves[u];

                //update fila de prioridade
                for(int i = 0; i < fila_de_prioridade.size(); i++){
                    if(fila_de_prioridade[i].idx == v)
                        fila_de_prioridade[i].chave = chaves[v];
                }
            }           
        }
        
        fila_de_prioridade.erase(fila_de_prioridade.begin());
        
        //ordena fila de prioridade
        std::sort(fila_de_prioridade.begin(), fila_de_prioridade.end());
        visitado[u] = true;
    }

    //print uma tabela dizendo nó atual, pai, chave
    std::cout << "\nTabela de Caminhos:" << std::endl;
    std::cout << "no atual | pai | custos" << std::endl;
    std::cout <<""<< std::endl;

    for(int i = 0; i < this->graph.numVertices; i++){
        std::cout << i << " | " << pai[i] << " | " << chaves[i] << std::endl;
    }

    std::vector<int> path;

    for(int no = destiny; no > -1; no = pai[no]){
        if(pai[no]> -1){
            path.push_back(pai[no]);
        }
    }

    std::reverse(path.begin(), path.end());
    path.push_back(destiny);

    return path;
    
    // // printar caminho
    // std::cout << "\nCaminho: " << std::endl;
    // for(int i = 0; i < path.size() - 1; i++){
    //     std::cout << path[i] << " -> ";
    // }
    // std::cout << path[path.size() - 1] << std::endl;
}