#ifndef GRAFO_H
#define GRAFO_H

#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "Nodo.h"

template<typename T>

class Grafo{
private:
    std::vector<std::vector<int>> edges;
    std::list<Nodo<T>> vertices;
    std::unordered_map<int, std::vector<int>> adjList;

public:
    Grafo();
    ~Grafo();
    void DFS_Matriz(int idInicio);
    void BFS_Matriz(int idInicio);
    void plano_Matriz();
    void DFS_Lista(int idInicio);
    void BFS_Lista(int idInicio);
    void plano_Lista();
    void agregarNodo(Nodo<T> nodo);
    void eliminarNodo(int id);
    void addEdge(int origen, int destino);
    Nodo<T>* getNodo(int id);
    void convertirALista();
    void convertirAMatriz();
    std::vector<std::pair<int, int>> convertPairs();
};

#endif
