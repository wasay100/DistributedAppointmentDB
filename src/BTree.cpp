#include "BTree.h"
#include <iostream>

using namespace std;

BTree::BTree(int t) : degree(t), root(nullptr) {
    root = new Node(true);
}

BTree::~BTree() {
    deleteTree(root);
}

void BTree::deleteTree(Node* node) {
    if (node) {
        if (!node->isLeaf) {
            for (size_t i = 0; i < node->children.size(); i++) {
                deleteTree(node->children[i]);
            }
        }
        delete node;
    }
}

void BTree::insert(const Appointment& apt) {
    if (root->keys.size() == (2 * degree - 1)) {
        Node* newRoot = new Node(false);
        newRoot->children.push_back(root);
        splitChild(newRoot, 0);
        root = newRoot;
    }
    insertNonFull(root, apt);
}

void BTree::splitChild(Node* parent, int index) {
    Node* fullChild = parent->children[index];
    Node* newChild = new Node(fullChild->isLeaf);   
    int mid = degree - 1;
    for (int i = mid + 1; i < fullChild->keys.size(); i++) {
        newChild->keys.push_back(fullChild->keys[i]);
    }
    if (!fullChild->isLeaf) {
        for (int i = mid + 1; i < fullChild->children.size(); i++) {
            newChild->children.push_back(fullChild->children[i]);
        }
        fullChild->children.resize(mid + 1);
    }
    parent->keys.insert(parent->keys.begin() + index, fullChild->keys[mid]);
    parent->children.insert(parent->children.begin() + index + 1, newChild);
    fullChild->keys.resize(mid);
}

void BTree::insertNonFull(Node* node, const Appointment& apt) {
    int i = node->keys.size() - 1;
    if (node->isLeaf) {
        node->keys.push_back(apt);
        while (i >= 0 && node->keys[i].date + node->keys[i].time > apt.date + apt.time) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = apt;
    } else {
        while (i >= 0 && node->keys[i].date + node->keys[i].time > apt.date + apt.time) {
            i--;
        }
        i++;
        if (node->children[i]->keys.size() == (2 * degree - 1)) {
            splitChild(node, i);
            if (node->keys[i].date + node->keys[i].time < apt.date + apt.time) {
                i++;
            }
        }
        insertNonFull(node->children[i], apt);
    }
}

void BTree::display() {
    vector<Appointment> all = getAll();
    cout << endl << "=== All Appointments (B-Tree Sorted) ===" << endl;
    for (size_t i = 0; i < all.size(); i++) {
        cout << i + 1 << ". " << all[i].date << " " << all[i].time << " - " 
             << all[i].name << " (" << all[i].city << ")" << endl;
    }
}

vector<Appointment> BTree::getAll() {
    vector<Appointment> result;
    traverse(root, result);
    return result;
}

void BTree::traverse(Node* node, vector<Appointment>& result) {
    if (node) {
        int i;
        for (i = 0; i < node->keys.size(); i++) {
            if (!node->isLeaf) {
                traverse(node->children[i], result);
            }
            result.push_back(node->keys[i]);
        }
        if (!node->isLeaf) {
            traverse(node->children[i], result);
        }
    }
}

vector<Appointment> BTree::searchByDateRange(const string& startDate, const string& endDate) {
    vector<Appointment> result;
    searchRange(root, startDate, endDate, result);
    return result;
}

void BTree::searchRange(Node* node, const string& startDate, const string& endDate, vector<Appointment>& result) {
    if (node) {
        int i;
        for (i = 0; i < node->keys.size(); i++) {
            if (!node->isLeaf) {
                searchRange(node->children[i], startDate, endDate, result);
            }
            if (node->keys[i].date >= startDate && node->keys[i].date <= endDate) {
                result.push_back(node->keys[i]);
            }
        }
        if (!node->isLeaf) {
            searchRange(node->children[i], startDate, endDate, result);
        }
    }
}
