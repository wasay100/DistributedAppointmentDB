#ifndef BTREE_H
#define BTREE_H

#include "Appointment.h"
#include <vector>

using namespace std;

class BTree {
private:
    struct Node {
        bool isLeaf;
        vector<Appointment> keys;
        vector<Node*> children;
        
        Node(bool leaf) : isLeaf(leaf) {}
    };
    
    Node* root;
    int degree;
    
    void splitChild(Node* parent, int index);
    void insertNonFull(Node* node, const Appointment& apt);
    void traverse(Node* node, vector<Appointment>& result);
    void searchRange(Node* node, const string& startDate, const string& endDate, vector<Appointment>& result);
    void deleteTree(Node* node);
    
public:
    BTree(int t);
    ~BTree();
    void insert(const Appointment& apt);
    void display();
    vector<Appointment> getAll();
    vector<Appointment> searchByDateRange(const string& startDate, const string& endDate);
};

#endif
