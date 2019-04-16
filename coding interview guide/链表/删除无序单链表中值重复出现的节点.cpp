//
// Created by 钟奇龙 on 2019-04-16.
//


#include <iostream>
#include <set>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x):data(x),next(NULL){

    }
};

void removeDuplicatedNode(Node *head){
    set<int> node_set;
    Node *pre = head;
    Node *cur = head->next;
    node_set.insert(head->data);
    while(cur){
        if(node_set.find(cur->data) != node_set.end()){
            pre->next = cur->next;
        }else{
            node_set.insert(cur->data);
            pre = cur;
        }
        cur = cur->next;
    }
}

