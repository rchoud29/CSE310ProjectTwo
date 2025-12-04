#include "AdjacencyMatrix.h"
#include "MinHeap.h"
#include <iostream>
#include <climits>

AdjacencyMatrix::AdjacencyMatrix(int n, int m){
    this->n = n;
    this->m = m;
    this->adjMatrix = new int*[n];

    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[m];

        for (int j = 0; j < m; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void AdjacencyMatrix::update(int u, int v, int w) {
    u--,v--;
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;
}

int AdjacencyMatrix::get_weight(int u, int v) {
    return adjMatrix[u][v];
}

int AdjacencyMatrix::getDegree(int u) {
    int* col = adjMatrix[u];
    int degree = 0;

    for (int i = 0; i < m; i++) {
        degree += col[i] > 0 ? 1 : 0;
    }

    return degree;
}

int* AdjacencyMatrix::dijkstra(int start) {
    int* dist = new int[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[start] = 0;

    MinHeap distHeap(n * 10);
    MinHeap nodeHeap(n * 10);

    distHeap.insert(dist[start]);
    nodeHeap.insert(start);

    while (true) {
        int u = nodeHeap.getMin();

        if (u == -1) break;
        
        int d = dist[u];
        if (d != dist[u]) continue;

        for (int v = 0; v < n; v++) {
            int w = adjMatrix[u][v];

            if (w <= 0) continue;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                distHeap.insert(dist[v]);
                nodeHeap.insert(v);
            }
        }
    }

    return dist;
}

void AdjacencyMatrix::print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void AdjacencyMatrix::printDijkstra(int* dist) {
    for (int i = 0; i < n; i++) {
        std::cout << "  " << i+1 << ": " << dist[i] << std::endl;
    }
}
