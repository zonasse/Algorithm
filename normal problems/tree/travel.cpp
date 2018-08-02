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
    //1.先序遍历（递归）
    void preOrder1(tNode *root){
        if(!root){
            return;
        }
        printf("%d ",root->data);
        preOrder1(root->left);
        preOrder1(root->right);
    }
    //2.先序遍历（非递归）
    void preOrder2(tNode *root){
        if(!root){
            return;
        }
        stack<tNode*> node_stack;
        node_stack.push(root);
        while(node_stack.empty() == false){
            tNode *node = node_stack.top();
            node_stack.pop();
            printf("%d\n",node->data);
            if(node->right){
                node_stack.push(node->right);
            }
            if(node->left){
                node_stack.push(node->left);
            }
        }

    }
    //3.中序遍历（递归）
    void inOrder1(tNode *root){
        if(!root){
            return;
        }
        inOrder1(root->left);
        printf("%d\n",root->data);
        inOrder1(root->right);
    }
    //4.中序遍历（非递归）
    void inOrder2(tNode *root){
        if(!root){
            return;
        }
        stack<tNode*> node_stack;
        tNode *cur = root;
        while(true){
            while(cur){
                node_stack.push(cur);
                cur = cur->left;
            }
            if(node_stack.empty()){
                break;
            }
            cur = node_stack.top();
            printf("%d ",cur->data);
            node_stack.pop();
            cur = cur->right;
        }

    }
    //5.后序遍历（递归）
    void postOrder1(tNode *root){
        if(!root){
            return;
        }
        postOrder1(root->left);
        postOrder1(root->right);
        printf("%d ",root->data);
    }
    //6.后序遍历（非递归）
    void postOrder2(tNode *root){
        if(!root){
            return;
        }
        stack<tNode*> node_stack;
        stack<tNode*> output;
        tNode *cur = root;
        node_stack.push(cur);
        while(node_stack.empty() == false){
            cur = node_stack.top();
            output.push(cur);
            if(cur->left){
                node_stack.push(cur->left);
            }
            if(cur->right){
                node_stack.push(cur->right);
            }
        }
        while(!output.empty()){
            printf("%d ",output.top());
            output.pop();
        }
    }
    //7.层次遍历非递归
    void levelOrder1(tNode *root){
        if(!root){
            return;
        }
        queue<tNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            tNode *node = Q.front();
            Q.pop();
            printf("%d ",node->data);
            if(node->left){
                Q.push(node->left);
            }
            if(node->right){
                Q.push(node->right);
            }
        }
    }
    //8.层次遍历递归
    void levelOrder2(tNode *root){
        if(!root){
            return;
        }
        vector<vector<int> > ret;
        vector<int> temp;
        ret.push_back(temp);
        dfs(root,0,ret);
        //打印ret
        for(int i=0; i<ret.size(); ++i){
            for(int j=0; j<ret[i].size(); ++j){
                printf("%d ",ret[i][j]);
            }
            printf("\n");
        }
    }
    void dfs(tNode *root,int level,vector<vector<int> > &ret){
        if(!root){
            return;
        }
        if(level >= ret.size()){
            vector<int> temp;
            ret.push_back(temp);
        }
        ret[level].push_back(root->data);
        dfs(root->left,level+1,ret);
        dfs(root->right,level+1,ret);
    }
};

int main(){
    tNode *root = new tNode(1);
    root->left = new tNode(2);
    root->right = new tNode(3);
    Solution handle;
    handle.levelOrder2(root);
    return 0;
}
