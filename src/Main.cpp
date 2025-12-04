#include "Edge.h"
#include "AdjacencyMatrix.h"
#include <iostream>

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;
    AdjacencyMatrix* adjM;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    } else{
        std::cout<<"Input not found!"<<std::endl;
        return NULL;
    }
    
    adjM = new AdjacencyMatrix(numOfVertices, numOfVertices);


    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        int weight;
        std::cin >> startVertice;
        std::cin >> endVertice;
        std::cin >> weight;
        Edge* newEdge = new Edge(startVertice, endVertice);
        newEdge->setWeight(weight);
        // Here is where you load up the Graph object
        adjM->update(startVertice, endVertice, weight);
    }

    adjM->print();
    for (int i = 0; i < numOfVertices; i ++) {
        int deg = adjM->getDegree(i);
        if (deg % 2 > 0) {
            std::cout << i << ", ";
        }
    }

    // And here is where you start working on the three tasks

    return 0;
}
