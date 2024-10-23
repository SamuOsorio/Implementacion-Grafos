#include "Grafo.h"
#include "Grafo.cpp"
#include "Nodo.h"
#include "Nodo.cpp"
#include <iostream>


int main() {
     // Crear un grafo de enteros
    Grafo<int> grafo;

    // Agregar nodos al grafo
    grafo.agregarNodo(Nodo<int>(0, 10));
    grafo.agregarNodo(Nodo<int>(1, 20));
    grafo.agregarNodo(Nodo<int>(2, 30));
    grafo.agregarNodo(Nodo<int>(3, 40));
    grafo.agregarNodo(Nodo<int>(4, 50));
    grafo.agregarNodo(Nodo<int>(5, 60));

    // Agregar aristas
    grafo.addEdge(0, 1);
    grafo.addEdge(0, 2);
    grafo.addEdge(1, 3);
    grafo.addEdge(1, 4);
    grafo.addEdge(2, 5);
    grafo.addEdge(3, 4);
    grafo.addEdge(4, 5);

    // Ejecutar DFS y BFS desde el nodo 0
    std::cout << "DFS comenzando desde el nodo 0:\n";
    grafo.DFS(0);
    std::cout << "\nBFS comenzando desde el nodo 0:\n";
    grafo.BFS(0);

    // Mostrar la representación en plano del grafo
    std::cout << "\nRepresentacion del grafo en plano:\n";
    grafo.plano();

    return 0;
}
