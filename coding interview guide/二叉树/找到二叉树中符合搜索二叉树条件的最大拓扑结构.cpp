//
// Created by 钟奇龙 on 2019-05-01.
//
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};
bool isBSTNode(Node *root,Node *target){
    if(!root) return false;
    if(root == target) return true;
    return root->data > target->data ? isBSTNode(root->left,target):isBSTNode(root->right,target);
}
int maxTopo(Node *root,Node *subNode){
    if(root && subNode && isBSTNode(root,subNode)){
        return maxTopo(root,subNode->left),maxTopo(root,subNode->right) + 1;
    }
    return 0;
}
int bestTopoSize(Node *root){
    if(!root) return 0;
    int maxSize = maxTopo(root,root);
    maxSize = max(bestTopoSize(root->left),maxSize);
    maxSize = max(bestTopoSize(root->right),maxSize);
    return maxSize;
}
int main(){

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node5->right = node7;

    cout<<bestTopoSize(node1);

    return 0;
}