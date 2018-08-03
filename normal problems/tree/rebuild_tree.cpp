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
    //由先序遍历和中序遍历序列重建二叉树
    tNode* rebuild_tree(vector<int> &preorder,vector<int> &inorder){
        if(inorder.empty() || preorder.empty()){
            return NULL;
        }
        tNode *ret = rebuild(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return ret;
    }
    tNode* rebuild(vector<int> &preorder,int preLeft,int preRight,
                   vector<int> &inorder,int inLeft,int inRight){
        if(preLeft > preRight || inLeft > inRight){
            return NULL;
        }
        tNode *newRoot = new tNode(preorder[preLeft]);
        int idx;
        for(idx = inLeft; idx <= inRight; ++idx){
            if(preorder[preLeft] == inorder[idx]){
                break;
            }
        }
        int leftLen = idx-inLeft;
        int rightLen = inRight-idx;
        newRoot->left = rebuild(preorder,preLeft+1,preLeft+leftLen,inorder,inLeft,idx-1);
        newRoot->right = rebuild(preorder,preRight-rightLen+1,preRight,inorder,idx+1,inRight);
        return newRoot;
    }
    //对结果进行后序遍历
    void postTravel(tNode *root){
        if(!root){
            return;
        }
        postTravel(root->left);
        postTravel(root->right);
        printf("%d ",root->data);
    }

};

int main(){
    Solution handle;
    int preorder[] = {1,2,4,5,6,3,7};
    int inorder[] = {4,2,5,6,1,3,7};

    vector<int> pre_vec(preorder,preorder+7);
    vector<int> in_vec(inorder,inorder+7);

    tNode *root = handle.rebuild_tree(pre_vec,in_vec);
    handle.postTravel(root);

    return 0;
}
