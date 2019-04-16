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

Node* removeNodeWithValue(Node* head, int value){
    while(head && head->data == value){
        head = head->next;
    }
    Node *pre = head;
    Node *cur = head;
    while(cur){
        if(cur->data == value){
            pre->next = cur->next;
        }else{
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
}