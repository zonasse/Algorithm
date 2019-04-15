//
// Created by 钟奇龙 on 2019-04-15.
//

#include <iostream>
#include <stack>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int x):data(x),next(NULL){

    }
};

bool isPalindrome(Node *head){
    stack<Node*> s;
    Node *cur = head;
    while(cur){
        s.push(cur);
        cur = cur->next;
    }
    while(head){
        if(head->data != s.top()->data){
            return false;
        }
        head = head->next;
        s.pop();
    }
    return true;
}