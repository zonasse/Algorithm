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
    TreeNode *pre;
    TreeNode *first;
    TreeNode *second;
    void recoverTree(TreeNode* root) {
        pre = NULL;
        first = NULL;
        second = NULL;
        inorder(root);
        if(first && second) swap(first->val,second->val);
    }
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        if(!pre){
            pre = root;
        }else{
            if(root->val < pre->val){
                if(!first) first = pre;
                second = root;
            }
            pre = root;
        }
        inorder(root->right);
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
    void recoverTree(TreeNode* root) {
        /*
         * morrisÖÐÐò±éÀú
         */
        if(!root) return;

        TreeNode *first = NULL,*second = NULL,*parent = NULL;

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
                    if(parent->val > cur1->val){
                        if(!first) first = parent;
                        second = cur1;
                    }
                    parent = cur1;
                }
            }

            if(parent && parent->val > cur1->val){
                if(!first)  first = parent;
                second = cur1;
            }
            parent = cur1;
            cur1 = cur1->right;
        }


        if(first && second) swap(first->val,second->val);
    }
};
