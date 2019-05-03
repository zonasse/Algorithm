//
// Created by 钟奇龙 on 2019-05-03.
//
#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};

bool isBST(Node *root){
    if(!root) return true;
    Node *node1 = root;
    Node *node2 = NULL;
    Node *pre = NULL;
    bool res = true;
    while(node1){
        node2 = node1->left;
        if(node2){
            while(node2->right && node2->right != node1){
                node2 = node2->right;
            }
            if(node2->right == NULL){
                node2->right = node1;
                node1 = node1->left;
                continue;
            }else{
                node2->right = NULL;
            }
        }
        if(pre && pre->data > node1->data){
            res = false;
        }
        pre = node1;
        node1 = node1->right;
    }
    return res;
}

bool isCBT(Node *root){
    if(!root) return true;
    queue<Node*> node_queue;
    bool leaf = false;
    node_queue.push(root);
    while(node_queue.empty() == false){
        Node *cur = node_queue.front();
        node_queue.pop();
        Node *left = cur->left;
        Node *right = cur->right;
        if((leaf && (left || right)) || (!left && right)){
            return false;
        }
        if(left){
            node_queue.push(left);
        }
        if(right){
            node_queue.push(right);
        }else{
            leaf = true;
        }

    }
    return true;
}

int main(){

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);

    node4->left = node2;
    node4->right = node5;
//    node2->left = node1;
    node2->right = node3;

    cout<<isBST(node4)<<endl;
    cout<<isCBT(node4)<<endl;

    return 0;
}