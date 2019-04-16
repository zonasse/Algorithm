//
// Created by 钟奇龙 on 2019-04-16.
//


#include <iostream>
#include <stack>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x):data(x),next(NULL){

    }
};
//将栈内节点顺序连接并返回链表尾节点
Node* resignStack(stack<Node*> &node_stack,Node* left, Node* right){
    Node *cur = node_stack.top();
    node_stack.pop();
    if(left){
        left->next = cur;
    }
    while(node_stack.empty() == false){
        Node *next = node_stack.top();
        node_stack.pop();
        cur->next = next;
        cur = next;
    }
    cur->next = right;
    return cur;
}

Node* reversePerKNodes(Node *head,int k){
    if(k < 2) return head;
    stack<Node*> node_stack;
    Node *newHead = head;
    Node *pre = NULL;
    Node *cur = head;

    while(cur){
        Node* next = cur->next;
        node_stack.push(cur);
        if(node_stack.size() == k){
            pre = resignStack(node_stack,pre,next);
            newHead = newHead == head ? cur:newHead;
        }
        cur = next;
    }
    return newHead;
}