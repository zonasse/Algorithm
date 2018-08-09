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
    char* Serialize(TreeNode *root) {
        if(!root){
            return NULL;
        }
        string str;
        _serialize(root,str);
        char *ret = new char[str.size() + 1];
        for(int i=0; i<str.size(); ++i){
            ret[i] = str[i];
        }
        ret[str.size()] = '\0';
        return ret;
    }
    TreeNode* Deserialize(char *str) {
        if(str == NULL){
            return NULL;
        }
        string s(str);
        //按！将s分割
        vector<string> string_vec;
        int start = 0;
        string subStr;
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '!'){
                subStr = s.substr(start,i-start);
                string_vec.push_back(subStr);
                start = i+1;
            }
        }
        //进行反序列化
        queue<string> Q;
        for(int i=0; i<string_vec.size(); ++i){
            Q.push(string_vec[i]);
        }
        return _deSerialize(Q);

    }
private:
    void _serialize(TreeNode *root,string &str){
        if(!root){
            str += "#!";
            return;
        }
        string temp = to_string(root->val);
        str += temp + "!";
        _serialize(root->left,str);
        _serialize(root->right,str);
    }
    TreeNode* _deSerialize(queue<string> &Q){
        if(Q.empty()){
            return NULL;
        }
        string cur = Q.front();
        Q.pop();
        if(cur == "#"){
            return NULL;
        }
        TreeNode *node = new TreeNode(atoi(cur.c_str()));
        node->left = _deSerialize(Q);
        node->right = _deSerialize(Q);
        return node;
    }
};
