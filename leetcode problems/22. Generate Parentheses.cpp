class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n < 1){
            return ret;
        }
        string cur = "";
        dfs(ret,cur,0,0,n);
        return ret;
    }
    void dfs(vector<string> &ret,string cur,int leftNum,int rightNum,int n){
        if(leftNum < rightNum) return;
        if(leftNum > n || rightNum > n) return;
        if(leftNum == n && rightNum == n){
            ret.push_back(cur);
            return;
        }
        for(int i=1; i<=2; ++i){
            if(i == 1){
                dfs(ret,cur+'(',leftNum+1,rightNum,n);
            }else{
                dfs(ret,cur+')',leftNum,rightNum+1,n);
            }
        }
    }
};
