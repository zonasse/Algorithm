class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if(s.empty() || wordDict.empty()) return res;

        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        string temp = "";
        vector<bool> possible(s.size()+1,true);
        dfs(s,0,temp,res,wordSet,possible);
        return res;
    }
    void dfs(string s,int cur, string temp,vector<string> &res,unordered_set<string> &wordSet,vector<bool> &possible){
        if(cur == s.size()){
            res.push_back(temp.substr(0,temp.size()-1));
            return;
        }
        for(int i=cur; i<s.size(); ++i){
            string word = s.substr(cur,i-cur+1);
            if(wordSet.count(word) && possible[i+1]){
                temp += word + " ";
                int oldSize = res.size();
                dfs(s,i+1,temp,res,wordSet,possible);
                if(oldSize == res.size()) possible[i+1] = false;
                temp.resize(temp.size()-word.size()-1);
            }
        }
    }
};
