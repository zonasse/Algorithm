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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        travel(root,res);
        return res;
    }
    int travel(TreeNode *root,int &res){
        if(!root){
            return 0;
        }
        int leftMax = max(travel(root->left,res),0);
        int rightMax = max(travel(root->right,res),0);
        res = max(res,leftMax+rightMax+root->val);
        return root->val + max(leftMax,rightMax);

    }
};
