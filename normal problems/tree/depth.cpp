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
    //递归方式
    int depth1(tNode *root){
        if(!root){
            return 0;
        }
        else return 1 + max(depth1(root->left),depth1(root->right));

    }
    //非递归方式
    int depth2(tNode *root){
        int depth = 0;
        queue<tNode*> Q;
        Q.push(root);
        int currentNodes = 1;
        int nextLevelNodes = 0;
        while(Q.empty() == false){
            tNode *node = Q.front();
            Q.pop();
            currentNodes--;
            if(node->left){
                Q.push(node->left);
                nextLevelNodes++;
            }
            if(node->right){
                Q.push(node->right);
                nextLevelNodes++;
            }
            if(currentNodes == 0){
                depth++;
                currentNodes = nextLevelNodes;
                nextLevelNodes = 0;
            }
        }
        return depth;
    }

};

int main(){
    tNode *root = new tNode(1);
    root->left = new tNode(2);
    root->right = new tNode(3);
    Solution handle;
    printf("%d\n",handle.depth2(root));
    return 0;
}
