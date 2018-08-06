/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() || vin.empty()){
            return NULL;
        }
        TreeNode *root = build(pre,0,pre.size()-1,vin,0,vin.size()-1);
        return root;
    }
    TreeNode* build(vector<int> &pre,int preLeft,int preRight,vector<int> &vin,
                   int vinLeft,int vinRight){
        if(preLeft > preRight || vinLeft > vinRight){
            return NULL;
        }
        TreeNode *node = new TreeNode(pre[preLeft]);
        int idx;
        for(idx = vinLeft; idx <= vinRight; ++idx){
            if(vin[idx] == pre[preLeft]){
                break;
            }
        }
        int leftLen = idx-vinLeft;
        int rightLen = vinRight-idx;
        node->left = build(pre,preLeft+1,preLeft+leftLen,vin,vinLeft,idx-1);
        node->right = build(pre,preRight-rightLen+1,preRight,vin,idx+1,vinRight);
        return node;

    }
};
