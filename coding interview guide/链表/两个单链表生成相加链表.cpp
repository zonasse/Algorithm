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

Node* reverseList(Node *head){
    Node *pre = NULL;
    while(head){
        Node *next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

Node* addList(Node *head1,Node *head2){
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    Node *p1 = head1;
    Node *p2 = head2;
    //头插法建立
    int n1 = 0;
    int n2 = 0;
    int carry = 0;
    Node *pre = NULL;
    while(p1 || p2){
        n1 = p1 ? p1->data : 0;
        n2 = p2 ? p2->data : 0;
        int current_num = n1 + n2 + carry;
        Node *new_node = new Node(current_num%10);
        new_node->next = pre;
        pre = new_node;
        carry = current_num / 10;
        p1 = p1 ? p1->next : NULL;
        p2 = p2 ? p2->next : NULL;
    }
    if(carry){
        Node *new_node = new Node(1);
        new_node->next = pre;
        pre = new_node;
    }
    reverseList(head1);
    reverseList(head2);
    return pre;


}

int main(){
    Node *node1 = new Node(9);
    Node *node2 = new Node(3);
    Node *node3 = new Node(7);
    Node *node4 = new Node(6);
    Node *node5 = new Node(3);
    node1->next = node2;
    node2->next = node3;
    node4->next = node5;
    Node *result = addList(node1,node4);
    return 0;
}