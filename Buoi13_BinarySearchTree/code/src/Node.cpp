#include "Node.h"
#include <queue>

Node* Node::createNode(int _key){
    Node* newNode = new Node(_key);
    newNode->key = _key;
    newNode->left = newNode->right = nullptr;

    return newNode;
}

Node* Node::insertNode(Node* root, int _key){

    if(root == nullptr){
        return Node::createNode(_key);
    }
    if(_key < root->key){
        root->left = Node::insertNode(root->left, _key);
    }
    else if(_key > root->key){
        root->right = Node::insertNode(root->right, _key);
    }

    return root;
}

Node* Node::searchNode(Node* root, int _key){

    if(root == nullptr || root->key == _key){
        return root;
    }
    if(root->key > _key){
        return searchNode(root->left, _key);
    }
    return searchNode(root->right, _key);
}


Node* Node::createTree(int a[], int n){
    Node* root = nullptr;
    for(int i=0; i < n; i++){
        root = insertNode(root, a[i]);
    }
    return root;
}

void Node::printTreeValue(Node* root){
    if (root != nullptr){
        std::cout << root->key << " ";
        printTreeValue(root->left);
        printTreeValue(root->right);
    }
}

Node* Node::searchNode(Node* root){
    if(root->right == nullptr)
        return root;
    return searchNode(root->right);
}
