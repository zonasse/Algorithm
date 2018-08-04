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
    int full_tree_node_count(tNode *root){
        if(!root){
            return 0;
        }
        //左子树高度
        int leftHigh = 0;
        tNode* node = root->left;
        while(node){
            leftHigh++;
            node = node->left;
        }
        //右子树高度
        int rightHigh = 0;
        node = root->right;
        while(node){
            rightHigh++;
            node = node->left;
        }
        if(leftHigh == rightHigh){
            //左子树为满二叉树
            return 1 + pow(2,leftHigh) - 1 + full_tree_node_count(root->right);
        }else{
            //右子树为满二叉树
            return 1 + pow(2,rightHigh) - 1 + full_tree_node_count(root->left);
        }

    }


};
int main(){
    tNode *n1 = new tNode(1);
    tNode *n2 = new tNode(2);
    tNode *n3 = new tNode(3);
    tNode *n4 = new tNode(4);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = new tNode(5);
    n3->left = new tNode(6);
    Solution handle;
    printf("%d\n",handle.full_tree_node_count(n1));
    return 0;
}
