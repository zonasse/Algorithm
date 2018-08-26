class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if(s.empty()) return res;
        vector<string> temp;
        dfs(s,0,temp,res);
        return res;
    }
    void dfs(string s,int cur,vector<string> &temp,vector<vector<string> > &res){
        if(cur == s.size()){
            res.push_back(temp);
            return;
        }
        for(int i=cur; i<s.size(); ++i){
            if(isPalindrome(s,cur,i)){
                temp.push_back(s.substr(cur,i-cur+1));
                dfs(s,i+1,temp,res);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int left,int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};
