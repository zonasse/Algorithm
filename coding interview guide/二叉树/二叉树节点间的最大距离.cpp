//
// Created by 钟奇龙 on 2019-05-03.
//
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    int leftMax;
    int rightMax;
    Node *left;
    Node *right;
    Node(int x):data(0),leftMax(0),rightMax(0),left(NULL),right(NULL){

    }

};
int maxDistance = INT_MIN;
int getMaxDistance(Node *head){
    if(!head) return 0;
    if(head->left){
        head->leftMax = getMaxDistance(head->left) + 1;
    }
    if(head->right){
        head->rightMax = getMaxDistance(head->right) + 1;
    }
    int sum = head->leftMax + head->rightMax + 1;
    if(sum > maxDistance){
        maxDistance = sum;
    }
    return head->leftMax > head->rightMax ? head->leftMax:head->rightMax;
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
    node3->right = node7;
    cout<<getMaxDistance(node1)<<endl;
    cout<<maxDistance<<endl;
    return 0;
}