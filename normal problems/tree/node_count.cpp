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
    int node_count(tNode *root){
        if(root == NULL){
            return 0;
        }
        return 1 + node_count(root->left) + node_count(root->right);

    }
};

int main(){
    tNode *root = new tNode(1);
    root->left = new tNode(2);
    root->right = new tNode(3);
    Solution handle;
    printf("%d\n",handle.node_count(root));
    return 0;
}
