//
// Created by 钟奇龙 on 2019-04-16.
//

#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){

    }
};
void inOrderToQueue(Node* head,queue<Node*> &node_queue){
    if(!head) return;
    inOrderToQueue(head->left,node_queue);
    node_queue.push(head);
    inOrderToQueue(head->right,node_queue);
}
Node* convert(Node* head){
    queue<Node*> node_queue;
    inOrderToQueue(head,node_queue);
    if(node_queue.empty()){
        return head;
    }
    head = node_queue.front();
    node_queue.pop();
    Node *pre = head;
    pre->left = NULL;
    while(node_queue.empty() == false){
        Node *cur = node_queue.front();
        node_queue.pop();
        pre->right = cur;
        cur->left=  pre;
        pre = cur;
    }
    pre->right = NULL;
    return head;
}
