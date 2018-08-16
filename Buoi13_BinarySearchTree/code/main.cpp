/*
*
*/
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include "Node.h"

using namespace std;

#define N 10000

int main()
{
    int n, _min = 10000000;
    std::queue<Node*> myqueue;

    cin >> n;

    int price[N];

    for(int i=0; i < n; i++){
        cin >> price[i];
    }

    Node* root = Node::createTree(price, n);

    if(root != nullptr)
        myqueue.push(root);

    while(!myqueue.empty()){
        Node* curNode = myqueue.front();
        //std::cout << curNode->key << " ";

        if(curNode->left != nullptr){
            myqueue.push(curNode->left);
            _min = min(_min, curNode->key - Node::searchNode(curNode->left)->key);
        }
        if(curNode->right != nullptr)
            myqueue.push(curNode->right);
        myqueue.pop();
    }

    std::cout << _min << endl;

	return 0;
}
