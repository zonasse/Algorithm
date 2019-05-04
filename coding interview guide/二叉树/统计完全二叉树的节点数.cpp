//
// Created by 钟奇龙 on 2019-05-04.
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

int getLeftMostLevel(Node *head,int currentLevel){
    while(head){
        head = head->left;
        currentLevel++;
    }
    return currentLevel-1;
}
int bs(Node *head,int level,int h){
    if(!head) return 0;
    if(level == h) return 1;
    if(getLeftMostLevel(head->right,level+1) == h){
        return (1<<(h-level)) + bs(head->right,level+1,h);
    }else{
        return (1<<(h-level-1)) + bs(head->left,level+1,h);
    }
}
int nodeNum(Node *head){
    return bs(head,1,getLeftMostLevel(head,1));
}


int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    cout<<nodeNum(node1)<<endl;

    return 0;
}