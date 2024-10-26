#include "Grafo.h"
#include "Grafo.cpp"
#include "Nodo.h"
#include "Nodo.cpp"
#include <iostream>


int main() {
    Grafo<int> grafo;

    // Agregar nodos
    for (int i = 0; i < 6; i++) {
        grafo.agregarNodo(Nodo<int>(i, i));
    }

    // Agregar aristas en matriz de adyacencia
    grafo.addEdge(0, 1);
    grafo.addEdge(0, 2);
    grafo.addEdge(1, 3);
    grafo.addEdge(1, 4);
    grafo.addEdge(2, 4);
    grafo.addEdge(3, 5);
    grafo.addEdge(4, 5);

    std::cout << "----- Representacion con Matriz de Adyacencia -----\n";
    std::cout << "\nDFS desde nodo 0:\n";
    grafo.DFS_Matriz(0);

    std::cout << "\nBFS desde nodo 0:\n";
    grafo.BFS_Matriz(0);

    std::cout << "\nPlano del grafo (Matriz de Adyacencia):\n";
    grafo.plano_Matriz();

    // Convertir de matriz a lista de adyacencia
    grafo.convertirALista();

    std::cout << "\n----- Representacion con Lista de Adyacencia -----\n";
    std::cout << "\nDFS desde nodo 0:\n";
    grafo.DFS_Lista(0);

    std::cout << "\nBFS desde nodo 0:\n";
    grafo.BFS_Lista(0);

    std::cout << "\nPlano del grafo (Lista de Adyacencia):\n";
    grafo.plano_Lista();


    return 0;
}
