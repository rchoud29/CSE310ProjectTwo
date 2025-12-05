all: Main.o Edge.o Vertex.o AdjacencyMatrix.o MinHeap.o
		g++ -g -Wall Main.o Edge.o Vertex.o \
			AdjacencyMatrix.o MinHeap.o -o dijkstra

Edge.o: Edge.h Edge.cpp
		g++ -g -Wall -c Edge.cpp

Vertex.o: Vertex.h Vertex.cpp	
		g++ -g -Wall -c Vertex.cpp

AdjacencyMatrix.o: AdjacencyMatrix.h AdjacencyMatrix.cpp
		g++ -g -Wall -c AdjacencyMatrix.cpp

MinHeap.o: MinHeap.h MinHeap.cpp
		g++ -g -Wall -c MinHeap.cpp

Main.o: Main.cpp
		g++ -g -Wall -c Main.cpp

clean:
	rm -rf *.o dijkstra
