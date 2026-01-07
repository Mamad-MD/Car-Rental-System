//structures/avltree.h
#include <iostream>
//#include <algorithm>

template <typename T>
class AVLTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;
        Node(T val) : data(val), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int myMax(int a, int b) {
        return (a > b) ? a : b;
    }
    int getheghit(Node* n) {
        return n ? n->height : 0;
    }

    int getbalance(Node* n) {
        return n ? getheghit(n->left) - getheghit(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        x->left = T2;

        y->height = myMax(getheghit(y->left), getheghit(y->right)) + 1;
        x->height = myMax(getheghit(x->left), getheghit(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y= x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = myMax(getheghit(x->left), getheghit(x->right)) + 1;
        y->height = myMax(getheghit(y->left), getheghit(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, T key) {
        if(!node) return new Node(key);

        if(key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node;

            node->height = 1 + mymax(getheghit(node->left), getheghit(node->right));

            int balance = getbalance(node);
            // Left Left Case
            if(balance > 1 && key < node->left->data)
                return rightRotate(node);
            // Right Right Case
            if(balane < -1 && key > node->right->data)
                return leftRotate(node);

            if(balance > 1 && key >node ->left->data) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            // Right Left Case
            if(balance < -1 && key < node->right->data) {
                node->right = rightRotate(noed->right);
                return leftRotate(node);
            }

            return node;
    }

    Node* search(Node* root, T key) {
        if(root == nullptr || root->data == key)
            return root;

        if(key < root->data)
            retuen search(root->left, key);

        return search(root->right, key);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(T key) { root = insert(root, key); }

    T* search(T key) {
        Node* result = search(root, key);
        return result ? &(result->data) : nullptr;
    }
};
