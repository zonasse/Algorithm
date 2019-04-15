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

Node* reversePartList(Node *head,int from, int to){
    int len = 0;
    Node *fPre = NULL;
    Node *tPos = NULL;
    Node *cur = head;
    while(cur){
        len++;
        fPre = len == from-1 ? cur:fPre;
        tPos = len == to+1 ? cur:tPos;
        cur = cur->next;
    }
    if(from > to || from < 1 || to > len){
        return head;
    }
    Node *pre = fPre == NULL ? head:fPre->next;
    Node *temp = pre->next;
    pre->next = tPos;
    while(temp != tPos){
        Node *next = temp->next;
        temp->next = pre;
        pre = temp;
        temp = next;
    }
    if(fPre){
        fPre->next = pre;
        return head;
    }
    return pre;
}