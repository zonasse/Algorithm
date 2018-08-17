class Solution {
public:
    int totalNQueens(int n) {
        vector<int> colNumber(n,-1);
        int ans = 0;
        dfs(0,n,ans,colNumber);
        return ans;
    }
    void dfs(int cur,int n,int &ans,vector<int> &colNumber){
        if(cur == n){
            ans++;
            return;
        }
        for(int i=0; i<n; ++i){
            bool flag = true;
            colNumber[cur] = i;
            for(int j=0; j<cur; ++j){
                if(colNumber[j] == colNumber[cur] || colNumber[j]+j == colNumber[cur]+cur || colNumber[j]-j == colNumber[cur]-cur){
                    flag = false;
                    break;
                }
            }
            if(flag == true) dfs(cur+1,n,ans,colNumber);
        }
    }
};
