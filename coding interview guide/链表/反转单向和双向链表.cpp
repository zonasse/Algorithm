//
// Created by 钟奇龙 on 2019-04-15.
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

Node* reverseSingleList(Node* head){
    Node *pre = NULL;
    Node *next = NULL;
    while(head){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

class DoubleNode{
public:
    int data;
    DoubleNode *pre;
    DoubleNode *next;
    DoubleNode(int x):data(x),pre(NULL),next(NULL){

    }
};

DoubleNode* reverseDoubleList(DoubleNode *head){
    DoubleNode *pre = NULL;
    DoubleNode *next = NULL;
    while(head){
        next = head->next;
        head->next = pre;
        head->pre = next;
        pre = head;
        head = next;
    }
    return pre;
}