class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int> > dp(r,vector<int> (c,0));

        int res = 0;
        for(int i=0; i<r; ++i){
            for(int j=0 ;j<c; ++j){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j] - '0';
                }else if(matrix[i][j] == '1'){
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                }
                res = max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};
