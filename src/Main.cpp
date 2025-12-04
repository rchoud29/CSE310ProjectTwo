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

    // And here is where you start working on the three tasks
    std::cout << "The adjacency matrix of G is:" << std::endl;
    adjM->print();

    int* oddDegrees = nullptr;
    int c = 0;
    for (int i = 0; i < numOfVertices; i ++) {
        int deg = adjM->getDegree(i);
        if (deg % 2 > 0) {
            c++;
        }
    }
    oddDegrees = new int[c];
    for (int i = 0, j = 0; i < numOfVertices; i++) {
        int deg = adjM->getDegree(i);
        if (deg % 2 > 0) {
            oddDegrees[j] = i;
            j++;
        }
    }
    
    std::cout << "\nThe nodes with odd degrees in G are:" << std::endl;
    std::cout << "O = { ";
    for (int i = 0; i < c; i++) {
        std::cout << oddDegrees[i] + 1 << " ";
    }
    std::cout << "}" << std::endl << std::endl;

    for (int i = 0; i < c; i++) {
        std::cout << "The shortest path lengths from Node " 
                  << oddDegrees[i] + 1 
                  << " to all other nodes are:" << std::endl;
        adjM->printDijkstra(adjM->dijkstra(oddDegrees[i]));
        std::cout << std::endl;
    }

    return 0;
}
