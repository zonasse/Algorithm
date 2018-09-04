/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "#!";
        }
        string res = to_string(root->val) + "!";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        /*
         * ½«data°´!·Ö¸î
         */
        queue<string> Q;
        int start = 0;
        for(int i=0; i<data.size(); ++i){
            if(data[i] == '!'){
                Q.push(data.substr(start,i-start));
                start = i+1;
            }
        }
        return _deserialize(Q);
    }
    TreeNode *_deserialize(queue<string> &Q){
        if(Q.empty()){
            return NULL;
        }
        if(Q.front() == "#"){
            Q.pop();
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(Q.front()));
        Q.pop();
        root->left = _deserialize(Q);
        root->right = _deserialize(Q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
