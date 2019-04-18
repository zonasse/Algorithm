//
// Created by 钟奇龙 on 2019-04-18.
//

#include <iostream>
#include <stack>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):data(x),left(NULL),right(NULL){

    }
};

void preorderWithNoRecur(TreeNode *root){
    if(root){
        stack<TreeNode *> node_stack;
        node_stack.push(root);
        while(node_stack.empty() == false){
            TreeNode *cur = node_stack.top();
            node_stack.pop();
            cout<<cur->data<<endl;
            if(cur->right){
                node_stack.push(cur->right);
            }
            if(cur->left){
                node_stack.push(cur->left);
            }
        }
    }
}

void inorderWithNoRecur(TreeNode *root){
    if(root){
        stack<TreeNode*> node_stack;
        while(node_stack.empty() == false || root){
            if(root){
                node_stack.push(root);
                root = root->left;
            }else{
                root = node_stack.top();
                node_stack.pop();
                cout<<root->data<<endl;
                root = root->right;
            }
        }
    }
}

void posorderWithNoRecur(TreeNode *root){
    if(root){
        stack<TreeNode *> node_stack1;
        stack<TreeNode *> node_stack2;
        node_stack1.push(root);
        while(node_stack1.empty() == false){
            root = node_stack1.top();
            node_stack1.pop();
            node_stack2.push(root);
            if(root->left){
                node_stack1.push(root->left);
            }
            if(root->right){
                node_stack1.push(root->right);
            }
        }
        while(node_stack2.empty() == false){
            cout<<node_stack2.top()->data<<endl;
            node_stack2.pop();
        }
    }
}

//int main(){
//    TreeNode *node1 = new TreeNode(1);
//    TreeNode *node2 = new TreeNode(2);
//    TreeNode *node3 = new TreeNode(3);
//    TreeNode *node4 = new TreeNode(4);
//    TreeNode *node5 = new TreeNode(5);
//    node1->left = node2;
//    node1->right = node3;
//    node2->left = node4;
//    node2->right = node5;
//    posorderWithNoRecur(node1);
//
//    return 0;
//}