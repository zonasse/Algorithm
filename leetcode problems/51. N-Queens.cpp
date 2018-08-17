class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> colNumber(n,-1);//存放某行皇后放置的列号
        vector<vector<string> > ret;
        if(n < 1) return ret;
        dfs(n,ret,0,colNumber);
        return ret;
    }
    void dfs(int n,vector<vector<string> > &ret,int cur,vector<int> &colNumber){
        if(cur == n){
            vector<string> temp = getOneSolution(colNumber);
            ret.push_back(temp);
            return;
        }
        for(int i=0; i<n; ++i){
            bool flag = true;
            colNumber[cur] = i;
            for(int j=0; j<cur; ++j){
                if(colNumber[j] == colNumber[cur] || colNumber[j]+j == colNumber[cur] + cur || colNumber[j]-j == colNumber[cur]-cur){
                    flag = false;
                    break;
                }
            }
            if(flag == true) dfs(n,ret,cur+1,colNumber);
        }
    }
    vector<string> getOneSolution(vector<int> &colNumber){
        vector<string> ret(colNumber.size());
        for(int i=0; i<colNumber.size(); ++i){
            for(int j=0; j<colNumber.size(); ++j){
                if(colNumber[i] == j){
                    ret[i].push_back('Q');
                }else{
                    ret[i].push_back('.');
                }
            }
        }
        return ret;
    }
};
