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

    void Mirror1(TreeNode *pRoot) {
        if(!pRoot){
            return;
        }
        queue<TreeNode*> Q;
        Q.push(pRoot);
        while(!Q.empty()){
            TreeNode *cur = Q.front();
            Q.pop();
            TreeNode *temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            if(cur->left){
                Q.push(cur->left);
            }
            if(cur->right){
                Q.push(cur->right);
            }
        }
    }
    void Mirror2(TreeNode *pRoot) {
        if(!pRoot || (!pRoot->left && !pRoot->right)){
            return;
        }
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror2(pRoot->left);
        Mirror2(pRoot->right);
    }
};
