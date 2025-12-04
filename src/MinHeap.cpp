#include "MinHeap.h"

MinHeap::MinHeap(int n) {
    cap = n;
    size = 0;
    A = new int[cap];
}

void MinHeap::minHeapify(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int smallest = i;

    if (left < size && A[left] < A[smallest])
        smallest = left;

    if (right < size && A[right] < A[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;

        minHeapify(smallest);
    }
}

void MinHeap::insert(int key) {
    if (size == cap)
        return; // queue full, cannot insert

    int i = size;
    A[i] = key;
    size++;

    // bubble up
    while (i > 0 && A[i] < A[(i - 1) / 2]) {
        int temp = A[i];
        A[i] = A[(i - 1) / 2];
        A[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

int MinHeap::getMin() {
    if (size == 0)
        return -1; // empty

    int root = A[0];

    A[0] = A[size - 1];
    size--;

    minHeapify(0);

    return root;
}

int MinHeap::peek() {
    if (size == 0)
        return -1;
    return A[0];
}
