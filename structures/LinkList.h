//structures/linklist.h
#include <iostream>


template <typename T>
class LinkList {
private:
    struct Node {
        T data;
        node* next;
        Node* prev;
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkList() { clear(); }

    void push_back(T value) {
        Node* newNode = new Node(value);
        if(!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    bool remove(T value) {
        Node* current = head;
        while(current) {
            if (current->data == value) {
                if(current->prev) current->prev->next = current->next;
                else head = current->next;

                if(current->next) current->next->prev = current->prev;
                else tail = current->prev;

                delete current;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    T* search(T value) {
        Node*current = head;
        while(current) {
            if (current->data == value) {
                return &(current->data);
            }
            current = current->next;
        }
        return nullptr;
    }

    void clear() {
        Node* current = head;
        while(current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        size= 0;
    }

    template <typename Func>
    void traverse(Func func) const {
        Node* current = head;
        while (current) {
            func(current->data);
            current = current ->next;
        }
    }
    int getsize() const {return size;}
};
