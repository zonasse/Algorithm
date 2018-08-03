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
    //递归
    int leaf_count(tNode *root){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        return leaf_count(root->left) + leaf_count(root->right);
    }
    //非递归
    int leaf_count2(tNode *root){
        if(!root){
            return 0;
        }
        int leaf = 0;
        queue<tNode*> Q;
        Q.push(root);
        while(Q.empty() == false){
            root = Q.front();
            Q.pop();
            if(root->left){
                Q.push(root->left);
            }
            if(root->right){
                Q.push(root->right);
            }
            if(!root->left && !root->right){
                leaf++;
            }
        }
        return leaf;
    }

};

int main(){
    tNode *root = new tNode(1);
    root->left = new tNode(2);
    root->right = new tNode(3);
    Solution handle;
    printf("%d\n",handle.leaf_count2(root));
    return 0;
}
