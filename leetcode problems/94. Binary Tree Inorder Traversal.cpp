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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> node_stack;
        while(node_stack.empty() == false || root){
            if(root){
                node_stack.push(root);
                root = root->left;
            }else{
                root = node_stack.top();
                node_stack.pop();
                res.push_back(root->val);
                root = root->right;
            }

        }
        return res;
    }
};
