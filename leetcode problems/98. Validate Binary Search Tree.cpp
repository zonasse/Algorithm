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
    bool isValidBST(TreeNode* root) {
        /*
         * morrisÖĞĞò±éÀú
         */
        if(!root) return true;
        bool res = true;
        TreeNode *pre = NULL;
        TreeNode *cur1 = root;
        TreeNode *cur2 = NULL;
        while(cur1){
            cur2 = cur1->left;
            if(cur2){
                while(cur2->right && cur2->right != cur1){
                    cur2 = cur2->right;
                }
                if(!cur2->right){
                    cur2->right = cur1;
                    cur1 = cur1->left;
                    continue;
                }else{
                    cur2->right = NULL;
                }

            }
            if(pre && pre->val >= cur1->val){
                res = false;
            }
            pre = cur1;
            cur1 = cur1->right;
        }
        return res;
    }
};
