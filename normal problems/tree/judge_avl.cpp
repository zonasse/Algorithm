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
    bool judge_avl(tNode *root){
        if(!root){
            return false;
        }
        if(abs(depth(root->left) - depth(root->right)) > 1){
            return false;
        }
        return judge_avl(root->left) && judge_avl(root->right);
    }
    int depth(tNode *root){
        if(!root){
            return 0;
        }
        return 1 + max(depth(root->left),depth(root->right));
    }

private:
    int abs(int x){
        return x>0? x:-x;
    }

};

int main(){


    return 0;
}
