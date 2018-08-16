#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node{
public:
    int key;
    Node* left;
    Node* right;

    Node(int item){
        key = item;
        right = left = nullptr;
    }

    static Node* createNode(int _key);
    static Node* insertNode(Node*, int _key);
    Node* searchNode(Node*, int _key);
    static Node* createTree(int a[], int n);
    void printTreeValue(Node* root);
    static Node* searchNode(Node* root);
};

#endif // NODE_H
