class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        if(n < k) return res;
        vector<int> temp;
        dfs(n,1,k,temp,res);
        return res;
    }
    void dfs(int n,int cur,int k,vector<int> &temp,vector<vector<int> > &res){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        for(int i=cur; i<=n; ++i){
            temp.push_back(i);
            dfs(n,i+1,k,temp,res);
            temp.pop_back();
        }
    }
};
