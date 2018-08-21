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
    TreeNode *pre;
    TreeNode *first;
    TreeNode *second;
    void recoverTree(TreeNode* root) {
        pre = NULL;
        first = NULL;
        second = NULL;
        inorder(root);
        if(first && second) swap(first->val,second->val);
    }
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        if(!pre){
            pre = root;
        }else{
            if(root->val < pre->val){
                if(!first) first = pre;
                second = root;
            }
            pre = root;
        }
        inorder(root->right);
    }
};
