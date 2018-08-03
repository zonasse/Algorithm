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
    //方法1 破坏原树(递归方法)
    tNode* mirror(tNode *root){
        if(!root){
            return root;
        }
        tNode *left = mirror(root->left);
        tNode *right = mirror(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    //方法1 破坏原树(非递归方法)
    tNode* mirror2(tNode *root){
        if(!root){
            return root;
        }
        stack<tNode*> node_stack;
        node_stack.push(root);
        while(!node_stack.empty()){
            tNode *cur = node_stack.top();
            node_stack.pop();
            tNode *temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            if(cur->right){
                node_stack.push(cur->right);
            }
            if(cur->left){
                node_stack.push(cur->left);
            }
        }
        return root;
    }

    //2.不破坏原树，返回新的镜像(递归)
    tNode* mirrorCopy(tNode *root){
        if(!root){
            return root;
        }
        tNode *newNode = new tNode(root->data);
        newNode->right = mirrorCopy(root->left);
        newNode->left = mirrorCopy(root->right);
        return newNode;
    }
    //2.不破坏原树，返回新的镜像(非递归)
        tNode* mirrorCopy2(tNode *root){
            if(!root){
                return root;
            }
            tNode *newRoot = new tNode(root->data);
            stack<tNode*> node_stack;
            stack<tNode*> node_stack_copy;
            node_stack.push(root);
            node_stack_copy.push(newRoot);
            while(node_stack.empty() == false){
                tNode *cur = node_stack.top();
                node_stack.pop();
                tNode *cur_copy = node_stack_copy.top();
                node_stack_copy.pop();
                if(cur->right){
                    cur_copy->left = new tNode(cur->right->data);
                    node_stack.push(cur->right);
                    node_stack_copy.push(cur_copy->left);
                }
                if(cur->left){
                    cur_copy->right = new tNode(cur->left->data);
                    node_stack.push(cur->left);
                    node_stack_copy.push(cur_copy->right);
                }
            }
            return newRoot;
        }

    //3.判断两棵树是否相互镜像
    bool judge_mirror(tNode *root1,tNode *root2){
        if(!root1 && !root2){
            return true;
        }
        if(!root1 || !root2){
            return false;
        }
        if(root1->data != root2->data){
            return false;
        }
        return judge_mirror(root1->left,root2->right) && judge_mirror(root1->right,root2->left);
    }

};
int main(){

    return 0;
}
