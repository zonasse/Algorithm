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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        vector<int> temp;
        queue<TreeNode*> Q;
        Q.push(root);
        TreeNode* last = root;
        TreeNode* nlast = NULL;
        while(!Q.empty()){
            root = Q.front();
            Q.pop();
            temp.push_back(root->val);
            if(root->left){
                nlast = root->left;
                Q.push(root->left);
            }
            if(root->right){
                nlast = root->right;
                Q.push(root->right);
            }
            if(root == last){
                last = nlast;
                res.insert(res.begin(),temp);
                temp.clear();
            }
        }
        return res;
    }
};
