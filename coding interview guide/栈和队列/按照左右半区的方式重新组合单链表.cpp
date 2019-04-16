//
// Created by 钟奇龙 on 2019-04-16.
//
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x):data(x),next(NULL){

    }
};
void mergeLR(Node* left,Node *right){
    while(left->next){
        Node *next = right->next;
        right->next = left->next;
        left->next = right;
        left = right->next;
        right = next;
    }
    left->next = right;
}
void relocate(Node *head){
    if(!head || !head->next){
        return;
    }
    Node *mid = head;
    Node *right = head->next;
    while(right->next && right->next->next){
        mid = mid->next;
        right = right->next->next;
    }
    right = mid->next;
    mid->next = NULL;
    mergeLR(head,right);
}