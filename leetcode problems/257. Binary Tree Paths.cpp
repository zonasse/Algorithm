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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        string temp = "";
        dfs(root,temp,res);
        return res;
    }
    void dfs(TreeNode *root,string temp,vector<string> &res){
        if(!root->left && !root->right){
            temp += to_string(root->val);
            res.push_back(temp);
            return;
        }
        temp += to_string(root->val) + "->";
        if(root->left){
            dfs(root->left,temp,res);
        }
        if(root->right){
            dfs(root->right,temp,res);
        }
    }
};
