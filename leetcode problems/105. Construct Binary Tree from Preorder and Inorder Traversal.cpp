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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) return NULL;
        return rebuild(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* rebuild(vector<int> &preorder,int preL,int preR,vector<int> &inorder,int inL,int inR){
        if(preL > preR || inL > inR) return NULL;
        TreeNode *root = new TreeNode(preorder[preL]);
        int idx;
        for(idx=inL; idx<=inR; ++idx){
            if(inorder[idx] == preorder[preL]) break;
        }
        int leftLen = idx-inL;
        int rightLen = inR-idx;
        root->left = rebuild(preorder,preL+1,preL+leftLen,inorder,inL,idx-1);
        root->right = rebuild(preorder,preR-rightLen+1,preR,inorder,idx+1,inR);
        return root;
    }
};
