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
    TreeNode* Convert(TreeNode* root)
    {
        if(!root){
            return root;
        }
        stack<TreeNode*> node_stack;
        TreeNode *cur = root;
        TreeNode *old = NULL;
        TreeNode *head = NULL;
        while(true){
            while(cur){
                node_stack.push(cur);
                cur = cur->left;
            }
            if(node_stack.empty()){
                break;
            }
            //此时无左孩子，输出栈顶元素
            cur = node_stack.top();
            node_stack.pop();
            if(old){
                old->right = cur;
                cur->left = old;
            }
            if(!head){
                head = cur;
            }
            old = cur;
            cur = cur->right;
        }
        return head;
    }
};
