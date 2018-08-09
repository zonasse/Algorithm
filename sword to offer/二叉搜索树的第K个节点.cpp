
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
class Solution1 {
public:
    int count;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot){
            return NULL;
        }
        count = 0;
        TreeNode *ret = NULL;
        inorder(pRoot,ret,k);
        return ret;
    }
    void inorder(TreeNode *root,TreeNode *&ret,int k){
        if(!root){
            return ;
        }
        inorder(root->left,ret,k);
        if(++count == k){
            ret = root;
            return;
        }
        inorder(root->right,ret,k);

    }

};
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
class Solution2 {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        //进行中序遍历，记录当前节点编号
        if(!pRoot){
            return NULL;
        }
        vector<TreeNode*> vec;
        inOrder(pRoot,vec,k);
        if(vec.empty() || vec.size() < k){
            return NULL;
        }
        return vec[vec.size()-1];
    }
    void inOrder(TreeNode *root,vector<TreeNode*> &vec,int k){
        if(!root){
            return;
        }
        inOrder(root->left,vec,k);
        if(vec.size() < k){
            vec.push_back(root);
        }else{
            return;
        }
        inOrder(root->right,vec,k);
    }


};
