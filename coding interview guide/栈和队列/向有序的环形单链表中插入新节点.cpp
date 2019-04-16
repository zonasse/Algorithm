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

Node* insertNum(Node *head,int num){
    Node *newNode = new Node(num);
    if(!head){
        newNode->next = newNode;
        return newNode;
    }
    Node *pre = head;
    Node *cur = head->next;
    while(cur != head){
        if(pre->data < num && cur->data > num){
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    pre->next = newNode;
    newNode->next = cur;
    return head->data < num ? head:newNode;
}