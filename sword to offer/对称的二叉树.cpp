/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot){
            return true;
        }
        return compare(pRoot->left,pRoot->right);
    }
    bool compare(TreeNode *left,TreeNode *right){
        if(!left) return right == NULL;
        if(!right) return false;
        if(left->val != right->val){
            return false;
        }
        return compare(left->left,right->right) &&compare(left->right,right->left);
    }

};
