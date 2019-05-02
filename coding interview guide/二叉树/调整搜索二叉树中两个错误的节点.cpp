//
// Created by 钟奇龙 on 2019-05-02.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};
vector<Node*> getTwoErrorNodes(Node *root){
    vector<Node*> errors(2);
    if(!root) return errors;
    stack<Node*> node_stack;
    Node *pre = NULL;
    while(node_stack.empty() == false || root){
        if(root){
            node_stack.push(root);
            root = root->left;
        }else{
            root = node_stack.top();
            node_stack.pop();
            if(pre && pre->data > root->data){
                errors[0] = errors[0] == NULL ? pre : errors[0];
                errors[1] = root;
            }
            pre = root;
            root = root->right;
        }
    }
    return errors;
}
int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    node5->left = node1;
    node5->right = node3;
    node4->left = node5;
    node4->right = node2;
    vector<Node*> errors = getTwoErrorNodes(node4);
    return 0;
}