class Solution1 {
public:
    int numSquares(int n) {
        vector<int> dp(1,0);
        while(dp.size() <= n){
            int m = dp.size();
            int val = INT_MAX;
            for(int i=1; i*i <= m; ++i){
                val = min(val,dp[m - i*i] + 1);
            }
            dp.push_back(val);
        }
        return dp.back();
    }
};
class Solution2 {
public:
    int numSquares(int n) {
        int res = n;
        int m = 2;
        while(m * m <= n){
            int a = n/(m*m), b = n%(m*m);
            res = min(res,a + numSquares(b));
            m++;
        }
        return res;
    }
};
