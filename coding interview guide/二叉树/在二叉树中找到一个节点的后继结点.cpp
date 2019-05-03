//
// Created by 钟奇龙 on 2019-05-03.
//
//
// Created by 钟奇龙 on 2019-05-01.
//
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *parent;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL),parent(NULL){}
};

Node* getNextNode(Node *root){
    if(!root) return NULL;
    if(root->right){
        Node *right = root->right;
        while(right->left){
            right = right->left;
        }
        return right;
    }else{
        Node *parent = root->parent;
        while(parent && parent->left != root){
            root = parent;
            parent = root->parent;
        }
        return parent;
    }
}