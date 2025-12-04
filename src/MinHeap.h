#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap {
private:
    int* A;        // array storing heap
    int size;      // current number of elements
    int cap;       // fixed capacity

    void minHeapify(int i);

public:
    MinHeap(int n);       // constructor
    void insert(int key); // enqueue
    int getMin();         // dequeue (extractMin)
    int peek();           // return min without removing
};

#endif

