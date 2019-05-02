//
// Created by 钟奇龙 on 2019-05-02.
//
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};

void printByLevel(Node *root){
    if(!root) return;
    int level = 1;
    queue<Node*> node_queue;
    node_queue.push(root);
    Node *last = root;
    Node *nlast = NULL;
    cout<<"level "<<level++<<": ";
    while(node_queue.empty() == false){
        Node *cur = node_queue.front();
        node_queue.pop();
        cout<<cur->data<<" ";
        if(cur->left){
            node_queue.push(cur->left);
            nlast = cur->left;
        }
        if(cur->right){
            node_queue.push(cur->right);
            nlast = cur->right;
        }
        if(cur == last && node_queue.empty() == false){
            cout<<"\nlevel "<<level++<<": ";
            last = nlast;
        }
    }
}
void printLevelAndOrientation(int level,bool ltor){
    cout<<"\nlevel "<<level<<" "<<(ltor? "from left to right":"from right to left")<<" : ";
}
void printZigzag(Node *root){
    if(!root) return;
    deque<Node*> node_deque;
    bool ltor = true;
    Node *last = root;
    Node *nlast = NULL;
    node_deque.push_back(root);
    int level = 1;
    printLevelAndOrientation(level++,ltor);
    while(node_deque.empty() == false){
        Node *cur = NULL;
        if(ltor){
            cur = node_deque.front();
            node_deque.pop_front();
            cout<<cur->data<<" ";
            if(cur->left){
                nlast = nlast == NULL ? cur->left : nlast;
                node_deque.push_back(cur->left);
            }
            if(cur->right){
                nlast = nlast == NULL ? cur->right : nlast;
                node_deque.push_back(cur->right);
            }
        }else{
            cur = node_deque.back();
            node_deque.pop_back();
            cout<<cur->data<<" ";
            if(cur->right){
                nlast = nlast == NULL ? cur->right : nlast;
                node_deque.push_front(cur->right);
            }
            if(cur->left){
                nlast = nlast == NULL ? cur->left : nlast;
                node_deque.push_front(cur->left);
            }
        }
        if(cur == last && node_deque.empty() == false){
            last = nlast;
            nlast = NULL;
            ltor = !ltor;
            printLevelAndOrientation(level++,ltor);
        }
    }
}

int main(){

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node5->right = node7;
    node5->left = node8;

//    printByLevel(node1);
    printZigzag(node1);
    return 0;
}