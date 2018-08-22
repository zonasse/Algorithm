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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        vector<int> temp;
        if(!root) return res;
        queue<TreeNode*> Q;
        Q.push(root);
        TreeNode *last = root;
        TreeNode *nlast = NULL;
        while(!Q.empty()){
            TreeNode *cur = Q.front();
            Q.pop();
            temp.push_back(cur->val);
            if(cur->left){
                Q.push(cur->left);
                nlast = cur->left;
            }
            if(cur->right){
                Q.push(cur->right);
                nlast = cur->right;
            }
            if(cur == last){
                res.push_back(temp);
                temp.clear();
                last = nlast;
            }
        }
        return res;
    }
};
