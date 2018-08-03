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
    bool judge_full_tree(tNode *root){
        if(!root){
            return true;
        }
        if(judge_full_tree(root->left) && judge_full_tree(root->right) && depth(root->left) == depth(root->right)){
            return true;
        }
        return false;
    }
    int depth(tNode *root){
        if(!root){
            return 0;
        }
        return max(depth(root->left),depth(root->right)) + 1;

    }



};

int main(){
    tNode *n1 = new tNode(1);
    tNode *n2 = new tNode(2);
    tNode *n3 = new tNode(3);
    tNode *n4 = new tNode(4);

    n1->left = n2;
    n1->right = n3;
    //n2->left = n4;
    //n2->right = new tNode(5);
    Solution handle;
    printf("%d\n",handle.judge_full_tree(n1));
    return 0;
}
