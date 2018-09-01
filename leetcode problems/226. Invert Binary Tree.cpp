/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode *temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        swap(root->left,root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};
