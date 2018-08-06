/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ret;
        if(!root){
            return ret;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while(Q.empty() == false){
            TreeNode *cur = Q.front();
            Q.pop();
            ret.push_back(cur->val);
            if(cur->left){
                Q.push(cur->left);
            }
            if(cur->right){
                Q.push(cur->right);
            }
        }
        return ret;
    }
};
