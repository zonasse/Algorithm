/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()||postorder.empty() || inorder.size() != postorder.size()){
            return NULL;
        }
        return rebuild(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* rebuild(vector<int> &inorder,int inL,int inR,vector<int> &postorder,int postL,int postR){
        if(inL > inR || postL > postR) return NULL;
        TreeNode *root = new TreeNode(postorder[postR]);
        int idx;
        for(idx=inL; idx<=inR; ++idx){
            if(inorder[idx] == postorder[postR]) break;
        }
        int leftLen = idx-inL;
        int rightLen = inR-idx;
        root->left = rebuild(inorder,inL,idx-1,postorder,postL,postL+leftLen-1);
        root->right = rebuild(inorder,idx+1,inR,postorder,postR-rightLen,postR-1);
        return root;
    }
};
