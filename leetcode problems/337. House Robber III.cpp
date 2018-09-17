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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> M;
        return dfs(root,M);
    }
    int dfs(TreeNode *root,unordered_map<TreeNode *,int> &M){
        if(!root) return 0;
        if(M.count(root)) return M[root];
        int val = 0;
        if(root->left){
            val += dfs(root->left->left,M) + dfs(root->left->right,M);
        }
        if(root->right){
            val += dfs(root->right->left,M) + dfs(root->right->right,M);
        }
        val = max(val + root->val,dfs(root->left,M)+dfs(root->right,M));
        M[root] = val;
        return val;
    }
};
