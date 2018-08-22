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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return hasPath(root,0,sum);
    }
    bool hasPath(TreeNode* root,int cur,int sum){
        if(!root) return false;
        cur+=root->val;
        if(!root->left && !root->right) return cur == sum;
        return hasPath(root->left,cur,sum) || hasPath(root->right,cur,sum);
    }
};
