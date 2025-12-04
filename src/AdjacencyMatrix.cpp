#include "AdjacencyMatrix.h"
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
    this->adjMatrix[u][v] = w;
    this->adjMatrix[v][u] = w;
}

int AdjacencyMatrix::get_weight(int u, int v) {
    return this->adjMatrix[u][v];
}

int AdjacencyMatrix::getDegree(int u) {
    int* col = this->adjMatrix[u];
    int degree = 0;

    for (int i = 0; i < this->m; i++) {
        degree += col[i] > 0 ? 1 : 0;
    }

    return degree;
}

int* AdjacencyMatrix::dijkstra(int start) {
    int* dist = new int[this->n];
    bool* visited = new bool[this->n];

    for (int i = 0; i < this->n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[start] = 0;

    for (int c = 0; c < this->n - 1; c++) {
        int minDist = INT_MAX, u = -1;

        for (int i = 0; i < this->n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < this->n; v++) {
            if (this->adjMatrix[u][v] > 0) {
                if (!visited[v] && dist[u] + this->adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + this->adjMatrix[u][v];
                }
            }
        }
    }

    return dist;
}

void AdjacencyMatrix::print() {
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this->m; j++) {
            std::cout << this->adjMatrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void AdjacencyMatrix::printDijkstra(int* dist) {
    for (int i = 0; i < this->m; i++) {
        std::cout << i+1 << ": " << dist[i] << std::endl;
    }
}
