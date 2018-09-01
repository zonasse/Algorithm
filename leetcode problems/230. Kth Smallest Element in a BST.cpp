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
    int kthSmallest(TreeNode* root, int k) {
        /*
         * 非递归实现二叉树中序遍历
         */
        stack<TreeNode *> node_stack;
        TreeNode *p = root;
        int cn = 0;
        while(p || !node_stack.empty()){
            if(p){
                node_stack.push(p);
                p = p->left;
            }else{
                p = node_stack.top();
                node_stack.pop();
                cn++;
                if(cn == k) return p->val;
                p = p->right;
            }
        }
        return 0;
    }
};
