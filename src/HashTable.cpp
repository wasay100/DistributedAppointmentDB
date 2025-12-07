#include "HashTable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int cap) : capacity(cap), size(0) {
    table.resize(capacity, nullptr);
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; i++) {
        HashNode* current = table[i];
        while (current) {
            HashNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

int HashTable::hashFunction(const string& key) {
    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % capacity;
}

void HashTable::insert(const string& key, const Appointment& apt) {
    int index = hashFunction(key);
    HashNode* newNode = new HashNode(key, apt);
    if (table[index] == nullptr) {
        table[index] = newNode;
    } else {
        HashNode* current = table[index];
        while (current->next) {
            if (current->key == key) {
                current->value = apt;
                delete newNode;
                return;
            }
            current = current->next;
        }
        if (current->key == key) {
            current->value = apt;
            delete newNode;
        } else {
            current->next = newNode;
        }
    }
    size++;
}

Appointment* HashTable::search(const string& key) {
    int index = hashFunction(key);
    HashNode* current = table[index];
    while (current) {
        if (current->key == key) {
            return &(current->value);
        }
        current = current->next;
    }
    return nullptr;
}

void HashTable::display() {
    cout << endl << "=== Hash Table Contents ===" << endl;
    int count = 0;
    for (int i = 0; i < capacity; i++) {
        HashNode* current = table[i];
        while (current) {
            count++;
            cout << count << ". Key: " << current->key << " -> " 
                 << current->value.name << " (" << current->value.city << ")" << endl;
            current = current->next;
        }
    }
}

int HashTable::getSize() {
    return size;
}
