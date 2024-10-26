#include "Grafo.h"
#include <iostream>
#include <stdexcept>
#include <stack>
#include <queue>


template<typename T>
Grafo<T>::Grafo()
{
}

template<typename T>
Grafo<T>::~Grafo()
{
}

template<typename T>
void Grafo<T>::DFS_Matriz(int idInicio)
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
void Grafo<T>::BFS_Matriz(int idInicio)
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
void Grafo<T>::plano_Matriz()
{
    std::cout << "Representacion del grafo en plano:\n";
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
void Grafo<T>::DFS_Lista(int idInicio)
{
    if (adjList.find(idInicio) == adjList.end())
    {
        std::cout << "El nodo de inicio no existe en el grafo.\n";
        return;
    }

    std::unordered_map<int, bool> visitado;
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

            // Agrega los nodos adyacentes no visitados
            for (int vecino : adjList[idNodo])
            {
                if (!visitado[vecino])
                {
                    stack.push(vecino);
                }
            }
        }
    }
}

template<typename T>
void Grafo<T>::BFS_Lista(int idInicio)
{
    if (adjList.find(idInicio) == adjList.end())
    {
        std::cout << "El nodo de inicio no existe en el grafo.\n";
        return;
    }

    std::unordered_map<int, bool> visitado;
    std::queue<int> queue;

    visitado[idInicio] = true;
    queue.push(idInicio);

    while (!queue.empty())
    {
        int idNodo = queue.front();
        queue.pop();
        std::cout << "Visitando nodo " << idNodo << std::endl;

        // Agrega los nodos adyacentes no visitados
        for (int vecino : adjList[idNodo])
        {
            if (!visitado[vecino])
            {
                visitado[vecino] = true;
                queue.push(vecino);
            }
        }
    }
}

template<typename T>
void Grafo<T>::plano_Lista()
{
    for (const auto& par : adjList) {
        auto nodo = par.first;
        auto listaAdyacentes = par.second;

        // Imprimir el nodo y su lista de adyacentes (o procesar como necesites)
        std::cout << "Nodo: " << nodo << " tiene adyacentes: ";
        for (const auto& adyacente : listaAdyacentes) {
            std::cout << adyacente << " ";
        }
        std::cout << std::endl;
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
void Grafo<T>::convertirALista()
{
    adjList.clear(); // Limpiar la lista de adyacencia actual
    for (size_t i = 0; i < edges.size(); ++i)
    {
        for (size_t j = 0; j < edges[i].size(); ++j)
        {
            if (edges[i][j] == 1)   // Hay arista
            {
                adjList[i].push_back(j);
            }
        }
    }
}

template<typename T>
void Grafo<T>::convertirAMatriz()
{
    edges.clear();
    edges.resize(vertices.size(), std::vector<int>(vertices.size(), 0));

    for (auto it = adjList.begin(); it != adjList.end(); ++it)
    {
        int origen = it->first;
        const std::vector<int>& listaAdyacente = it->second;
        for (int destino : listaAdyacente)
        {
            edges[origen][destino] = 1;
        }
    }
}
