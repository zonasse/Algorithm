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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return count(root,1,mostLeftLevel(root,1));
    }
    int count(TreeNode *root,int curLevel,int height){
        if(curLevel == height) return 1;
        if(mostLeftLevel(root->right,curLevel+1) == height){
            return (1<<(height-curLevel)) + count(root->right,curLevel+1,height);
        }else{
            return (1<<(height-curLevel-1)) + count(root->left,curLevel+1,height);
        }
    }

    int mostLeftLevel(TreeNode *root,int level){
        while(root){
            level++;
            root = root->left;
        }
        return level-1;
    }
};
