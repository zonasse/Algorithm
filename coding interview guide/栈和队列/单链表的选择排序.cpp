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
Node* getSmallestPreNode(Node *head){
    if(!head) return NULL;
    Node *smallPre = NULL;
    Node *small = head;
    Node *pre = head;
    Node *cur = head->next;
    while(cur){
        if(cur->data < small->data){
            small = cur;
            smallPre = pre;
        }
        pre = cur;
        cur = cur->next;
    }
    return smallPre;
}
Node* selectionSort(Node *head){
    Node *tail = head;
    Node *cur = head;
    Node *small = NULL;
    while(cur){
        Node *smallPre = getSmallestPreNode(cur);
        //如果最小节点不是第一个节点
        if(smallPre){
            small = smallPre->next;
            smallPre->next = small->next;
        }
        //若当前节点为最小节点则下移一位
        cur = cur == small ? cur->next:cur;

        if(tail){
            tail->next = small;
            tail = small;
        }else{
            head = small;
        }
    }
    return head;
}