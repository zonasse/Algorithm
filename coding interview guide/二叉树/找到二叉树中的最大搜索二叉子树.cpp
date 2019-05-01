//
// Created by 钟奇龙 on 2019-05-01.
//
#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};
Node* posorderFind(Node *root,vector<int> &record){
    if(!root){
        record[0] = 0;
        record[1] = INT_MAX;
        record[2] = INT_MIN;
        return NULL;
    }
    Node *left = root->left;
    Node *right = root->right;
    Node *leftBST = posorderFind(left,record);
    int leftSize = record[0];
    int leftMin = record[1];
    int leftMax = record[2];
    Node *rightBST = posorderFind(right,record);
    int rightSize = record[0];
    int rightMin = record[1];
    int rightMax = record[2];
    record[1] = min(leftMin,root->data);
    record[2] = max(rightMax,root->data);
    if(left == leftBST && right == rightBST && leftMax < root->data && rightMin > root->data){
        record[0] = max(leftSize,rightSize) + 1;
        return root;
    }
    record[0] = max(leftSize,rightSize);
    return leftSize > rightSize ? leftBST:rightBST;
}
Node* biggestSubBST(Node *root){
    vector<int> record(3);
    return posorderFind(root,record);
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

    Node *bst = biggestSubBST(node1);

    return 0;
}