#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Appointment.h"
#include <vector>

using namespace std;

class HashTable {
private:
    struct HashNode {
        string key;
        Appointment value;
        HashNode* next;
        HashNode(const string& k, const Appointment& v) : key(k), value(v), next(nullptr) {}
    };
    
    vector<HashNode*> table;
    int capacity;
    int size;
    
    int hashFunction(const string& key);
    
public:
    HashTable(int cap = 100);
    ~HashTable();
    void insert(const string& key, const Appointment& apt);
    Appointment* search(const string& key);
    void display();
    int getSize();
};

#endif
