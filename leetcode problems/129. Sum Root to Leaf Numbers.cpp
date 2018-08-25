/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<int> sum_vec;
        dfs(root,0,sum_vec);
        int ans = 0;
        for(int i=0; i<sum_vec.size(); ++i){
            ans += sum_vec[i];
        }
        return ans;
    }
    void dfs(TreeNode *root,int cur,vector<int> &sum_vec){
        cur = cur*10+root->val;
        if(!root->left && !root->right){
            sum_vec.push_back(cur);
            return;
        }
        if(root->left){
            dfs(root->left,cur,sum_vec);
        }
        if(root->right){
            dfs(root->right,cur,sum_vec);
        }
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
    int dfs(TreeNode *root,int sum){
        if(!root) return 0;
        sum = sum*10 + root->val;
        if(!root->left && !root->right) return sum;
        return dfs(root->left,sum) + dfs(root->right,sum);
    }
};
