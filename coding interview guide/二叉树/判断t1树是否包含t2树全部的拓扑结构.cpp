//
// Created by 钟奇龙 on 2019-05-02.
//
#include <iostream>
#include <map>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};
bool check(Node *t1,Node *t2){
    if(!t2) return true;
    if(!t1 || t1->data != t2->data) return false;
    return check(t1->left,t2->left) && check(t1->right,t2->right);
}
bool contains(Node *t1,Node *t2){
    return check(t1,t2) || contains(t1->left,t2) || contains(t1->right,t2);
}