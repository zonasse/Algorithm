class Solution1 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        if(k*9 < n || k > n) return res;
        vector<int> temp;
        dfs(1,k,n,res,temp);
        return res;
    }
    void dfs(int curCount,int k,int n,vector<vector<int> > &res,vector<int> temp){
        if(n < 0) return;
        if(temp.size() == k && n == 0){
            res.push_back(temp);
            return;
        }
        for(int i=curCount; i<=9; ++i){
            temp.push_back(i);
            dfs(i+1,k,n-i,res,temp);
            temp.pop_back();
        }
    }
};
class Solution2 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        if(k*9 < n || k > n) return res;
        vector<int> temp;
        vector<bool> mark(10,false);
        dfs(1,0,k,0,n,res,temp,mark);
        return res;
    }
    void dfs(int curNumber,int curCount,int k,int curSum,int n,vector<vector<int> > &res,vector<int> temp,vector<bool> &mark){
        if(curCount > k || curSum > n) return;
        if(curCount == k && curSum == n){
            res.push_back(temp);
            return;
        }
        for(int i=curNumber; i<=9; ++i){
            if(!mark[i]){
                mark[i] = true;
                temp.push_back(i);
                curSum += i;
                dfs(i+1,curCount+1,k,curSum,n,res,temp,mark);
                curSum -= i;
                temp.pop_back();
                mark[i] = false;
            }

        }
    }
};
