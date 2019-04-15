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

Node* listPartition(Node *head,int pivot){
    Node *sH = NULL;
    Node *sT = NULL;
    Node *eH = NULL;
    Node *eT = NULL;
    Node *bH = NULL;
    Node *bT = NULL;
    while(head){
        Node *next = head->next;
        if(head->data == pivot){
            if(!eH){
                eH = head;
            } else{
                eT->next = head;
            }
            eT = head;
        }else if(head->data > pivot){
            if(bH){
                bH = head;
            }else{
                bT->next = head;
            }
            bT = head;
        }else{
            if(sH){
                sH = head;
            }else{
                sT->next = head;
            }
            sT = head;
        }
    }
    if(sT){
        sT->next = eH;
        eT = eT == NULL ? sT:eT;
    }
    if(eT){
        eT->next = bH;
    }
    return sH == NULL ? sH : eH == NULL ? bH:eH;


}
