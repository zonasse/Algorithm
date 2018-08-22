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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(!root) return res;
        vector<int> temp;
        deque<TreeNode*> Q;
        Q.push_back(root);
        TreeNode *last = root;
        TreeNode *nlast = NULL;
        bool leftToRight = true;
        while(!Q.empty()){
            if(leftToRight){
                root = Q.front();
                Q.pop_front();
                temp.push_back(root->val);
                if(root->left){
                    nlast = nlast == NULL ? root->left:nlast;
                    Q.push_back(root->left);
                }
                if(root->right){
                    nlast = nlast == NULL ? root->right:nlast;
                    Q.push_back(root->right);
                }
            }else{
                root = Q.back();
                Q.pop_back();
                temp.push_back(root->val);
                if(root->right){
                    nlast = nlast == NULL ? root->right:nlast;
                    Q.push_front(root->right);
                }
                if(root->left){
                    nlast = nlast == NULL ? root->left:nlast;
                    Q.push_front(root->left);
                }
            }
            if(root == last){
                leftToRight = !leftToRight;
                res.push_back(temp);
                temp.clear();
                last = nlast;
                nlast = NULL;
            }
        }
        return res;
    }
};
