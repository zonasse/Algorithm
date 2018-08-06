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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > ret;
        if(!root || root->val > expectNumber){
            return ret;
        }
        vector<int> path;
        find(root,0,expectNumber,path,ret);
        return ret;
    }
    void find(TreeNode* root,int cur,int target,vector<int> &path,vector<vector<int> > &ret){
        cur += root->val;
        path.push_back(root->val);
        if(cur == target && !root->left && !root->right){
            ret.push_back(path);
        }
        if(root->left){
            find(root->left,cur,target,path,ret);
        }
        if(root->right){
            find(root->right,cur,target,path,ret);
        }
        path.pop_back();
        cur -= root->val;

    }
};
