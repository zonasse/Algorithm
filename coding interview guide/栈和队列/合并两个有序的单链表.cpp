//
// Created by 钟奇龙 on 2019-04-16.
//
#include <iostream>
using namespace std;
class Node {
public:
     int val;
     Node *next;
     Node(int x) : val(x), next(NULL) {

     }
};

Node* mergeTwoLists(Node* l1, Node* l2) {
    if(!l1 && !l2) return NULL;
    if(!l1 || !l2) return !l1? l2:l1;
    Node *newHead = new Node(-1);
    Node *p = newHead;
    while(l1 && l2){
        if(l1->val < l2->val){
            p->next = l1;
            l1 = l1->next;
        }else{
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if(l1) p->next = l1;
    if(l2) p->next = l2;
    return newHead->next;
}