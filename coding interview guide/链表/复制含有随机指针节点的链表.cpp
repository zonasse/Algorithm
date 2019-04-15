//
// Created by 钟奇龙 on 2019-04-15.
//
#include <iostream>
#include <map>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *random;
    Node(int x):data(x),next(NULL),random(NULL){

    }
};

Node* copyListWithRand(Node *head){
    map<Node*,Node*> node_map;
    Node *cur = head;
    while(cur){
        node_map[cur] = new Node(cur->data);
        cur = cur->next;
    }
    cur = head;
    while(cur){
        node_map[cur]->next = node_map[cur->next];
        node_map[cur]->random = node_map[cur->random];
        cur = cur->next;
    }
    return node_map[head];
}

Node* copyListWithRand2(Node *head){
    if(!head) return NULL;
    Node *cur = head;
    //复制next域
    while(cur){
        Node *nextNode = cur->next;
        cur->next = new Node(cur->data);
        cur->next->next = nextNode;
        cur = nextNode;
    }
    //复制rand域
    cur = head;
    while(cur){
        Node *nextNode = cur->next->next;
        Node *copyNode = cur->next;
        copyNode->random = cur->random ? cur->random->next : NULL;
        cur = nextNode;
    }
    //拆分链表
    Node *res = head->next;
    cur = head;
    while(cur){
        Node *nextNode = cur->next->next;
        Node *copyNode = cur->next;
        copyNode->next = nextNode ? nextNode->next : NULL;
        cur->next = nextNode;
        cur = nextNode;
    }
    return res;

}