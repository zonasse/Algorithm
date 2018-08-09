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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > ret;
            if(!pRoot){
                return ret;
            }
            TreeNode *last = pRoot;
            TreeNode *nLast = NULL;
            queue<TreeNode*> Q;
            Q.push(pRoot);
            vector<int> currentLevelNodes;
            while(Q.empty() == false){
                TreeNode *node = Q.front();
                currentLevelNodes.push_back(node->val);
                Q.pop();
                if(node->left){
                    Q.push(node->left);
                    nLast = node->left;
                }
                if(node->right){
                    Q.push(node->right);
                    nLast = node->right;
                }
                if(node == last && Q.empty() == false){
                    last = nLast;
                    ret.push_back(currentLevelNodes);
                    currentLevelNodes.clear();
                }
            }
            if(currentLevelNodes.size() != 0){
                ret.push_back(currentLevelNodes);
            }
            return ret;
        }

};
