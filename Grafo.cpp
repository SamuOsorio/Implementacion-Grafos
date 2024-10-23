#include "Grafo.h"
#include <iostream>
#include <stdexcept>

template<typename T>
Grafo<T>::Grafo()
{
}

template<typename T>
Grafo<T>::~Grafo()
{
}

template<typename T>
void Grafo<T>::DFS(int idInicio)
{
    std::vector<bool> visitado(vertices.size(), false);
    std::stack<int> stack;

    stack.push(idInicio);

    while (!stack.empty())
    {
        int idNodo = stack.top();
        stack.pop();

        if (!visitado[idNodo])
        {
            visitado[idNodo] = true;
            std::cout << "Visitando nodo " << idNodo << std::endl;

            // Agregamos los nodos adyacentes no visitados
            for (size_t i = 0; i < edges[idNodo].size(); ++i)
            {
                if (edges[idNodo][i] == 1 && !visitado[i])
                {
                    stack.push(i);
                }
            }
        }
    }
}

template<typename T>
void Grafo<T>::BFS(int idInicio)
{
    std::vector<bool> visitado(vertices.size(), false);  // Vector de nodos visitados
    std::queue<int> queue;

    visitado[idInicio] = true;
    queue.push(idInicio);

    while (!queue.empty())
    {
        int idNodo = queue.front();
        queue.pop();
        std::cout << "Visitando nodo " << idNodo << std::endl;

        // Agregamos los nodos adyacentes no visitados
        for (size_t i = 0; i < edges[idNodo].size(); ++i)
        {
            if (edges[idNodo][i] == 1 && !visitado[i])
            {
                visitado[i] = true;
                queue.push(i);
            }
        }
    }
}

template<typename T>
void Grafo<T>::plano()
{
    std::cout << "Representación del grafo en plano:\n";
    for (auto it = vertices.begin(); it != vertices.end(); ++it)
    {
        std::cout << "Nodo " << it->id << ": "; // Usar el iterador para acceder al nodo

        // Obtener el índice actual del nodo
        int index = std::distance(vertices.begin(), it);

        for (size_t j = 0; j < edges[index].size(); ++j)
        {
            if (edges[index][j] == 1)
            {
                // Usamos un nuevo iterador para acceder al nodo correspondiente
                auto adjIt = std::next(vertices.begin(), j);
                std::cout << " -> " << adjIt->id; // Imprime las aristas salientes
            }
        }
        std::cout << std::endl; // Nueva línea para cada nodo
    }
}

template<typename T>
void Grafo<T>::agregarNodo(Nodo<T> nodo)
{
    vertices.push_back(nodo);
    for (auto& row : edges)
    {
        row.push_back(0);
    }
    edges.push_back(std::vector<int>(vertices.size(), 0));
}

template<typename T>
void Grafo<T>::eliminarNodo(int id)
{
    if (id < 0 || id >= vertices.size())
    {
        throw std::invalid_argument("ID de nodo inválido");
    }

    // Eliminar el nodo de la lista de vértices
    auto it = vertices.begin();
    std::advance(it, id);
    vertices.erase(it);

    // Eliminar el nodo de la matriz de adyacencia
    edges.erase(edges.begin() + id);
    for (auto& row : edges)
    {
        row.erase(row.begin() + id);
    }

    // Ajustar los índices de los nodos restantes
    for (int i = id; i < edges.size(); ++i)
    {
        for (int j = 0; j < edges[i].size(); ++j)
        {
            if (edges[i][j] > id)
            {
                edges[i][j]--; // Decrementar índices de nodos mayores que id
            }
        }
    }
}

template<typename T>
void Grafo<T>::addEdge(int origen, int destino)
{
    if (origen < edges.size() && destino < edges.size())
    {
        edges[origen][destino] = 1;
    }
}

template<typename T>
Nodo<T>* Grafo<T>::getNodo(int id)
{
    for (auto& nodo : vertices)
    {
        if (nodo.id == id) return &nodo;
    }
    return nullptr;
}


template<typename T>
std::vector<std::pair<int, int>> Grafo<T>::convertPairs()
{
    std::vector<std::pair<int, int>> pairs;
    for (size_t i = 0; i < edges.size(); ++i)
    {
        for (size_t j = 0; j < edges[i].size(); ++j)
        {
            if (edges[i][j] != 0)
            {
                pairs.push_back({i, j});
            }
        }
    }
    return pairs;
}
