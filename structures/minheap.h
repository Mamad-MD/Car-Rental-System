#include <iostream>

template <typename T>
class MinHeap {
private:
    T* heapArray;
    int capacity;
    int size;

    void mySwap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void resize() {
        int newCapacity = capacity * 2;
        T* newArray = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = heapArray[i];
        }
        delete[] heapArray;
        heapArray = newArray;
        capacity = newCapacity;
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heapArray[index] < heapArray[parent]) {
            mySwap(heapArray[index], heapArray[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heapArray[left] < heapArray[smallest])
            smallest = left;
        if (right < size && heapArray[right] < heapArray[smallest])
            smallest = right;

        if (smallest != index) {
            mySwap(heapArray[index], heapArray[smallest]);
            heapifyDown(smallest);
        }
    }

public: // <--- این خط بسیار مهم است
    MinHeap(int cap = 10) : capacity(cap), size(0) {
        heapArray = new T[capacity];
    }

    ~MinHeap() {
        delete[] heapArray;
    }

    void push(T value) {
        if (size == capacity) {
            resize();
        }
        heapArray[size] = value;
        heapifyUp(size);
        size++;
    }

    T pop() {
        if (isEmpty()) {
            return T(); // بازگرداندن مقدار پیش‌فرض
        }

        T minVal = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapifyDown(0);
        return minVal;
    }

    T peek() const {
        if (isEmpty()) return T();
        return heapArray[0];
    }

    bool isEmpty() const {
        return size == 0;
    }
};
