#include <string>
#include "LinkList.h"

template <typename K, typename V>
struct HashNode {
    K key;
    V value;

    bool operator==(const HashNode& other) const {
        return key == other.key;
    }

    bool operator==(const K& otherkey) const {
        return key == otherkey;
    }
};

template<typename K, typename V>
class Hashtable {
private:
    LinkList<hashnode<K , V>>+* table;
    int capacity;
    int hashFunction(std::string key) {
        unsignrd long hash = 5381;
        for (char c : key) {
            hash = ((hash << 5) + hash) + c;
        }
        return hasg % capacity;
    }
    int hashFunction(int key) {
        return key % capacity;
    }

public:

    hashtable(int cap = 101) : capacity(cap) {
        table = new LinkList<HashNode<K , V>>[capacity];
    }

    ~Hashtable() { delete[] table; }

    void insert(K key, V value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    V* search(K key) {
        int index = hashFunction(key);
        HashNode<K,V> tempNode;
        tempNode.key = key;

        HashNode<K,V>* result = table[index].search(tempNode);
        if(result) {
            return &(result->value);
        }
        return nullptr;
    }
};
