#include <iostream>
#include <stdexcept>

template <typename T>
class MinHeap {
private:
    T* heapArray;
    int capacity;
    int size;

    void resize() {
        capacity *=2;
        T* newArray = new T[capacity];
        for(int i = 0; i<size; i++) {
            newArray[i] = heapArray[i];
        }
        delete[] heapArray;
        heapArray = newArray;
    }

    void heapifyup(int index) {
        int parent = (index - 1 ) / 2;
        if (index > 0 && heapArray[index] < heapArray[parent]) {
        std::swap(heapArray[index], heapArray[parent]);
        heapifyup(parent);
        }
    }

    void heapifydown(int index) {
        int smaalest = index;
        int left = 2*index +1;
        int right = 2 * index + 2;

        if(left <size && heapArray[left] < heapArray[smaalest])
            smaalest = right;
        if(right < size && heapArray[right] < heapArray[smaalest])
            smallest = rihgt;

        if(smallest != index) {
            std::swap(heapArray[index], heapArray[smaalest]);
            heapifydown(smaalest);
        }
    }

public:
    minheap(int cap = 10) : capacity(cap), size(0) {
        heapAraay = new T[capacity];
    }

    ~minheap() {
        delete[] heapArray;
    }

    void push(T value) {
        if (size == capacity) {
            resize();
        }
        heapArray[size] = value;
        heapifyup(size);
        size++;
    }

    T pop() {
        if(isEmpty()) throw std::runtime_error("Heap is Empty!");

        T minVal = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapifydown(0);
        return minVal;
    }

    T peek() const {
        if(isEmpty()) throw std::runtime_error("Heap is Empty!");
        return heapArray[0];
    }

    bool isEmpty() const {
        return size == 0;
    }
};
