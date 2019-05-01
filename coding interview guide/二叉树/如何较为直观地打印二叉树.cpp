//
// Created by 钟奇龙 on 2019-05-01.
//
#include <iostream>
#include <string>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};
string getspace(int length){
    string res = "";
    for(int i=0; i<length; ++i){
        res += " ";
    }
    return res;
}
void printspace(int length){
    for(int i=0; i<length; ++i){
        cout<<" ";
    }
}
void printInOrder(Node *root,int level,string to,int length){
    if(!root) return;
    //打印右子树
    printInOrder(root->right,level+1,"v",length);
    //拼装字符串并打印当前字符
    string str = to + to_string(root->data) + to;
    int leftLen = (length - str.size()) / 2;
    int rightLen = length - leftLen - str.size();
    str = getspace(leftLen) + str + getspace(rightLen);
    printspace(level*length);
    cout<<str<<endl;
    //打印左子树
    printInOrder(root->left,level+1,"^",length);
}
void printTree(Node *root){
    cout<<"print tree:"<<endl;
    printInOrder(root,0,"H",17);
    cout<<endl;
}

int main(){
//    Node *node1 = new Node(1);
//    Node *node2 = new Node(2);
//    Node *node3 = new Node(3);
//    Node *node4 = new Node(4);
//    Node *node5 = new Node(5);
//    Node *node6 = new Node(6);
//    Node *node7 = new Node(7);
//
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    node3->left = node6;
//    node5->right = node7;
//    printTree(node1);
    return 0;
}

