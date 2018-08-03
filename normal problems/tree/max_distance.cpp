#include <bits/stdc++.h>
using namespace std;

struct tNode{
    int data;
    tNode *left;
    tNode *right;
    tNode(int x):data(x),left(NULL),right(NULL){}
};

struct result{
    int maxDepth;
    int maxDistance;
    result():maxDepth(0),maxDistance(0){}
};

class Solution{
public:
    result* get_max_distance(tNode *root){
        if(!root){
            result *res = new result();
            return res;
        }
        result *lmd = get_max_distance(root->left);
        result *rmd = get_max_distance(root->right);
        result *res = new result();
        res->maxDepth = max(lmd->maxDepth,rmd->maxDepth) + 1;
        res->maxDistance = max(lmd->maxDepth+rmd->maxDepth,max(lmd->maxDistance,rmd->maxDistance));
        return res;
    }


};
int main(){
    tNode *root = new tNode(1);
    root->left = new tNode(2);
    root->right = new tNode(3);
    root->right->right = new tNode(4);
    root->left->right = new tNode(5);
    Solution handle;
    printf("%d\n",handle.get_max_distance(root)->maxDistance);
    return 0;
}

