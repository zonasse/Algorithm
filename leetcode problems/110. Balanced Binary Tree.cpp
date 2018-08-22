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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if(abs(leftHeight-rightHeight) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getHeight(TreeNode *root){
        if(!root) return 0;
        int leftHeight = getHeight(root->left) + 1;
        int rightHeight = getHeight(root->right) + 1;
        return max(leftHeight,rightHeight);
    }
};
