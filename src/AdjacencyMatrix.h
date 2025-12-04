#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

class AdjacencyMatrix{
    private:
        int n, m;
        int** adjMatrix;

    public:
        AdjacencyMatrix(int n, int m);
        void update(int u, int v, int w);
        void print();
        int getDegree(int u);
};


#endif
