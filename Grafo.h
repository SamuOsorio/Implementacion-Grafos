#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>
#include "Nodo.h"

template<typename T>
class Grafo{
private:
    std::vector<std::vector<int>> edges;
    std::list<Nodo<T>> vertices;

public:
    Grafo();
    ~Grafo();
    void DFS();
    void BFS();
    void plano();
    void agregarNodo(Nodo<T> nodo);
    void eliminarNodo(int id);
    void addEdge(int origen, int destino);
    Nodo<T>* getNodo(int id);
    std::vector<std::pair<int, int>> convertPairs();
};

#endif
