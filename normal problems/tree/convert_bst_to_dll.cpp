#include <bits/stdc++.h>
using namespace std;

struct tNode{
    int data;
    tNode *left;
    tNode *right;
    tNode(int x):data(x),left(NULL),right(NULL){}

};

class Solution{
public:
    //递归转换
    tNode* convert_bst_to_dll(tNode *root){
        root = sub_convert(root);
        while(root->left){
            root = root->left;
        }
        return root;
    }
    tNode* sub_convert(tNode* root){
        if(!root ||(!root->left && !root->right)){
            return root;
        }
        tNode *temp = NULL;
        if(root->left){
            temp = sub_convert(root->left);
            while(temp->right){
                temp = temp->right;
            }
            temp->right = root;
            root->left = temp;
        }
        if(root->right){
            temp = sub_convert(root->right);
            while(temp->left){
                temp = temp->left;
            }
            root->right = temp;
            temp->left = root;
        }
        return root;
    }
    //非递归转换
    tNode* convert2(tNode *root){
        if(!root){
            return root;
        }
        stack<tNode*> node_stack;
        tNode *cur = root;
        tNode *old = NULL;
        tNode *head = NULL;
        while(true){
            while(cur){
                node_stack.push(cur);
                cur = cur->left;
            }
            if(node_stack.empty()){
                break;
            }
            //此时无左孩子，输出栈顶元素
            cur = node_stack.top();
            node_stack.pop();
            if(old){
                old->right = cur;
                cur->left = old;
            }
            if(!head){
                head = cur;
            }
            old = cur;
            cur = cur->right;
        }
        return head;

    }
};

int main(){

    return 0;
}
