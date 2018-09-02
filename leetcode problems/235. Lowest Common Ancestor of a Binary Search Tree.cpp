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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || (!p && !q)) return root;
        if(!p || !q) return !p ? q:p;
        if(p->val > q->val) swap(p,q);
        TreeNode *temp = root;
        while(temp && !(temp->val >= p->val && temp->val <= q->val)){
            if(temp->val > q->val){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        return temp;
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode *leftAncestor = lowestCommonAncestor(root->left,p,q);
        TreeNode *rightAncestor = lowestCommonAncestor(root->right,p,q);
        if(leftAncestor && rightAncestor) return root;
        return leftAncestor ? leftAncestor : rightAncestor;
    }
};
