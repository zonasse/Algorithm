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
        TreeNode *currentNode = pRoot;
        deque<TreeNode *> Q;
        Q.push_back(currentNode);
        TreeNode *last = pRoot;
        TreeNode *nLast = NULL;
        vector<int> currentLevelNodes;
        bool left_to_right = true;
        while(Q.empty() == false){
            if(left_to_right){
                currentNode = Q.front();
                Q.pop_front();
                currentLevelNodes.push_back(currentNode->val);
                if(currentNode->left){
                    Q.push_back(currentNode->left);
                    nLast = nLast == NULL? currentNode->left : nLast;
                }
                if(currentNode->right){
                    Q.push_back(currentNode->right);
                    nLast = nLast == NULL? currentNode->right: nLast;
                }
            }else{
                currentNode = Q.back();
                Q.pop_back();
                currentLevelNodes.push_back(currentNode->val);
                if(currentNode->right){
                    Q.push_front(currentNode->right);;
                    nLast = nLast == NULL ? currentNode->right:nLast;
                }
                if(currentNode->left){
                    Q.push_front(currentNode->left);
                    nLast = nLast == NULL ? currentNode->left:nLast;
                }
            }
            if(currentNode == last && Q.empty() == false){
                last = nLast;
                nLast = NULL;
                ret.push_back(currentLevelNodes);
                currentLevelNodes.clear();
                left_to_right = !left_to_right;
            }
        }
        if(currentLevelNodes.size() > 0){
            ret.push_back(currentLevelNodes);
        }
        return ret;
    }

};
