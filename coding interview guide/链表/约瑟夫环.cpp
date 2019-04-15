//
// Created by 钟奇龙 on 2019-04-15.
//

#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int x):data(x),next(NULL){

    }
};


int getLiveNum(int i,int m){
    if(i == 1){
        return i;
    }
    return (getLiveNum(i-1,m)+m-1) % i + 1;
}

Node* josephusKill(Node *head,int m){
    if(!head || head->next == head || m < 1){
        return head;
    }
    Node* cur = head->next;
    int len = 0;
    while(cur != head){
        len++;
        cur = cur->next;
    }
    int liveNum = getLiveNum(len,m);
    while(--liveNum != 0){
        head = head->next;
    }
    head->next = head;
    return head;

}