//
// Created by 钟奇龙 on 2019-05-01.
//
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};

void morrisIn(Node *root){
    if(!root) return;
    Node *node1 = root;
    Node *node2 = NULL;
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
        cout<<node1->data<<" ";
        node1 = node1->right;
    }
    cout<<endl;
}

void morrisPre(Node *root){
    if(!root) return;
    Node *node1 = root;
    Node *node2 = NULL;
    while(node1){
        node2 = node1->left;
        if(node2){
            while(node2->right && node2->right != node1){
                node2 = node2->right;
            }
            if(node2->right == NULL){
                node2->right = node1;
                cout<<node1->data<<" ";
                node1 = node1->left;
                continue;
            }else{
                node2->right = NULL;
            }
        }else{
            cout<<node1->data<<" ";
        }
        node1 = node1->right;
    }
    cout<<endl;
}
int main(){

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node5->right = node7;
    morrisPre(node1);

    return 0;
}