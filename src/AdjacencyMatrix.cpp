#include "AdjacencyMatrix.h"
#include <iostream>

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

int AdjacencyMatrix::getDegree(int u) {
    int* col = this->adjMatrix[u];
    int degree = 0;

    for (int i = 0; i < this->m; i++) {
        degree += col[i] > 0 ? 1 : 0;
    }

    return degree;
}

void AdjacencyMatrix::print() {
    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this->m; j++) {
            std::cout << this->adjMatrix[i][j];
        }
        std::cout << '\n';
    }
}
