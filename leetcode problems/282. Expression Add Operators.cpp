class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num,target,0,0,"",res);
        return res;
    }
    void dfs(string num,int target,long long diff,long long curNum,string temp,vector<string> &res){
        if(num.size() == 0 && curNum == target){
            res.push_back(temp);
        }
        for(int i=1; i<=num.size(); ++i){
            string cur = num.substr(0,i);
            if(cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            if(temp.size() > 0){
                dfs(next,target,stoll(cur),curNum + stoll(cur),temp + "+" + cur,res);
                dfs(next,target,-stoll(cur),curNum-stoll(cur),temp + "-" + cur,res);
                dfs(next,target,diff*stoll(cur),curNum-diff+diff*stoll(cur),temp + "*" + cur,res);
            }else{
                dfs(next,target,stoll(cur),stoll(cur),cur,res);
            }
        }
    }
};
