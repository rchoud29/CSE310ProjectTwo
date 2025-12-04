#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

class AdjacencyMatrix{
    private:
        int n, m;
        int** adjMatrix;

    public:
        AdjacencyMatrix(int n, int m);

        void update(int u, int v, int w);
        int get_weight(int u, int v);

        void print();

        int getDegree(int u);

        int* dijkstra(int start);
        void printDijkstra(int* dist);
};


#endif
