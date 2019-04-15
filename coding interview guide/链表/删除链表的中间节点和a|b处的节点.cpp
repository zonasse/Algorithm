//
// Created by 钟奇龙 on 2019-04-15.
//

#include <iostream>
#include <math.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x):data(x),next(NULL){

    }
};

Node* removeMidNode(Node *head){
    if(!head | !head->next){
        return head;
    }
    if(!head->next->next){
        return head->next;
    }
    Node *slow = head;
    Node *fast = head->next->next;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}

Node* removeByRatio(Node *head,int a,int b){
    if(a < 1 || a > b){
        return head;
    }
    int len = 0;
    Node *cur = head;
    while(cur){
        cur = cur->next;
        len++;
    }
    int r = ceil((double)(a*len)/(double)b);
    if(r == 1){
        head = head->next;
    }else if(r > 1){
        Node *cur = head;
        while(--r != 1){
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
    return head;
}