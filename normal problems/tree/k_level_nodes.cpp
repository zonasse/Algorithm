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
    //1.递归方式
    int k_level_nodes(tNode *root,int k){
        if(!root || k < 1){
            return 0;
        }
        if(k == 1){
            return 1;
        }
        int leftNum = k_level_nodes(root->left,k-1);
        int rightNum = k_level_nodes(root->right,k-1);
        return leftNum+rightNum;
    }
    //2.非递归方式
    int k_level_nodes_2(tNode *root,int k){
        if(!root){
            return 0;
        }
        int currentNodes = 1;
        int nextLevelNodes = 0;
        tNode *cur = root;
        queue<tNode*> Q;
        Q.push(cur);
        int currentLevel = 1;
        while(Q.empty() == false && currentLevel < k){
            cur = Q.front();
            Q.pop();
            currentNodes--;
            if(cur->left){
                nextLevelNodes++;
                Q.push(cur->left);
            }
            if(cur->right){
                nextLevelNodes++;
                Q.push(cur->right);
            }
            if(currentNodes == 0){
                currentLevel++;
                currentNodes = nextLevelNodes;
                nextLevelNodes = 0;
            }

        }
        return currentNodes;
    }
};

int main(){
    tNode *root = new tNode(1);
    root->left = new tNode(2);
    root->right = new tNode(3);
    Solution handle;
    printf("%d\n",handle.k_level_nodes_2(root,2));
    return 0;
}
