#include "Grafo.h"
#include <stdexcept>

template<typename T>
Grafo<T>::Grafo() {
}

template<typename T>
Grafo<T>::~Grafo(){
}

template<typename T>
void Grafo<T>::DFS() {
}

template<typename T>
void Grafo<T>::BFS() {
}

template<typename T>
void Grafo<T>::plano() {
}

template<typename T>
void Grafo<T>::agregarNodo(Nodo<T> nodo) {
    vertices.push_back(nodo);
    for (auto& row : edges) {
        row.push_back(0);
    }
    edges.push_back(std::vector<int>(vertices.size(), 0));
}

template<typename T>
void Grafo<T>::eliminarNodo(int id) {
}

template<typename T>
void Grafo<T>::addEdge(int origen, int destino) {
    if (origen < edges.size() && destino < edges.size()) {
        edges[origen][destino] = 1;
    }
}

template<typename T>
Nodo<T>* Grafo<T>::getNodo(int id) {
    for (auto& nodo : vertices) {
        if (nodo.id == id) return &nodo;
    }
    return nullptr;
}


template<typename T>
std::vector<std::pair<int, int>> Grafo<T>::convertPairs() {
    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i < edges.size(); ++i) {
        for (size_t j = 0; j < edges[i].size(); ++j) {
            if (edges[i][j] != 0) {
                pairs.push_back({i, j});
            }
        }
    }
    return pairs;
}
