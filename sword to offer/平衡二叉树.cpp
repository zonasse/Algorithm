class Solution {
public:

    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot){
            return true;
        }
        int depth = 0;
        return balanced(pRoot,depth);
    }
    //后序遍历方法，减少重复访问
    bool balanced(TreeNode *root,int &depth){
        if(!root){
            depth = 0;
            return true;
        }
        int leftDepth = 0;
        int rightDepth = 0;
        if(balanced(root->left,leftDepth) && balanced(root->right,rightDepth)){
            if(abs(leftDepth-rightDepth) < 2){
                depth = (leftDepth > rightDepth?leftDepth:rightDepth)+1;
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};
